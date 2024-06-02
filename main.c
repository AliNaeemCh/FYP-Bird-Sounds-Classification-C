#include"stdio.h"
#include<stdbool.h>
#include"parameters.h"
#include"computefft.h"
#include "DSK6713_AIC23.h"
#include <math.h>
#include"hamming.h"
#include"sign.h"
#include"melfilterbanks.h"
#include"computedct.h"
#include"computelogpowerspect.h"
#include"computedelmfccs.h"
#include"computespectralcentroid.h"
#include"computezcr.h"
#include"computesro.h"
#include"normalizeit.h"
#include"theta.h"
#include"minval.h"
#include"maxval.h"
#include"avg.h"
#include"classnames.h"
#include"normfv.h"
#include"mean.h"
#include"calcmean.h"
#include"max.h"
#include"identifyclass.h"
#include"silencecheck.h"
Uint32 fs=DSK6713_AIC23_FREQ_16KHZ; //set sampling rate
bool idle=true, inflag=true, on=true, off=false;
short frame_in[framesize];
short identified_class_index;
short silentframes=0;
short samplehold;
short index1=0, index2=0, findex=0, rsindex=0, bindex=0, sindex1=0, sindex2=totaloverlappingsamples;
float surplus_samples[surplus_samples_size];
float sum[1];
float frame[framesize];
float frame_dft[dftvals];
float logpowerspect[totalmelfilterbanks];
short overlappingsamples[totaloverlappingsamples];
float fvin[totalframes][totalfeatures];
float fvout[totalfeatures+1];
char *identified_class;
interrupt void c_int11() //interrupt service routine
{
	 samplehold = input_sample(); //input data
if(inflag==true){
 if(index1>=totalnonoverlappingsamples)	{
	 overlappingsamples[index2]=samplehold;
	 index2=index2+1;
 }
 frame_in[index1]=samplehold;
 frame[index1]=samplehold*hamming[index1];
 index1=index1+1;}
else{
	surplus_samples[sindex1]=samplehold*hamming[sindex2];
	sindex1++;
	sindex2++;
}
 return;
}
void main()
{
	comm_intr(); //init DSK, codec, McBSP
	while(1){
	if(DSK6713_DIP_get(0)==0)
		silencethreshold=1000;
	else if(DSK6713_DIP_get(1)==0)
		silencethreshold=5000;
	else if(DSK6713_DIP_get(2)==0)
		silencethreshold=10000;
	else if(DSK6713_DIP_get(3)==0)
		silencethreshold=15000;
	if(index1>=framesize){
		inflag=false;		//halts samples incoming
		if(idle==false){
			rsindex++;
			if(rsindex>result_stay_frames)
				idle=true;
		}
		else{
			bindex++;
			if(bindex==idle_blink_frame_gap){
							if(on==true){
								on=false;
								DSK6713_LED_on(0);
							    DSK6713_LED_on(1);
								DSK6713_LED_on(2);
								DSK6713_LED_on(3);
							}
							else on=true;
							if(off==true){
								off=false;
								DSK6713_LED_off(0);
							    DSK6713_LED_off(1);
								DSK6713_LED_off(2);
								DSK6713_LED_off(3);
							}
							else off=true;
							bindex=0;
						}
					}
		if(silencecheck(sum,frame)==false && idle==true){
		silentframes=0;
		computefft(frame_dft,frame);
		computelogpowerspect(logpowerspect,frame_dft);
		computedct(fvin,logpowerspect,findex);
		computedelmfccs(fvin,findex);
		fvin[findex][totalmfccs+totaldelmfccs]=computezcr(frame);
		fvin[findex][totalmfccs+totaldelmfccs+1]=computespectralcentroid(frame_dft);
		fvin[findex][totalmfccs+totaldelmfccs+2]=computesro(frame_dft);
		findex++;
		if(findex>=totalframes){
			findex=0;
			calcmean(fvout,fvin);
			normfv(fvout);
			identified_class_index=identifyclass(fvout);
			identified_class=classnames[identified_class_index];
			rsindex=0;
			idle=false;
			puts(identified_class);
			switch(identified_class_index){
			case 0:
						DSK6713_LED_on(3);
						DSK6713_LED_off(2);
						DSK6713_LED_off(1);
						DSK6713_LED_off(0);
						break;
			case 1:
						DSK6713_LED_on(2);
						DSK6713_LED_off(3);
						DSK6713_LED_off(1);
						DSK6713_LED_off(0);
						break;
			case 2:
						DSK6713_LED_on(3);
						DSK6713_LED_on(2);
						DSK6713_LED_off(1);
						DSK6713_LED_off(0);
						break;
			case 3:
						DSK6713_LED_on(1);
						DSK6713_LED_off(3);
						DSK6713_LED_off(2);
						DSK6713_LED_off(0);
						break;
			case 4:
						DSK6713_LED_on(3);
						DSK6713_LED_on(1);
						DSK6713_LED_off(2);
						DSK6713_LED_off(0);
						break;
			case 5:
						DSK6713_LED_on(1);
						DSK6713_LED_on(2);
						DSK6713_LED_off(3);
						DSK6713_LED_off(0);
						break;
			case 6:
						DSK6713_LED_off(0);
						DSK6713_LED_on(3);
						DSK6713_LED_on(2);
						DSK6713_LED_on(1);
						break;
			case 7:
						DSK6713_LED_on(0);
						DSK6713_LED_off(3);
						DSK6713_LED_off(2);
						DSK6713_LED_off(1);
						break;

			default:
						DSK6713_LED_off(0);
						DSK6713_LED_off(1);
						DSK6713_LED_off(2);
						DSK6713_LED_off(3);
			}
		}
		for(index1=0;index1<totaloverlappingsamples;index1++)
			frame[index1]=overlappingsamples[index1]*hamming[index1];		//transferring overlapping samples to the beginning of new frame

		for(index2=0;index1<sindex2;index1++,index2++)
			frame[index1]=surplus_samples[index2];							//transferring surplus samples after the overlapping samples in the new frame
		}
		else{
			index1=0;
			if(findex>0){
				if(silentframes<=tolerable_silent_frames)
					silentframes++;
				else
					findex=0;
			}
		}
		index2=0;
		sindex1=0;
		sindex2=totaloverlappingsamples;
		inflag=true;	//resume samples incoming
	}
	}
}

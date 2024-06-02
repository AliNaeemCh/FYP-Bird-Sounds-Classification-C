//FFTr2.c FFT using TI's optimized FFT function and real-time input
#include "dsk6713_aic23.h"
#include <math.h>
#include"stdio.h"

//#define SQRT_N 16					//SQRT_N >= SQRT(N)
#define RADIX 2				    	//radix or base
#define DELTA (2*PI)/fftpts			    //argument for sine/cosine
#define PI 3.14159265358979
short i = 0;
short iTwid[fftpts/2];					//index for twiddle constants W
short iData[fftpts];						//index for bitrev X
//float Xmag[fftpts/2+1];						//magnitude spectrum of x
typedef struct Complex_tag {float re,im;}Complex;
Complex W[fftpts/RADIX];			    	//array for twiddle constants
Complex x[fftpts]; 				    	//fftpts complex data values
#pragma DATA_ALIGN(W,sizeof(Complex))   //align W on boundary
#pragma DATA_ALIGN(x,sizeof(Complex))	//align input x on boundary
void computefft(float *Xmag, float *input){
 for( i = 0 ; i < fftpts/RADIX ; i++ )
  {
   W[i].re = cos(DELTA*i);			//real component of W
   W[i].im = sin(DELTA*i);			//neg imag component
  }						    		//see cfftr2_dit
 digitrev_index(iTwid, fftpts/RADIX, RADIX);//produces index for bitrev() W
 bitrev(W, iTwid, fftpts/RADIX);		       //bit reverse W
 for(i=0; i<=fftpts/2; i++)
 	Xmag[i] = 0;					//init output magnitude

  for( i = 0 ; i < fftpts ; i++ )
   {
    x[i].re = input[i];
    x[i].im = 0.0 ;				    //zero imaginary part
   }

  cfftr2_dit(x, W, fftpts ) ;			    	//TI floating-pt complex FFT
  digitrev_index(iData, fftpts, RADIX);		//produces index for bitrev() X
  bitrev(x, iData, fftpts);			    	//freq scrambled->bit-reverse x
  for (i =0; i<=fftpts/2; i++)
    Xmag[i] = sqrt(x[i].re*x[i].re+x[i].im*x[i].im)/fftscale; //magnitude of X
}
    

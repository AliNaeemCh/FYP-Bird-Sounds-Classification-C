//this method is used for calculating mfccs
void computedct(float (*fvin)[totalfeatures], float *in, short findex){
	short M=totalmelfilterbanks;
	short Mdouble=M*2;
	
	for(i=firstdctcoeff;i<=lastdctcoeff;i++){
		fvin[findex][i-1]=0;
		for(j=0;j<M;j++)
			fvin[findex][i-firstdctcoeff]=fvin[findex][i-firstdctcoeff]+in[j]*cos( (PI*i*(2*j+1))/Mdouble );
		fvin[findex][i-firstdctcoeff]=2*fvin[findex][i-firstdctcoeff];
	}
}


void computelogpowerspect(float *logpowerspect,float *dft){
	float hold[dftvals];
	float holdsum;
	for(i=totalmelfilterbanks-1;i>=0;i--){
		holdsum=0;
		for(j=0;j<dftvals;j++){
			hold[j]=0;
			hold[j]=melfilterbanks[i][j]*dft[j];
			hold[j]=hold[j]*hold[j];
			holdsum=holdsum+hold[j];
		}
		logpowerspect[i]=0;
		logpowerspect[i]=log10(holdsum/dftvals);
	}
}

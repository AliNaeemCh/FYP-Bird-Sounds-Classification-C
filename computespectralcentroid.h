float computespectralcentroid(float *dft){
	float spectralcentroid;
	float num=0,den=0;
	for(i=0;i<dftvals;i++){
		num=num+dft[i]*i;
		den=den+dft[i];
	}
	spectralcentroid=0;
	spectralcentroid=num*resolution/den;
	return spectralcentroid;
}

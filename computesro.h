#define threshold 0.8
float computesro(float *dft){
	float cumsum[dftvals];
	float sro;
	cumsum[0]=dft[0];
	for(j=1;j<dftvals;j++)
		cumsum[j]=cumsum[j-1]+dft[j];
	float thresholdmag=threshold*cumsum[dftvals-1];
	for(j=0;j<dftvals;j++){
		if(cumsum[j]>thresholdmag){
			sro=j*resolution;
			return sro;
		}
	}
}

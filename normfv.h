void normfv(float *featurevector){
	for(i=0;i<totalfeatures;i++)
        featurevector[i]=(featurevector[i]-avg[i])/(maxval[i]-minval[i]);
}

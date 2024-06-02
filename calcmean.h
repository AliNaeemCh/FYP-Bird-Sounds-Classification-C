void calcmean(float *fvout, float (*fvin)[totalfeatures]){
	float rows[totalframes];
	for(i=0;i<totalfeatures;i++){
		for(j=0;j<totalframes;j++)
			rows[j]=fvin[j][i];
		fvout[i]=mean(rows,totalframes);
	}
}

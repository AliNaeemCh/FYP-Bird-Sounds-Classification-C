void computedelmfccs(float (*fvin)[totalfeatures], short findex){
	for(i=totalmfccs,j=0;j<totalmfccs-1;i++,j++)
		fvin[findex][i]=fvin[findex][j+1]-fvin[findex][j];
}

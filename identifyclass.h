#define Pthreshold 0.5							//Probability Threshold or the Minimum Confidence you consider to report a class
short identifyclass(float *featurevector){
	float Pden=0;
	float P[totalclasses];
	float Pnum[totalclasses];
	float valindex[2];
	featurevector[totalfeatures]=1;			//appending 1 at the end of feature vector
	for(i=0;i<totalclasses;i++){
		Pnum[i]=0;
		for(j=0;j<=totalfeatures;j++)
			Pnum[i]=Pnum[i]+theta[j][i]*featurevector[j];
		Pnum[i]=exp(Pnum[i]);
		Pden=Pden+Pnum[i];
	}
	for(i=0;i<totalclasses;i++)
		P[i]=Pnum[i]/Pden;
	max(valindex,P,totalclasses);
	if(valindex[0]>Pthreshold)
	return (short)(valindex[1]);
	else return NoClassIndex;
}

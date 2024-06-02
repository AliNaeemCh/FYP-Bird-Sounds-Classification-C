bool silencecheck(float *sum,float *frame){
	//int sum=0;
	sum[0]=0;
	for(i=framesize-1;i>=0;i--){
		sum[0]=sum[0]+fabs(frame[i]);}
    if(sum[0]<=silencethreshold)
    	return true;
    else return false;
}

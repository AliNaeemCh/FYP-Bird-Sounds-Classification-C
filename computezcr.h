float computezcr(float *frame){
	float zcr=0;
	for(i=0;i<framesize-1;i++)
		zcr=zcr+(float)abs(sign(frame[i])-sign(frame[i+1]))/2;
	return zcr;
}

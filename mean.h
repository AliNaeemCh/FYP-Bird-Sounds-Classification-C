float mean(float *data, short size){
	float mean=0;
	short k;
	for(k=0;k<size;k++)
		mean=mean+data[k];
	mean=mean/size;
	return mean;
}

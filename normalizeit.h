void normalizeit(float *data){
	float absmax;
	for(i=0;i<framesize;i++)
		data[i]=fabs(data[i]);
	absmax=data[0];
    for(i=1;i<framesize;i++) {
    if(absmax<data[i]) 
      absmax = data[i];
  }
  	for(i=0;i<framesize;i++)
  		data[i]=data[i]/absmax;
}

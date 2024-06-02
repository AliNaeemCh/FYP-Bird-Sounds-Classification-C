void max(float *dataout, float *datain, short size){
	dataout[1]=0;
	for (i=1;i<size;i++) {
    if (datain[0] < datain[i]) {
	datain[0]= datain[i];
	dataout[1]= i;			//transferring index of maxvalue
	}
  }
  dataout[0]=datain[0];	//transferring max value
}

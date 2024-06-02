void transferbirdname(short *writeop,short identified_bird_index){
FILE *fp;
		fp=fopen("D:\\Study\\My Documents\\FYP\\FYP-III\\WORK FILES\\MATLAB SIMULATION - SOFTMAX\\bird.txt","w");
		    // open the file for writing

						fwrite(&writeop[identified_bird_index],2,1,fp);
		// close the file
				        fclose(fp);
				        }



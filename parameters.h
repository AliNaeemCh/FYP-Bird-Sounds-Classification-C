#define framesize 512
#define framestep 384
#define totalclasses 9				//Among these, 8 are bird species and the last one is Noise Data
#define NoClassIndex 8
#define Fs 16000
#define fftpts 512
#define fftscale 256				//scaling factor is half of fft points (fftpts/2). For fftpts=512 points, fftscale=256
#define resolution 31.25
#define dftvals 257
#define totalmelfilterbanks 10
#define totalmfccs 9
#define totaldelmfccs 8
#define firstdctcoeff 1					//This will calculate mfccs from MFCC 2 
#define lastdctcoeff 9					//This will calculate mfccs up to MFCC 10
#define totalfeatures 20
#define PI 3.14159265358979
#define totaloverlappingsamples 128
#define totalnonoverlappingsamples 384
#define surplus_samples_size 100
#define totalframes 42                   //42 frames will be captured in a span of approx. 1 second
#define tolerable_silent_frames 42		 //this will allow approx. 1.3s silence period without resetting
#define result_stay_frames 16           //16 frames stay means result will stay for approx. 0.4-0.5 seconds
#define idle_blink_frame_gap 4          //In idle state, the LEDs will toggle after 4 frames i-e 128ms (~8Hz)
short i,j;
int silencethreshold;


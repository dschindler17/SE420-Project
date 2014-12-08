#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>


#include "eagleEye.h"

void readLatencyTest()
{
  char header[512];
  unsigned char img[2500*2500], newimg[2500*2500];
  int bufflen, hdrlen, caseNumber = 0; unsigned row=0, col=0, chan=0, pix;
  double rate=0.0;
  double totalRate=0.0, aveRate=0.0;
  struct timeval StartTime, StopTime;
  unsigned long long int microsecs;

  
  // TEST CASE 
  //
  // Basic PPM file read test
  //
  printf("Read Latency Test\n");
  for(caseNumber = 1; caseNumber < 50; caseNumber++)
  {
    gettimeofday(&StartTime, 0);
    memset(header, 0, sizeof(header));
    memset(img, 0, sizeof(img));
    memset(newimg,0,sizeof(newimg));
	bufflen = 0;
	hdrlen = 0;
	row = 0;
	col = 0;
    header[0]='\0';
	if(caseNumber > 10)
	  caseNumber = caseNumber%10;
	if(caseNumber == 0)
	  caseNumber++;
    switch (caseNumber) {
	
	case 1:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage1.ppm", 0);
	  break;
	  
	case 2:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage2.ppm", 0);
	  break;
	  
	case 3:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage3.ppm", 0);
	  break;
	  
	case 4:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage4.ppm", 0);
	  break;
	  
	case 5:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage5.ppm", 0);
	  break;
	 
	case 6:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage6.ppm", 0);
	  break;
	  
	case 7:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage7.ppm", 0);
	  break;
	  
	case 8:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage8.ppm", 0);
	  break;
	  
	case 9:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage9.ppm", 0);
	  break;
	  
	case 10:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage10.ppm", 0);
	  break;
	  
    }
  }
  gettimeofday(&StopTime, 0);
  microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);

  if(StopTime.tv_usec > StartTime.tv_usec)
    microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
  else
  microsecs-=(StartTime.tv_usec - StopTime.tv_usec);

  printf("Test Done in %u microsecs for %d iterations\n", microsecs, 10);
  rate=((double)10)/(((double)microsecs)/1000000.0);
  printf("%lf Read ops per second\n", rate);
}

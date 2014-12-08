#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>


#include "eagleEye.h"

void transformLatencyTest()
{
  char header[512];
  unsigned char img[2500*2500], newimg[2500*2500];
  int bufflen, hdrlen, caseNumber = 0; unsigned row=0, col=0, chan=0, radius;
  struct timeval StartTime, StopTime;
  unsigned long int microsecs;

  
  // TEST CASE 
  //
  // Basic Ptest to perform various transforms on various .ppm images to see the latency for each operation.
  //
  printf("Transform Latency Test\n");
  for(caseNumber = 1; caseNumber < 11; caseNumber++)
  {
    memset(header, 0, sizeof(header));
    memset(img, 0, sizeof(img));
    memset(newimg,0,sizeof(newimg));
	bufflen = 0;
	hdrlen = 0;
	row = 0;
	col = 0;
    header[0]='\0';

    switch (caseNumber) {
	
	case 1:
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage1.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatGrayTestImage1.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
	case 2:
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage2.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatGrayTestImage2.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
	case 3:
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage3.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatGrayTestImage3.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
	case 4:
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage4.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatGrayTestImage4.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
	case 5:
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage5.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatGrayTestImage5.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	 
	case 6:
	  radius = 1; 
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage1.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatBlurTestImage1Rad1.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
	case 7:
	  radius = 2; 
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage2.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatBlurTestImage2Rad2.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
	case 8:
	  radius = 3; 
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage3.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatBlurTestImage3Rad3.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
	case 9:
	  radius = 4; 
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage4.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatBlurTestImage4Rad4.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
	case 10:
	  radius = 5; 
	  gettimeofday(&StartTime, 0);
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage5.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "transformLatBlurTestImage5Rad5.ppm", 0);
      gettimeofday(&StopTime, 0);
      microsecs=((StopTime.tv_sec - StartTime.tv_sec)*1000000);
      if(StopTime.tv_usec > StartTime.tv_usec)
       microsecs+=(StopTime.tv_usec - StartTime.tv_usec);
      else
        microsecs-=(StartTime.tv_usec - StopTime.tv_usec);
      printf("Test Case #%d done in %u microsecs\n", caseNumber, microsecs);
	  break;
	  
    }
  }
}
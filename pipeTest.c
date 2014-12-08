#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "eagleEye.h"


void pipeTest()
{
  char header[512], str[10];
  unsigned char img[2500*2500], newimg[2500*2500];
  int bufflen, hdrlen; unsigned row=0, col=0, chan=0;
  int radius, caseNumber =0; 

  // TEST CASE #0
  //
  // Basic PPM file read, pipeline through all possible configurations, and write-back
  //
  printf("Pipeline Module Test");
  
  for(caseNumber = 1, radius = 1; caseNumber < 11; caseNumber++, radius++)
  {
    memset(header, 0, sizeof(header));
    memset(img, 0, sizeof(img));
    memset(newimg,0,sizeof(newimg));
	memset(str,0,sizeof(str));
	bufflen = 0;
	hdrlen = 0;
	row = 0;
	col = 0;
    header[0]='\0';
    switch (caseNumber) {
	
	case 1:
	  sprintf(str, "1.");
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage1.ppm", 0);
	  pipeline(img, newimg, row, col, chan, str);
      writeppm(newimg, bufflen, header, hdrlen, "PipeTestImage1.ppm", 0);
	  printf("\nTest Case 1 Completed\n");
	  break;
	  
	case 2:
	  sprintf(str, "2.");
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage1.ppm", 0);
	  pipeline(img, newimg, row, col, chan, str);
      writeppm(newimg, bufflen, header, hdrlen, "PipeTestImage2.ppm", 0);
	  printf("\nTest Case 2 Completed\n");
	  break;

	case 3:
	  sprintf(str, "12.");
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage1.ppm", 0);
	  pipeline(img, newimg, row, col, chan, str);
      writeppm(newimg, bufflen, header, hdrlen, "PipeTestImage3.ppm", 0);
	  printf("\nTest Case 3 Completed\n");
	  break;

	case 4:
	  sprintf(str, "2,1.");
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage1.ppm", 0);
	  pipeline(img, newimg, row, col, chan, str);
      writeppm(newimg, bufflen, header, hdrlen, "PipeTestImage4.ppm", 0);
	  printf("\nTest Case 4 Completed\n");
	  break;	  
	  
    }
  }

  

}
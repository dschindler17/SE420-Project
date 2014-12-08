#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "eagleEye.h"


void grayTest()
{
  char header[512];
  unsigned char img[2500*2500], newimg[2500*2500];
  int bufflen, hdrlen, caseNumber = 0; unsigned row=0, col=0, chan=0, pix;

  
  // TEST CASE #0
  //
  // Basic PPM file read, blur transform, and write-back
  //
  printf("Gray-Scale Module Test");
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
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage1.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage1.ppm", 0);
	  printf("\nTest Case 1 Completed");
	  break;
	  
	case 2:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage2.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage2.ppm", 0);
	  printf("\nTest Case 2 Completed");
	  break;
	  
	case 3:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage3.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage3.ppm", 0);
	  printf("\nTest Case 3 Completed");
	  break;
	  
	case 4:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage4.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage4.ppm", 0);
	  printf("\nTest Case 4 Completed");
	  break;
	  
	case 5:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage5.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage5.ppm", 0);
	  printf("\nTest Case 5 Completed");
	  break;
	 
	case 6:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage6.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage6.ppm", 0);
	  printf("\nTest Case 6 Completed");
	  break;
	  
	case 7:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage7.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage7.ppm", 0);
	  printf("\nTest Case 7 Completed");
	  break;
	  
	case 8:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage8.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage8.ppm", 0);
	  printf("\nTest Case 8 Completed");
	  break;
	  
	case 9:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage9.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage9.ppm", 0);
	  printf("\nTest Case 9 Completed");
	  break;
	  
	case 10:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage10.ppm", 0);
	  luminGray(img, newimg, row, col, chan);
      writeppm(newimg, bufflen, header, hdrlen, "GrayTestImage10.ppm", 0);
	  printf("\nTest Case 10 Completed\n");
	  break;
	  
    }
  }
}

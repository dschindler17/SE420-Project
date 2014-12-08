#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "eagleEye.h"

//Blur Test
//This test will take three .ppm images and read them in, transform them to their blurred counterpart
//according to the blur function and write back to new .ppm image files the results of the transform.
//The test will only utilize a single radius, set at 5, to perform the transform. 
void blurTest(int argc, char *argv[])
{
  char header[1024];
  unsigned char img[2500*2500], newimg[2500*2500];

  
  int bufflen, hdrlen; unsigned row=0, col=0, chan=0, pix;
  int radius, caseNumber =0; 

  
  // TEST CASE #0
  //
  // Basic PPM file read, blur transform, and write-back
  //
  printf("Blur Module Test");
 
  for(caseNumber = 1, radius = 1; caseNumber < 11; caseNumber++, radius++)
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
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage1.ppm", 0);
	  printf("\nTest Case 1 Completed");
	  break;
	  
	case 2:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage2.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage2.ppm", 0);
	  printf("\nTest Case 2 Completed");
	  break;
	  
	case 3:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage3.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage3.ppm", 0);
	  printf("\nTest Case 3 Completed");
	  break;
	  
	case 4:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage4.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage4.ppm", 0);
	  printf("\nTest Case 4 Completed");
	  break;
	  
	case 5:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage5.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage5.ppm", 0);
	  printf("\nTest Case 5 Completed");
	  break;
	 
	case 6:
	  radius = radius%5;
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage6.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage6.ppm", 0);
	  printf("\nTest Case 6 Completed");
	  break;
	  
	case 7:
	  radius = radius%5;
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage7.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage7.ppm", 0);
	  printf("\nTest Case 7 Completed");
	  break;
	  
	case 8:
	  radius = radius%5;
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage8.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage8.ppm", 0);
	  printf("\nTest Case 8 Completed");
	  break;
	  
	case 9:
	  radius = radius%5;
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage9.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage9.ppm", 0);
	  printf("\nTest Case 9 Completed");
	  break;
	  
	case 10:
	  radius = radius%5 + 1;
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage10.ppm", 0);
	  blur(img, newimg, row, col, chan, radius);
      writeppm(newimg, bufflen, header, hdrlen, "BlurTestImage10.ppm", 0);
	  printf("\nTest Case 10 Completed");
	  break;
	  
    }
  }
  //
  // END TEST CASE #2
  
}
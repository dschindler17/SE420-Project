#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>


#include "eagleEye.h"

void readWriteTest()
{
  char header[512];
  unsigned char img[2500*2500], newimg[2500*2500];
  int bufflen, hdrlen, caseNumber = 0; unsigned row=0, col=0, chan=0;

  
  // TEST CASE 
  //
  // Basic PPM file read test
  //
  printf("Read/Write  Test\n");
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
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage1.ppm", 0);
	  printf("\nTest Case #%d Done.",caseNumber);
	  break;
	  
	case 2:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage2.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage2.ppm", 0);
	  break;
	  
	case 3:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage3.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage3.ppm", 0);
	  break;
	  
	case 4:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage4.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage4.ppm", 0);
	  break;
	  
	case 5:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage5.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage5.ppm", 0);
	  break;
	 
	case 6:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage6.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage6.ppm", 0);
	  break;
	  
	case 7:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage7.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage7.ppm", 0);
	  break;
	  
	case 8:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage8.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage8.ppm", 0);
	  break;
	  
	case 9:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage9.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage9.ppm", 0);
	  break;
	  
	case 10:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleImage10.ppm", 0);
	  writeppm(newimg, bufflen, header, hdrlen, "ReadWriteTestImage10.ppm", 0);
	  break;
    }
	printf("\nTest Case #%d Done.\n",caseNumber);
  }
}

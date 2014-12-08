#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>


#include "eagleEye.h"

void invalidLocation()
{
  char header[512];
  unsigned char img[2500*2500], newimg[2500*2500];
  int bufflen, hdrlen, caseNumber = 0; 
  unsigned row=0, col=0, chan=0;

  
  // TEST CASE 
  //
  // Acceptance Test ci
  //
  printf("Invalid Location Test\n");
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
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "somethinag.ppm", 0);
	  break;
	  
	case 2:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleI.ppm", 0);
	  break;
	  
	case 3:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Sa.ppm", 0);
	  break;
	  
	case 4:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SampleIma.ppm", 0);
	  break;
	  
	case 5:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Sam5.ppm", 0);
	  break;
	 
	case 6:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Samplege6.ppm", 0);
	  break;
	  
	case 7:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "SaImage7.ppm", 0);
	  break;
	  
	case 8:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Samplge8.ppm", 0);
	  break;
	  
	case 9:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Sammage9.ppm", 0);
	  break;
	  
	case 10:
	  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Samp10.ppm", 0);
	  break;
	  
    }
	printf("\nTest Case #%d Done.\n",caseNumber);
  }
}

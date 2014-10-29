#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define PIXIDX ((i*col*chan)+(j*chan)+k)
#define PIXIDX2 ((i*col*chan)+(j*chan))
#define SAT 255


//Convert ppm image buffer to grayscale
//
//Function will...
//
//PRECONDITIONS
//
// 
//POSTCONDITIONS
//
//
void luminGray(unsigned char *img, unsigned char *newimg, unsigned row, unsigned col, unsigned chan)
{
  int unsigned avgpix;
  int i, j, k=0;
  for(i=0; i < row; i++)
    for(j=0; j < col; j++)
	{
	  avgpix = (unsigned)((.299*(float)img[PIXIDX2]) + (.587 * (float)img[PIXIDX2 + 1]) + (.114 * (float)img[PIXIDX2 + 2]));
	  for(k=0; k < chan; k++)
	  {
        newimg[PIXIDX] = avgpix > SAT ? SAT : avgpix;
	  }
	}
}

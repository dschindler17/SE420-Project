#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define PIXIDX ((rowIdx*col*chan)+(colIdx*chan)+chanIdx)
#define PIXIDXAVG (((rowIdx+HIdx)*col*chan)+((colIdx+VIdx)*chan)+chanIdx)
#define SAT 255


//Blur image
//
//Function will...
//
//PRECONDITIONS
//
// 
//POSTCONDITIONS
//
//
void blur(unsigned char *img, unsigned char *newimg, unsigned row, unsigned col, unsigned chan, int radius)
{
  int unsigned avgpix;
  int rowIdx = 0, colIdx = 0, chanIdx = 0, HIdx = 0, VIdx = 0; 
  float kernCount = 0.0, pixTotal =0.0;
  for(rowIdx=0; rowIdx < row; rowIdx++)
    for(colIdx=0; colIdx < col; colIdx++)
	{
	  for(chanIdx=0; chanIdx < chan; chanIdx++)
	  {
	    kernCount = 0;
		pixTotal = 0;
		if(colIdx < radius)
		{
		    for (VIdx = 0; VIdx < radius; VIdx++)
		    {
			  if(rowIdx < radius)
			  {
		        for (HIdx = 0; HIdx < radius; HIdx++)
		        {
		          pixTotal = pixTotal + img[PIXIDXAVG];
			      kernCount++;
		        }
			  }
			  else
			  {
		        for (HIdx = -radius; HIdx < radius; HIdx++)
		        {
		          pixTotal = pixTotal + img[PIXIDXAVG];
			      kernCount++;
		        }
			  }
	        }
		}
		else
		{
		    for (VIdx = -radius; VIdx < radius; VIdx++)
		    {
			  if(rowIdx < radius)
			  {
		        for (HIdx = radius; HIdx < radius; HIdx++)
		        {
		          pixTotal = pixTotal + img[PIXIDXAVG];
			      kernCount++;
		        }
			  }
			  else
			  {
		        for (HIdx = -radius; HIdx < radius; HIdx++)
		        {
		          pixTotal = pixTotal + img[PIXIDXAVG];
			      kernCount++;
		        }
			  }
	        }
		}
	  avgpix = (unsigned)(pixTotal / kernCount);
      newimg[PIXIDX] = avgpix > SAT ? SAT : avgpix;
	}
  }
}
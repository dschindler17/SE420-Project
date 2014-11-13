#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "brighten.h"


void pipeline(unsigned char *img, unsigned char *newimg, unsigned row, unsigned col, unsigned chan, char *argv[])
{
  unsigned char imgMed[4080*1024];
  char pipeOption;
  int pipeCount, argc = sizeof(*argv)/sizeof(argv[0]), radius; 
  double alpha;  unsigned char beta;

  for(pipeCount = 1; pipeCount <= argc; pipeCount++)
  { 
    pipeOption = ((int)argv[pipeCount] - 48); 
    switch (pipeOption) 
    {
                    case 1:
					        if (pipeCount == 0)
                              luminGray(img, newimg, row, col, chan);
							else if (pipeCount%2 == 0)
							  luminGray(newimg, imgMed, row, col, chan);
							else
							  luminGray(imgMed,newimg, row, col, chan);
                            break;
                    case 2:
                            printf("Enter the radius of the blur:");
                            scanf("%d", &radius);
                            if (pipeCount == 0)
                              blur(img, newimg, row, col, chan, radius);
							else if (pipeCount%2 == 0)
							  blur(newimg, imgMed, row, col, chan, radius);
							else 
							  blur(imgMed, newimg, row, col, chan, radius); 
                            break;
                    default:
                            printf("U have entered wrong option!!\n");
                            break;
    }
  }
  if (pipeCount%2 != 0)
    newimg = imgMed; 
}
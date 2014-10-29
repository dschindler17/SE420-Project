#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "brighten.h"


void main(int argc, char *argv[])
{
  char header[512], file[32], pipeOption = 'a', transOption = '0';
  unsigned char img[1024*1024], newimg[1024*1024*2], pipeimg[1024*1024*2];
  int bufflen, hdrlen; unsigned row=0, col=0, chan=0, pix;
  int radius; 
  double alpha;  unsigned char beta;

  printf("Please Enter name of Image: ");
  scanf(" %s", file);
  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, file, 0);
  
  printf("\nWould you like to perform multiple transforms? [y/n] ");
  scanf(" %c", &pipeOption);
  if(pipeOption == 'n' || pipeOption == 'N')
  {
    printf("\nPlease select from options below:");
	printf("\n[1] Brighten and Contrast");
	printf("\n[2] Grayscale");
	printf("\n[3] Blur\n");
	scanf(" %c", &transOption);
	if(transOption == '1')
	{
	  printf("\nAlpha: ");
	  scanf(" %f", &alpha);
	  printf("\nBeta: ");
	  scanf(" %c", &beta);
	  
	  scaleImage(img, newimg, row, col, chan, (double)alpha, (unsigned char)beta);
	}
	else if(transOption == '2')
	{
	  luminGray(img, newimg, row, col, chan);
	}
	else if(transOption == '3')
	{
	  printf("\nRadius: ");
	  scanf(" %d", &radius);
	  blur(img, newimg, row, col, chan, radius);
	}
	else
	  printf("\nIncorrect Input");
	writeppm(newimg, bufflen, header, hdrlen, "newImage.ppm", 0);
  }
  else
  {
    while(transOption != '4')
	{
	  printf("\nPlease select from options below:");
	  printf("\n[1] Brighten and Contrast");
	  printf("\n[2] Grayscale");
	  printf("\n[3] Blur");
	  printf("\n[4] Transform Image");
	  scanf(" %c", &transOption);
	  if(transOption == '1')
	  {
	    printf("\nAlpha: ");
	    scanf(" %f", &alpha);
	    printf("\nBeta: ");
	    scanf(" %c", &beta);
	    scaleImage(img, pipeimg, row, col, chan, (double)alpha, (unsigned char)beta);
	  }
	  else if(transOption == '2')
	  {
	    luminGray(img, pipeimg, row, col, chan);
	  }
	  else if(transOption == '3')
	  {
	    printf("\nRadius: ");
	    scanf(" %d", &radius);
	    blur(img, pipeimg, row, col, chan, radius);
	  }
	  else
	    printf("\nIncorrect Input");
	}
    writeppm(pipeimg, bufflen, header, hdrlen, "newImage.ppm", 0);
  }

}

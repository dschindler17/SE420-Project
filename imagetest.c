#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "brighten.h"


void main(int argc, char *argv[])
{
  char header[512];
  unsigned char img[4080*1024], newimg[4080*1024*2];
  int bufflen, hdrlen; unsigned row=0, col=0, chan=0, pix; int i, j, k;
  double alpha=1.25;  unsigned char beta=25;


  // TEST CASE #0
  //
  // Basic PPM file read, scaling and bias test, and write-back
  //
  header[0]='\0';
  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, argv[1], 0);

  alpha=1.25, beta =25;
  scaleImage(img, newimg, row, col, chan, alpha, beta);
  writeppm(newimg, bufflen, header, hdrlen, "brighter-1.25-25.ppm", 0);
  
  luminGray(img, newimg, row, col, chan);
  writeppm(newimg, bufflen, header, hdrlen, "gray.ppm", 0);

  alpha=1.5, beta =50;
  scaleImage(img, newimg, row, col, chan, alpha, beta);
  writeppm(newimg, bufflen, header, hdrlen, "brighter-1.5-50.ppm", 0);

  //
  // END TEST CASE #0
  

}

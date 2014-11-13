#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "brighten.h"


void main()
{
  char header[512];
  unsigned char img[4080*1024], newimg[4080*1024];
  int bufflen, hdrlen; unsigned row=0, col=0, chan=0;

  // TEST CASE #0
  //
  // Basic PPM file read, pipeline through all possible configurations, and write-back
  //
  header[0]='\0';
  
  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Baby-Musk-Ox.ppm", 0);
  pipeline(img, newimg, row, col, chan, 1);
  writeppm(newimg, bufflen, header, hdrlen, "pipe1a", 0);
  
  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Baby-Musk-Ox.ppm", 0);
  pipeline(img, newimg, row, col, chan, 12);
  writeppm(newimg, bufflen, header, hdrlen, "pipe2a", 0);
  
   readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Baby-Musk-Ox.ppm", 0);
  pipeline(img, newimg, row, col, chan, 2);
  writeppm(newimg, bufflen, header, hdrlen, "pipe3a", 0);
  

  //
  // END TEST CASE #0
  

}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "brighten.h"

//Gray-Scale Test
//This test will take three .ppm images and read them in, transform them to their grayscale counterpart
//according to the luminGray function and write back to new .ppm image files the results of the transform.
void main()
{
  char header[512];
  char header2[512];
  char header3[512];
  unsigned char img[1024*1024], newimg[1024*1024*2];
  unsigned char img2[1024*1024], newimg2[1024*1024*2];
  unsigned char img3[1024*1024], newimg3[1024*1024*2];
  
  int bufflen, hdrlen; unsigned row=0, col=0, chan=0, pix;
  int bufflen2, hdrlen2; unsigned row2=0, col2=0, chan2=0, pix2;
  int bufflen3, hdrlen3; unsigned row3=0, col3=0, chan3=0, pix3;


  // TEST CASE #0
  //
  // Basic PPM file read, convert to gray scale, and write-back
  //
  header[0]='\0';
  
  readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, "Baby-Musk-Ox.ppm", 0);
  luminGray(img, newimg, row, col, chan);
  writeppm(newimg, bufflen, header, hdrlen, "OxGray.ppm", 0);
  
  readppm(img2, &bufflen2, header2, &hdrlen2, &row2, &col2, &chan2, "Black-Shiba-Inu.ppm", 0);
  luminGray(img2, newimg2, row2, col2, chan2);
  writeppm(newimg2, bufflen2, header2, hdrlen2, "ShibaGray.ppm", 0);

  readppm(img3, &bufflen3, header3, &hdrlen3, &row3, &col3, &chan3, "Moose-Earthquake-Park.ppm", 0);
  luminGray(img3, newimg3, row3, col3, chan3);
  writeppm(newimg3, bufflen3, header3, hdrlen3, "MooseGray.ppm", 0);

  //
  // END TEST CASE #0
  

}

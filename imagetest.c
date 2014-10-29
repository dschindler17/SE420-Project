#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "brighten.h"


void main(int argc, char *argv[])
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
  double alpha=1.25;  unsigned char beta=25;


  // TEST CASE #0
  //
  // Basic PPM file read, scaling and bias test, and write-back
  //
  // header[0]='\0';
  // readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, argv[1], 0);

  // alpha=1.25, beta =25;
  // scaleImage(img, newimg, row, col, chan, alpha, beta);
  // writeppm(newimg, bufflen, header, hdrlen, "brighter-1.25-25.ppm", 0);
  
  // luminGray(img, newimg, row, col, chan);
  // writeppm(newimg, bufflen, header, hdrlen, "gray.ppm", 0);

  // alpha=1.5, beta =50;
  // scaleImage(img, newimg, row, col, chan, alpha, beta);
  // writeppm(newimg, bufflen, header, hdrlen, "brighter-1.5-50.ppm", 0);

  //
  // END TEST CASE #0
  
  // TEST CASE #1
  //
  // Basic PPM file read, convert to gray scale, and write-back
  //
  header[0]='\0';
  header2[0]='\0';
  header3[0]='\0';
  
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
  // END TEST CASE #1

}

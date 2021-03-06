#ifndef BRIGHTEN_H
#define BRIGHTEN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SAT (255)

//Prototypes for modules
void readppm(unsigned char *buffer, int *bufferlen, 
             char *header, int *headerlen,
             unsigned *rows, unsigned *cols, unsigned *chans,
             char *file, int debug);

void writeppm(unsigned char *buffer, int bufferlen,
              char *header, int headerlen,
              char *file, int debug);


void luminGray(unsigned char *img, unsigned char *newimg, unsigned row, unsigned col, unsigned chan);

void blur(unsigned char *img, unsigned char *newimg, unsigned row, unsigned col, unsigned chan, int radius);

unsigned char pipeline(unsigned char *img, unsigned char *newimg, unsigned row, unsigned col, unsigned chan, char *pipeString);

//Prototypes for Acceptance Tests
void blurTest();
void grayTest();
void pipeTest();
void readLatencyTest();
void transformLatencyTest();
void readWriteTest();
void invalidLocation();
void invalidType();

#endif

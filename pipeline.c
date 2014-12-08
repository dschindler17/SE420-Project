#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void  pipeline(unsigned char *buffer, unsigned char *newBuffer, unsigned row, unsigned col, unsigned chan, char *pipeString)
{
   int pipeStringIndex = 0, radius;
   while(pipeString[pipeStringIndex] !=  '.')
   {
      if (pipeString[pipeStringIndex] == '1')
	  {
	     luminGray(buffer,newBuffer,row, col, chan);
		 printf("\nGrayscale completed successfully");
	  }
      else if (pipeString[pipeStringIndex] == '2')
	  {
	     printf("\nPlease enter radius for blur: ");
		 scanf(" %d", &radius);
		 blur(buffer, newBuffer, row, col, chan, radius);
		 printf("Blur completed successfully");
	  }
	  else if (pipeString[pipeStringIndex] == ',')
	  {
   
	  }
	  else
	    printf("\nIncorrect input, please enter only 1,2, or .");
	  pipeStringIndex++;
	  if(pipeString[pipeStringIndex + 1] != '.')
	  {
	    memcpy(buffer,newBuffer,sizeof(buffer));
	    memset(newBuffer,0,sizeof(newBuffer));
	  }
   }
}
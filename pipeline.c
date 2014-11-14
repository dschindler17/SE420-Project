#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


unsigned char  pipeline(unsigned char **buffer, unsigned row, unsigned col, unsigned chan, char *pipeString)
{
   int pipeStringIndex = 0, radius;
   unsigned char newBuffer[4080 * 1024], *temp;
   printf("%s",*pipeString);
   while(pipeString[pipeStringIndex] != NULL)
   {
      if (pipeString[pipeStringIndex] == '1')
	  {
	     luminGray(buffer,newBuffer,row, col, chan);
		 printf("\nGrayscale completed successfully\n");
	  }
      else if (pipeString[pipeStringIndex] == '2')
	  {
	     printf("\nPlease enter radius for blur: ");
		 scanf(" %d", &radius);
		 blur(buffer, newBuffer, row, col, chan, radius);
		 printf("\nBlur completed successfully\n");
	  }
	  else if (pipeString[pipeStringIndex] == ',')
	  {
	  
	  }
	  else
	    printf("\nIncorrect input, please enter only 1,2,3 or ,");
	  temp = (*buffer);
	  (*buffer) = newBuffer; 
	  *newBuffer = temp;
	  pipeStringIndex++;
   }
   return buffer;
}
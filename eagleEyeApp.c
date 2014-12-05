#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "eagleEye.h"

#define TOPMENU "Menu: Please enter of one the following commands.\n1 to perform a single transform\n2 to perform multiple transforms on single image\n3 to quit program: "
#define SINGLEMENU "Please enter of one the following commands.\n1 to perform a Gray-Scale transform\n2 to perform a blur transform\n3 to go back to previous menu: "
#define PIPEMENU "To perform a pipe transform enter a string in the format [1,2,1.] where 1 is for a gray-scale transform and 2 is for a blur transform: "

int main()
{
  unsigned char img[2500*2500], newimg[2500*2500];
  int bufflen, hdrlen, caseNumber = 0, radius = 0, transformNumber = 0;
  unsigned row = 0, col = 0, chan = 0;
  char programCommand = 'a', topMenu[sizeof(TOPMENU)] = TOPMENU, header[512], fileName[250], pipeString[10], newFileName[50];
  char singleMenu[sizeof(SINGLEMENU)] = SINGLEMENU, pipeMenu[sizeof(PIPEMENU)] = PIPEMENU;

  printf("\nWelcome to EagleEye v1.0\n");

  while (1)
  {
    printf("\nPlease enter the name of the image file you would like to use (must be in same directory as application: ");
    scanf(" %s", fileName);
    readppm(img, &bufflen, header, &hdrlen, &row, &col, &chan, fileName, 0);
    printf("\n%s", topMenu);
    scanf(" %c", &programCommand);
	//Single Transform Operation
	if(programCommand == '1')
	{
	  printf("\n%s", singleMenu);
	  scanf(" %c",&programCommand);
	  if (programCommand == '1')
	    luminGray(img, newimg, row, col, chan);
	  else if (programCommand == '2')
	  {
	    printf("\nPlease enter radius for blur: ");
		scanf(" %d", &radius);
	    blur(img, newimg, row, col, chan, radius);
		printf("Blur Transform completed.\n");
	  }
	  else if (programCommand = '3')
	    printf("\nGoing back to previous menu\n");
	  else
	  {
	    printf("Incorrect input, please try again.");
	    printf("\n%s", singleMenu);
	    scanf(" %c",&programCommand);
	  }
	  programCommand = 'a';
	  transformNumber++;
	  sprintf(newFileName,"newImage%d.ppm",transformNumber);
	  writeppm(newimg, bufflen, header, hdrlen, newFileName, 0);
	  printf("\nNew image created, file name = %s", newFileName);
	  printf("\nWould you like to perform another operation [y/n]: ");
	  scanf(" %c", &programCommand); 
	  if(programCommand == 'y' || programCommand == 'Y')
	  {
	    //resetting all allocated memory back to zero states
	    memset(header, 0, sizeof(header));
        memset(img, 0, sizeof(img));
        memset(newimg,0,sizeof(newimg));
	    bufflen = 0;
	    hdrlen = 0;
	    row = 0;
	    col = 0;
        header[0]='\0';
	  }
	  else
	  {
	     printf("\nProgram Exited.\n");
	     break;
	  }
	}
	//Pipeline Transform Operation
	else if(programCommand == '2')
	{
	  printf("\n%s", pipeMenu);
	  scanf(" %s",&pipeString);
	  pipeline(img, newimg, row, col, chan, pipeString);
	  transformNumber++;
	  sprintf(newFileName,"newImage%d.ppm",transformNumber);
	  writeppm(newimg, bufflen, header, hdrlen, newFileName, 0);
	  printf("\nNew image created, file name = %s",newFileName);
	  printf("\nWould you like to perform another operation [y/n]: ");
	  scanf(" %c", &programCommand); 
	  if(programCommand == 'y' || programCommand == 'Y')
	  {
	    //resetting all allocated memory back to zero states
	    memset(header, 0, sizeof(header));
        memset(img, 0, sizeof(img));
        memset(newimg,0,sizeof(newimg));
	    bufflen = 0;
	    hdrlen = 0;
	    row = 0;
	    col = 0;
        header[0]='\0';
	  }
	  else
	  {
	     printf("\nProgram Exited.\n");
	     break;
	  }
	}
    
	//Quit option
	else if (programCommand == '3' )
	{
	  printf("\nProgram Exited.\n");
	  break;
	}
	else
	{
	  printf("\nIncorrect Input");
	  printf("\n\n%s", topMenu);
	  scanf(" %c", &programCommand);	
	}
  }
  return 0;
}  
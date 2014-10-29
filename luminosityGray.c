#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define PIXIDX ((i*col*chan)+(j*chan)+k)
#define PIXIDX2 ((i*col*chan)+(j*chan))
#define SAT 255


//Search the Binary Tree Function
//
//Function will take as input a previously declared pointer to the root node of a BST and data from the node being
//searched for. The node being searched for is not currently a node within the BST but is a node that is to be inserted 
//into the BST. The function will search all nodes of the BST to locate the location of where the node should be inserted
//and return the necessary parent of the node being searched for.
//
//PRECONDITIONS
//The data passed into the function must be previously declared and must not be a part of the BST.
//The pointer passed into the function must point to the root node of some previously declared BST.
// 
//POSTCONDITIONS
//The function will not alter the BST containing the root node pointed to by the pointer passed into the function.
//The function will return the address of the necessary parent (according to the BST property) where a node containing
//the searched for data should be located.
//
void luminGray(unsigned char *img, unsigned char *newimg, unsigned row, unsigned col, unsigned chan)
{
  int unsigned avgpix;
  int i, j, k=0;
  for(i=0; i < row; i++)
    for(j=0; j < col; j++)
	{
	  avgpix = (unsigned)((.299*(float)img[PIXIDX2]) + (.587 * (float)img[PIXIDX2 + 1]) + (.114 * (float)img[PIXIDX2 + 2]));
	  for(k=0; k < chan; k++)
	  {
        newimg[PIXIDX] = avgpix > SAT ? SAT : avgpix;
	  }
	}
}

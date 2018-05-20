#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "Grid.h"

G_Grid G_createGrid(char *arrayParameters[G_LENGTH])
{

	G_Grid grid;
	S_SQUARE *square = S_createSquare();
	int i;

	for (i = 0; i < G_LENGTH; i++)
	{
		S_defineSquare(c, arrayParameters[i], i);
		grille.arraySquares[i] = *square;
	}

	S_delete(c);
	return grille;
}

S_SQUARE G_getSquare(G_Grid grid, int squareNumber)
{
	return g.arraySquares[squareNumber];
}

LL_LinkedList G_getNeighbours(G_Grid grid, S_SQUARE square)
{

	int squareNumber = S_getPosition(c);
	LL_LinkedList linkedList = LL_createLinkedList();
	int neighbourgs[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
	int i;
	S_SQUARE *neighbourg = S_createSquare();
	if (squareNumber % 4 == 0)
	{ //left column of the grid
		neighbourgs[1] = squareNumber - G_COTE;
		neighbourgs[2] = squareNumber - G_COTE + 1;
		neighbourgs[4] = squareNumber + 1;
		neighbourgs[6] = squareNumber + G_COTE;
		neighbourgs[7] = squareNumber + G_COTE + 1;
	}
	else if ((squareNumber + 1 % 4) == 0)
	{ // 0 is excluded thanks to the first if (right column of the grid)
		neighbourgs[0] = squareNumber - G_COTE - 1;
		neighbourgs[1] = squareNumber - G_COTE;
		neighbourgs[3] = squareNumber - 1;
		neighbourgs[5] = squareNumber + G_COTE - 1;
		neighbourgs[6] = squareNumber + G_COTE;
	}
	else
	{
		neighbourgs[0] = squareNumber - G_COTE - 1;
		neighbourgs[1] = squareNumber - G_COTE;
		neighbourgs[2] = squareNumber - G_COTE + 1;
		neighbourgs[3] = squareNumber - 1;
		neighbourgs[4] = squareNumber + 1;
		neighbourgs[5] = squareNumber + G_COTE - 1;
		neighbourgs[6] = squareNumber + G_COTE;
		neighbourgs[7] = squareNumber + G_COTE + 1;
	}

	for (i = 0; i < 8; i++)
	{
		if ((neighbourgs[i] >= 0) && (neighbourgs[i] < G_LENGTH))
		{
			*neighbourg = G_getSquare(g, neighbourgs[i]);
			LL_add(&linkedList, neighbourg, S_copy);
		}
	}
	S_delete(neighbourg);
	return linkedList;
}

void G_deleteGrid(G_Grid grid)
{
	int i;
	for (i = 0; i < G_LENGTH; i++)
	{
		free(S_getValue(G_getSquare(grid, i)));
	}
}

#include <string.h>
#include <assert.h>

#include "createGridToSolve.h"

G_Grid createGridToSolve(char *stringParametersGrid)
{

	assert(strlen(stringParametersGrid) == (G_LENGTH * 4)); /* 16 fois (CARACTERE + 3*space)*/
	char *arrayParameters[G_LENGTH];
	int i;
	for (i = 0; i < G_LENGTH; i++)
	{
		arrayParameters[i] = subString(stringParametersGrid, i * G_COTE, i * G_COTE + G_COTE - 1);
	}
	return G_createGrid(arrayParameters);
}

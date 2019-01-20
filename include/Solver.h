#ifndef __SOLVER__
#define __SOLVER__

#include <string.h>

#include "Dictionary.h"
#include "Grid.h"
#include "LinkedList.h"

/**
 *	\fn LL_LinkedList solveRuzzle(char *stringGrid, char *pathToIntelligentFile);
 *	\brief Solve the ruzzle and return a list with all the words ordered by
 number of points.
 *
 *	\param *stringGrid The grid in the form of a string.
 *	\param *pathToIntelligentFile Pointer to the file containing the
 serialized dictionary. *	\return LL_LinkedList listSolutions
 */

LL_LinkedList solveRuzzle(char *stringGrid, char *pathToIntelligentFile);
#endif
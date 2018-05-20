/*Michel Cressant 11/12/2014*/

/** \file createGridToSolve.h
 *	\brief Contient la fonction qui permet de create la grille à solve
 *	\version 1.0
 *	\date 26/12/2014
 */

#ifndef __CREATE_GRID_TO_SOLVE__
#define __CREATE_GRID_TO_SOLVE__

#include "Dictionary.h"
#include "Grid.h"
#include "Word.h"
#include "LinkedList.h"
#include "subString.h"

/**
 *	\fn G_Grid *squarereerGridAResoudre(char *stringParametersGrid)
 *	\brief Permet de create une grille
 *	\param *grid la grille dans laquelle se trouve la case (pointeur)
 *	\param *adjacentSquare les cases contigues (pointeur)
 *	\return LL_LinkedList
 */
G_Grid createGridToSolve(char *stringParametersGrid);

#endif

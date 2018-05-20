/* Michel CRESSANT - 11/12/2014 */
/* Benjamin Deguerre - 02/01/2015 */

/** \file solveGrid.h
 *	\brief Contient la fonction qui permet de solve une grid de ruzzle
 *	\version 1.0
 *	\date 02/01/2015
 */
#ifndef __SOLVE_GRID__
#define __SOLVE_GRID__

#include <string.h>

#include "AdjacentSquares.h"
#include "Dictionary.h"
#include "Grid.h"
#include "LinkedList.h"
#include "Word.h"
#include "isSolution.h"

/**
 *	\typedef sG_Word
 *	\brief Contient un mot avec sa value en point dans la grid
 */
typedef struct sG_Word {
  char *word; /**< le mot */
  int point;  /**< Valeur en point du mot */
} sG_Word;

/**
 *	\fn	LL_LinkedList solveGrid(D_Dictionary dictionary, G_Grid
 *gridToSolve)
 *	\brief retourne une
 *	\param dic le dictionary contenant l'ensemble des mots possible
 *	\param gridToSolve la grid à solve
 *	\return LL_LinkedList
 */

LL_LinkedList solveGrid(D_Dictionary dictionary, G_Grid gridToSolve);

#endif

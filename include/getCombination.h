/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */

/** \file getCombinaisons.h
 *	\brief Contient la fonction qui permet d'get les combinaisons d'une grille
 *	\version 1.0
 *	\date 11/12/2014
 */
#ifndef __GET_COMBINATION__
#define __GET_COMBINATION__

#include "Grid.h"
#include "Word.h"
#include "LinkedList.h"

/**
 *	\fn LL_LinkedList *getCombination(G_Grid *grid);
 *	\brief Permet d'get les combinaisons d'une grille
 *	\param *grid est un pointeur sur une grille
 *	\return int
 */
LL_LinkedList *getCombination(G_Grid *grid);

#endif

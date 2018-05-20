/* Arthur Hamelin - 10/12/2014 */
/* Benjamin Deguerre - 25/12/2014 */

/** \file AdjacentSquares.h
 *	\brief Implémentation du TAD AdjacentSquares
 *	\version 1.0
 *	\date 26/12/2014
 */

#ifndef __ADJACENT_SQUARES__
#define __ADJACENT_SQUARES__

#include "Square.h"
#include "LinkedList.h"
#include "Grid.h"

/**
 *	\typedef AS_AdjacentSquares
 *	\brief Structure représentant une suite de cases
 *
 *	Cette structure contient, une liste ordonnée de case, le nombre de points des cases (sans le bonus multiplicateur sur le mot mais avec celui sur la lettre, et le coefficient du bonus sur le mot
 */
typedef struct
{
	LL_LinkedList linkedList;
	int numberOfPoints;   /**< nombre de point des cases (somme), sans compter mot compte double, triple... */
	int coefficientBonus; /**< contient le coefficient multiplicateur du bonus sur le mot */
} AS_AdjacentSquares;

#define AS_MEMORY_ERROR 1

/**
 *	\fn AS_AdjacentSquares AS_createAdjacentSquares()
 *	\brief Créé la suite de case, linkedList vide et numberOfPoints, coefficientBonus à 0
 *	\return AS_AdjacentSquares*
 */
AS_AdjacentSquares *AS_createAdjacentSquares();

/**
 *	\fn LL_LinkedList AS_getPossibleNeighbours(G_Grid *grid, AS_AdjacentSquares *adjacentSquare)
 *	\brief Permet d'get tout les cases voisins possible de la dernière case
 *
 *	Les cases déjà préssentes dans la suite de cases contigues ne seront pas renvoyées
 *	\param *grid la grille dans laquelle se trouve la case (pointeur)
 *	\param *adjacentSquare les cases contigues (pointeur)
 *	\return LL_LinkedList
 */
LL_LinkedList AS_getPossibleNeighbours(G_Grid *grid, AS_AdjacentSquares *adjacentSquare);

/**
 *	\fn void AS_addSquare(AS_AdjacentSquares *adjacentSquare, S_SQUARE *square)
 *	\brief ajoute une case en tête de string et met à jour les values de point bonus et du nombre de points
 *	\param *adjacentSquare Les cases contigues auxquelle on veut radd la case (pointeur)
 *	\param *square la case à radd (pointeur)
 *	\return void
 */
void AS_addSquare(AS_AdjacentSquares *adjacentSquare, S_SQUARE *square);

/**
 *	\fn void AS_deleteSquare(AS_AdjacentSquares *adjacentSquare)
 *	\brief Supprime la dernière case d'une suite de cases contigues
 *	\param *adjacentSquare la suite de cases contigues cible
 *	\return void
 */
void AS_deleteSquare(AS_AdjacentSquares *adjacentSquare);

/**
 *	\fn char *AS_readSquares(AS_AdjacentSquares adjacentSquare)
 *	\brief retourne les strings de caractères présentes dans chaque cases sous la forme d'une longue string de caractère 
 *	\param adjacentSquare la suite de cases contigues cible
 *	\return char*
 */
char *AS_readSquares(AS_AdjacentSquares adjacentSquare);

/**
 *	\fn int AS_countPoints(AS_AdjacentSquares adjacentSquare)
 *	\brief retourne la value en point de la suite de cases contigues
 *	\param adjacentSquare la suite de cases contigues cible
 *	\return int
 */
int AS_countPoints(AS_AdjacentSquares adjacentSquare);

/**
 *	\fn int AS_getLength(AS_AdjacentSquares adjacentSquare)
 *	\brief retourne la longeur de la suite de cases contigues 
 *	\param adjacentSquare la suite de cases contigues cible
 *	\return int 
 */
int AS_getLength(AS_AdjacentSquares adjacentSquare);

/**
 *	\fn int AS_getBonus(AS_AdjacentSquares adjacentSquare)
 *	\brief retourne la value du coefficient bonus de la string de cases contigues
 *	\param adjacentSquare la suite de cases contigues cible
 *	\return int
 */
int AS_getBonus(AS_AdjacentSquares adjacentSquare);

/**
 *	\fn int AS_getNumberOfPoints(AS_AdjacentSquares adjacentSquare)
 *	\brief retourne numberOfPoints, value sans les bonus sur le mot
 *	\param adjacentSquare la suite de cases contigues cible
 *	\return int
 */
int AS_getNumberOfPoints(AS_AdjacentSquares adjacentSquare);

/**
 *	\fn LL_LinkedList* AS_getLinkedList(AS_AdjacentSquares *adjacentSquare)
 *	\brief retourne un pointeur sur la liste ordonnée contenue dans la structure caseContigues
 *	\param *adjacentSquare la suite de cases contigues cible (pointeur)
 *	\return LL_LinkedList*
 */
LL_LinkedList *AS_getLinkedList(AS_AdjacentSquares *adjacentSquare);

/**
 *	\fn void AS_setBonus(AS_AdjacentSquares *adjacentSquare, int bonus)
 *	\brief permet d'initialiser le bonus d'une suite de cases contigues
 *	\param *adjacentSquare la suite de cases contigues cible (pointeur)
 *	\param bonus la value du bonus
 *	\return void
 */
void AS_setBonus(AS_AdjacentSquares *adjacentSquare, int bonus);

/**
 *	\fn void AS_setNbPoints(AS_AdjacentSquares *adjacentSquare, int points)
 *	\brief permet d'initialiser la value de numberOfPoints d'une suite de cases contigues
 *	\param *adjacentSquare la suite de cases contigues cible (pointeur)
 *	\param points la value des points
 *	\return void
 */
void AS_setNbPoints(AS_AdjacentSquares *adjacentSquare, int points);

/**
 *	\fn S_SQUARE *AS_getSquare(AS_AdjacentSquares*, int)
 *	\brief Permet d'get la ième cases d'une suite de cases contigues
 *	\param *adjacentSquare la suite de cases contigues cible (pointeur)
 *	\param no le numéro de la case
 *	\return S_SQUARE
 */
S_SQUARE *AS_getSquare(AS_AdjacentSquares *adjacentSquare, int no);

#endif

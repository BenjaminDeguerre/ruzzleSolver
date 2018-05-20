/**
 *	\file Grid.h
 *	\brief Implémentation du TAD Grid
 *	\version 1.0
 *	\date 29/12/2014
 */
#ifndef __GRILLE__
#define __GRILLE__

#include "LinkedList.h"
#include "Square.h"
#include "Square.h"
#include "subString.h"

#define G_COTE 4
#define G_LENGTH (G_COTE * G_COTE)

/**
 *	\typedef G_Grid
 *	\brief Structure d'une grid, tableau de case
 */
typedef struct {
  S_SQUARE arraySquares[G_LENGTH]; /**< Le tableau de Squares */
} G_Grid;

/**
 *	\fn G_Grid G_createGrid(char *string[G_LENGTH])
 *	\brief Permet de créer une grid, prend en entrée la string contenant
 *les suites de caractères contenus dans les cases de la grid
 *
 *	La string en entré est de la forme suivante
 *"LetterValeurBonusLetterValeurBonus..." si aucun bonus mettre "  "
 *	\param string[G_LENGTH] la string de caractère contenant la value des
 *cases
 *	\return G_Grid
 */
G_Grid G_createGrid(char *string[G_LENGTH]);

/**
 *	\fn S_SQUARE* G_getSquare(G_Grid, int squareNumber)
 *	\brief Permet d'get un pointer sur la ieme case d'une grid (0-11,
 *gauche-droite, haut-bas)
 *	\param g la grid target
 *	\param squareNumber le numéro de la case que l'on souhaite get
 *	\return S_SQUARE*
 */
S_SQUARE G_getSquare(G_Grid grid, int squareNumber);

/**
 *	\fn LL_LinkedList G_getNeighbours(G_Grid grid, S_SQUARE square)
 *	\brief Permet d'get les neighbours d'une case donnée dans une grid
 *
 *	retourne une liste ordonnée contenant tous les neighbours possible
 *	\param g La grid target
 *	\param c La case dont on veut les neighbours
 *	\return LL_LinkedList
 */
LL_LinkedList G_getNeighbours(G_Grid grid, S_SQUARE square);

/**
 *	\fn void G_suppirmerGrid(G_Grid grid)
 *	\brief permet de delete les allocation mémoire faite avec la fonction
 *G_creeGrid
 *	\param g la grid à delete
 *	\return void
 */
void G_deleteGrid(G_Grid grid);
#endif

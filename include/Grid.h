#ifndef __GRILLE__
#define __GRILLE__

#include "LinkedList.h"
#include "Square.h"

#define G_COTE 4
#define G_LENGTH (G_COTE * G_COTE)

/**
 *	\typedef G_Grid
 *	\brief Structure of a grid, array of Square.
 */
typedef struct {
  S_Square **arraySquares;
} G_Grid;

/**
 *	\fn G_Grid G_createGrid(char **string)
 *	\brief Create a grid from a string representing a grid. "T1LDR1  A1
 *S1WTE1LTN1  C3LTE1  U1  R1  I1  L2WDS1  O1WDP3  S1  ", for the first letter :
 *T letter, value 1, Letter count Double, for the last letter : S letter, value
 *1, no bonus.
 * \param **string The string representing a grid. Should be of size 16 * 4.
 * \return G_Grid
 */
G_Grid G_createGrid(char **string);

/**
 *	\fn S_Square* G_getSquare(G_Grid grid, int squareNumber)
 *	\brief Return the square in the grid at the required position
 *
 *	\param grid The target grid.
 *	\param squareNumber The number of the square to get.
 *	\return S_Square*
 */
S_Square *G_getSquare(G_Grid grid, int squareNumber);

/**
 *	\fn LL_LinkedList G_getNeighbours(G_Grid grid, S_Square square)
 *	\brief Return the square around a given square.
 *
 *	\param grid The grid target (holding the squares).
 *	\param c The square from which we want the neighbours.
 *	\return LL_LinkedList
 */
LL_LinkedList G_getNeighbours(G_Grid grid, S_Square square);

/**
 *	\fn void G_deleteGrid(G_Grid grid)
 *	\brief Delete a grid.
 *	\param grid The grid to delete.
 *  \param freeElement
 *	\return void
 */
void G_deleteGrid(G_Grid grid);
#endif

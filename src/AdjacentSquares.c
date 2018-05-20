/* Arthur Hamelin - 10/12/2014 */
/* Benjamin Deguerre - 26/12/2014 */

#include <assert.h>
#include <errno.h>
#include <stdlib.h>

#include "AdjacentSquares.h"

/* #define NDEBUG */

/* Private */
int AS_getValueBonusWord(char *bonus) {
  int res;
  if (bonus[0] == 'M') {
    switch (bonus[1]) {
    case 'D':
      res = 2;
      break;
    case 'T':
      res = 3;
      break;
    default:
      res = 0;
      break;
    }
  } else {
    res = 0;
  }
  return res;
}

int AS_getValueBonusLetter(char *bonus) {
  int res;
  if (bonus[0] == 'L') {
    switch (bonus[1]) {
    case 'D':
      res = 2;
      break;
    case 'T':
      res = 3;
      break;
    default:
      res = 0;
      break;
    }
  } else {
    res = 0;
  }
  return res;
}

/* Public */
AS_AdjacentSquares *AS_createAdjacentSquares() {
  errno = 0;
  AS_AdjacentSquares *adjacentSquare =
      (AS_AdjacentSquares *)malloc(sizeof(AS_AdjacentSquares));

  adjacentSquare->linkedList = LL_createLinkedList();
  adjacentSquare->numberOfPoints = 0;
  adjacentSquare->coefficientBonus = 0;

  return adjacentSquare;
}

LL_LinkedList AS_getPossibleNeighbours(G_Grid *grid,
                                       AS_AdjacentSquares *adjacentSquare) {
  errno = 0;
  S_SQUARE *square = LL_getElement(adjacentSquare->linkedList);
  LL_LinkedList listNeighbours = G_getNeighbours(*grid, *square);
  LL_LinkedList listPossibleNeighbours = LL_createLinkedList();

  do {
    S_SQUARE *squareToCheck = LL_getElement(listNeighbours);

    if (squareToCheck != NULL) {
    }

  } while (LL_getNextList(listNeighbours) != NULL);

  return listPossibleNeighbours;
}

void AS_addSquare(AS_AdjacentSquares *adjacentSquare, S_SQUARE *square) {

  char *Bonus = S_getBonus(*square);
  int vBonusWord = AS_getValueBonusWord(Bonus);
  int vBonusLetter = AS_getValueBonusLetter(Bonus);
  LL_add(&(adjacentSquare->linkedList), (void *)square, S_copy);
  AS_setBonus(adjacentSquare, AS_getBonus(*adjacentSquare) + vBonusWord);
  if (vBonusLetter == 0) {
    AS_setNbPoints(adjacentSquare, AS_getNumberOfPoints(*adjacentSquare) +
                                       S_getPointsNumber(*square) - 48);
  } else {
    AS_setNbPoints(adjacentSquare,
                   AS_getNumberOfPoints(*adjacentSquare) +
                       (S_getPointsNumber(*square) - 48) * vBonusLetter);
  }
  free(Bonus);
}

void AS_deleteSquare(AS_AdjacentSquares *adjacentSquare) {

  S_SQUARE *square = AS_getSquare(adjacentSquare, 1);
  int vBonusLetter = AS_getValueBonusLetter(S_getBonus(*square));
  int vBonusWord = AS_getValueBonusWord(S_getBonus(*square));
  AS_setBonus(adjacentSquare, AS_getBonus(*adjacentSquare) - vBonusWord);

  if (vBonusLetter == 0) {
    AS_setNbPoints(adjacentSquare, AS_getNumberOfPoints(*adjacentSquare) -
                                       (S_getPointsNumber(*square) - 48));
  } else {
    AS_setNbPoints(adjacentSquare,
                   AS_getNumberOfPoints(*adjacentSquare) -
                       (S_getPointsNumber(*square) - 48) * vBonusLetter);
  }

  LL_deleteHead(&(adjacentSquare->linkedList), S_delete);
}

char *AS_readSquares(AS_AdjacentSquares adjacentSquare) {
  char *squaresString =
      (char *)malloc(sizeof(char) * AS_getLength(adjacentSquare));

  return squaresString;
}

int AS_countPoints(AS_AdjacentSquares adjacentSquare) {
  int points = AS_getNumberOfPoints(adjacentSquare);
  // printf("%d\n",points);
  int bonus = AS_getBonus(adjacentSquare);
  // printf("%d\n",bonus);
  if (bonus == 0) {
    bonus = 1;
  }
  return points * bonus;
}

int AS_getLength(AS_AdjacentSquares adjacentSquare) {
  return LL_length(adjacentSquare.linkedList);
}

int AS_getBonus(AS_AdjacentSquares adjacentSquare) {
  return adjacentSquare.coefficientBonus;
}

int AS_getNumberOfPoints(AS_AdjacentSquares adjacentSquare) {
  return adjacentSquare.numberOfPoints;
}

LL_LinkedList *AS_getLinkedList(AS_AdjacentSquares *adjacentSquare) {
  return &(adjacentSquare->linkedList);
}

void AS_setBonus(AS_AdjacentSquares *adjacentSquare, int bonus) {
  adjacentSquare->coefficientBonus = bonus;
}

void AS_setNbPoints(AS_AdjacentSquares *adjacentSquare, int points) {
  adjacentSquare->numberOfPoints = points;
}

S_SQUARE *AS_getSquare(AS_AdjacentSquares *adjacentSquare, int number) {
  S_SQUARE *square = NULL;
  int i;

  assert(number > 0);

  LL_LinkedList *maList = AS_getLinkedList(adjacentSquare);
  if (number != 1) {
    for (i = 0; i < number - 1; i++) {
      *maList = LL_getNextList(*maList);
    }
  }
  square = (S_SQUARE *)LL_getElement(*maList);
  return square;
}

#include "Grid.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utils.h"

G_Grid G_createGrid(char **arrayParameters) {
  G_Grid grid;
  S_Square *square;
  int i;
  for (i = 0; i < G_LENGTH; i++) {
    square = S_createSquare();
    S_defineSquare(square, arrayParameters[i], i);
    grid.arraySquares[i] = square;
  }
  return grid;
}

S_Square *G_getSquare(G_Grid grid, int squareNumber) {
  return (S_Square *)S_copy((S_Square *)grid.arraySquares[squareNumber]);
}

LL_LinkedList G_getNeighbours(G_Grid grid, S_Square square) {
  int squareNumber = S_getPosition(square);
  LL_LinkedList linkedList = LL_createLinkedList();
  int neighbours[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
  int i;
  S_Square *neighbour;
  if (squareNumber % 4 == 0) {
    // left column of the grid
    neighbours[1] = squareNumber - G_COTE;
    neighbours[2] = squareNumber - G_COTE + 1;
    neighbours[4] = squareNumber + 1;
    neighbours[6] = squareNumber + G_COTE;
    neighbours[7] = squareNumber + G_COTE + 1;
  } else if (((squareNumber + 1) % 4) == 0) {
    // 0 is excluded thanks to the first
    // if (right column of the grid)
    neighbours[0] = squareNumber - G_COTE - 1;
    neighbours[1] = squareNumber - G_COTE;
    neighbours[3] = squareNumber - 1;
    neighbours[5] = squareNumber + G_COTE - 1;
    neighbours[6] = squareNumber + G_COTE;
  } else {
    neighbours[0] = squareNumber - G_COTE - 1;
    neighbours[1] = squareNumber - G_COTE;
    neighbours[2] = squareNumber - G_COTE + 1;
    neighbours[3] = squareNumber - 1;
    neighbours[4] = squareNumber + 1;
    neighbours[5] = squareNumber + G_COTE - 1;
    neighbours[6] = squareNumber + G_COTE;
    neighbours[7] = squareNumber + G_COTE + 1;
  }
  for (i = 0; i < 8; i++) {
    if ((neighbours[i] >= 0) && (neighbours[i] < G_LENGTH)) {
      neighbour = G_getSquare(grid, neighbours[i]);
      LL_add(&linkedList, neighbour, S_copy, S_compare);
      S_delete(neighbour);
    }
  }
  return linkedList;
}

void G_deleteGrid(G_Grid grid) {
  int i;
  for (i = 0; i < G_LENGTH; i++) {
    S_delete(G_getSquare(grid, i));
  }
}

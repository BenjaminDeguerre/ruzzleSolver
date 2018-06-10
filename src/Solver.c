#include "Solver.h"
#include "Dictionary.h"
#include "Grid.h"
#include "Solution.h"
#include "Utils.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define SQUARE_NUMBER G_LENGTH
/* private*/
char *append(char *s, char c) {
  char *res = malloc(sizeof(char) * strlen(s) + 2);
  res = strcpy(res, s);
  int len = strlen(s);

  res[len] = c;
  res[len + 1] = '\0';
  return res;
}
int AS_getValueBonusWord(char *bonus) {
  int res;
  if (bonus[0] == 'W') {
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
void solveGridRecurrent(D_Dictionary dictionary, G_Grid grid,
                        int usedSquare[G_LENGTH], S_Square square,
                        char *wordToTest, LL_LinkedList *l, int point) {
  int i, position;
  S_Square *newSquare;
  char *newWordToTest = append(wordToTest, S_getLetter(square));

  char *Bonus = S_getBonus(square);
  int vBonusWord = AS_getValueBonusWord(Bonus);
  int vBonusLetter = AS_getValueBonusLetter(Bonus);
  if (vBonusLetter == 0) {
    point = point + S_getPointsNumber(square) - 48;
  } else {
    point = point + (S_getPointsNumber(square) - 48) * vBonusLetter;
  }
  free(Bonus);
  usedSquare[S_getPosition(square)] = 1;

  // If isSolution return >= 0, the word is in the dictionary, but might not be
  // at an end.
  if (1 >= 0) {
    // if (isSolution(&dictionary, newWordToTest) >= 0) {
    // If the word is a complete word
    if (1 == 1) {
      // if (isSolution(&dictionary, newWordToTest) == 1) {
      So_Solution *solution;
      char *newWord = malloc(sizeof(char) * (strlen(newWordToTest)));
      newWord = strcpy(newWord, newWordToTest);
      solution = So_createSolution(newWord, point);
      LL_add(l, (void *)solution, So_copy, So_compare);

      free(newWord);
      So_delete(solution);
    }
    // We keep testing for all the neighbours square in the grid not already
    // used.

    LL_LinkedList neighbours = G_getNeighbours(grid, square);
    LL_LinkedList tmp = neighbours;
    int compteur = LL_length(neighbours);

    for (i = 0; i < compteur; i++) {
      newSquare = (S_Square *)LL_getElement(tmp);
      position = S_getPosition(*newSquare);

      if (usedSquare[position] != 1) {
        int *tmpSquareUsed = malloc(sizeof(int) * G_LENGTH);
        for (int j = 0; j < G_LENGTH; j++) {
          tmpSquareUsed[j] = usedSquare[j];
        }
        solveGridRecurrent(dictionary, grid, tmpSquareUsed, *newSquare,
                           newWordToTest, l, point);
        free(tmpSquareUsed);
      }
      tmp = LL_getNextList(tmp);
    }
    LL_delete(&neighbours, S_delete);
  }
  free(newWordToTest);
}

/* public*/
LL_LinkedList solveGrid(D_Dictionary dictionary, G_Grid gridToSolve) {
  int i;
  LL_LinkedList solution = LL_createLinkedList();
  for (i = 0; i < 16; i++) {
    S_Square *square = G_getSquare(gridToSolve, i);
    int usedSquare[G_LENGTH] = {0};
    char *wordToTest = "";
    solveGridRecurrent(dictionary, gridToSolve, usedSquare, *square, wordToTest,
                       &solution, 0);
  }
  return solution;
}

LL_LinkedList solveRuzzle(char *stringGrid, char *pathToIntelligentFile) {
  G_Grid gridToSolve;
  D_Dictionary dictionary;
  LL_LinkedList listSolutions;

  assert(strlen(pathToIntelligentFile) >= 4); /* .dat */

  /* FILE *inputFile = fopen(pathToIntelligentFile, "r+");*/

  gridToSolve = createGridToSolve(stringGrid);
  dictionary = D_unserialize(pathToIntelligentFile);
  listSolutions = solveGrid(dictionary, gridToSolve);

  return listSolutions;
}

G_Grid createGridToSolve(char *stringParametersGrid) {
  assert(strlen(stringParametersGrid) ==
         (G_LENGTH * 4)); /* 16 fois (CARACTERE + 3*space)*/
  char **arrayParameters = malloc(sizeof(char *) * G_LENGTH);
  int i;
  for (i = 0; i < G_LENGTH; i++) {
    arrayParameters[i] =
        subString(stringParametersGrid, i * G_COTE, i * G_COTE + G_COTE - 1);
  }
  return G_createGrid(arrayParameters);
}

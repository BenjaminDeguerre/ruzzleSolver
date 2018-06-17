#include "Solver.h"
#include "Dictionary.h"
#include "Grid.h"
#include "Solution.h"
#include "Utils.h"

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
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
  char *newStringToTest = append(wordToTest, tolower(S_getLetter(square)));
  char *Bonus = S_getBonus(square);
  char *newWord;
  W_Word *newWordToTest = W_createWord(newStringToTest);
  int vBonusWord = AS_getValueBonusWord(Bonus);
  int vBonusLetter = AS_getValueBonusLetter(Bonus);
  int compteur, wordIn;
  int *tmpSquareUsed;

  So_Solution *solution;
  LL_LinkedList neighbours, tmp;

  if (vBonusLetter == 0) {
    point = point + S_getPointsNumber(square);
  } else {
    point = point + (S_getPointsNumber(square)) * vBonusLetter;
  }

  free(Bonus);
  usedSquare[S_getPosition(square)] = 1;

  // If isSolution return >= 0, the word is in the dictionary.
  wordIn = D_wordIsIn(*newWordToTest, dictionary);

  if (wordIn >= 1) {
    if (wordIn == 2) {
      // printf("%s\n", newStringToTest);
      solution = So_createSolution(newStringToTest, point);
      LL_add(l, solution, So_copy, So_compare);
      So_delete(solution);
    }
    // We keep testing for all the neighbours square in the grid not already
    // used.

    neighbours = G_getNeighbours(grid, square);
    tmp = neighbours;  // To keep the head.
    compteur = LL_length(neighbours);

    for (i = 0; i < compteur; i++) {
      newSquare = (S_Square *)LL_getElement(tmp);
      position = S_getPosition(*newSquare);

      // If not already been to the position.
      if (usedSquare[position] != 1) {
        tmpSquareUsed = malloc(sizeof(int) * G_LENGTH);
        for (int j = 0; j < G_LENGTH; j++) {
          tmpSquareUsed[j] = usedSquare[j];
        }
        solveGridRecurrent(dictionary, grid, tmpSquareUsed, *newSquare,
                           newStringToTest, l, point);
        free(tmpSquareUsed);
      }
      tmp = LL_getNextList(tmp);
    }
    LL_delete(&neighbours, S_delete);
  }
  free(newStringToTest);
}

LL_LinkedList solveRuzzle(char *stringGrid, char *pathToIntelligentFile) {
  assert(strlen(pathToIntelligentFile) >= 4);
  assert(strlen(stringGrid) == (G_LENGTH * 4));

  G_Grid gridToSolve;
  D_Dictionary dictionary;
  char **arrayParameters = malloc(sizeof(char *) * G_LENGTH);
  int i;

  for (i = 0; i < G_LENGTH; i++) {
    arrayParameters[i] =
        subString(stringGrid, i * G_COTE, i * G_COTE + G_COTE - 1);
  }
  gridToSolve = G_createGrid(arrayParameters);

  dictionary = D_unserialize(pathToIntelligentFile);

  LL_LinkedList solution = LL_createLinkedList();

  for (i = 0; i < 16; i++) {
    S_Square *square = G_getSquare(gridToSolve, i);
    int usedSquare[G_LENGTH] = {0};
    char *wordToTest = "";
    solveGridRecurrent(dictionary, gridToSolve, usedSquare, *square, wordToTest,
                       &solution, 0);
    printf("--------------------------%d\n", LL_length(solution));
  }

  return solution;
}

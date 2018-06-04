/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 14/12/2014 */

#include "solveGrid.h"
#include "Solution.h"

/* private*/
char *append(char *s, char c)
{

  char *res = malloc(sizeof(char) * strlen(s) + 2);
  res = strcpy(res, s);
  int len = strlen(s);

  res[len] = c;
  res[len + 1] = '\0';
  return res;
}

void *sG_copyWord(void *wordToCopy)
{
  char *copy = malloc(sizeof(char) * strlen(wordToCopy) + 1);
  copy = strcpy(copy, (char *)wordToCopy);
  return (void *)copy;
}

void solveGridRecurrent(D_Dictionary dictionary, G_Grid grid,
                        int usedSquare[G_LENGTH], S_SQUARE square,
                        char *wordToTest, LL_LinkedList *l,
                        AS_AdjacentSquares *adjacentSquare)
{

  int i, position;
  S_SQUARE *newSquare;

  char *newWordToTest = append(wordToTest, S_getLetter(square));
  AS_addSquare(adjacentSquare, &square);
  usedSquare[S_getPosition(square)] = 1;

  // If isSolution return >= 0, the word is in the dictionary, but might not be
  // at an end.

  if (isSolution(&dictionary, newWordToTest) >= 0)
  {
    // If the word is a complete word
    if (isSolution(&dictionary, newWordToTest) == 1)
    {
      int point;
      So_Solution *solution;
      char *newWord = malloc(sizeof(char) * (strlen(newWordToTest)));

      newWord = strcpy(newWord, newWordToTest);
      point = AS_countPoints(*adjacentSquare);
      solution = So_createSolution(newWord, point);
      LL_add(l, (void *)solution, So_copy, So_compare);

      free(newWord);
    }
    // We keep testing for all the neighbours square in the grid not already
    // used.

    LL_LinkedList neighbours = G_getNeighbours(grid, square);
    LL_LinkedList tmp = neighbours;
    int compteur = LL_length(neighbours);

    for (i = 0; i < compteur; i++)
    {

      newSquare = (S_SQUARE *)LL_getElement(tmp);
      position = S_getPosition(*newSquare);

      if (usedSquare[position] != 1)
      {
        int *tmpSquareUsed = malloc(sizeof(int) * G_LENGTH);
        for (int j = 0; j < G_LENGTH; j++)
        {
          tmpSquareUsed[j] = usedSquare[j];
        }
        solveGridRecurrent(dictionary, grid, tmpSquareUsed, *newSquare,
                           newWordToTest, l, adjacentSquare);
        free(tmpSquareUsed);
      }
      tmp = LL_getNextList(tmp);
    }
    // LL_delete(&neighbours, S_delete);
  }
  free(newWordToTest);
}

/* public*/
LL_LinkedList solveGrid(D_Dictionary dictionary, G_Grid gridToSolve)
{

  int i;
  LL_LinkedList solution = LL_createLinkedList();
  for (i = 0; i < 16; i++)
  {
    AS_AdjacentSquares *adjacentSquare = AS_createAdjacentSquares();
    S_SQUARE square = G_getSquare(gridToSolve, i);
    int usedSquare[G_LENGTH] = {0};
    char *wordToTest = "";
    solveGridRecurrent(dictionary, gridToSolve, usedSquare, square, wordToTest,
                       &solution, adjacentSquare);
    AS_deleteSquare(adjacentSquare);
  }
  return solution;
}

#include "Square.h"
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #define NDEBUG */

/* public */
S_SQUARE *S_createSquare()
{
  S_SQUARE *square = malloc(sizeof(S_SQUARE));
  square->number = 0;
  square->value = NULL;
  return square;
}

int S_isEmpty(S_SQUARE square)
{
  errno = 0;
  return square.value == NULL;
}

char *S_getValue(S_SQUARE square)
{
  return strcpy(malloc(sizeof(char) * strlen(square.value)), square.value);
}

char S_getLetter(S_SQUARE square)
{
  assert(!S_isEmpty(square));
  return square.value[0];
}

int S_getPosition(S_SQUARE square)
{
  assert(!S_isEmpty(square));
  return square.number;
}

int S_getPointsNumber(S_SQUARE square)
{
  assert(!S_isEmpty(square));
  return square.value[1];
}

char *S_getBonus(S_SQUARE square)
{
  assert(!S_isEmpty(square));

  char *bonus = (char *)malloc(sizeof(char) * 3);

  bonus[0] = square.value[2];
  bonus[1] = square.value[3];
  bonus[2] = '\0';

  return bonus;
}

void S_defineSquare(S_SQUARE *square, char *value, int squareNumber)
{
  assert(strlen(value) == 4);
  assert(squareNumber >= 0);

  if (square->value != NULL)
  {

    free(square->value);
  }

  char *valueToSave = malloc(sizeof(char) * strlen(value));
  strcpy(valueToSave, value);
  square->number = squareNumber;
  square->value = valueToSave;
}

void *S_copy(void *square)
{
  S_SQUARE *result = S_createSquare();
  char *valueToSave =
      malloc(sizeof(char) * strlen(((S_SQUARE *)square)->value));

  strcpy(valueToSave, ((S_SQUARE *)square)->value);

  result->number = ((S_SQUARE *)square)->number;
  result->value = valueToSave;

  return (void *)result;
}

void S_delete(void *square)
{
  free(((S_SQUARE *)square)->value);
  free(square);
}

int S_compare(void *square1, void *square2)
{
  if (S_getPosition(*(S_SQUARE *)square1) < S_getPosition(*(S_SQUARE *)square2))
  {
    return -1;
  }
  else if (S_getPosition(*(S_SQUARE *)square1) == S_getPosition(*(S_SQUARE *)square2))
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

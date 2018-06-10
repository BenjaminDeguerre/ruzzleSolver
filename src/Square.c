#include "Square.h"
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

S_Square *S_createSquare() {
  S_Square *square = malloc(sizeof(S_Square));

  if (square != NULL) {
    square->number = 0;
    square->value = NULL;
  } else {
    errno = S_MEMORY_ERROR;
    exit(errno);
  }
  return square;
}

int S_isEmpty(S_Square square) { return square.value == NULL; }

char *S_getValue(S_Square square) {
  assert(!S_isEmpty(square));
  return square.value;
}

char S_getLetter(S_Square square) {
  assert(!S_isEmpty(square));
  return square.value[0];
}

int S_getPosition(S_Square square) {
  assert(!S_isEmpty(square));
  return square.number;
}

int S_getPointsNumber(S_Square square) {
  assert(!S_isEmpty(square));
  return square.value[1] - '0';
}

char *S_getBonus(S_Square square) {
  assert(!S_isEmpty(square));

  char *bonus = (char *)malloc(sizeof(char) * 3);
  if (bonus != NULL) {
    bonus[0] = square.value[2];
    bonus[1] = square.value[3];
    bonus[2] = '\0';
  } else {
    errno = S_MEMORY_ERROR;
    exit(errno);
  }
  return bonus;
}

void S_defineSquare(S_Square *square, char *value, int squareNumber) {
  assert(strlen(value) == 4);
  assert(squareNumber >= 0);

  if (square->value != NULL) {
    free(square->value);
  }

  char *valueToSave = malloc(sizeof(char) * strlen(value) + 1);
  if (valueToSave != NULL) {
    strcpy(valueToSave, value);
    square->number = squareNumber;
    square->value = valueToSave;
  } else {
    errno = S_MEMORY_ERROR;
    exit(errno);
  }
}

void *S_copy(void *square) {
  assert(!S_isEmpty((*((S_Square *)square))));
  S_Square *result = S_createSquare();
  char *valueToSave =
      malloc(sizeof(char) * strlen(((S_Square *)square)->value) + 1);

  if ((square != NULL) && (valueToSave != NULL)) {
    strcpy(valueToSave, ((S_Square *)square)->value);
    result->number = ((S_Square *)square)->number;
    result->value = valueToSave;
  } else {
    errno = S_MEMORY_ERROR;
    exit(errno);
  }

  return (void *)result;
}

void S_delete(void *square) {
  if (((S_Square *)square)->value != NULL) {
    free(((S_Square *)square)->value);
  }
  free(square);
}

int S_compare(void *square1, void *square2) {
  if (S_getPosition(*(S_Square *)square1) <
      S_getPosition(*(S_Square *)square2)) {
    return -1;
  } else if (S_getPosition(*(S_Square *)square1) ==
             S_getPosition(*(S_Square *)square2)) {
    return 0;
  } else {
    return 1;
  }
}

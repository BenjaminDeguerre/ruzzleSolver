#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "Solution.h"

So_Solution *So_createSolution(char *word, int value) {
  So_Solution *solution = (So_Solution *)malloc(sizeof(So_Solution));
  char *newWord;

  if (solution != NULL) {
    newWord = malloc(sizeof(char) * strlen(word));
    strcpy(newWord, word);
    solution->word = newWord;
    solution->value = value;
  } else {
    errno = S_MEMORY_ERROR;
    exit(errno);
  }
  return solution;
}

char *So_getString(So_Solution solution) { return solution.word; }

int So_getValue(So_Solution solution) { return solution.value; }

void *So_copy(void *solution) {
  So_Solution *res = So_createSolution(((So_Solution *)solution)->word,
                                       ((So_Solution *)solution)->value);
  return (void *)res;
}

void So_delete(void *solution) {
  free(((So_Solution *)solution)->word);
  free(solution);
}

int So_compare(void *solution1, void *solution2) {
  if (((So_Solution *)solution1)->value < ((So_Solution *)solution2)->value) {
    return -1;
  } else if (((So_Solution *)solution1)->value ==
             ((So_Solution *)solution2)->value) {
    return 0;
  } else {
    return 1;
  }
}
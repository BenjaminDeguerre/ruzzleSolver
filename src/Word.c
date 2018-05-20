/* Alexandre DUVAL - 07/12/14 */
/* Alexandre DUVAL - 31/12/14 */

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Word.h"

/* #define NDEBUG */

/* private */
char *lower(char *string) {
  char *res = (char *)malloc(sizeof(char) * strlen(string) + 1);
  int i;
  for (i = 0; string[i] != '\0'; i++) {
    if (string[i] < 97) {
      res[i] = tolower(string[i]);
    } else {
      res[i] = string[i];
    }
  }
  res[i] = '\0';
  return res;
}

/* public */
W_Word *W_createWord(char *value) {
  W_Word *word = malloc(sizeof(W_Word));

  errno = 0;

  word->length = strlen(value);
  word->value = lower(value); //(char *)malloc(sizeof(char) * strlen(value)+1);

  if (word->value == NULL) {
    errno = W_MEMORY_ERROR;
    exit(errno);
  }
  return word;
}

char *W_getString(W_Word word) { return word.value; }

char W_getIthCharacter(W_Word word, int position) {
  assert(position >= 0);
  assert(position < W_getLength(word));

  return word.value[position];
}

int W_getLength(W_Word word) { return word.length; }

void *W_copy(void *word) {
  W_Word *result = W_createWord(W_getString(*(W_Word *)word));
  return (void *)result;
}

void W_remove(void *word) {
  free(((W_Word *)word)->value);
  ((W_Word *)word)->value = NULL;
}

void W_delete(void *word) {
  free(((W_Word *)word)->value);
  free(word);
}

int W_compareString(void *word1, void *word2) {
  return strcmp(W_getString(*(W_Word *)word1), W_getString(*(W_Word *)word2));
}

int W_compare(void *word1, void *word2) {
  return (strcmp(W_getString(*(W_Word *)word1),
                 W_getString(*(W_Word *)word2)) == 0);
}

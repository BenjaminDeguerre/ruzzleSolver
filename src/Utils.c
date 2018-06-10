#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "Dictionary.h"
#include "Utils.h"
#include "Word.h"

char* subString(char* string, int begin, int end) {
  assert(end >= begin);
  assert(end <= strlen(string));
  assert(begin >= 0);

  char* res = malloc(sizeof(char) * (end - begin + 2));
  res[end - begin + 1] = '\0';
  int i;

  if (res == NULL) {
    errno = 1;
    exit(errno);
  }

  for (i = begin; i <= end; i++) {
    res[i - begin] = string[i];
  }

  return res;
}

D_Dictionary readFile(FILE* file) {
  D_Dictionary dictionary = D_createDictionary();
  char* string = (char*)malloc(100 * sizeof(char));

  while (fscanf(file, "%s", string) == 1) {
    if (strcmp(string, "Internet") != 0) {
      if (strcmp(string, "Länder") == 0) {
        string = "Lander";
      }

      W_Word* word = W_createWord(string);
      D_add(word, &dictionary);
      W_delete((void*)word);
    }
  }

  free(string);

  return dictionary;
}

FILE* openFile(char* fileName, char* mode) {
  FILE* file;

  file = fopen(fileName, mode);

  if (file == NULL) {
    fprintf(stderr,
            "\tERROR : Unable to open %s, check if file exists and "
            "permissions.\n\t",
            fileName);
    exit(1);
  }

  return file;
}
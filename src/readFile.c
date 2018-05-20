/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

#include <stdlib.h>

#include "readFile.h"

D_Dictionary readFile(FILE *file) {
  D_Dictionary dictionary = D_createDictionary();
  char *string = (char *)malloc(100 * sizeof(char));

  while (fscanf(file, "%s", string) == 1) {
    if (strcmp(string, "Internet") != 0) {
      if (strcmp(string, "Länder") == 0) {
        string = "Lander";
      }

      W_Word *word = W_createWord(string);
      D_add(word, &dictionary);
      W_delete((void *)word);
    }
  }

  free(string);

  return dictionary;
}

/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 17/12/2014 */

#include "openFile.h"

FILE *openFile(char *fileName, char *mode)
{
  FILE *file;

  file = fopen(fileName, mode);

  if (file == NULL)
  {
    fprintf(stderr, "\tERREUR : impossible d'open %s, verifiez l'existence du file et ses droits.\n\t (openFile.c)\n", fileName);
    exit(1);
  }

  return file;
}
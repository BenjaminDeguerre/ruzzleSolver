/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

#include "transcode.h"

int transcode(char *source, char *target) {
  FILE *inputFile, *outputFile;

  inputFile = openFile(source, "r+");
  outputFile = openFile(target, "w");

  return (D_serialize(readFile(inputFile), outputFile) == 0);
}

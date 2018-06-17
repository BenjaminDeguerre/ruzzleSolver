#include "transcode.h"
#include "Utils.h"

int transcode(char *source, char *target) {
  FILE *inputFile, *outputFile;

  inputFile = openFile(source, "r+");
  outputFile = openFile(target, "w");

  return (D_serialize(readFile(inputFile), outputFile) == 0);
}

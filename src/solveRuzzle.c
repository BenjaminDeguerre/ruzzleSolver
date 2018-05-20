/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 17/12/2014 */

#include "solveRuzzle.h"
#include "openFile.h"
#include "readFile.h"

#include <assert.h>
#include <string.h>

#define SQUARE_NUMBER G_LENGTH

LL_LinkedList solveRuzzle(char *stringGrid, char *pathToIntelligentFile) {

  G_Grid gridToSolve;
  D_Dictionary dictionary;
  LL_LinkedList listSolutions;

  assert(strlen(pathToIntelligentFile) >= 4); /* .dat */

  /* FILE *inputFile = fopen(pathToIntelligentFile, "r+");*/

  gridToSolve = createGridToSolve(stringGrid);
  dictionary = D_unserialize(pathToIntelligentFile);
  listSolutions = solveGrid(dictionary, gridToSolve);

  return listSolutions;
}

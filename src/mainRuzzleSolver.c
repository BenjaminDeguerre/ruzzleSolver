/* Alexandre DUVAL - 06/12/14 */
/* Alexandre DUVAL - 13/12/14 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "solveRuzzle.h"

int main(int argc, char **argv)
{

  // Test values, uncomment to avoid re-entering everything each time when testing
  argv[1] = "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
  argv[2] = "dictionary.dat";
  LL_LinkedList listSolutions = solveRuzzle(argv[1], argv[2]);
  char *valueArray[LL_length(listSolutions) + 1];
  int size = LL_length(listSolutions);
  printf("%d solutions\n", size);
  for (int i = 0; i < size; i++)
  {
    valueArray[i] = (char *)LL_getElement(listSolutions);
    printf("%s\n", valueArray[i]);
    listSolutions = LL_getNextList(listSolutions);
  }

  return EXIT_SUCCESS;
}

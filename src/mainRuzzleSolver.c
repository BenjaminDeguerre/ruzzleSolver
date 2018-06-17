#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Solution.h"
#include "Solver.h"

int main(int argc, char **argv) {
  // Test values, uncomment to avoid re-entering everything each time when
  // testing
  argv[1] = "T1LDR1  A1  S1WTE1LTN1  C3LTE1  U1  R1  I1  L2WDS1  O1WDP3  S1  ";
  argv[2] = "dictionary.dat";

  LL_LinkedList listSolutions = solveRuzzle(argv[1], argv[2]);

  So_Solution *solution;
  int size = LL_length(listSolutions);

  printf("%d solutions\n", size);
  int i = 0;
  while (listSolutions != NULL) {
    solution = So_copy((So_Solution *)LL_getElement(listSolutions));
    printf("%s %d\n", So_getString(*solution), So_getValue(*solution));
    LL_removeElements(&listSolutions, (void *)solution, So_compareString,
                      So_delete);
    // listSolutions = LL_getNextList(listSolutions);
    i = i + 1;
    So_delete(solution);
  }
  printf("%d\n", i);
  return EXIT_SUCCESS;
}

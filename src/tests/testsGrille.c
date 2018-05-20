/* Deguerre Benjamin - 23/12/2014 */
/* Deguerre Benjamin - 30/12/2014 */

#include "Grid.h"
#include "LinkedList.h"
#include "Square.h"
#include "createGridToSolve.h"
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_1_Grid(void) {
  char *string =
      "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
  G_Grid grid = createGridToSolve(string);
  S_SQUARE *squareTest = S_createSquare();
  S_SQUARE *squareRef = S_createSquare();
  S_defineSquare(cRef, "T1LD", 0);
  *squareTest = G_getSquare(g, 0);
  char *stringTest = S_getValue(*squareTest);
  printf("%s \n", stringTest);
  char *stringRef = S_getValue(*squareRef);
  printf("%s", stringRef);
  CU_ASSERT_STRING_EQUAL(stringTest, stringRef);
  S_delete((void *)cTest);
  S_delete((void *)cRef);
  G_deleteGrid(g);
}

void test_2_Grid(void) {
  char *string =
      "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
  G_Grid grid = createGridToSolve(string);
  S_SQUARE *squareTest = S_createSquare();
  S_SQUARE *squareRef = S_createSquare();
  S_defineSquare(cRef, "A1  ", 2);
  *squareTest = G_getSquare(g, 2);
  char *stringTest = S_getValue(*squareTest);
  char *stringRef = S_getValue(*squareRef);
  CU_ASSERT_STRING_EQUAL(stringTest, stringRef);
  S_delete((void *)cTest);
  S_delete((void *)cRef);
  G_deleteGrid(g);
}

void test_3_Grid(void) {
  char *string =
      "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
  G_Grid grid = createGridToSolve(string);
  S_SQUARE *squareTest = S_createSquare();
  S_SQUARE *squareRef = S_createSquare();
  S_defineSquare(cRef, "A1  ", 2);
  *squareTest = G_getSquare(g, 2);
  char *stringTest = S_getValue(*squareTest);
  char *stringRef = S_getValue(*squareRef);
  CU_ASSERT_STRING_EQUAL(stringTest, stringRef);
  S_delete((void *)cTest);
  S_delete((void *)cRef);
  G_deleteGrid(g);
}

void test_4_Grid(void) {
  char *string =
      "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
  G_Grid grid = createGridToSolve(string);
  S_SQUARE *squareTest = S_createSquare();
  S_SQUARE *squareRef = S_createSquare();
  S_defineSquare(cRef, "A1  ", 2);
  *squareTest = G_getSquare(g, 2);
  char *stringTest = S_getValue(*squareTest);
  char *stringRef = S_getValue(*squareRef);
  CU_ASSERT_STRING_EQUAL(stringTest, stringRef);
  S_delete((void *)cTest);
  S_delete((void *)cRef);
  G_deleteGrid(g);
}

int test_Grid(CU_pSuite pSuite) {
  return ((NULL == CU_add_test(pSuite, "G_createGrid", test_1_Grid)) ||
          (NULL == CU_add_test(pSuite,
                               "extraction d'une case de la grid (troisième)",
                               test_2_Grid)) ||
          (NULL ==
           CU_add_test(pSuite, "S_defineSquare(c,b2MD) == 2 ", test_3_Grid)) ||
          (NULL ==
           CU_add_test(pSuite, "S_defineSquare(c,b2MD) == MD", test_4_Grid)));
}

int main() {

  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("Tests boite blanche", init_suite_success,
                        clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (test_Grid(pSuite)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRW_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");
}

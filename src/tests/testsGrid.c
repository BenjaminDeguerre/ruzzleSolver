/* Deguerre Benjamin - 23/12/2014 */
/* Deguerre Benjamin - 30/12/2014 */

#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Grid.h"
#include "LinkedList.h"
#include "Square.h"
#include "Utils.h"

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_createGrid(void) {
  char **string = malloc(sizeof(char *) * G_LENGTH);
  char *entry =
      "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
  int i;
  for (i = 0; i < G_LENGTH; i++) {
    string[i] = subString(entry, i * G_COTE, i * G_COTE + G_COTE - 1);
  }

  G_Grid grid = G_createGrid(string);

  S_Square *squareTest, *squareRef = S_createSquare();
  char *stringTest, *stringRef;

  S_defineSquare(squareRef, "T1LD", 0);
  squareTest = G_getSquare(grid, 0);

  stringTest = S_getValue(*squareTest);
  stringRef = S_getValue(*squareRef);

  CU_ASSERT_STRING_EQUAL(stringTest, stringRef);

  S_defineSquare(squareRef, "A1  ", 2);
  squareTest = G_getSquare(grid, 2);

  stringTest = S_getValue(*squareTest);
  stringRef = S_getValue(*squareRef);

  CU_ASSERT_STRING_EQUAL(stringTest, stringRef);

  S_defineSquare(squareRef, "C3LT", 6);
  squareTest = G_getSquare(grid, 6);

  stringTest = S_getValue(*squareTest);
  stringRef = S_getValue(*squareRef);

  CU_ASSERT_STRING_EQUAL(stringTest, stringRef);

  S_defineSquare(squareRef, "S1  ", 15);
  squareTest = G_getSquare(grid, 15);

  stringTest = S_getValue(*squareTest);
  stringRef = S_getValue(*squareRef);

  CU_ASSERT_STRING_EQUAL(stringTest, stringRef);

  S_delete((void *)squareRef);
  G_deleteGrid(grid);
  for (i = 0; i < G_LENGTH; i++) {
    free(string[i]);
  }
  free(string);
}

void test_getNeighbours(void) {
  char **string = malloc(sizeof(char *) * G_LENGTH);
  char *entry =
      "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
  int i;
  for (i = 0; i < G_LENGTH; i++) {
    string[i] = subString(entry, i * G_COTE, i * G_COTE + G_COTE - 1);
  }
  G_Grid grid = G_createGrid(string);
  LL_LinkedList list, head;
  S_Square *squareTest, *squareList;

  // Testing the top left corner
  squareTest = G_getSquare(grid, 0);
  head = G_getNeighbours(grid, *squareTest);
  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "N1  ");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "E1LT");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "R1  ");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);
  LL_delete(&head, S_delete);

  // Testing the bottom left corner
  squareTest = G_getSquare(grid, 12);
  head = G_getNeighbours(grid, *squareTest);

  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "O1MD");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "R1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "U1  ");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);
  LL_delete(&head, S_delete);

  // Testing the top right corner
  squareTest = G_getSquare(grid, 3);
  head = G_getNeighbours(grid, *squareTest);

  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "E1  ");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "C3LT");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "A1  ");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);
  LL_delete(&head, S_delete);

  // Testing the bottom right corner
  squareTest = G_getSquare(grid, 15);
  head = G_getNeighbours(grid, *squareTest);

  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "P3  ");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "L2MD");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "I1  ");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);
  LL_delete(&head, S_delete);

  // Testing the top middle
  squareTest = G_getSquare(grid, 1);
  head = G_getNeighbours(grid, *squareTest);

  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "C3LT");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "N1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "E1LT");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "A1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "T1LD");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);
  LL_delete(&head, S_delete);

  // Testing the bottom middle
  squareTest = G_getSquare(grid, 14);
  head = G_getNeighbours(grid, *squareTest);

  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "S1  ");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "O1MD");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "L2MD");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "I1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "R1  ");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);
  LL_delete(&head, S_delete);

  // Testing the left middle
  squareTest = G_getSquare(grid, 8);
  head = G_getNeighbours(grid, *squareTest);

  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "O1MD");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "S1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "R1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "N1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "E1LT");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);
  LL_delete(&head, S_delete);

  // Testing the right middle
  squareTest = G_getSquare(grid, 7);
  head = G_getNeighbours(grid, *squareTest);

  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "L2MD");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "I1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "C3LT");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "S1MT");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "A1  ");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);
  LL_delete(&head, S_delete);

  // Testing the middle
  squareTest = G_getSquare(grid, 9);
  head = G_getNeighbours(grid, *squareTest);

  squareList = (S_Square *)LL_getElement(head);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "P3  ");

  list = LL_getNextList(head);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "O1MD");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "S1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "I1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "U1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "C3LT");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "N1  ");

  list = LL_getNextList(list);
  squareList = (S_Square *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(S_getValue(*squareList), "E1LT");

  list = LL_getNextList(list);
  CU_ASSERT(list == NULL);

  for (i = 0; i < G_LENGTH; i++) {
    free(string[i]);
  }
  free(string);
  LL_delete(&head, S_delete);
  G_deleteGrid(grid);
}

int test_Grid(CU_pSuite pSuite) {
  return ((NULL ==
           CU_add_test(pSuite, "G_createGrid/G_getSquare", test_createGrid)) ||
          (NULL == CU_add_test(pSuite, "G_getNeighbours", test_getNeighbours)));
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  pSuite = CU_add_suite("Tests grid", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (test_Grid(pSuite)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");
}

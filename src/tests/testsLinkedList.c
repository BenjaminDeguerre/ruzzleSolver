/* Deguerre Benjamin - 04/01/2015 */
/* Deguerre Benjamin - 04/01/2015 */

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Solution.h"

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_createLinkedList(void) {
  LL_LinkedList list = LL_createLinkedList();
  CU_ASSERT(list->element == NULL);
  CU_ASSERT(list->newLinkedList == NULL);
  LL_delete(&list, So_delete);
}

void test_elementIsNull(void) {
  LL_LinkedList list = LL_createLinkedList();
  CU_ASSERT(LL_elementIsNull(list));

  So_Solution *solution = So_createSolution("hello", 35);
  LL_add(&list, solution, So_copy, So_compare);
  CU_ASSERT_FALSE(LL_elementIsNull(list));
  LL_delete(&list, So_delete);
}

void test_newListIsNull(void) {
  LL_LinkedList list = LL_createLinkedList();
  CU_ASSERT(LL_newtListIsNull(list));

  So_Solution *solution = So_createSolution("hello", 35);
  So_Solution *solution2 = So_createSolution("hello", 35);
  LL_add(&list, solution, So_copy, So_compare);
  LL_add(&list, solution2, So_copy, So_compare);
  CU_ASSERT_FALSE(LL_newtListIsNull(list));
  LL_delete(&list, So_delete);
}

void test_isEmpty(void) {
  LL_LinkedList list = LL_createLinkedList();
  CU_ASSERT(LL_isEmpty(list));

  So_Solution *solution = So_createSolution("hello", 35);
  LL_add(&list, solution, So_copy, So_compare);
  CU_ASSERT_FALSE(LL_isEmpty(list));

  LL_delete(&list, So_delete);
}

void test_add(void) {
  LL_LinkedList list = LL_createLinkedList();

  So_Solution *solution = So_createSolution("hello", 35);
  So_Solution *solution2 = So_createSolution("by", 42);
  LL_add(&list, solution, So_copy, So_compare);
  LL_add(&list, solution2, So_copy, So_compare);

  CU_ASSERT(So_compare(LL_getElement(list), solution2) == 0);
  CU_ASSERT(So_compare(LL_getElement(LL_getNextList(list)), solution) == 0);
  LL_delete(&list, So_delete);
}

void test_setElement(void) {
  LL_LinkedList list = LL_createLinkedList();
  So_Solution *solutionToGet;
  So_Solution *solution = So_createSolution("hello", 35);
  So_Solution *solution2 = So_createSolution("by", 42);
  So_Solution *solution3 = So_createSolution("third", 33);

  LL_add(&list, solution, So_copy, So_compare);
  LL_add(&list, solution2, So_copy, So_compare);
  solutionToGet = (So_Solution *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(So_getString(*solutionToGet), "by");
  CU_ASSERT_TRUE(So_getValue(*solutionToGet) == 42);

  LL_setElement(&list, (void *)solution3, So_copy, So_delete);
  solutionToGet = (So_Solution *)LL_getElement(list);
  CU_ASSERT_STRING_EQUAL(So_getString(*solutionToGet), "third");
  CU_ASSERT_TRUE(So_getValue(*solutionToGet) == 33);

  LL_delete(&list, So_delete);
  So_delete(solution);
  So_delete(solution2);
  So_delete(solution3);
}

void test_setNextList(void) {
  LL_LinkedList list = LL_createLinkedList();
  LL_LinkedList list2 = LL_createLinkedList();

  So_Solution *solution = So_createSolution("hello", 35);
  So_Solution *solution2 = So_createSolution("by", 42);
  LL_add(&list, solution, So_copy, So_compare);
  LL_add(&list2, solution2, So_copy, So_compare);

  LL_setNextList(&list, list2);

  CU_ASSERT(LL_equals(LL_getNextList(list), list2, So_compare) == 1);

  LL_delete(&list, So_delete);
}

void test_deleteHead(void) {

  LL_LinkedList list = LL_createLinkedList();
  So_Solution *solutionToGet;
  So_Solution *solution = So_createSolution("hello", 35);
  So_Solution *solution2 = So_createSolution("by", 42);
  LL_add(&list, solution, So_copy, So_compare);
  LL_add(&list, solution2, So_copy, So_compare);
  LL_deleteHead(&list, So_delete);
  solutionToGet = (So_Solution *)LL_getElement(list);

  CU_ASSERT_STRING_EQUAL(So_getString(*solutionToGet), "hello");
  CU_ASSERT_TRUE(So_getValue(*solutionToGet) == 35);
  LL_delete(&list, So_delete);
}

void test_copy_equals(void) {
  LL_LinkedList list = LL_createLinkedList();
  LL_LinkedList list2;

  So_Solution *solution = So_createSolution("hello", 35);
  So_Solution *solution2 = So_createSolution("by", 42);
  LL_add(&list, solution, So_copy, So_compare);
  LL_add(&list, solution2, So_copy, So_compare);
  list2 = LL_copy(list, So_copy, So_compare);
  CU_ASSERT(LL_equals(list, list2, So_compare) == 1);
  LL_delete(&list, So_delete);
  LL_delete(&list2, So_delete);
}

void test_length(void) {
  LL_LinkedList list = LL_createLinkedList();
  So_Solution *solution = So_createSolution("allo", 35);
  So_Solution *solution2 = So_createSolution("allo", 35);
  LL_add(&list, solution, So_copy, So_compare);
  LL_add(&list, solution2, So_copy, So_compare);
  CU_ASSERT(LL_length(list) == 2);

  So_Solution *solution3 = So_createSolution("allo", 35);
  LL_add(&list, solution3, So_copy, So_compare);
  CU_ASSERT(LL_length(list) == 3);

  LL_delete(&list, So_delete);
}

int test_LinkedList(CU_pSuite pSuite) {
  return (
      (NULL == CU_add_test(pSuite, "LL_createList()", test_createLinkedList)) ||
      (NULL == CU_add_test(pSuite, "LL_elementIsNull()", test_elementIsNull)) ||
      (NULL == CU_add_test(pSuite, "LL_newListIsNull()", test_newListIsNull)) ||
      (NULL == CU_add_test(pSuite, "LL_isEmpty", test_isEmpty)) ||
      (NULL == CU_add_test(pSuite, "LL_add", test_add)) ||
      (NULL == CU_add_test(pSuite, "LL_getsetElement", test_setElement)) ||
      (NULL == CU_add_test(pSuite, "LL_getsetNextList", test_setNextList)) ||
      (NULL == CU_add_test(pSuite, "LL_deleteHead", test_deleteHead)) ||
      (NULL == CU_add_test(pSuite, "LL_copy", test_copy_equals)) ||
      (NULL == CU_add_test(pSuite, "LL_length", test_length)));
}

int main() {

  CU_pSuite pSuite = NULL;

  /* initialisation du registre de test */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d’une suite de test */
  pSuite = CU_add_suite("Tests boite noire", init_suite_success,
                        clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* ajout des tests à la suite de tests boite noire */
  if (test_LinkedList(pSuite)) {
    printf("plip\n");
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");
}

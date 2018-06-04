/* Deguerre Benjamin - 04/01/2015 */
/* Deguerre Benjamin - 04/01/2015 */

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Word.h"

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_createLinkedList(void) {
  LL_LinkedList list = LL_createLinkedList();
  CU_ASSERT(list->element == NULL);
  CU_ASSERT(list->newLinkedList == NULL);

  LL_delete(&list, W_delete);
}

void test_elementIsNull(void) {
  LL_LinkedList maList = LL_createLinkedList();
  W_Word *wordTest = W_createWord("plop");
  LL_add(&maList, (void *)wordTest, W_copy, W_compare);
  CU_ASSERT_FALSE(LL_isEmpty(maList));
  LL_delete(&maList, W_delete);
}

void test_newListIsNull(void) {
  LL_LinkedList maList = LL_createLinkedList();
  W_Word *wordTest = W_createWord("plop");
  LL_add(&maList, (void *)wordTest, W_copy, W_compare);
  CU_ASSERT(W_compare(LL_getElement(maList), (void *)wordTest));
  LL_delete(&maList, W_delete);
}

void test_isEmpty(void) {
  LL_LinkedList maList = LL_createLinkedList();
  LL_LinkedList maListTemp = maList;
  W_Word *wordTest = W_createWord("plop");
  LL_add(&maList, (void *)wordTest, W_copy, W_compare);
  CU_ASSERT(LL_getNextList(maList) == maListTemp);
  LL_delete(&maList, W_delete);
}

void test_add(void) {
  LL_LinkedList maList = LL_createLinkedList();
  LL_LinkedList maList1 = LL_createLinkedList();
  W_Word *wordTest = W_createWord("plop");
  LL_add(&maList, (void *)wordTest, W_copy, W_compare);
  LL_add(&maList1, (void *)wordTest, W_copy, W_compare);
  CU_ASSERT(LL_equals(maList, maList1, W_compare));
  LL_delete(&maList, W_delete);
}

void test_getsetElement(void) {
  LL_LinkedList maList = LL_createLinkedList();
  W_Word *wordTest = W_createWord("plop");
  for (int i = 1; i <= 4; i++) {
    LL_add(&maList, (void *)wordTest, W_copy, W_compare);
    CU_ASSERT(LL_length(maList) == i);
  }

  LL_delete(&maList, W_delete);
}
void test_getsetNextList(void) {}

void test_deleteHead(void) {}

void test_copy(void) {}

void test_equals(void) {}
void test_length(void) {}

int test_LinkedList(CU_pSuite pSuite) {
  return (
      (NULL == CU_add_test(pSuite, "LL_createList()", test_createLinkedList)) ||
      (NULL == CU_add_test(pSuite, "LL_elementIsNull()", test_elementIsNull)) ||
      (NULL == CU_add_test(pSuite, "LL_newListIsNull()", test_newListIsNull)) ||
      (NULL == CU_add_test(pSuite, "LL_isEmpty", test_isEmpty)) ||
      (NULL == CU_add_test(pSuite, "LL_add", test_add)) ||
      (NULL == CU_add_test(pSuite, "LL_getsetElement", test_getsetElement)) ||
      (NULL == CU_add_test(pSuite, "LL_getsetNextList", test_getsetNextList)) ||
      (NULL == CU_add_test(pSuite, "LL_deleteHead", test_deleteHead)) ||
      (NULL == CU_add_test(pSuite, "LL_copy", test_copy)) ||
      (NULL == CU_add_test(pSuite, "LL_equals", test_equals)) ||
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

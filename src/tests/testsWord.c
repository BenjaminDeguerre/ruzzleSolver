#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Word.h"

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_createWord(void) {
  W_Word *word1 = W_createWord("avion");
  W_Word *word2 = W_createWord("Avion");

  CU_ASSERT_EQUAL(W_getLength(*word1), 5);
  CU_ASSERT_EQUAL(W_getLength(*word2), 5);

  CU_ASSERT_STRING_EQUAL(W_getString(*word1), "avion");
  CU_ASSERT_STRING_EQUAL(W_getString(*word2), "avion");

  CU_ASSERT(W_compare(word1, word2) == 0);

  W_delete(word1);
  W_delete(word2);
}

void test_copy(void) {
  W_Word *word1 = W_createWord("balloon");
  W_Word *word2 = W_copy(word1);

  CU_ASSERT_STRING_EQUAL(W_getString(*word1), W_getString(*word2));
  CU_ASSERT(W_compare(word1, word2) == 0);
  W_delete(word1);
  W_delete(word2);
}

void test_ithChar(void) {
  W_Word *word1 = W_createWord("avion");

  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 0), 'a');
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 1), 'v');
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 2), 'i');
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 3), 'o');
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 4), 'n');

  W_delete(word1);
}

void test_compare(void) {
  W_Word *word1 = W_createWord("avion");
  W_Word *word2 = W_createWord("avion");
  W_Word *word3 = W_createWord("aa");
  W_Word *word4 = W_createWord("lion");

  CU_ASSERT_EQUAL(W_compare(word1, word2), 0);
  CU_ASSERT_EQUAL(W_compare(word2, word1), 0);
  CU_ASSERT(W_compare(word1, word3) > 0);
  CU_ASSERT(W_compare(word3, word1) < 0);
  CU_ASSERT(W_compare(word1, word4) < 0);
  CU_ASSERT(W_compare(word4, word1) > 0);

  W_delete(word1);
  W_delete(word2);
  W_delete(word3);
  W_delete(word4);
}

int test_Word(CU_pSuite pSuite) {
  return ((NULL == CU_add_test(pSuite, "test_createWord", test_createWord)) ||
          (NULL == CU_add_test(pSuite, "test_copy", test_copy)) ||
          (NULL == CU_add_test(pSuite, "test_ithChar", test_ithChar)) ||
          (NULL == CU_add_test(pSuite, "test_compare", test_compare)));
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  pSuite =
      CU_add_suite("Tests white box", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (test_Word(pSuite)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  CU_cleanup_registry();
  return CU_get_error();
}

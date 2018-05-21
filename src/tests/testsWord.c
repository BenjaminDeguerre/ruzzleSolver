/* Alexandre DUVAL - 03/01/2015 */
/* Alexandre DUVAL - 03/01/2015 */

#include "Word.h"
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_suite_success(void) { return 0; }
int clean_suite_success(void) { return 0; }

void test_W_global(void)
{
  W_Word *word1 = W_createWord("avion");
  W_Word *word2 = W_copy(word1);

  CU_ASSERT_EQUAL(W_getLength(*word1), 5);
  CU_ASSERT_STRING_EQUAL(W_getString(*word1), "avion");
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 0), 'a');
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 1), 'v');
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 2), 'i');
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 3), 'o');
  CU_ASSERT_EQUAL(W_getIthCharacter(*word1, 4), 'n');

  CU_ASSERT_STRING_EQUAL(W_getString(*word1), W_getString(*word2));
  CU_ASSERT(W_compare(word1, word2));
}

int test_Word(CU_pSuite pSuite)
{
  return ((NULL == CU_add_test(pSuite, "W_global", test_W_global)));
}

int main()
{
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  pSuite = CU_add_suite("Tests boite blanche", init_suite_success,
                        clean_suite_success);
  if (NULL == pSuite)
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (test_Word(pSuite))
  {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");
}

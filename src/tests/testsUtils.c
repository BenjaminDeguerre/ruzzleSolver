/* Deguerre Benjamin - 27/12/2014 */
/* Deguerre Benjamin - 30/12/2014 */

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdlib.h>
#include "Utils.h"

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_1_subString(void) {
  char* sub = subString("bonjour", 0, 0);
  CU_ASSERT_STRING_EQUAL(sub, "b");
  free(sub);
}

void test_2_subString(void) {
  char* sub = subString("bonjour", 0, 2);
  CU_ASSERT_STRING_EQUAL(sub, "bon");
  free(sub);
}

void test_3_subString(void) {
  char* sub = subString("bonjour", 3, 6);
  CU_ASSERT_STRING_EQUAL(sub, "jour");
  free(sub);
}

int test_subString(CU_pSuite pSuite) {
  return ((NULL == CU_add_test(pSuite, "subString(bonjour,0,0) == b",
                               test_1_subString)) ||
          (NULL == CU_add_test(pSuite, "subString(bonjour,0,2) == bon",
                               test_2_subString)) ||
          (NULL == CU_add_test(pSuite, "subString(bonjour,3,6) == jour",
                               test_3_subString)));
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

  if (test_subString(pSuite)) {
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

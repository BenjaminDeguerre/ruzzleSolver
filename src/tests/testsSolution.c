/* Deguerre Benjamin - 23/12/2014 */
/* Deguerre Benjamin - 30/12/2014 */

#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Solution.h"

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_createSolution(void) {
  So_Solution *solution = So_createSolution("winner", 42);
  So_Solution *solution2 = So_createSolution("loser", 24);
  CU_ASSERT_STRING_EQUAL(So_getString(*solution), "winner");
  CU_ASSERT_TRUE(So_getValue(*solution) == 42);

  CU_ASSERT_STRING_EQUAL(So_getString(*solution2), "loser");
  CU_ASSERT_TRUE(So_getValue(*solution2) == 24);

  So_delete((void *)solution);
  So_delete((void *)solution2);
}

void test_copySolution(void) {
  So_Solution *solution = So_createSolution("winner", 42);
  So_Solution *solution2;

  solution2 = So_copy(solution);
  CU_ASSERT_TRUE(So_compare((void *)solution, (void *)solution2) == 0);
  CU_ASSERT_STRING_EQUAL(So_getString(*solution), So_getString(*solution2));
  So_delete((void *)solution);
  So_delete((void *)solution2);
}

void test_compareSolution(void) {
  So_Solution *solution1 = So_createSolution("winner", 42);
  So_Solution *solution2 = So_createSolution("winner", 35);
  So_Solution *solution3 = So_createSolution("first", 72);
  So_Solution *solution4 = So_createSolution("second", 42);

  CU_ASSERT_TRUE(So_compare((void *)solution1, (void *)solution2) == 1);
  CU_ASSERT_TRUE(So_compare((void *)solution2, (void *)solution1) == -1);
  CU_ASSERT_TRUE(So_compare((void *)solution3, (void *)solution1) == 1);
  CU_ASSERT_TRUE(So_compare((void *)solution1, (void *)solution4) == 0);

  So_delete((void *)solution1);
  So_delete((void *)solution2);
  So_delete((void *)solution3);
  So_delete((void *)solution4);
}

int test_Solution(CU_pSuite pSuite) {
  return ((NULL ==
           CU_add_test(pSuite, "So_createSolution()", test_createSolution)) ||
          (NULL == CU_add_test(pSuite, "So_copy()", test_copySolution)) ||
          (NULL == CU_add_test(pSuite, "S_compare()", test_compareSolution)));
}

int main() {
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de test */
  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  /* ajout d’une suite de test */
  pSuite = CU_add_suite("Tests boite noire", init_suite_success,
                        clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* ajout des tests à la suite de tests boite noire */
  if (test_Solution(pSuite)) {
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

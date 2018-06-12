/* Deguerre Benjamin - 28/12/2014 */
/* Deguerre Benjamin - 28/12/2014 */

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <string.h>
#include "Node.h"

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_createNode(void) {
  N_Node *node = N_createNode(1, 'p');
  CU_ASSERT(node->value == 'p');
  CU_ASSERT(node->isLast);
  N_delete(node);
}

void test_isLast(void) {
  N_Node *node = N_createNode(1, 'a');
  CU_ASSERT(N_isLast(*node));
  N_delete(node);
}

void test_defineValue(void) {
  N_Node *node = N_createNode(1, 'p');
  N_defineValue(node, 'u');

  CU_ASSERT_EQUAL(N_getValue(*node), 'u');
  N_delete(node);
}

void test_defineEnd(void) {
  N_Node *node = N_createNode(1, 'p');
  N_defineEnd(node, 0);

  CU_ASSERT_FALSE(N_isLast(*node));
  N_delete(node);
}

void test_copy(void) {
  N_Node *node1 = N_createNode(1, 'p');
  N_Node *node2;

  node2 = N_copy(node1);

  CU_ASSERT(N_compare(node1, node2) == 0);

  N_delete(node1);
  N_delete(node2);
}

void test_compare(void) {
  N_Node *node1 = N_createNode(1, 'p');
  N_Node *node2 = N_createNode(1, 'p');
  CU_ASSERT(N_compare(node1, node2) == 0);

  N_defineValue(node1, 'a');
  CU_ASSERT(N_compare(node1, node2) < 0);
  CU_ASSERT(N_compare(node2, node1) > 0);

  N_defineValue(node1, 'z');
  CU_ASSERT(N_compare(node1, node2) > 0);
  CU_ASSERT(N_compare(node2, node1) < 0);

  N_delete(node1);
  N_delete(node2);
}

int test_Node(CU_pSuite pSuite) {
  return ((NULL == CU_add_test(pSuite, "test_createNode", test_createNode)) ||
          (NULL == CU_add_test(pSuite, "test_isLast", test_isLast)) ||
          (NULL == CU_add_test(pSuite, "test_defineValue", test_defineValue)) ||
          (NULL == CU_add_test(pSuite, "test_defineEnd", test_defineEnd)) ||
          (NULL == CU_add_test(pSuite, "test_copy", test_copy)) ||
          (NULL == CU_add_test(pSuite, "test_compare", test_compare)));
}

int main() {
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de test */
  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  /* ajout d’une suite de test */
  pSuite = CU_add_suite("Tests boite blanche", init_suite_success,
                        clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* ajout des tests à la suite de tests*/
  if (test_Node(pSuite)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /*Netoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}

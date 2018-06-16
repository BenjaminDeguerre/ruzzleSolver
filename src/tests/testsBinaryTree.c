#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"
#include "Node.h"

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_createBT(void) {
  BT_BinaryTree tree = BT_createBT();
  CU_ASSERT(BT_isEmpty(tree));
  CU_ASSERT(tree->leftChild == NULL);
  CU_ASSERT(tree->rightChild == NULL);
  CU_ASSERT(tree->isProcessed == 0);

  BT_delete(tree, N_delete);
}

void test_getsetLeftChild(void) {
  BT_BinaryTree tree = BT_createBT();
  BT_BinaryTree leftChild = BT_createBT();
  N_Node *node = N_createNode(0, 'a');

  BT_setNode(tree, node);
  BT_setLeftChild(tree, leftChild);

  CU_ASSERT(leftChild == BT_getLeftChild(tree));

  BT_delete(tree, N_delete);
  N_delete(node);
}

void test_getsetRightChild(void) {
  BT_BinaryTree tree = BT_createBT();
  BT_BinaryTree rightChild = BT_createBT();
  N_Node *node = N_createNode(0, 'a');

  BT_setNode(tree, node);
  BT_setLeftChild(tree, rightChild);

  CU_ASSERT(rightChild == BT_getLeftChild(tree));

  BT_delete(tree, N_delete);
  N_delete(node);
}

void test_getsetIsProcessed(void) {
  BT_BinaryTree tree = BT_createBT();
  N_Node *node = N_createNode(0, 'a');

  CU_ASSERT(BT_isProcessed(tree) == 0);
  BT_setNode(tree, node);
  BT_setIsProcessed(tree, 1);
  CU_ASSERT(BT_isProcessed(tree) == 1);
  BT_delete(tree, N_delete);
  N_delete(node);
}

void test_getaddRoot(void) {
  BT_BinaryTree leftChild = BT_createBT();
  N_Node *nodeLeft = N_createNode(0, 'a');
  BT_BinaryTree rightChild = BT_createBT();
  N_Node *nodeRight = N_createNode(0, 'b');
  N_Node *nodeRoot = N_createNode(0, 'c');
  BT_BinaryTree root;

  BT_setNode(leftChild, nodeLeft);
  BT_setNode(rightChild, nodeRight);

  root = BT_addRoot(leftChild, rightChild, nodeRoot, N_copy);

  CU_ASSERT(BT_getLeftChild(root) == leftChild);
  CU_ASSERT(BT_getRightChild(root) == rightChild);
  CU_ASSERT(N_getValue(*BT_getRoot(root)) == N_getValue(*nodeRoot));

  BT_delete(root, N_delete);
  N_delete(nodeLeft);
  N_delete(nodeRight);
  N_delete(nodeRoot);
}

int test_BinaryTree(CU_pSuite pSuite) {
  return ((NULL == CU_add_test(pSuite, "test_createBT", test_createBT)) ||
          (NULL ==
           CU_add_test(pSuite, "test_getsetLeftChild", test_getsetLeftChild)) ||
          (NULL == CU_add_test(pSuite, "test_getsetRightChild",
                               test_getsetRightChild)) ||
          (NULL == CU_add_test(pSuite, "test_getsetIsProcessed",
                               test_getsetIsProcessed)) ||
          (NULL == CU_add_test(pSuite, "test_getaddRoot", test_getaddRoot)));
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  pSuite =
      CU_add_suite("Tests black box", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (test_BinaryTree(pSuite)) {
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

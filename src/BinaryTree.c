/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 02/01/2015 */

#include <assert.h>
#include <errno.h>
#include <stdlib.h>

#include "BinaryTree.h"

BT_BinaryTree BT_createBT() {
  BT_BinaryTree tree = (BT_BinaryTree)malloc(sizeof(BT_Node));

  if (tree != NULL) {
    tree->root = NULL;
    tree->leftChild = NULL;
    tree->rightChild = NULL;
    tree->isProcessed = 0;
  } else {
    errno = BT_MEMORY_ERROR;
    exit(errno);
  }
  return tree;
}

int BT_isEmpty(BT_BinaryTree tree) { return tree->root == NULL; }

void BT_setLeftChild(BT_BinaryTree tree, BT_BinaryTree leftChild) {
  assert(!BT_isEmpty(tree));
  tree->leftChild = leftChild;
}

void BT_setRightChild(BT_BinaryTree tree, BT_BinaryTree rightChild) {
  assert(!BT_isEmpty(tree));
  tree->rightChild = rightChild;
}

BT_BinaryTree BT_addRoot(BT_BinaryTree leftChild, BT_BinaryTree rightChild,
                         N_Node *node, EC_copy copy) {
  BT_BinaryTree tree = BT_createBT();
  N_Node *root = (N_Node *)copy(node);
  if ((node != NULL) || (tree != NULL)) {
    errno = 0;
    tree->root = root;
    tree->leftChild = leftChild;
    tree->rightChild = rightChild;
    tree->isProcessed = 0;

    return tree;
  } else {
    errno = BT_MEMORY_ERROR;
    exit(errno);
  }
}

N_Node *BT_getRoot(BT_BinaryTree tree) {
  assert(!BT_isEmpty(tree));
  return tree->root;
}

void BT_deleteRoot(BT_BinaryTree tree, BT_BinaryTree *leftChild,
                   BT_BinaryTree *rightChild, EC_delete freeNode) {
  *leftChild = BT_getLeftChild(tree);
  *rightChild = BT_getRightChild(tree);

  freeNode(BT_getRoot(tree));
  free(tree);
}

void BT_delete(BT_BinaryTree tree, EC_delete freeNode) {
  BT_BinaryTree *leftChild = (BT_BinaryTree *)malloc(sizeof(BT_BinaryTree));
  BT_BinaryTree *rightChild = (BT_BinaryTree *)malloc(sizeof(BT_BinaryTree));

  if (!(BT_isEmpty(tree))) {
    BT_deleteRoot(tree, leftChild, rightChild, freeNode);
    if (*leftChild != NULL) {
      BT_delete(*leftChild, freeNode);
    }
    if (*rightChild != NULL) {
      BT_delete(*rightChild, freeNode);
    }

  } else {
    free(tree);
  }
  free(leftChild);
  free(rightChild);
}

BT_BinaryTree BT_getRightChild(BT_BinaryTree tree) {
  assert(!BT_isEmpty(tree));
  return tree->rightChild;
}

BT_BinaryTree BT_getLeftChild(BT_BinaryTree tree) {
  assert(!BT_isEmpty(tree));
  return tree->leftChild;
}

void BT_setIsProcessed(BT_BinaryTree tree, int processed) {
  assert(!BT_isEmpty(tree));
  tree->isProcessed = processed;
}

int BT_isProcessed(BT_BinaryTree tree) { return tree->isProcessed; }

void BT_setNode(BT_BinaryTree tree, N_Node *node) {
  if (!BT_isEmpty(tree)) {
    N_delete(tree->root);
  }
  tree->root = N_copy((void *)node);
}

N_Node *BT_getNode(BT_BinaryTree tree) {
  assert(!BT_isEmpty(tree));
  return tree->root;
}
/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 02/01/2015 */

#include <assert.h>
#include <errno.h>
#include <stdlib.h>

#include "BinaryTree.h"

BT_BinaryTree BT_createSBT() {
  BT_BinaryTree tree = NULL;
  return tree;
}

int BT_isEmpty(BT_BinaryTree myBT) { return myBT == NULL; }

void BT_setLeftChild(BT_BinaryTree *myBT, BT_BinaryTree leftChild) {
  assert(!BT_isEmpty(*myBT));
  (*myBT)->leftChild = leftChild;
}

void BT_setRightChild(BT_BinaryTree *myBT, BT_BinaryTree rightChild) {
  assert(!BT_isEmpty(*myBT));
  (*myBT)->rightChild = rightChild;
}

void BT_setIsProcessed(BT_BinaryTree *myBT, int processed) {
  assert(!BT_isEmpty(*myBT));
  (*myBT)->isProcessed = processed;
}

int BT_isProcessed(BT_BinaryTree *myBT) {
  assert(!BT_isEmpty(*myBT));
  return (*myBT)->isProcessed;
}

BT_BinaryTree BT_addRoot(BT_BinaryTree leftChild, BT_BinaryTree rightChild,
                         N_Node *node, EC_copy copy) {
  BT_BinaryTree tree = (BT_BinaryTree)malloc(sizeof(BT_Node));
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
    return BT_createSBT();
  }
}

N_Node *BT_getRoot(BT_BinaryTree myBT) {
  assert(!BT_isEmpty(myBT));
  return myBT->root;
}

void BT_deleteRoot(BT_BinaryTree *myBT, BT_BinaryTree *leftChild,
                   BT_BinaryTree *rightChild, EC_delete freeNode) {
  *leftChild = BT_getLeftChild(*myBT);
  *rightChild = BT_getRightChild(*myBT);

  freeNode(BT_getRoot(*myBT));
  *myBT = NULL;
  free(*myBT);
}

void BT_delete(BT_BinaryTree *myBT, EC_delete freeNode) {
  BT_BinaryTree leftChild = BT_createSBT();
  BT_BinaryTree rightChild = BT_createSBT();

  if (!(BT_isEmpty(*myBT))) {
    BT_deleteRoot(myBT, &leftChild, &rightChild, freeNode);
    BT_delete(&leftChild, freeNode);
    BT_delete(&rightChild, freeNode);
  }
}

BT_BinaryTree BT_getRightChild(BT_BinaryTree myBT) {
  assert(!BT_isEmpty(myBT));
  return myBT->rightChild;
}

BT_BinaryTree BT_getLeftChild(BT_BinaryTree myBT) {
  assert(!BT_isEmpty(myBT));
  return myBT->leftChild;
}

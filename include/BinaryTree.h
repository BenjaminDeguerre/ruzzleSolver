#ifndef __SEARCH_BINARY_TREE__
#define __SEARCH_BINARY_TREE__

#include "Node.h"
#include "elementCollection.h"

/**
 *	\typedef BT_BinaryTree
 */
typedef struct BT_Node *BT_BinaryTree;

/**
 *	\typedef BT_Node
 *	\struct BT_Node
 *	\brief Structure of a search binary tree.
 */
typedef struct BT_Node {
  N_Node *root;
  BT_BinaryTree leftChild;
  BT_BinaryTree rightChild;
  int isProcessed;
} BT_Node;

#define BT_MEMORY_ERROR 1

/**
 *	\fn BT_BinaryTree BT_createBT()
 *	\brief Create an empty search binary tree.
 *
 *	The tree is initialized to NULL.
 *	\return BT_BinaryTree
 */
BT_BinaryTree BT_createBT();

/**
 *	\fn int BT_isEmpty(BT_BinaryTree tree)
 *	\brief To know if the tree is empty or not.
 *
 *	Return 0 is false, 1 else.
 *	\param tree pointer to a tree.
 *	\return int
 */
int BT_isEmpty(BT_BinaryTree tree);

/**
 *	\fn void BT_setLeftChild(BT_BinaryTree tree, BT_BinaryTree leftChild)
 *	\brief Set the left child of the tree. It is the responsability of the coder to handle the non empty case.
 *
 *  \param tree The tree to have its child set.
 *  \param leftChild The child to set \return void
 */
void BT_setLeftChild(BT_BinaryTree tree, BT_BinaryTree leftChild);

/**
 *	\fn void BT_setRightChild(BT_BinaryTree tree, BT_BinaryTree rightChild)
 *	\brief Set the right child of a tree. It is the responsability of the
 *coder to handle the non empty case.
 *  \param tree The tree to have its child
 *set.
 *  \param rightChild The child to set \return void
 */
void BT_setRightChild(BT_BinaryTree tree, BT_BinaryTree rightChild);

/**
 *	\fn BT_BinaryTree BT_addRoot(BT_BinaryTree leftChild, BT_BinaryTree rightChild, N_Node *node, EC_copy copy)
 *	\brief Create a new tree and set the right and left child.
 *	\param leftChild The left child.
 *	\param rightChild The right child
 *	\param *node The node to use as root.
 *	\param copy Function to copy the node.
 *	\return BT_BinaryTree
 */
BT_BinaryTree BT_addRoot(BT_BinaryTree leftChild, BT_BinaryTree rightChild,
                         N_Node *node, EC_copy copy);

/**
 *	\fn N_Node* BT_getRoot(BT_BinaryTree tree)
 *	\brief Return the root of the given tree
 *	\param tree Tree from which to get the root.
 *	\return N_Node*
 */
N_Node *BT_getRoot(BT_BinaryTree tree);

/**
 *	\fn void BT_deleteRoot(BT_BinaryTree tree, BT_BinaryTree *leftChild, BT_BinaryTree *rightChild, EC_delete freeNode)
 *	\brief Delete the root of a tree and create two sub-trees.
 *	\param tree The tree to have the root deleted.
 *	\param leftChild Output, the new tree obtained from the left child of
 *the current tree. \param rightChild Output, the new tree obtained from the
 *right child of the current tree. \param freeNode Function to delete a node.
 *	\return void
 */
void BT_deleteRoot(BT_BinaryTree tree, BT_BinaryTree *leftChild,
                   BT_BinaryTree *rightChild, EC_delete freeNode);

/**
 *	\fn void BT_delete(BT_BinaryTree tree, EC_delete freeNode)
 *	\brief Delete the whole tree.
 *	\param tree The tree to delete.
 *	\param freeNode Function to delete the nodes.
 *	\return void
 */
void BT_delete(BT_BinaryTree tree, EC_delete freeNode);

/**
 *	\fn BT_BinaryTree BT_getRightChild(BT_BinaryTree tree)
 *	\brief Get the right child of a tree.
 *	\param tree The tree to get the right child from.
 *	\return BT_BinaryTree
 */
BT_BinaryTree BT_getRightChild(BT_BinaryTree tree);

/**
 *	\fn BT_BinaryTree BT_getLeftChild(BT_BinaryTree tree)
 *	\brief Get the left child of a tree.
 *	\param tree The tree to get the left child from.
 *	\return BT_BinaryTree
 */
BT_BinaryTree BT_getLeftChild(BT_BinaryTree tree);

/**
 *	\fn void BT_setIsProcessed(BT_BinaryTree tree, int processed)
 *	\brief
 *	\param tree
 *	\return BT_BinaryTree
 */
void BT_setIsProcessed(BT_BinaryTree tree, int processed);

/**
 *	\fn int BT_isProcessed(BT_BinaryTree tree)
 *	\brief
 *	\param tree
 *	\return BT_BinaryTree
 */
int BT_isProcessed(BT_BinaryTree tree);

/**
 *	\fn void BT_setNode(BT_BinaryTree tree, N_Node *node)
 *	\brief Setter for the node.
 *	\param tree The tree to have its node set.
 *	\return BT_BinaryTree
 */
void BT_setNode(BT_BinaryTree tree, N_Node *node);

/**
 *	\fn N_Node *BT_getNode(BT_BinaryTree tree)
 *	\brief Return the node of the tree.
 *	\param tree The tree to get the node from.
 *	\return BT_BinaryTree
 */
N_Node *BT_getNode(BT_BinaryTree tree);

#endif

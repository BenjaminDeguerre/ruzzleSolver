/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 02/01/2015 */
 
/** \file BinaryTree.h
 *	\brief Implementation of abstract data type BinaryTree
 *	\version 1.0
 *	\date 26/12/2014
 */
#ifndef __SEARCH_BINARY_TREE__
#define __SEARCH_BINARY_TREE__

#include "Node.h"
#include "elementCollection.h"

/** 
 *	\typedef BT_BinaryTree
 */
typedef struct BT_Node* BT_BinaryTree;

/**
 *	\typedef BT_Node
 *	\struct BT_Node
 *	\brief Structure of a search binary tree.
 */
typedef struct BT_Node {	
	N_Node *root; /**< tree's root */
	BT_BinaryTree leftChild; /**< left child, tree too */
	BT_BinaryTree rightChild; /**< right child, tree too */
	int isProcessed;
} BT_Node;

#define BT_MEMORY_ERROR 1

/** 
 *	\fn BT_BinaryTree BT_createSBT()
 *	\brief Create an empty search binary tree.
 *	
 *	The tree is initialized to NULL.
 *	\return BT_BinaryTree
 */
BT_BinaryTree BT_createSBT();

/** 
 *	\fn int BT_isEmpty(BT_BinaryTree *mySBR)
 *	\brief To know if the tree is empty or not.
 *
 *	Return 0 is false, 1 else.
 *	\param *myBT pointer to a tree.
 *	\return int
 */ 
int BT_isEmpty(BT_BinaryTree myBT);

/** 
 *	\fn void BT_setLeftChild(BT_BinaryTree *myBT, BT_BinaryTree *leftChild)
 *	\brief Set the left child of the tree.
 *	\param *mySBR pointeur sur un arbre
 *	\param *leftChild pointeur sur un arbre, fils à fixer
 *	\return void
 */ 
void BT_setLeftChild(BT_BinaryTree *myBT, BT_BinaryTree leftChild);

/** 
 *	\fn void BT_setRightChild(BT_BinaryTree *myBT, BT_BinaryTree *rightChild)
 *	\brief Permet de fixer le fils droit de l'arbre
 *	\param *mySBR pointeur sur un arbre
 *	\param *rightChild pointeur sur un arbre, fils à fixer
 *	\return void
 */ 
void BT_setRightChild(BT_BinaryTree *myBT, BT_BinaryTree rightChild);

/** 
 *	\fn BT_BinaryTree BT_addRoot(BT_BinaryTree *leftChild, BT_BinaryTree *rightChild, N_Node *node, EC_copy copy)
 *	\brief Permet de racroccher deux arbres à une même root (node)
 *	\param *leftChild pointeur sur un arbre, nouveau fils gauche du node
 *	\param *rightChild pointeur sur un arbre, nouveau fils droit du node
 *	\param *node pointeur sur un node, nouvelle root
 *	\param copy fonction permettant la copie d'un node
 *	\return BT_BinaryTree
 */ 
BT_BinaryTree BT_addRoot(BT_BinaryTree leftChild, BT_BinaryTree rightChild, N_Node *node, EC_copy copy);

/** 
 *	\fn N_Node* BT_getRoot(BT_BinaryTree *abr)
 *	\brief Permet d'obtenir la root d'un arbre binaire de recherche
 *	\param *abr pointeur sur un arbre, arbre dont on veut la root
 *	\return N_Node*
 */ 
N_Node* BT_getRoot(BT_BinaryTree myBT);

/** 
 *	\fn void BT_deleteRoot(BT_BinaryTree* a, BT_BinaryTree* leftChild, BT_BinaryTree* rightChild, EC_delete freeNode)
 *	\brief Permet de delete la root d'un arbre binaire de recherche (deux sous arbre sont "créés")
 *	\param *a pointeur sur un arbre, celui dont on veut delete la root
 *	\param *leftChild pointeur sur un arbre, (sortie) sous arbre gauche résultant de la suppression de la root
 *	\param *rightChild pointeur sur un arbre, (sortie) sous arbre droit résultant de la suppression de la root
 *	\param freeNode fonction permettant de libérer l'espace mémoire occupé par le node
 *	\return void
 */ 
void BT_deleteRoot(BT_BinaryTree *myBT BT_BinaryTree* leftChild, BT_BinaryTree* rightChild, EC_delete freeNode);

/** 
 *	\fn void BT_delete(BT_BinaryTree* a, EC_delete freeNode)
 *	\brief Supprime un arbre binaire de recherche en entier
 *	\param *a pointeur sur l'arbre à delete
 *	\param freeNode fonction permettant de libérer l'espace mémoire occupé par le node
 *	\return void
 */
void BT_delete(BT_BinaryTree* a, EC_delete freeNode);

/** 
 *	\fn BT_BinaryTree* BT_getRightChild(BT_BinaryTree *mySBR)
 *	\brief Getter, permet d'obtenir le fils droit de la root d'un arbre
 *	\param *mySBR pointeur sur l'abre dont on veut le fils droitx	
 *	\return BT_BinaryTree*
 */
BT_BinaryTree BT_getRightChild(BT_BinaryTree mySBR);

/** 
 *	\fn BT_BinaryTree* BT_getLeftChild(BT_BinaryTree *mySBR)
 *	\brief Getter, permet d'obtenir le fils gauche de la root d'un arbre
 *	\param *mySBR pointeur sur l'abre dont on veut le fils gauche
 *	\return BT_BinaryTree*
 */ 
BT_BinaryTree BT_getLeftChild(BT_BinaryTree mySBR);


void BT_setIsProcessed(BT_BinaryTree *myBT int processed);

int BT_isProcessed(BT_BinaryTree *myBT);

#endif

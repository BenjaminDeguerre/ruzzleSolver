/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

/** \file Node.h
 *	\brief Implémentation du TAD Node
 *	\version 1.0
 *	\date 28/12/2014
 */

#ifndef __NODE__
#define __NODE__

/**
 *	\typedef N_Node
 *	\brief contient une value char et un booleen pour indique si il est le dernier node  d'une suite de node
 */
typedef struct
{
	char value; /**< value du node, une string de caractères*/
	int isLast; /**< booleen indiquant si le node est fin ou non d'une suite de nodes*/
} N_Node;

#define N_MEMORY_ERROR 1
/**
 *	\fn N_Node N_createNode(int, char)
 *	\brief Créer un node et l'initialise sur les values isLast et value
 *	\param isLast int donnant la value de finalité du node
 *	\param value char, value du node 
 *	\return N_Node*
 */
N_Node *N_createNode(int isLast, char value);

/**
 *	\fn int N_isLast(N_Node n)
 *	\brief Renvoit un int définissant la finalité d'un noeus=d
 *	\param n le node cible
 *	\return int
 */
int N_isLast(N_Node node);

/**
 *	\fn void N_defineValue(N_Node *n, char *value)
 *	\brief Permet de définir la value d'un node
 *	\param *n le node dont on veut changer la value (pointeur)
 *	\param value la nouvelle value du node
 *	\return void
 */
void N_defineValue(N_Node *node, char value);

/**
 *	\fn void N_defineEnd(N_Node *n, int isLast)
 *	\brief Permet de défnir la value de isLast
 *	\param *n le node dont on veut changer la value de isLast (pointeur)
 *	\param isLast la nouvelle value de isLast du node
 *	\return void
 */
void N_defineEnd(N_Node *node, int isLast);

/**
 *	\fn N_getValue(N_Node n)
 *	\brief	Permet d'get la value d'un node 
 *	\param	n le node cible
 *	\return char
 */
char N_getValue(N_Node node);

/**
 *	\fn void freeNode(N_Node *n)
 *	\brief Permet de libérer l'espace mémoire occupé par un node
 *	\param *n le node à libérer
 *	\return void
 */
void N_free(void *node);

/**
 *	\fn N_copy(N_Node*)
 *	\brief Permet de faire la copie d'un node (retourne le node sous le type void*, à transtyper)
 *
 *	match avec les typedef de élements collection
 *	\param *n le node à copy
 *	\return void*
 */
void *N_copy(void *node);

/**
 *	\fn N_compare(N_Node*, N_Node*)
 *	\brief Compare deux nodes. Ne compare que les strings de caractères des deux nodes
 *
 *	retourne 0 si les deux nodes sont égaux, un nombre positif si la string de caractère de node1 est lexicographiquement supérieure à celle de node2, un nombre négatif sinon
 *	\param *node1 le premier node à compare (pointeur)
 *	\param *node2 le deuxième node à compare (pointeur)
 *	\return int
 */
int N_compare(void *node1, void *node2);

#endif

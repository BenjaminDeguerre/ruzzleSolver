#ifndef __NODE__
#define __NODE__

/**
 *	\typedef N_Node
 *	\brief Contains a boolean to tell if the node is the last of a series of
 *node and a char (the letter of the node).
 */
typedef struct {
  char value;
  int isLast;
} N_Node;

#define N_MEMORY_ERROR 1

/**
 *	\fn N_Node *N_createNode(int, char)
 *	\brief Create a node and initialize it with the values isLast and value.
 *	\param isLast int tells if the node is final or not.
 *	\param value char, value of the node.
 *	\return N_Node*
 */
N_Node *N_createNode(int isLast, char value);

/**
 *	\fn int N_isLast(N_Node node);
 *	\brief Tells if a node is last.
 *	\param node The target node.
 *	\return int
 */
int N_isLast(N_Node node);

/**
 *	\fn void N_defineValue(N_Node *node, char value);
 *	\brief Define the value of the node.
 *	\param *node Node with the value to be set.
 *	\param value The new value of the node.
 *	\return void
 */
void N_defineValue(N_Node *node, char value);

/**
 *	\fn void N_defineEnd(N_Node *n, int isLast);
 *	\brief Allow to define islast value.
 *	\param *node Node with the value to be set.
 *	\param isLast The new value for is last.
 *	\return void
 */
void N_defineEnd(N_Node *node, int isLast);

/**
 *	\fn N_getValue(N_Node node);
 *	\brief Get the value for a node.
 *	\param node ode with the value to be get.
 *	\return char
 */
char N_getValue(N_Node node);

/**
 *	\fn void N_delete(void *node);
 *	\brief Delete the node.
 *	\param *node The node to be deleted.
 *	\return void
 */
void N_delete(void *node);

/**
 *	\fn void *N_copy(void*);
 *	\brief Copy a node.
 *	\param *node The node to copy
 *	\return void* The copied node.
 */
void *N_copy(void *node);

/**
 *	\fn int N_compare(void *node1, void *node2);
 *	\brief Compare two node.
 *	\param *node1 The first node to compare.
 *	\param *node2 The second node to compare.
 *	\return int, 1 if node1 > node2, 0 if == and -1 else.
 */
int N_compare(void *node1, void *node2);

#endif

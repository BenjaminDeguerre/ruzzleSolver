/* Arthur Hamelin - 10/12/2014 */
/* Benjamin Deguerre - 28/12/2014 */

#include "Node.h"
#include <assert.h>
#include <errno.h>
#include <stdlib.h>

N_Node *N_createNode(int isLast, char value) {
  N_Node *node = (N_Node *)malloc(sizeof(N_Node));

  if (node != NULL) {
    node->isLast = isLast;
    node->value = value;

    return node;
  } else {
    errno = N_MEMORY_ERROR;
    exit(errno);
  }
}

int N_isLast(N_Node node) { return node.isLast; }

void N_defineValue(N_Node *node, char value) { node->value = value; }

void N_defineEnd(N_Node *node, int isLast) { node->isLast = isLast; }

char N_getValue(N_Node node) { return node.value; }

void N_delete(void *node) { free(node); }

void *N_copy(void *node) {
  N_Node *res =
      N_createNode(N_isLast(*((N_Node *)node)), N_getValue(*((N_Node *)node)));
  return (void *)res;
}

int N_compare(void *node1, void *node2) {
  if ((*(N_Node *)node1).value < (*(N_Node *)node2).value) {
    return -1;
  } else if ((*(N_Node *)node1).value == (*(N_Node *)node2).value) {
    return 0;
  } else {
    return 1;
  }
}

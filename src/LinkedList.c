/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

#include "LinkedList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*#define NDEBUG */

/* private */
void LL_deleteR(LL_LinkedList *list, ES_delete freeElement) {
  errno = 0;
  if (!LL_isEmpty(*list)) {
    LL_deleteHead(list, freeElement);
    LL_deleteR(list, freeElement);
  }
}

/* public */
LL_LinkedList LL_createLinkedList() {
  errno = 0;
  LL_LinkedList pNode = (LL_LinkedList)malloc(sizeof(LL_Node));
  if (pNode != NULL) {
    pNode->element = NULL;
    pNode->newtLinkedList = NULL;
  } else {
    errno = LL_MEMORY_ERROR;
  }
  return pNode;
}

int LL_elementIsNull(LL_LinkedList list) {
  errno = 0;
  return list->element == NULL;
}

int LL_newtListIsNull(LL_LinkedList list) {
  errno = 0;
  return list->newtLinkedList == NULL;
}

int LL_isEmpty(LL_LinkedList list) {
  errno = 0;
  return (list->element == NULL) && (list->newtLinkedList == NULL);
}

void LL_add(LL_LinkedList *list, void *source, ES_copy copyElement) {
  LL_LinkedList pNode = (LL_LinkedList)malloc(sizeof(LL_Node));
  void *donnee = copyElement(source);
  if ((pNode != NULL) || (donnee != NULL)) {
    errno = 0;

    pNode->element = donnee;
    pNode->newtLinkedList = *list;

    *list = pNode;
  } else {
    errno = LL_MEMORY_ERROR;
  }
}

void *LL_getElement(LL_LinkedList list) {
  assert(!LL_isEmpty(list));
  errno = 0;
  return list->element;
}

LL_LinkedList LL_getNextList(LL_LinkedList list) {
  assert(!LL_isEmpty(list));
  errno = 0;
  return list->newtLinkedList;
}

void LL_setNextList(LL_LinkedList *list, LL_LinkedList newtList) {
  assert(!LL_isEmpty(*list));
  errno = 0;
  (*list)->newtLinkedList = newtList;
}

void LL_setElement(LL_LinkedList *list, void *source, ES_copy copyElement,
                   ES_delete freeElement) {
  assert(!LL_isEmpty(*list));
  errno = 0;

  void *donnee = copyElement(source);

  if (donnee != NULL) {
    if ((*list)->element != NULL) {
      freeElement((*list)->element);
    }
    (*list)->element = donnee;
  } else {
    errno = LL_MEMORY_ERROR;
  }
}

void LL_deleteHead(LL_LinkedList *list, ES_delete freeElement) {
  LL_LinkedList tmp;

  assert(!LL_isEmpty(*list));

  errno = 0;

  freeElement((void *)LL_getElement(*list));
  tmp = LL_getNextList(*list);
  free(*list);
  *list = tmp;
}

void LL_delete(LL_LinkedList *list, ES_delete freeElement) {

  errno = 0;
  LL_deleteR(list, freeElement);
  free(*list);
}

LL_LinkedList LL_copy(LL_LinkedList list, ES_copy copyElement) {
  LL_LinkedList tmp;

  errno = 0;

  if (LL_isEmpty(list)) {
    return LL_createLinkedList();
  } else {
    tmp = LL_copy(LL_getNextList(list), copyElement);
    LL_add(&tmp, LL_getElement(list), copyElement);

    return tmp;
  }
}

int LL_equals(LL_LinkedList list1, LL_LinkedList list2,
              ES_compare compareElement) {
  errno = 0;

  if (LL_isEmpty(list1) && LL_isEmpty(list2)) {
    return 1;
  } else {
    if (LL_isEmpty(list1) || LL_isEmpty(list2)) {
      return 0;
    } else {
      if (compareElement(LL_getElement(list1), LL_getElement(list2))) {
        return LL_equals(LL_getNextList(list1), LL_getNextList(list2),
                         compareElement);
      } else {
        return 0;
      }
    }
  }

  return 0;
}

int LL_length(LL_LinkedList list) {
  if (LL_newtListIsNull(list)) {
    return 0;
  } else {
    return (LL_length(LL_getNextList(list)) + 1);
  }
}

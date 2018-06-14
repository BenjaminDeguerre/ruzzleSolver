/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

#include "LinkedList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Square.h"

/* private */

/* public */
LL_LinkedList LL_createLinkedList() {
  errno = 0;
  LL_LinkedList pNode = (LL_LinkedList)malloc(sizeof(LL_Node));
  if (pNode != NULL) {
    pNode->element = NULL;
    pNode->newLinkedList = NULL;
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
  return list->newLinkedList == NULL;
}

int LL_isEmpty(LL_LinkedList list) {
  errno = 0;
  return (list->element == NULL) && (list->newLinkedList == NULL);
}

void LL_add(LL_LinkedList *list, void *source, EC_copy copyElement,
            EC_compare compareElement) {
  LL_LinkedList *current, pNode;
  void *donnee = copyElement(source);
  int inserted = 0;

  if (((*list)->element) == NULL) {
    (*list)->element = donnee;
    return;
  }

  pNode = LL_createLinkedList();
  pNode->element = donnee;

  current = list;

  while (current && !inserted) {
    if (!((*current)->newLinkedList)) {
      if (compareElement(donnee, (*list)->element) == 1) {
        pNode->newLinkedList = *list;
        *list = pNode;
        inserted = 1;
      } else {
        (*current)->newLinkedList = pNode;
        inserted = 1;
      }
    } else if (compareElement(donnee, (*list)->element) == 1) {
      pNode->newLinkedList = *list;
      *list = pNode;
      inserted = 1;
    } else if (compareElement(donnee, (*list)->element) == 0) {
      pNode->newLinkedList = (*current)->newLinkedList;
      (*current)->newLinkedList = pNode;
      inserted = 1;
    } else {
      *current = ((*current)->newLinkedList);
    }
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
  return list->newLinkedList;
}

void LL_setNextList(LL_LinkedList *list, LL_LinkedList newtList) {
  assert(!LL_elementIsNull(*list));
  errno = 0;
  (*list)->newLinkedList = newtList;
}

void LL_setElement(LL_LinkedList *list, void *source, EC_copy copyElement,
                   EC_delete freeElement) {
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

void LL_deleteHead(LL_LinkedList *list, EC_delete freeElement) {
  LL_LinkedList tmp;

  assert(!LL_isEmpty(*list));

  errno = 0;

  freeElement((void *)LL_getElement(*list));
  tmp = LL_getNextList(*list);
  free(*list);
  *list = tmp;
}

void LL_delete(LL_LinkedList *list, EC_delete freeElement) {
  errno = 0;
  LL_LinkedList nextList;
  if (!LL_isEmpty(*list)) {
    if (!LL_elementIsNull(*list)) {
      freeElement((*list)->element);
    }
    if (!LL_newtListIsNull(*list)) {
      nextList = LL_getNextList(*list);
      free(*list);
      LL_delete(&nextList, freeElement);
    } else {
      free(*list);
    }
  } else {
    free(*list);
  }
}

LL_LinkedList LL_copy(LL_LinkedList list, EC_copy copyElement,
                      EC_compare compareElement) {
  LL_LinkedList tmp;

  errno = 0;

  if (LL_isEmpty(list)) {
    return LL_createLinkedList();
  } else if (LL_newtListIsNull(list)) {
    tmp = LL_createLinkedList();
    LL_add(&tmp, LL_getElement(list), copyElement, compareElement);
    return tmp;
  } else {
    tmp = LL_copy(LL_getNextList(list), copyElement, compareElement);
    LL_add(&tmp, LL_getElement(list), copyElement, compareElement);
    return tmp;
  }
}

int LL_equals(LL_LinkedList list1, LL_LinkedList list2,
              EC_compare compareElement) {
  errno = 0;

  if (LL_isEmpty(list1) && LL_isEmpty(list2)) {
    return 1;
  } else {
    if (LL_isEmpty(list1) || LL_isEmpty(list2)) {
      return 0;
    } else {
      if (compareElement(LL_getElement(list1), LL_getElement(list2)) == 0) {
        if (LL_newtListIsNull(list1) && LL_newtListIsNull(list2)) {
          return 1;
        }
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
  if (LL_newtListIsNull(list) && LL_elementIsNull(list)) {
    return 0;
  } else if (LL_newtListIsNull(list)) {
    return 1;
  } else {
    return (LL_length(LL_getNextList(list)) + 1);
  }
}

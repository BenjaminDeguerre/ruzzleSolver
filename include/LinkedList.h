#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <errno.h>
#include "elementCollection.h"

typedef struct LL_Node *LL_LinkedList;
typedef struct LL_Node {
  void *element;
  LL_LinkedList newLinkedList;
} LL_Node;

#define LL_MEMORY_ERROR 1

/**
 *	\fn LL_LinkedList LL_createLinkedList();
 *	\brief Create a linked list.
 *	\return LL_LinkedList
 */
LL_LinkedList LL_createLinkedList();

/**
 *	\fn int LL_elementIsNull(LL_LinkedList list);
 *	\brief Tells if an element of a linked list is null.
 *	\param list The linked list to test.
 *	\return int
 */
int LL_elementIsNull(LL_LinkedList list);

/**
 *	\fn int LL_newtListIsNull(LL_LinkedList list)
 *	\brief Tells if a the new linked list of a list is null.
 *	\param list The linked list to test.
 *	\return int
 */
int LL_newtListIsNull(LL_LinkedList list);

/**
 *	\fn int LL_isEmpty(LL_LinkedList);
 *	\brief Tells if a linked list is empty.
 *	\param list The linked list to test.
 *	\return int
 */
int LL_isEmpty(LL_LinkedList list);

/**
 *	\fn void LL_add(LL_LinkedList *list, void *source, EC_copy copyElement);
 *	\brief Add a copy of an element to the list. The element are ordered.
 *	\param *list Pointer to the list to add the element to.
 *  \param *source The element to copy.
 *	\param copyElement The function to copy the element.
 *	\return void
 */
void LL_add(LL_LinkedList *list, void *source, EC_copy copyElement,
            EC_compare compareElement);

/**
 *	\fn void* LL_getElement(LL_LinkedList);
 *	\brief Get the element of the current list.
 *	\param list The list to get the element from.
 *	\return void
 */
void *LL_getElement(LL_LinkedList list);

/**
 *	\fn LL_LinkedList LL_getNextList(LL_LinkedList);
 *	\brief Get the next list.
 *	\param list The list to get the element from.
 *	\return LL_LinkedList, the next list.
 */
LL_LinkedList LL_getNextList(LL_LinkedList list);

/**
 *	\fn void LL_setNextList(LL_LinkedList* list, LL_LinkedList newList);
 *	\brief Set the next linked list of a list.
 *	\param *list Pointer to the list to add the list to.
 *	\param newtList The list to be added.
 *	\return void
 */
void LL_setNextList(LL_LinkedList *list, LL_LinkedList newList);

/**
 *	\fn	void LL_setElement(LL_LinkedList*, void*, EC_copy copyElement,
 *EC_delete freeElement) \brief Set the element of a linked list. \param *list
 *The list to change the element of. \param void* source The new element. \param
 *copyElement The function to copy the new element. \param freeElement The
 *function to delete the current element if any. \return void
 */
void LL_setElement(LL_LinkedList *list, void *source, EC_copy copyElement,
                   EC_delete freeElement);

/**
 *	\fn void LL_deleteHead(LL_LinkedList *list, EC_delete freeElement);
 *	\brief Remove the head of the list
 *	\param list* The list to remove the head from.
 *	\param freeElement The function to delete the element of the head.
 *	\return void
 */
void LL_deleteHead(LL_LinkedList *list, EC_delete freeElement);

/**
 *	\fn void LL_delete(LL_LinkedList* list, EC_delete freeElement);
 *	\brief Delete the provided list.
 *	\param *list The list to be deleted.
 *	\param freeElement, The function to delete the elements of the list.
 *	\return void
 */
void LL_delete(LL_LinkedList *list, EC_delete freeElement);

/**
 *	\fn LL_LinkedList LL_copy(LL_LinkedList list, EC_copy copyElement,
                      EC_compare compareElement);
 *	\brief Copy a full list.
 *	\param list The list to be copied.
 *	\param copyElement, The function to copy the element.
 *  \param compareElement, The function to compare two elements.
 *	\return LL_LinkedList
 */
LL_LinkedList LL_copy(LL_LinkedList list, EC_copy copyElement,
                      EC_compare compareElement);

/**
 *	\fn int LL_equals(LL_LinkedList list1, LL_LinkedList list2, EC_compare
 *compareElement); \brief Tells if two list are equals. \param list1 The first
 *list. \param list2 The second list. \param compareElement The function to
 *compare two elements. \return int
 */
int LL_equals(LL_LinkedList list1, LL_LinkedList list2,
              EC_compare compareElement);

/**
 *	\fn int LL_length(LL_LinkedList list);
 *	\brief Tell the length of a list.
 *	\param list The list to test.
 *	\return int
 */
int LL_length(LL_LinkedList list);

#endif

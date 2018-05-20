/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

#ifndef __ORDERED_LIST__
#define __ORDERED_LIST__

#include "elementCollection.h"
#include <errno.h>

typedef struct LL_Node *LL_LinkedList;
typedef struct LL_Node {
  void *element;
  LL_LinkedList newtLinkedList;
} LL_Node;

#define LL_MEMORY_ERROR 1

/**
 *	\fn LL_LinkedList LL_createLinkedList();
 *	\brief permet de create une liste stringe
 *	\return LL_LinkedList
 */
LL_LinkedList LL_createLinkedList();

/**
 *	\fn int LL_elementIsNull(LL_LinkedList);
 *	\brief permet de savoir si l'element est vide (ie. element NULL)
 *	\param list une liste stringe
 *	\return int
 */
int LL_elementIsNull(LL_LinkedList);

/**
 *	\fn int LL_newtListIsNull(LL_LinkedList list)
 *	\brief permet de savoir si la liste stringe possede une suite (ie. liste
 *suivante NULL)
 *	\param list une liste stringe
 *	\return int
 */
int LL_newtListIsNull(LL_LinkedList list);

/**
 *	\fn int LL_isEmpty(LL_LinkedList);
 *	\brief permet de savoir si une liste stringe est une vide (ie. element
 *et liste suivante NULL)
 *	\param list une liste stringe
 *	\return int
 */
int LL_isEmpty(LL_LinkedList list);

/**
 *	\fn void LL_add(LL_LinkedList* , void* source, ES_copy copyElement);
 *	\brief permet d'add un element en tête de liste, après la fonction, list
 *pointe sur le nouvel élément
 *	\param *list un pointeur sur une liste stringe
 *  \param *source l'element a copy
 *	\param fonction pour copy l'element
 *	\return void
 */
void LL_add(LL_LinkedList *list, void *source, ES_copy copyElement);

/**
 *	\fn void* LL_getElement(LL_LinkedList);
 *	\brief permet d'get l'element courant d'une liste stringe
 *	\param list une liste stringe
 *	\return void
 */
void *LL_getElement(LL_LinkedList list);

/**
 *	\fn LL_LinkedList LL_getNextList(LL_LinkedList);
 *	\brief permet d'get la liste suivante d'une liste stringe
 *	\param list une liste stringe
 *	\return LL_LinkedList
 */
LL_LinkedList LL_getNextList(LL_LinkedList list);

/**
 *	\fn void LL_setNextList(LL_LinkedList* list, LL_LinkedList newtList);
 *	\brief permet de set la liste suivante newtList a list
 *	\param *list un pointeur sur une liste stringe
 *	\param newtList la liste stringe a set
 *	\return void
 */
void LL_setNextList(LL_LinkedList *list, LL_LinkedList newtList);

/**
 *	\fn	void LL_setElement(LL_LinkedList*, void*, ES_copy, ES_delete)
 *	\brief	Permet de set un element sur une liste NON VIDE
 *
 * Si ES_delete utilise free, si un élément a été radd d'une manière autre
 *qu'avec les fonction du TAD, la fonction bug
 *	\param *list liste dont on veut modifier l'élément (pointeur)
 *	\param void* source l'élément à add
 *	\param copyElement la fonction de copie de l'élément
 *	\param freeElement la fonction de suppression de l'élément
 *	\return void
 */
void LL_setElement(LL_LinkedList *list, void *source, ES_copy copyElement,
                   ES_delete freeElement);

/**
 *	\fn void LL_deleteHead(LL_LinkedList*, ES_delete);
 *	\brief permet de delete la tete de la liste stringe
 *	\param list* un pointeur sur une liste stringe
 *	\param freeElement
 *	\return void
 */
void LL_deleteHead(LL_LinkedList *list, ES_delete freeElement);

/**
 *	\fn void LL_delete(LL_LinkedList* list, ES_delete);
 *	\brief permet de delete un element de la liste
 *	\param *list un pointeur sur une liste stringe
 *	\param freeElement
 *	\return void
 */
void LL_delete(LL_LinkedList *list, ES_delete freeElement);

/**
 *	\fn LL_LinkedList LL_copy(LL_LinkedList, ES_copy);
 *	\brief
 *	\param list une liste stringe
 *	\param copyElement
 *	\return LL_LinkedList
 */
LL_LinkedList LL_copy(LL_LinkedList list, ES_copy copyElement);

/**
 *	\fn int LL_equals(LL_LinkedList, LL_LinkedList, ES_compare);
 *	\brief permet de savoir si deux listes sont egales
 *	\param list1 une liste stringe
 *	\param list2 une liste ordonne
 *	\param compareElement
 *	\return int
 */
int LL_equals(LL_LinkedList list1, LL_LinkedList list2,
              ES_compare compareElement);

/**
 *	\fn int LL_length(LL_LinkedList list);
 *	\brief permet d'get la length d'une liste stringe
 *	\param list une liste stringe
 *	\return int
 */
int LL_length(LL_LinkedList list);

#endif

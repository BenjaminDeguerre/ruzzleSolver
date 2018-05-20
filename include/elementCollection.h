/* Arthur Hamelin - 10/12/2014 */
/* Arthur Hamelin - 05/01/2015 */

/** \file elementCollection.h
 *	\brief Déclaration des fonctions copy, delete et compare pour l'ensemble des collections.
 *	\version 1.0
 *	\date 05/01/2015
 */

#ifndef __ELEMENT_COLLECTION__
#define __ELEMENT_COLLECTION__

typedef void* (*ES_copy)(void*);
typedef void (*ES_delete)(void*);
typedef int (*ES_compare)(void*, void*);

#endif

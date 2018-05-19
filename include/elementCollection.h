/* Arthur Hamelin - 10/12/2014 */
/* Arthur Hamelin - 05/01/2015 */

/** \file elementCollection.h
 *	\brief Déclaration des fonctions copier, supprimer et comparer pour l'ensemble des collections.
 *	\version 1.0
 *	\date 05/01/2015
 */

#ifndef __ELEMENT_COLLECTION__
#define __ELEMENT_COLLECTION__

typedef void* (*EC_copier)(void*);
typedef void (*EC_supprimer)(void*);
typedef int (*EC_comparer)(void*, void*);

#endif

/* Arthur Hamelin - 10/12/2014 */
/* Arthur Hamelin - 05/01/2015 */

/** \file elementCollection.h
 *	\brief Type for the compare, delete and copy function, general types.
 *	\version 1.0
 *	\date 05/01/2015
 */

#ifndef __ELEMENT_COLLECTION__
#define __ELEMENT_COLLECTION__

typedef void *(*EC_copy)(void *);
typedef void (*EC_delete)(void *);
typedef int (*EC_compare)(void *, void *);

#endif

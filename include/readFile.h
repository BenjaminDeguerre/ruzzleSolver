/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 17/12/2014 */
/* Michel CRESSANT*/

/** \file readFile(FILE *file);
 *	\brief Contient la fonction qui permet dlie un file
 *	\version 1.0
 *	\date 05/01/2015
 */

#ifndef __READ_FILE__
#define __READ_FILE__

#include <string.h>

#include "Dictionary.h"

/**
 *	\fn D_Dictionary readFile(FILE *file);
 *	\brief Permet de read un file
 *	\param *file un pointeur sur un file
 *	\return D_Dictionary
 */
D_Dictionary readFile(FILE *file);

#endif

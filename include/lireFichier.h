/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 17/12/2014 */
/* Michel CRESSANT*/

/** \file lireFichier(FILE *fichier);
 *	\brief Contient la fonction qui permet dlie un fichier
 *	\version 1.0
 *	\date 05/01/2015
 */
 

#ifndef __LIRE_FICHIER__
#define __LIRE_FICHIER__

#include <string.h>

#include "Dictionnaire.h"

/**
 *	\fn D_Dictionnaire lireFichier(FILE *fichier);
 *	\brief Permet de lire un fichier
 *	\param *fichier un pointeur sur un fichier
 *	\return D_Dictionnaire
 */
D_Dictionnaire lireFichier(FILE *fichier);

#endif

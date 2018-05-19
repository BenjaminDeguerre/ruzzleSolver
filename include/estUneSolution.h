/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */
/* Michel CRESSANT - 05/01/2015 */


/** \file estUneSolution.h
 *	\brief Contient la fonction qui permet de savoir si une chaine de caractères est dans le dictionnaire
 *	\version 1.0
 *	\date 05/01/2015
 */
 

#ifndef __EST_UNE_SOLUTION__
#define __EST_UNE_SOLUTION__

#include "Dictionnaire.h"

/**
 *	\fn int estUneSolution(D_Dictionnaire *dico, char *chATester);
 *	\brief Permet de savoir si une chaine de caractère est dans le dictionnaire
 *	\param *dico est un pointeur sur un dictionnaire
 *	\param *chATester est un pointeur sur la chaine de caractère à tester
 *	\return int
 */
int estUneSolution(D_Dictionnaire *dico, char *chATester);

#endif

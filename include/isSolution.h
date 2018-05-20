/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */
/* Michel CRESSANT - 05/01/2015 */


/** \file isSolution.h
 *	\brief Contient la fonction qui permet de savoir si une string de caractères est dans le dictionary
 *	\version 1.0
 *	\date 05/01/2015
 */
 

#ifndef __IS_A_SOLUTION__
#define __IS_A_SOLUTION__

#include "Dictionary.h"

/**
 *	\fn int isSolution(D_Dictionary *dictionary, char *stringToTest);
 *	\brief Permet de savoir si une string de caractère est dans le dictionary
 *	\param *dictionary est un pointeur sur un dictionary
 *	\param *stringToTest est un pointeur sur la string de caractère à tester
 *	\return int
 */
int isSolution(D_Dictionary *dictionary, char *stringToTest);

#endif

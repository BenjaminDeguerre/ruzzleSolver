/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */

/** \file subString.h
 *	\brief Contient la fonction qui permet d'extraire une sous string d'une string de caractère
 *	\version 1.0
 *	\date 27/12/2014
 */
 
#ifndef __SOUS_CHAINE__
#define __SOUS_CHAINE__

/**
 *	\fn char *subString(char *string, int begin, int end)
 *	\brief extrait la sous string commençant a la position début et se finissant à fin
 *	
 *	Le premier caractère est à 0, par exemple : soustring("bonjour",1,2) = "on". Malloc est utilisé, un free est nécéssaire
 *	\param *string notre string de caractère
 *	\param begin la position de début de la string à extraire
 *	\param fin la position de fin de la string à extraire
 *	\return char*
 */
char *subString(char *string, int begin, int end);

#endif

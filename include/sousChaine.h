/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */

/** \file sousChaine.h
 *	\brief Contient la fonction qui permet d'extraire une sous chaine d'une chaine de caractère
 *	\version 1.0
 *	\date 27/12/2014
 */
 
#ifndef __SOUS_CHAINE__
#define __SOUS_CHAINE__

/**
 *	\fn char *sousChaine(char *ch, int debut, int fin)
 *	\brief extrait la sous chaine commençant a la position début et se finissant à fin
 *	
 *	Le premier caractère est à 0, par exemple : souchaine("bonjour",1,2) = "on". Malloc est utilisé, un free est nécéssaire
 *	\param *ch notre chaine de caractère
 *	\param debut la position de début de la chaine à extraire
 *	\param fin la position de fin de la chaine à extraire
 *	\return char*
 */
char *sousChaine(char *ch, int debut, int fin);

#endif

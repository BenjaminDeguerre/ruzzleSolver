/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */


/** \file obtenirCombinaisons.h
 *	\brief Contient la fonction qui permet d'obtenir les combinaisons d'une grille
 *	\version 1.0
 *	\date 11/12/2014
 */
#ifndef __OBTENIR_COMBINAISONS__
#define __OBTENIR_COMBINAISONS__

#include "Grille.h"
#include "Mot.h"
#include "ListeChainee.h"

/**
 *	\fn LC_ListeChainee *obtenirCombinaisons(G_Grille *grille);
 *	\brief Permet d'obtenir les combinaisons d'une grille
 *	\param *grille est un pointeur sur une grille
 *	\return int
 */
LC_ListeChainee *obtenirCombinaisons(G_Grille *grille);

#endif

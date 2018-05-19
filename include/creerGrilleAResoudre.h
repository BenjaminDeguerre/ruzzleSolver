/*Michel Cressant 11/12/2014*/

/** \file creerGrilleAResoudre.h
 *	\brief Contient la fonction qui permet de creer la grille à resoudre
 *	\version 1.0
 *	\date 26/12/2014
 */
 
#ifndef __CREER_GRILLE_A_RESOUDRE__
#define __CREER_GRILLE_A_RESOUDRE__

#include "Dictionnaire.h"
#include "Grille.h"
#include "Mot.h"
#include "ListeChainee.h"
#include "sousChaine.h"
 
/**
 *	\fn G_Grille *creerGrilleAResoudre(char *chParametresGrille)
 *	\brief Permet de creer une grille
 *	\param *g la grille dans laquelle se trouve la case (pointeur)
 *	\param *cC les cases contigues (pointeur)
 *	\return LC_ListeChainee
 */
G_Grille creerGrilleAResoudre(char *chParametresGrille);

#endif


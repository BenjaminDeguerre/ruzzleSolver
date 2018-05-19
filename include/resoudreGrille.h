/* Michel CRESSANT - 11/12/2014 */
/* Benjamin Deguerre - 02/01/2015 */

/** \file resoudreGrille.h
 *	\brief Contient la fonction qui permet de resoudre une grille de ruzzle
 *	\version 1.0
 *	\date 02/01/2015
 */
#ifndef __RESOUDRE_GRILLE__
#define __RESOUDRE_GRILLE__

#include <string.h>

#include "Dictionnaire.h"
#include "Grille.h"
#include "Mot.h"
#include "ListeChainee.h"
#include "CasesContigues.h"
#include "estUneSolution.h"

/**
 *	\typedef rG_Mot
 *	\brief Contient un mot avec sa valeur en point dans la grille
 */
typedef struct rG_Mot {
	char *mot; /**< le mot */
	int point; /**< Valeur en point du mot */
} rG_Mot;

/**
 *	\fn	LC_ListeChainee resoudreGrille(D_Dictionnaire dic, G_Grille grilleAResoudre)
 *	\brief retourne une 	
 *	\param dic le dictionnaire contenant l'ensemble des mots possible
 *	\param grilleAResoudre la grille à resoudre
 *	\return LC_ListeChainee
 */

LC_ListeChainee resoudreGrille(D_Dictionnaire dic, G_Grille grilleAResoudre);

#endif


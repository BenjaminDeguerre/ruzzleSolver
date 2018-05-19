/* Arthur Hamelin - 10/12/2014 */
/* Benjamin Deguerre - 25/12/2014 */

/** \file CasesContigues.h
 *	\brief Implémentation du TAD CasesContigues
 *	\version 1.0
 *	\date 26/12/2014
 */
 
#ifndef __CASES_CONTIGUES__
#define __CASES_CONTIGUES__

#include "Case.h"
#include "ListeChainee.h"
#include "Grille.h"

/**
 *	\typedef CC_CasesContigues
 *	\brief Structure représentant une suite de cases
 *
 *	Cette structure contient, une liste ordonnée de case, le nombre de points des cases (sans le bonus multiplicateur sur le mot mais avec celui sur la lettre, et le coefficient du bonus sur le mot
 */ 
typedef struct {	
	LC_ListeChainee lCC;
	int nbPoints; /**< nombre de point des cases (somme), sans compter mot compte double, triple... */
	int coeffBonus; /**< contient le coefficient multiplicateur du bonus sur le mot */
} CC_CasesContigues;

#define CC_ERREUR_MEMOIRE 1

/**
 *	\fn CC_CasesContigues CC_creerCasesContigues()
 *	\brief Créé la suite de case, lCC vide et nbPoints, coeffBonus à 0
 *	\return CC_CasesContigues*
 */
CC_CasesContigues* CC_creerCasesContigues();

/**
 *	\fn LC_ListeChainee CC_obtenirVoisinsPossibles(G_Grille *g, CC_CasesContigues *cC)
 *	\brief Permet d'obtenir tout les cases voisins possible de la dernière case
 *
 *	Les cases déjà préssentes dans la suite de cases contigues ne seront pas renvoyées
 *	\param *g la grille dans laquelle se trouve la case (pointeur)
 *	\param *cC les cases contigues (pointeur)
 *	\return LC_ListeChainee
 */
LC_ListeChainee CC_obtenirVoisinsPossibles(G_Grille *g, CC_CasesContigues *cC);

/**
 *	\fn void CC_ajouterCase(CC_CasesContigues *cC, C_Case *c)
 *	\brief ajoute une case en tête de chaine et met à jour les valeurs de point bonus et du nombre de points
 *	\param *cC Les cases contigues auxquelle on veut rajouter la case (pointeur)
 *	\param *c la case à rajouter (pointeur)
 *	\return void
 */
void CC_ajouterCase(CC_CasesContigues *cC, C_Case *c);

/**
 *	\fn void CC_supprimerCase(CC_CasesContigues *cC)
 *	\brief Supprime la dernière case d'une suite de cases contigues
 *	\param *cC la suite de cases contigues cible
 *	\return void
 */
void CC_supprimerCase(CC_CasesContigues *cC);

/**
 *	\fn char *CC_lireCases(CC_CasesContigues cC)
 *	\brief retourne les chaines de caractères présentes dans chaque cases sous la forme d'une longue chaine de caractère 
 *	\param cC la suite de cases contigues cible
 *	\return char*
 */
char *CC_lireCases(CC_CasesContigues cC);

/**
 *	\fn int CC_compterPoints(CC_CasesContigues cC)
 *	\brief retourne la valeur en point de la suite de cases contigues
 *	\param cC la suite de cases contigues cible
 *	\return int
 */
int CC_compterPoints(CC_CasesContigues cC);
 

/**
 *	\fn int CC_obtenirLongueur(CC_CasesContigues cC)
 *	\brief retourne la longeur de la suite de cases contigues 
 *	\param cC la suite de cases contigues cible
 *	\return int 
 */
int CC_obtenirLongueur(CC_CasesContigues cC);

/**
 *	\fn int CC_obtenirBonus(CC_CasesContigues cC)
 *	\brief retourne la valeur du coefficient bonus de la chaine de cases contigues
 *	\param cC la suite de cases contigues cible
 *	\return int
 */
int CC_obtenirBonus(CC_CasesContigues cC);

/**
 *	\fn int CC_obtenirNbPoints(CC_CasesContigues cC)
 *	\brief retourne nbPoints, valeur sans les bonus sur le mot
 *	\param cC la suite de cases contigues cible
 *	\return int
 */
int CC_obtenirNbPoints(CC_CasesContigues cC);

/**
 *	\fn LC_ListeChainee* CC_obtenirListeChainee(CC_CasesContigues *cC)
 *	\brief retourne un pointeur sur la liste ordonnée contenue dans la structure caseContigues
 *	\param *cC la suite de cases contigues cible (pointeur)
 *	\return LC_ListeChainee*
 */
LC_ListeChainee* CC_obtenirListeChainee(CC_CasesContigues *cC);

/**
 *	\fn void CC_setBonus(CC_CasesContigues *cC, int bonus)
 *	\brief permet d'initialiser le bonus d'une suite de cases contigues
 *	\param *cC la suite de cases contigues cible (pointeur)
 *	\param bonus la valeur du bonus
 *	\return void
 */
void CC_setBonus(CC_CasesContigues *cC, int bonus);

/**
 *	\fn void CC_setNbPoints(CC_CasesContigues *cC, int points)
 *	\brief permet d'initialiser la valeur de nbPoints d'une suite de cases contigues
 *	\param *cC la suite de cases contigues cible (pointeur)
 *	\param points la valeur des points
 *	\return void
 */
void CC_setNbPoints(CC_CasesContigues *cC, int points);

/**
 *	\fn C_Case *CC_obtenirCase(CC_CasesContigues*, int)
 *	\brief Permet d'obtenir la ième cases d'une suite de cases contigues
 *	\param *cC la suite de cases contigues cible (pointeur)
 *	\param no le numéro de la case
 *	\return C_Case
 */
C_Case *CC_obtenirCase(CC_CasesContigues *cC, int no);

#endif

/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

#ifndef __LISTE_ORDONNEE__
#define __LISTE_ORDONNEE__

#include <errno.h>
#include "elementCollection.h"

typedef struct LC_Noeud* LC_ListeChainee;
typedef struct LC_Noeud {
	void *element;
	LC_ListeChainee listeChaineeSuivante;
} LC_Noeud;

#define LOE_ERREUR_MEMOIRE 1

/**
 *	\fn LC_ListeChainee LC_creerListeChainee();
 *	\brief permet de creer une liste chainee
 *	\return LC_ListeChainee
 */
LC_ListeChainee LC_creerListeChainee();

/**
 *	\fn int LC_elementEstNull(LC_ListeChainee);
 *	\brief permet de savoir si l'element est vide (ie. element NULL)
 *	\param lO une liste chainee
 *	\return int
 */
int LC_elementEstNull(LC_ListeChainee);

/**
 *	\fn int LC_listeSuivanteEstNull(LC_ListeChainee lO)
 *	\brief permet de savoir si la liste chainee possede une suite (ie. liste suivante NULL)
 *	\param lO une liste chainee
 *	\return int
 */
int LC_listeSuivanteEstNull(LC_ListeChainee lO);

/**
 *	\fn int LC_estVide(LC_ListeChainee);
 *	\brief permet de savoir si une liste chainee est une vide (ie. element et liste suivante NULL)
 *	\param lO une liste chainee
 *	\return int
 */
int LC_estVide(LC_ListeChainee lO);

/**
 *	\fn void LC_ajouter(LC_ListeChainee* , void* source, EC_copier copierElement);
 *	\brief permet d'ajouter un element en tête de liste, après la fonction, lO pointe sur le nouvel élément
 *	\param *lO un pointeur sur une liste chainee
 *  \param *source l'element a copier
 *	\param fonction pour copier l'element
 *	\return void
 */
void LC_ajouter(LC_ListeChainee* lO , void* source, EC_copier copierElement);

/**
 *	\fn void* LC_obtenirElement(LC_ListeChainee);
 *	\brief permet d'obtenir l'element courant d'une liste chainee
 *	\param lO une liste chainee
 *	\return void
 */
void* LC_obtenirElement(LC_ListeChainee lO);

/**
 *	\fn LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee);
 *	\brief permet d'obtenir la liste suivante d'une liste chainee
 *	\param lO une liste chainee
 *	\return LC_ListeChainee
 */
LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee lO);

/**
 *	\fn void LC_fixerListeSuivante(LC_ListeChainee* lO, LC_ListeChainee lOS);
 *	\brief permet de fixer la liste suivante lOS a lO
 *	\param *lO un pointeur sur une liste chainee
 *	\param lOS la liste chainee a fixer
 *	\return void
 */
void LC_fixerListeSuivante(LC_ListeChainee* lO, LC_ListeChainee lOS);

/**
 *	\fn	void LC_fixerElement(LC_ListeChainee*, void*, EC_copier, EC_supprimer)
 *	\brief	Permet de fixer un element sur une liste NON VIDE
 *
 * Si EC_supprimer utilise free, si un élément a été rajouter d'une manière autre qu'avec les fonction du TAD, la fonction bug
 *	\param *lO liste dont on veut modifier l'élément (pointeur)
 *	\param void* source l'élément à ajouter
 *	\param copierElement la fonction de copie de l'élément
 *	\param libererElement la fonction de suppression de l'élément
 *	\return void
 */
void LC_fixerElement(LC_ListeChainee *lO, void* source, EC_copier copierElement, EC_supprimer libererElement);

/**
 *	\fn void LC_supprimerTete(LC_ListeChainee*, EC_supprimer);
 *	\brief permet de supprimer la tete de la liste chainee
 *	\param lO* un pointeur sur une liste chainee
 *	\param libererElement
 *	\return void
 */
void LC_supprimerTete(LC_ListeChainee* lO, EC_supprimer libererElement); /*libererElementpascompris*/

/**
 *	\fn void LC_supprimer(LC_ListeChainee* lO, EC_supprimer);
 *	\brief permet de supprimer un element de la liste
 *	\param *lO un pointeur sur une liste chainee
 *	\param libererElement
 *	\return void
 */
void LC_supprimer(LC_ListeChainee* lO, EC_supprimer libererElement); /*idem*/

/**
 *	\fn LC_ListeChainee LC_copier(LC_ListeChainee, EC_copier);
 *	\brief
 *	\param lO une liste chainee
 *	\param copierElement
 *	\return LC_ListeChainee
 */
LC_ListeChainee LC_copier(LC_ListeChainee lO, EC_copier copierElement);/*idem a peut pret*/

/**
 *	\fn int LC_egales(LC_ListeChainee, LC_ListeChainee, EC_comparer);
 *	\brief permet de savoir si deux listes sont egales
 *	\param lO1 une liste chainee
 *	\param lO2 une liste ordonne
 *	\param comparerElement
 *	\return int
 */
int LC_egales(LC_ListeChainee lO1, LC_ListeChainee lO2, EC_comparer comparerElement);/*idem*/

/**
 *	\fn int LC_longueur(LC_ListeChainee lO);
 *	\brief permet d'obtenir la longueur d'une liste chainee
 *	\param lO une liste chainee
 *	\return int
 */
int LC_longueur(LC_ListeChainee lO);

#endif

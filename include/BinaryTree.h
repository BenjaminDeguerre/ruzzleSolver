/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 02/01/2015 */
 
/** \file BinaryTree.h
 *	\brief Implémentation du TAD BinaryTree
 *	\version 1.0
 *	\date 26/12/2014
 */
#ifndef __ARBRE_BINAIRE_DE_RECHERCHE__
#define __ARBRE_BINAIRE_DE_RECHERCHE__

#include "Noeud.h"
#include "elementCollection.h"

/** 
 *	\typedef AB_BinaryTree
 */
typedef struct AB_Noeud* AB_BinaryTree;

/**
 *	\typedef AB_Noeud
 *	\struct AB_Noeud
 *	\brief structure d'un arbre binaire de recherche
 */
typedef struct AB_Noeud {	
	N_Noeud *racine; /**< racine de l'arbre */
	AB_BinaryTree sAG; /**< fils gauche de l'arbre, aussi un arbre */
	AB_BinaryTree sAD; /**< fils droit de l'arbre, aussi un arbre */
	int estTraite;
} AB_Noeud;

#define AB_ERREUR_MEMOIRE 1

/** 
 *	\fn AB_BinaryTree AB_creerABR()
 *	\brief Creer un arbre binaire de recheche vide.
 *	
 *	L'arbre binaire est initilisé sur la valeur NULL.
 *	\return AB_BinaryTree
 */
AB_BinaryTree AB_creerABR();

/** 
 *	\fn int AB_estVide(AB_BinaryTree *monABR)
 *	\brief Permet de savoir si un arbre est vide ou non
 *
 *	La fonction renvoie 0 si faux, 1 sinon.
 *	\param *monABR pointeur un arbre
 *	\return int
 */ 
int AB_estVide(AB_BinaryTree monABR);

/** 
 *	\fn void AB_fixerFilsGauche(AB_BinaryTree *monArbre, AB_BinaryTree *filsGauche)
 *	\brief Permet de fixer le fils gauche de l'arbre
 *	\param *monABR pointeur sur un arbre
 *	\param *filsGauche pointeur sur un arbre, fils à fixer
 *	\return void
 */ 
void AB_fixerFilsGauche(AB_BinaryTree *monArbre, AB_BinaryTree filsGauche);

/** 
 *	\fn void AB_fixerFilsDroit(AB_BinaryTree *monArbre, AB_BinaryTree *filsDroit)
 *	\brief Permet de fixer le fils droit de l'arbre
 *	\param *monABR pointeur sur un arbre
 *	\param *filsDroit pointeur sur un arbre, fils à fixer
 *	\return void
 */ 
void AB_fixerFilsDroit(AB_BinaryTree *monArbre, AB_BinaryTree filsDroit);

/** 
 *	\fn AB_BinaryTree AB_ajouterRacine(AB_BinaryTree *filsGauche, AB_BinaryTree *filsDroit, N_Noeud *noeud, EC_copier copier)
 *	\brief Permet de racroccher deux arbres à une même racine (noeud)
 *	\param *filsGauche pointeur sur un arbre, nouveau fils gauche du noeud
 *	\param *filsDroit pointeur sur un arbre, nouveau fils droit du noeud
 *	\param *noeud pointeur sur un noeud, nouvelle racine
 *	\param copier fonction permettant la copie d'un noeud
 *	\return AB_BinaryTree
 */ 
AB_BinaryTree AB_ajouterRacine(AB_BinaryTree filsGauche, AB_BinaryTree filsDroit, N_Noeud *noeud, EC_copier copier);

/** 
 *	\fn N_Noeud* AB_obtenirRacine(AB_BinaryTree *abr)
 *	\brief Permet d'obtenir la racine d'un arbre binaire de recherche
 *	\param *abr pointeur sur un arbre, arbre dont on veut la racine
 *	\return N_Noeud*
 */ 
N_Noeud* AB_obtenirRacine(AB_BinaryTree aBR);

/** 
 *	\fn void AB_supprimerRacine(AB_BinaryTree* a, AB_BinaryTree* sAG, AB_BinaryTree* sAD, EC_supprimer libererNoeud)
 *	\brief Permet de supprimer la racine d'un arbre binaire de recherche (deux sous arbre sont "créés")
 *	\param *a pointeur sur un arbre, celui dont on veut supprimer la racine
 *	\param *sAG pointeur sur un arbre, (sortie) sous arbre gauche résultant de la suppression de la racine
 *	\param *sAD pointeur sur un arbre, (sortie) sous arbre droit résultant de la suppression de la racine
 *	\param libererNoeud fonction permettant de libérer l'espace mémoire occupé par le noeud
 *	\return void
 */ 
void AB_supprimerRacine(AB_BinaryTree* a, AB_BinaryTree* sAG, AB_BinaryTree* sAD, EC_supprimer libererNoeud);

/** 
 *	\fn void AB_supprimer(AB_BinaryTree* a, EC_supprimer libererNoeud)
 *	\brief Supprime un arbre binaire de recherche en entier
 *	\param *a pointeur sur l'arbre à supprimer
 *	\param libererNoeud fonction permettant de libérer l'espace mémoire occupé par le noeud
 *	\return void
 */
void AB_supprimer(AB_BinaryTree* a, EC_supprimer libererNoeud);

/** 
 *	\fn AB_BinaryTree* AB_obtenirFilsDroit(AB_BinaryTree *monABR)
 *	\brief Getter, permet d'obtenir le fils droit de la racine d'un arbre
 *	\param *monABR pointeur sur l'abre dont on veut le fils droitx	
 *	\return AB_BinaryTree*
 */
AB_BinaryTree AB_obtenirFilsDroit(AB_BinaryTree monABR);

/** 
 *	\fn AB_BinaryTree* AB_obtenirFilsGauche(AB_BinaryTree *monABR)
 *	\brief Getter, permet d'obtenir le fils gauche de la racine d'un arbre
 *	\param *monABR pointeur sur l'abre dont on veut le fils gauche
 *	\return AB_BinaryTree*
 */ 
AB_BinaryTree AB_obtenirFilsGauche(AB_BinaryTree monABR);


void AB_fixerEstTraite(AB_BinaryTree *a, int b);

int AB_estTraite(AB_BinaryTree *a);

#endif

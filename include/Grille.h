/**
 *	\file Grille.h
 *	\brief Implémentation du TAD Grille
 *	\version 1.0
 *	\date 29/12/2014
 */
#ifndef __GRILLE__
#define __GRILLE__

#include "Case.h"
#include "ListeChainee.h"
#include "sousChaine.h"
#include "Case.h"

#define G_COTE 4
#define G_TAILLE (G_COTE * G_COTE)

/**
 *	\typedef G_Grille
 *	\brief Structure d'une grille, tableau de case
 */
typedef struct {
	C_Case tabCases[G_TAILLE]; /**< Le tableau de Cases */
} G_Grille;

/**
 *	\fn G_Grille G_creerGrille(char *chaine[G_TAILLE])
 *	\brief Permet de créer une grille, prend en entrée la chaine contenant les suites de caractères contenus dans les cases de la grille
 *
 *	La chaine en entré est de la forme suivante "LettreValeurBonusLettreValeurBonus..." si aucun bonus mettre "  "
 *	\param chaine[G_TAILLE] la chaine de caractère contenant la valeur des cases
 *	\return G_Grille
 */
G_Grille G_creerGrille(char *chaine[G_TAILLE]);

/**
 *	\fn C_Case* G_obtenirCase(G_Grille, int noCase)
 *	\brief Permet d'obtenir un pointer sur la ieme case d'une grille (0-11, gauche-droite, haut-bas)
 *	\param g la grille cible
 *	\param noCase le numéro de la case que l'on souhaite obtenir
 *	\return C_Case*
 */
C_Case G_obtenirCase(G_Grille g, int noCase);

/**
 *	\fn LC_ListeChainee G_obtenirVoisins(G_Grille g, C_Case c)
 *	\brief Permet d'obtenir les voisins d'une case donnée dans une grille
 *
 *	retourne une liste ordonnée contenant tous les voisins possible
 *	\param g La grille cible
 *	\param c La case dont on veut les voisins
 *	\return LC_ListeChainee
 */
LC_ListeChainee G_obtenirVoisins(G_Grille g, C_Case c);

/**
 *	\fn void G_suppirmerGrille(G_Grille g)
 *	\brief permet de supprimer les allocation mémoire faite avec la fonction G_creeGrille
 *	\param g la grille à supprimer
 *	\return void
 */
void G_supprimerGrille(G_Grille g);
#endif

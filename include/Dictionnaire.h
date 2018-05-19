/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

#ifndef __DICTIONNAIRE__
#define __DICTIONNAIRE__

#include <stdio.h>

#include "Mot.h"
#include "BinaryTree.h"
#include "elementCollection.h"
#include "sousChaine.h"
#include "ouvrirFichier.h"
/** 
 *	\typedef D_Dictionnaire
 *	\struct AB_BinaryTree
 */
typedef struct D_Dictionnaire {	
	AB_BinaryTree aBRMots;
	int taille;
} D_Dictionnaire;

#define D_ERREUR_MEMOIRE 1
/**
 *	\fn D_Dictionnaire D_creerDictionnaire(); 
 *	\brief permet de creer un dictionnaire
 *	\return un D_Dictionnaire
 */
D_Dictionnaire D_creerDictionnaire(); 

/**
 *	\fn int D_estContenu (M_Mot *mot, D_Dictionnaire dictionnaire);
 *	\brief permet de savoir si un mot est contenu dans le dictionnaire
 *	\param *mot pointeur sur un mot
 *	\param D_Dictionnaire un dictionnaire de mots
 *	\return int
 */
int D_estContenu (M_Mot *mot, D_Dictionnaire dictionnaire);

/**
 *	\fn int D_taille (D_Dictionnaire dictionnaire);
 *	\brief permet d'obtenir la taille du dictionnaire
 *	\param dictionnaire un dictionnaire
 *	\return int
 */
int D_taille (D_Dictionnaire dictionnaire);

/**
 *	\fn void D_ajouter(M_Mot *mot, D_Dictionnaire *dictionnaire);
 *	\brief Permet d'ajouter un mot dans un dictionnaire
 *	\param *mot un pointeur sur un mot
 *	\param *dictionnaire un pointeur sur un dictionnaire
 *	\return void
 */
void D_ajouter(M_Mot *mot, D_Dictionnaire *dictionnaire);

/**
 *	\fn void D_retirer(M_Mot *mot, D_Dictionnaire *dictionnaire);
 *	\brief Permet de retirer un mot d'un dictionnaire
 *	\param *mot un pointeur sur un mot
 *	\param *dictionnaire un pointeur sur un dictionnaire
 *	\return void
 */
void D_retirer(M_Mot *mot, D_Dictionnaire *dictionnaire);

/**
 *	\fn int D_estVide(D_Dictionnaire *dictionnaire);
 *	\brief Permet de savoir si un dictionnaire est vide
 *	\param *dictionnaire un dictionnaire
 *	\return int
 */
int D_estVide(D_Dictionnaire *dictionnaire);

/**
 *	\fn int D_serialiser(D_Dictionnaire dictionnaire, FILE* fichierCible); 
 *	\brief ecrit le dictionnaire dans un fichier
 *	\param dictionnaire un dictionnaire
 *	\param *fichierCible un pointeur sur un fichier
 *	\return int
 */
int D_serialiser(D_Dictionnaire dictionnaire, FILE* fichierCible);
 
/**
 *	\fn D_Dictionnaire D_deserialiser(char *cheminFichier); 
 *	\brief lit le dico depuis un fichier
 *	\param *cheminFichier un pointeur sur le chemin du fichier
 *	\return D_Dictionnaire
 */
D_Dictionnaire D_deserialiser(char *cheminFichier); 

#endif

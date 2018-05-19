/* Alexandre DUVAL - 17/12/2014 */
/* Arthur Hamelin - 05/01/2015 */

/** \file transcoder.h
 *	\brief Contient la fonction qui permet de réécrire le dictionnaire en un format lisible pour la résolution de la Grille. But : obtenir un dictionnaire "sérialisé" que l'on appelle fichierIntelligent
 *	\version 1.0
 *	\date 05/01/2015
 */
 

#ifndef __TRANSCODER__
#define __TRANSCODER__

#include "ouvrirFichier.h"
#include "Dictionnaire.h"
#include "lireFichier.h"

/**
 *	\fn int transcoder(char *, char *)
 *	\brief récupère un fichier source.txt pour le ressortir en un format sérialisé de type arbre multiple.
 *	
 *	Pour la chaine de caractères "abaissables", le but de transcoder permet d'obtenir l'ensemble de mots "a","abaissa","baissa","abaissable",etc.
 *	\param * pointeur sur notre dictionnaire.txt de référence
 *	\param * pointeur sur notre dictionnaire.dat une fois sérialisé
 *	\return dictionnaire.dat
 */

int transcoder(char *, char *);

#endif

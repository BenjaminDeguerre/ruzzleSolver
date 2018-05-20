/* Alexandre DUVAL - 17/12/2014 */
/* Arthur Hamelin - 05/01/2015 */

/** \file transcode.h
 *	\brief Contient la fonction qui permet de réécrire le dictionary en un
 *format lisible pour la résolution de la Grid. But : get un dictionary
 *"sérialisé" que l'on appelle fileIntelligent
 *	\version 1.0
 *	\date 05/01/2015
 */

#ifndef __TRANSCODER__
#define __TRANSCODER__

#include "Dictionary.h"
#include "openFile.h"
#include "readFile.h"

/**
 *	\fn int transcode(char *, char *)
 *	\brief récupère un file source.txt pour le ressortir en un format
 *sérialisé de type arbre multiple.
 *
 *	Pour la string de caractères "abaissables", le but de transcode permet
 *d'get l'ensemble de mots "a","abaissa","baissa","abaissable",etc.
 *	\param * pointeur sur notre dictionary.txt de référence
 *	\param * pointeur sur notre dictionary.dat une fois sérialisé
 *	\return dictionary.dat
 */

int transcode(char *, char *);

#endif

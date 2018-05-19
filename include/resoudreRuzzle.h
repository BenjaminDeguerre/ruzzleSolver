/* Michel CRESSANT - 11/12/2014 */
/* Arthur Hamelin - 05/01/2015 */

/** \file resoudreRuzzle.h
 *	\brief Contient la fonction qui permet de lancer l'exécutable du projet dont le but est de résoudre une grille du jeu Ruzzle.
 *	\version 1.0
 *	\date 05/01/2015
 */
 
#ifndef __RESOUDRE_RUZZLE__
#define __RESOUDRE_RUZZLE__

#include "ListeChainee.h"
#include "Dictionnaire.h"
#include "Grille.h"
#include "creerGrilleAResoudre.h"
#include "resoudreGrille.h"

/**
 *	\fn LC_ListeChainee resoudreRuzzle(char *chaineGrille, char *cheminFichierIntelligent, float *tpsReel, float *tpsUtilisateur, float *tpsSysteme);

 *	\brief Renvoie une liste des mots disponibles sur la Grille dans l'ordre décroissant des points que chaque mot vaut.
 *	
 *	L'utilisateur rentre une chaine de caractère correspondant à la grille devant etre réslue, il rentre également le chemin d'accès du DictionnaireIntelligent. Cette fonction appelle  ensuite le reste des autres afin de renvoyer la réponse.
 *	\param *chaineGrille est un pointeur sur la chaine de caractère rentrée par l'utilisateur lors de l'appel de l'executable.
 *	\param *cheminFichierIntelligent est un pointeur sur le fichier intelligent Dico.dat contenant l'ensemble du dictionnaire sérialisé.
 *	\return LC_ListeChainee loSolutions
 */

LC_ListeChainee resoudreRuzzle(char *chaineGrille, char *cheminFichierIntelligent);

#endif

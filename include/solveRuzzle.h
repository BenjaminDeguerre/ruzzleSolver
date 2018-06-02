/* Michel CRESSANT - 11/12/2014 */
/* Arthur Hamelin - 05/01/2015 */

/** \file solveRuzzle.h
 *	\brief Contient la fonction qui permet de lancer l'exécutable du projet
 *dont le but est de résoudre une grid du jeu Ruzzle.
 *	\version 1.0
 *	\date 05/01/2015
 */

#ifndef __SOLVE_RUZZLE__
#define __SOLVE_RUZZLE__

/**
 *	\fn LL_LinkedList solveRuzzle(char *stringGrid, char
 *pathToIntelligentFile, float *tpsReel, float *tpsUtilisateur, float
 *tpsSysteme);

 *	\brief Renvoie une liste des mots disponibles sur la Grid dans l'ordre
 décroissant des points que chaque mot vaut.
 *
 *	L'utilisateur rentre une string de caractère correspondant à la grid
 devant etre réslue, il rentre également le chemin d'accès du
 DictionaryIntelligent. Cette fonction appelle  ensuite le reste des autres afin
 de renvoyer la réponse.
 *	\param *stringGrid est un pointeur sur la string de caractère rentrée
 par l'utilisateur lors de l'appel de l'executable.
 *	\param *pathToIntelligentFile est un pointeur sur le file intelligent
 Dico.dat contenant l'ensemble du dictionary sérialisé.
 *	\return LL_LinkedList listSolutions
 */

LL_LinkedList solveRuzzle(char *stringGrid, char *pathToIntelligentFile);

#endif

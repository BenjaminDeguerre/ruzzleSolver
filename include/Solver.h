#ifndef __SOLVER__
#define __SOLVER__

#include <string.h>

#include "Dictionary.h"
#include "Grid.h"
#include "LinkedList.h"

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

/**
 *	\typedef sG_Word
 *	\brief Contient un mot avec sa value en point dans la grid
 */
typedef struct sG_Word {
  char *word; /**< le mot */
  int point;  /**< Valeur en point du mot */
} sG_Word;

/**
 *	\fn	LL_LinkedList solveGrid(D_Dictionary dictionary, G_Grid
 *gridToSolve)
 *	\brief retourne une
 *	\param dic le dictionary contenant l'ensemble des mots possible
 *	\param gridToSolve la grid à solve
 *	\return LL_LinkedList
 */

LL_LinkedList solveGrid(D_Dictionary dictionary, G_Grid gridToSolve);

/**
 *	\fn G_Grid *squarereerGridAResoudre(char *stringParametersGrid)
 *	\brief Permet de create une grid
 *	\param *grid la grid dans laquelle se trouve la case (pointeur)
 *	\param *adjacentSquare les cases contigues (pointeur)
 *	\return LL_LinkedList
 */
G_Grid createGridToSolve(char *stringParametersGrid);
#endif
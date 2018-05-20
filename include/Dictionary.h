/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

#ifndef __DICTIONARY__
#define __DICTIONARY__

#include <stdio.h>

#include "BinaryTree.h"
#include "Word.h"
#include "elementCollection.h"
#include "openFile.h"
#include "subString.h"

/**
 *	\typedef D_Dictionary
 *	\struct BT_BinaryTree
 */
typedef struct D_Dictionary {
  BT_BinaryTree wordsBT;
  int size;
} D_Dictionary;

#define D_MEMORY_ERROR 1
/**
 *	\fn D_Dictionary D_createDictionary();
 *	\brief permet de create un dictionary
 *	\return un D_Dictionary
 */
D_Dictionary D_createDictionary();

/**
 *	\fn int D_wordIsIN (W_Word *word, D_Dictionary dictionarytionary);
 *	\brief permet de savoir si un mot est contenu dans le dictionary
 *	\param *word pointeur sur un mot
 *	\param D_Dictionary un dictionary de mots
 *	\return int
 */
int D_wordIsIN(W_Word *word, D_Dictionary dictionarytionary);

/**
 *	\fn int D_size (D_Dictionary dictionarytionary);
 *	\brief permet d'get la size du dictionary
 *	\param dictionary un dictionary
 *	\return int
 */
int D_size(D_Dictionary dictionarytionary);

/**
 *	\fn void D_add(W_Word *word, D_Dictionary *dictionary);
 *	\brief Permet d'add un mot dans un dictionary
 *	\param *word un pointeur sur un mot
 *	\param *dictionary un pointeur sur un dictionary
 *	\return void
 */
void D_add(W_Word *word, D_Dictionary *dictionary);

/**
 *	\fn void D_remove(W_Word *word, D_Dictionary *dictionary);
 *	\brief Permet de remove un mot d'un dictionary
 *	\param *word un pointeur sur un mot
 *	\param *dictionary un pointeur sur un dictionary
 *	\return void
 */
void D_remove(W_Word *word, D_Dictionary *dictionary);

/**
 *	\fn int D_isEmpty(D_Dictionary *dictionary);
 *	\brief Permet de savoir si un dictionary est vide
 *	\param *dictionary un dictionary
 *	\return int
 */
int D_isEmpty(D_Dictionary *dictionary);

/**
 *	\fn int D_serialize(D_Dictionary dictionarytionary, FILE* targetFile);
 *	\brief ecrit le dictionary dans un file
 *	\param dictionary un dictionary
 *	\param *targetFile un pointeur sur un file
 *	\return int
 */
int D_serialize(D_Dictionary dictionarytionary, FILE *targetFile);

/**
 *	\fn D_Dictionary D_unserialize(char *pathToFile);
 *	\brief lit le dictionary depuis un file
 *	\param *pathToFile un pointeur sur le chemin du file
 *	\return D_Dictionary
 */
D_Dictionary D_unserialize(char *pathToFile);

#endif

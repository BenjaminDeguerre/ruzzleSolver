#ifndef __DICTIONARY__
#define __DICTIONARY__

#include <stdio.h>

#include "BinaryTree.h"
#include "Word.h"

/**
 *	\typedef D_Dictionary
 *	\struct BT_BinaryTree
 *  \brief A dictionary is caracterised by its size and a binary tree.
 */
typedef struct D_Dictionary {
  BT_BinaryTree wordsBT;
  int size;
} D_Dictionary;

#define D_MEMORY_ERROR 1
/**
 *	\fn D_Dictionary D_createDictionary();
 *	\brief Function to create a dictionary.
 *	\return D_Dictionary
 */
D_Dictionary D_createDictionary();

/**
 *	\fn int D_wordIsIN (W_Word *word, D_Dictionary dictionary);
 *	\brief Tell if a word is in the dictionary or not.
 *	\param *word Pointer to the W_Word to check.
 *	\param dictionary The D_Dictionary to check.
 *	\return int
 */
int D_wordIsIN(W_Word *word, D_Dictionary dictionary);

/**
 *	\fn int D_size (D_Dictionary dictionary);
 *	\brief Getter for the dictionary size.
 *	\param dictionary The D_Dictionary to get the size from.
 *	\return int
 */
int D_size(D_Dictionary dictionary);

/**
 *	\fn void D_add(W_Word *word, D_Dictionary *dictionary);
 *	\brief Adds a word into the dictionary.
 *	\param *word A pointer to a W_Word to add.
 *	\param *dictionary A pointer to the dictionary to add the word to.
 *	\return void
 */
void D_add(W_Word *word, D_Dictionary *dictionary);

/**
 *	\fn void D_remove(W_Word *word, D_Dictionary *dictionary);
 *	\brief Remove a word from the dictionary.
 *	\param *word Pointer to the W_Word to remove.
 *	\param *dictionary The D_Dictionary to remove the word from.
 *	\return void
 */
void D_remove(W_Word *word, D_Dictionary *dictionary);

/**
 *	\fn int D_isEmpty(D_Dictionary *dictionary);
 *	\brief Tells if a dictionary is empty.
 *	\param *dictionary Pointer to the dictionary to check.
 *	\return int
 */
int D_isEmpty(D_Dictionary dictionary);

/**
 *	\fn int D_serialize(D_Dictionary dictionary, FILE* targetFile);
 *	\brief Serialize the dictionary to a file.
 *	\param dictionary The D_Dictionary to write.
 *	\param *targetFile A pointer to the name of the file to write the
 *dictionary to.
 *	\return int
 */
int D_serialize(D_Dictionary dictionary, FILE *targetFile);

/**
 *	\fn D_Dictionary D_unserialize(char *pathToFile);
 *	\brief Read a serialized dictionary from a file.
 *	\param *pathToFile Pointer to the file containing the serialized
 *dictionary.
 *	\return D_Dictionary
 */
D_Dictionary D_unserialize(char *pathToFile);

/**
 *	\fn D_Dictionary D_delete(D_Dictionary dictionary);
 *	\brief Delete a dictionary.
 *	\param dictionary The dictionary to delete.
 *	\return void
 */
void D_delete(D_Dictionary dictionary);

#endif

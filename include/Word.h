#ifndef __WORD__
#define __WORD__

/**
 *	\typedef W_Word
 *	\brief Structure for a word, string
 */
typedef struct {
  char *value;
} W_Word;

#define W_MEMORY_ERROR 1

/**
 *	\fn W_Word* W_createWord(char *value)
 *	\brief Create a new word.
 *	\param *value The string with the word.
 *	\return W_Word*
 */
W_Word *W_createWord(char *value);

/**
 *	\fn char* W_getString(W_Word word)
 *	\brief Return the string that represents the word.
 *	\param word The target word.
 *	\return char*
 */
char *W_getString(W_Word word);

/**
 *	\fn char W_getIthCharacter(W_Word word, int position)
 *	\brief Return the ith char of a word
 *
 *	\param word The target word.
 *	\param position The position of the letter.
 *	\return char
 */
char W_getIthCharacter(W_Word word, int position);

/**
 *	\fn int W_getLength(W_Word word)
 *	\brief Return the size of a word.
 *	\param word The target word.
 *	\return int
 */
int W_getLength(W_Word word);

/**
 *	\fn void* W_copy(W_Word* m)
 *	\brief Copy a word
 *	\param *word The word to copy.
 *	\return void*
 */
void *W_copy(void *word);

/**
 *	\fn void W_remove(W_Word *word)
 *	\brief Delete the word.
 *	\param *word The word to delete.
 *	\return void
 */
void W_delete(void *word);

/**
 *	\fn int W_compareString(W_Word *word1, W_Word *word2)
 *	\brief Compare two word using the alphabetical order.
 *
 *	\param *word1 The first word to compare.
 *	\param *word2 The second word to compare.
 *	\return int Return 0 if the word are equals, -1 if word1 < word2, 1
 *else.
 */
int W_compare(void *word1, void *word2);

#endif

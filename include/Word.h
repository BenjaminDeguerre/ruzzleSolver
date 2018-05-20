/* Alexandre DUVAL - 07/12/14 */
/* Alexandre DUVAL - 31/12/14 */

/** \file Word.h
 *	\brief Implémentation du TAD mot
 *	\version 1.0
 *	\date 02/01/2015
 */
#ifndef __WORD__
#define __WORD__

/**
 *	\typedef W_Word
 *	\brief	structure d'un mot, contient le mot et sa length
 */
typedef struct {
  char *value; /**< le mot */
  int length;  /**< la length du mot */
} W_Word;

#define W_MEMORY_ERROR 1

/**
 *	\fn W_Word* W_createWord(char *value)
 *	\brief Permet de create un new mot
 *	\param *value la string de caractère représentant le mot
 *	\return W_Word*
 */
W_Word *W_createWord(char *value);

/**
 *	\fn char* W_getString(W_Word word)
 *	\brief Permet d'get la string de caractère représentant le mot
 *	\param word le mot target
 *	\return char*
 */
char *W_getString(W_Word word);

/**
 *	\fn char W_getIthCharacter(W_Word word, int position)
 *	\brief Retourne le ieme caractère du mot
 *	\pre position > 0 && position < W_getLength(mot)
 *	\param word le mot target
 *	\param position La position de la lettre
 *	\return char
 */
char W_getIthCharacter(W_Word word, int position);

/**
 *	\fn int W_getLength(W_Word word)
 *	\brief Permet d'get la length d'un mot
 *	\param word le mot target
 *	\return int
 */
int W_getLength(W_Word word);

/* fonctions liees a l'utilisation du C et de l'allocation dynamique */
/**
 *	\fn void* W_copy(W_Word* m)
 *	\brief Permet de copy un mot
 *	\param *word le mot à copy (pointeur)
 *	\return void*
 */
void *W_copy(void *word);

/**
 *	\fn void W_remove(W_Word *wordyWord)
 *	\brief Permet d'effacer la value d'un mot
 *	\param *wordyWord le mot à effacer
 *	\return void
 */
void W_remove(void *word);

/**
 *	\fn void W_remove(W_Word *wordyWord)
 *	\brief Permet d'effacer un mot
 *	\param *wordyWord le mot à effacer
 *	\return void
 */
void W_delete(void *word);

/**
 *	\fn int W_compareString(W_Word *word1, W_Word *word2)
 *	\brief Permet de compare deux mot de façon lexicographique
 *
 *	renvoie 0 si les deux chaînes sont égales, un nombre positif si m1 est
 *lexicographiquement supérieure à m2, et un nombre négatif si m1 est
 *lexicographiquement inférieure à m2
 *	\param *word1 le premier mot à compare (pointeur)
 *	\param *word2 le deuxième mot à compare
 *	\return int
 */
int W_compareString(void *word1, void *word2);

/**
 *	\fn int W_compareString(W_Word *word1, W_Word *word2)
 *	\brief Permet de compare deux mot, vrai si égaux.
 *	\param *word1 le premier mot à compare (pointeur)
 *	\param *word2 le deuxième mot à compare
 *	\return int
 */
int W_compare(void *word1, void *word2);

#endif

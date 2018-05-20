/* Arthur Hamelin - 10/12/2014 */
/* Benjamin Deguerre - 26/12/2014 */

/** \file Square.h
 *	\brief Implémentation du TAD Square
 *	\version 1.0
 *	\date 26/12/2014
 */
#ifndef __SQUARE__
#define __SQUARE__

/** 
 *	\typedef S_SQUARE
 *	\brief Structure Square, contient une string de caractère ainsi que ça position dans la grille 
 */
typedef struct {
	char *value;	/**< string de caractère contenant la lettre, la value de la case et le bonus associé (dans cet ordre !) */
	int number; /**< integer représentant la position de la case dans la grille*/
} S_SQUARE;

#define S_MEMORY_ERROR 1

/** 
 *	\fn S_SQUARE S_createSquare()
 *	\brief Creer une case vide de toute value
 *
 *	La case est initialisée à NULL sur la string de caractère et 0 sur le no de case 
 *	\return S_SQUARE*
 */
S_SQUARE* S_createSquare();

/**
 *	\fn int S_isEmpty(S_SQUARE square)
 *	\brief Permet de savoir si une cae est vide ou non
 *
 *	retourne 1 si la case est vide, 0 sinon. Attention, la fonction ne regarde que si la string de caractère st a NULL ou non
 *	\param c la case
 *	\return int
 */
int S_isEmpty(S_SQUARE square);

/** 
 *	\fn char *S_getValue(S_SQUARE)
 *	\brief retourne la string de caractère complète de la case 
 *	\param c la case
 *	\return char*
 */
char* S_getValue(S_SQUARE square);

/** 
 *	\fn char S_getLetter(S_SQUARE square)
 *	\brief retourne la lettre contenue dans la case (première value de la string de caractère) 
 *	\param c la case
 *	\return char
 */
char S_getLetter(S_SQUARE square);

/** 
 *	\fn int S_getPosition(S_SQUARE square)
 *	\brief retourne la position de la case dans la grille 
 *	\param c la case
 *	\return int
 */
int S_getPosition(S_SQUARE square);

/** 
 *	\fn int S_getPointsNumber(S_SQUARE square)
 *	\brief retourne la value simple de la case, c'est à dire sans les bonus 
 *	\param c la case
 *	\return int
 */
int S_getPointsNumber(S_SQUARE square);

/** 
 *	\fn char *S_getBonus(S_SQUARE square)
 *	\brief retourne la string de caractère contenant les bonus 
 *
 *	Allocation avec malloc, un free sera nécéssaire
 *	\param c la case
 *	\return char*
 */
char *S_getBonus(S_SQUARE square);

/** 
 *	\fn S_SQUARE S_defineSquare(S_SQUARE square, char *value, int squareNumber)
 *	\brief permet de remplir la case avec les bonnes values 
 *	\param c la case
 *	\param *value, string de caractère contenant la lettre, la value de la case et le bonus associé
 *	\param squareNumber le numéro de la case
 *	\return void
 */
void S_defineSquare(S_SQUARE *square, char *value, int squareNumber);

/** 
 *	\fn void* S_copy(void* c)
 *	\brief fonction permettant de copy une case 
 *	
 *	appel de la fonction : var NewVar = S_copy(OldVar), la value de l'ancienne variable est copié dans la nouvelle, malloc est utilisé
 *	\param *square la case à copy (pointeur)
 *	\return void*
 */
void* S_copy(void *square);

/** 
 *	\fn void S_delete(void *square)
 *	\brief fonction permettant de delete une case et de libérer l'espace mémoire utilisé
 *	\param *square la case à delete (pointeur)
 *	\return void
 */
void S_delete(void *square);

/** 
 *	\fn S_compare(void *square1, void *square2)
 *	\brief fonction permettant de compare deux cases
 *	
 *	Deux cases sont égales quand elles ont la même value, ced même string de caractère 
 *	\param *square1 la première case à compare (pointeur)
 *	\param *square1 la deuxième case à compare (pointeur)
 *	\return int
 */
int S_compare(void *square1, void *square2);
#endif

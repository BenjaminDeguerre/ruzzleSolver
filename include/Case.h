/* Arthur Hamelin - 10/12/2014 */
/* Benjamin Deguerre - 26/12/2014 */

/** \file Case.h
 *	\brief Implémentation du TAD Case
 *	\version 1.0
 *	\date 26/12/2014
 */
#ifndef __CASE__
#define __CASE__

/** 
 *	\typedef C_Case
 *	\brief Structure Case, contient une chaine de caractère ainsi que ça position dans la grille 
 */
typedef struct {
	char *valeur;	/**< chaine de caractère contenant la lettre, la valeur de la case et le bonus associé (dans cet ordre !) */
	int no; /**< integer représentant la position de la case dans la grille*/
} C_Case;

#define C_ERREUR_MEMOIRE 1

/** 
 *	\fn C_Case C_creerCase()
 *	\brief Creer une case vide de toute valeur
 *
 *	La case est initialisée à NULL sur la chaine de caractère et 0 sur le no de case 
 *	\return C_Case*
 */
C_Case* C_creerCase();

/**
 *	\fn int C_estVide(C_Case c)
 *	\brief Permet de savoir si une cae est vide ou non
 *
 *	retourne 1 si la case est vide, 0 sinon. Attention, la fonction ne regarde que si la chaine de caractère st a NULL ou non
 *	\param c la case
 *	\return int
 */
int C_estVide(C_Case c);

/** 
 *	\fn char *C_obtenirValeur(C_Case)
 *	\brief retourne la chaine de caractère complète de la case 
 *	\param c la case
 *	\return char*
 */
char *C_obtenirValeur(C_Case c);

/** 
 *	\fn char C_obtenirLettre(C_Case c)
 *	\brief retourne la lettre contenue dans la case (première valeur de la chaine de caractère) 
 *	\param c la case
 *	\return char
 */
char C_obtenirLettre(C_Case c);

/** 
 *	\fn int C_obtenirPosition(C_Case c)
 *	\brief retourne la position de la case dans la grille 
 *	\param c la case
 *	\return int
 */
int C_obtenirPosition(C_Case c);

/** 
 *	\fn int C_obtenirNombrePoints(C_Case c)
 *	\brief retourne la valeur simple de la case, c'est à dire sans les bonus 
 *	\param c la case
 *	\return int
 */
int C_obtenirNombrePoints(C_Case c);

/** 
 *	\fn char *C_obtenirBonus(C_Case c)
 *	\brief retourne la chaine de caractère contenant les bonus 
 *
 *	Allocation avec malloc, un free sera nécéssaire
 *	\param c la case
 *	\return char*
 */
char *C_obtenirBonus(C_Case c);

/** 
 *	\fn C_Case C_definirCase(C_Case c, char *valeur, int noCase)
 *	\brief permet de remplir la case avec les bonnes valeurs 
 *	\param c la case
 *	\param *valeur, chaine de caractère contenant la lettre, la valeur de la case et le bonus associé
 *	\param noCase le numéro de la case
 *	\return void
 */
void C_definirCase(C_Case *c, char *valeur, int noCase);

/** 
 *	\fn void* C_copier(void* c)
 *	\brief fonction permettant de copier une case 
 *	
 *	appel de la fonction : var NewVar = C_copier(OldVar), la valeur de l'ancienne variable est copié dans la nouvelle, malloc est utilisé
 *	\param *c la case à copier (pointeur)
 *	\return void*
 */
void* C_copier(void *c);

/** 
 *	\fn void C_supprimer(void *c)
 *	\brief fonction permettant de supprimer une case et de libérer l'espace mémoire utilisé
 *	\param *c la case à supprimer (pointeur)
 *	\return void
 */
void C_supprimer(void *c);

/** 
 *	\fn C_comparer(void *c1, void *c2)
 *	\brief fonction permettant de comparer deux cases
 *	
 *	Deux cases sont égales quand elles ont la même valeur, ced même chaine de caractère 
 *	\param *c1 la première case à comparer (pointeur)
 *	\param *c1 la deuxième case à comparer (pointeur)
 *	\return int
 */
int C_comparer(void *c1, void *c2);
#endif

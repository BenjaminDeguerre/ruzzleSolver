/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

/** \file Noeud.h
 *	\brief Implémentation du TAD Noeud
 *	\version 1.0
 *	\date 28/12/2014
 */
 
#ifndef __NOEUD__
#define __NOEUD__

/**
 *	\typedef N_Noeud
 *	\brief contient une valeur char et un booleen pour indique si il est le dernier noeud  d'une suite de noeud
 */
typedef struct {	
	char valeur; /**< valeur du noeud, une chaine de caractères*/
	int estFin;	/**< booleen indiquant si le noeud est fin ou non d'une suite de noeuds*/
} N_Noeud;

#define N_ERREUR_MEMOIRE 1
/**
 *	\fn N_Noeud N_creerNoeud(int, char)
 *	\brief Créer un noeud et l'initialise sur les valeurs estFin et valeur
 *	\param estFin int donnant la valeur de finalité du noeud
 *	\param valeur char, valeur du noeud 
 *	\return N_Noeud*
 */
N_Noeud *N_creerNoeud(int estFin, char valeur);

/**
 *	\fn int N_estFin(N_Noeud n)
 *	\brief Renvoit un int définissant la finalité d'un noeus=d
 *	\param n le noeud cible
 *	\return int
 */
int N_estFin(N_Noeud n);

/**
 *	\fn void N_definirValeur(N_Noeud *n, char *valeur)
 *	\brief Permet de définir la valeur d'un noeud
 *	\param *n le noeud dont on veut changer la valeur (pointeur)
 *	\param valeur la nouvelle valeur du noeud
 *	\return void
 */
void N_definirValeur(N_Noeud *n, char valeur);

/**
 *	\fn void N_definirFin(N_Noeud *n, int estFin)
 *	\brief Permet de défnir la valeur de estFin
 *	\param *n le noeud dont on veut changer la valeur de estFin (pointeur)
 *	\param estFin la nouvelle valeur de estFin du noeud
 *	\return void
 */
void N_definirFin(N_Noeud *n, int estFin);

/**
 *	\fn N_obtenirValeur(N_Noeud n)
 *	\brief	Permet d'obtenir la valeur d'un noeud 
 *	\param	n le noeud cible
 *	\return char
 */
char N_obtenirValeur(N_Noeud n);

/**
 *	\fn void libererNoeud(N_Noeud *n)
 *	\brief Permet de libérer l'espace mémoire occupé par un noeud
 *	\param *n le noeud à libérer
 *	\return void
 */
void N_liberer(void *n);

/**
 *	\fn N_copier(N_Noeud*)
 *	\brief Permet de faire la copie d'un noeud (retourne le noeud sous le type void*, à transtyper)
 *
 *	match avec les typedef de élements collection
 *	\param *n le noeud à copier
 *	\return void*
 */
void* N_copier(void *n);

/**
 *	\fn N_comparer(N_Noeud*, N_Noeud*)
 *	\brief Compare deux noeuds. Ne compare que les chaines de caractères des deux noeuds
 *
 *	retourne 0 si les deux noeuds sont égaux, un nombre positif si la chaine de caractère de n1 est lexicographiquement supérieure à celle de n2, un nombre négatif sinon
 *	\param *n1 le premier noeud à comparer (pointeur)
 *	\param *n2 le deuxième noeud à comparer (pointeur)
 *	\return int
 */
int N_comparer(void *n1, void *n2);

#endif

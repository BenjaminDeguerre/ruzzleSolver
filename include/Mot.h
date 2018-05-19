/* Alexandre DUVAL - 07/12/14 */
/* Alexandre DUVAL - 31/12/14 */

/** \file Mot.h
 *	\brief Implémentation du TAD mot
 *	\version 1.0
 *	\date 02/01/2015
 */
#ifndef __MOT__
#define __MOT__

/**
 *	\typedef M_Mot
 *	\brief	structure d'un mot, contient le mot et sa longueur
 */
typedef struct {
  char *valeur; /**< le mot */
  int longueur; /**< la longueur du mot */
} M_Mot;

#define M_ERREUR_MEMOIRE 1

/**
 *	\fn M_Mot* M_creerMot(char *valeur)
 *	\brief Permet de creer un nouveau mot
 *	\param *valeur la chaine de caractère représentant le mot
 *	\return M_Mot*
 */
M_Mot* M_creerMot(char *valeur);

/**
 *	\fn char* M_obtenirChaine(M_Mot monMot)
 *	\brief Permet d'obtenir la chaine de caractère représentant le mot
 *	\param monMot le mot cible
 *	\return char*
 */
char* M_obtenirChaine(M_Mot monMot);

/**
 *	\fn char M_obtenirIemeCaractere(M_Mot monMot, int position)
 *	\brief Retourne le ieme caractère du mot
 *	\pre position > 0 && position < M_obtenirLongueur(mot)
 *	\param monMot le mot cible
 *	\param position La position de la lettre
 *	\return char
 */
char M_obtenirIemeCaractere(M_Mot monMot, int position);

/**
 *	\fn int M_obtenirLongueur(M_Mot monMot)
 *	\brief Permet d'obtenir la longueur d'un mot
 *	\param monMot le mot cible
 *	\return int
 */
int M_obtenirLongueur(M_Mot monMot);

/* fonctions liees a l'utilisation du C et de l'allocation dynamique */
/**
 *	\fn void* M_copier(M_Mot* m)
 *	\brief Permet de copier un mot
 *	\param *m le mot à copier (pointeur)
 *	\return void*
 */
void* M_copier(void *m);

/**
 *	\fn void M_effacer(M_Mot *monMot)
 *	\brief Permet d'effacer la valeur d'un mot
 *	\param *monMot le mot à effacer 
 *	\return void
 */
void M_effacer(void *unMot);

/**
 *	\fn void M_effacer(M_Mot *monMot)
 *	\brief Permet d'effacer un mot 
 *	\param *monMot le mot à effacer 
 *	\return void
 */
void M_supprimer(void *unMot);

/**
 *	\fn int M_comparerStr(M_Mot *m1, M_Mot *m2)
 *	\brief Permet de comparer deux mot de façon lexicographique
 *	
 *	renvoie 0 si les deux chaînes sont égales, un nombre positif si m1 est lexicographiquement supérieure à m2, et un nombre négatif si m1 est lexicographiquement inférieure à m2
 *	\param *m1 le premier mot à comparer (pointeur)
 *	\param *m2 le deuxième mot à comparer
 *	\return int
 */
int M_comparerStr(void *m1, void *m2);

/**
 *	\fn int M_comparerStr(M_Mot *m1, M_Mot *m2)
 *	\brief Permet de comparer deux mot, vrai si égaux.
 *	\param *m1 le premier mot à comparer (pointeur)
 *	\param *m2 le deuxième mot à comparer
 *	\return int
 */
int M_comparer(void *m1, void *m2);

#endif

/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 02/01/2015 */

#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "BinaryTree.h"

AB_BinaryTree AB_creerABR() {
	AB_BinaryTree abr = NULL;
	return abr; 
}

int AB_estVide(AB_BinaryTree a) {
	return a == NULL;
}

void AB_fixerFilsGauche(AB_BinaryTree *a, AB_BinaryTree filsGauche) {
	assert(!AB_estVide(*a));
	(*a)->sAG = filsGauche;
}

void AB_fixerFilsDroit(AB_BinaryTree *a, AB_BinaryTree filsDroit) {
	assert(!AB_estVide(*a));
	(*a)->sAD = filsDroit;
}

void AB_fixerEstTraite(AB_BinaryTree *a, int b) {
	assert(!AB_estVide(*a));
	(*a)->estTraite = b;
}

int AB_estTraite(AB_BinaryTree *a) {
	assert(!AB_estVide(*a));
	return (*a)->estTraite;
}

AB_BinaryTree AB_ajouterRacine(AB_BinaryTree filsGauche, AB_BinaryTree filsDroit, N_Noeud *noeud, EC_copier copier) {	
	AB_BinaryTree a = (AB_BinaryTree)malloc(sizeof(AB_Noeud));
	N_Noeud* racine = (N_Noeud *)copier(noeud);
	if((noeud != NULL) || (a != NULL)) {
		errno = 0;
 
		a->racine = racine;     
		a->sAG = filsGauche;
		a->sAD = filsDroit;
		a->estTraite = 0;

		return a;	
	} else  {
		errno = AB_ERREUR_MEMOIRE;
		return AB_creerABR();
	}
}

N_Noeud* AB_obtenirRacine(AB_BinaryTree abr) {
	assert(!AB_estVide(abr));
	return abr->racine;
}

void AB_supprimerRacine(AB_BinaryTree* a, AB_BinaryTree* sAG, AB_BinaryTree* sAD, EC_supprimer libererNoeud) {
	*sAG = AB_obtenirFilsGauche(*a);
	*sAD = AB_obtenirFilsDroit(*a);

	libererNoeud(AB_obtenirRacine(*a));
	*a = NULL;
	free(*a);
}

void AB_supprimer(AB_BinaryTree* a, EC_supprimer libererNoeud) {
	AB_BinaryTree sAG = AB_creerABR();
	AB_BinaryTree sAD = AB_creerABR();

	if(!(AB_estVide(*a))) {
		AB_supprimerRacine(a, &sAG, &sAD, libererNoeud);
		AB_supprimer(&sAG, libererNoeud);
		AB_supprimer(&sAD, libererNoeud);
	}
}

AB_BinaryTree AB_obtenirFilsDroit(AB_BinaryTree a) {
	assert(!AB_estVide(a));
	return a->sAD;	
}

AB_BinaryTree AB_obtenirFilsGauche(AB_BinaryTree a) {
	assert(!AB_estVide(a));
	return a->sAG;
}

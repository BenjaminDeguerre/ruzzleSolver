/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 02/01/2015 */

#include <stdlib.h>
#include <errno.h>
#include <assert.h>

#include "BinaryTreeDeRecherche.h"

ABR_BinaryTreeDeRecherche ABR_creerABR() {
	ABR_BinaryTreeDeRecherche abr = NULL;
	return abr; 
}

int ABR_estVide(ABR_BinaryTreeDeRecherche a) {
	return a == NULL;
}

void ABR_fixerFilsGauche(ABR_BinaryTreeDeRecherche *a, ABR_BinaryTreeDeRecherche filsGauche) {
	assert(!ABR_estVide(*a));
	(*a)->sAG = filsGauche;
}

void ABR_fixerFilsDroit(ABR_BinaryTreeDeRecherche *a, ABR_BinaryTreeDeRecherche filsDroit) {
	assert(!ABR_estVide(*a));
	(*a)->sAD = filsDroit;
}

void ABR_fixerEstTraite(ABR_BinaryTreeDeRecherche *a, int b) {
	assert(!ABR_estVide(*a));
	(*a)->estTraite = b;
}

int ABR_estTraite(ABR_BinaryTreeDeRecherche *a) {
	assert(!ABR_estVide(*a));
	return (*a)->estTraite;
}

ABR_BinaryTreeDeRecherche ABR_ajouterRacine(ABR_BinaryTreeDeRecherche filsGauche, ABR_BinaryTreeDeRecherche filsDroit, N_Noeud *noeud, EC_copier copier) {	
	ABR_BinaryTreeDeRecherche a = (ABR_BinaryTreeDeRecherche)malloc(sizeof(ABR_Noeud));
	N_Noeud* racine = (N_Noeud *)copier(noeud);
	free(noeud);

	if((racine != NULL) || (a != NULL)) {
		errno = 0;
		
		a->racine = racine;
		a->sAG = filsGauche;
		a->sAD = filsDroit;
		a->estTraite = 0;

		return a;
	} else  {
		errno = ABR_ERREUR_MEMOIRE;
		return ABR_creerABR();
	}
}

N_Noeud* ABR_obtenirRacine(ABR_BinaryTreeDeRecherche abr) {
	assert(!ABR_estVide(abr));
	return abr->racine;
}

void ABR_supprimerRacine(ABR_BinaryTreeDeRecherche* a, ABR_BinaryTreeDeRecherche* sAG, ABR_BinaryTreeDeRecherche* sAD, EC_supprimer libererNoeud) {
	*sAG = ABR_obtenirFilsGauche(*a);
	*sAD = ABR_obtenirFilsDroit(*a);

	libererNoeud(ABR_obtenirRacine(*a));
	*a = NULL;
	free(*a);
}

void ABR_supprimer(ABR_BinaryTreeDeRecherche* a, EC_supprimer libererNoeud) {
	ABR_BinaryTreeDeRecherche sAG = ABR_creerABR();
	ABR_BinaryTreeDeRecherche sAD = ABR_creerABR();

	if(!(ABR_estVide(*a))) {
		ABR_supprimerRacine(a, &sAG, &sAD, libererNoeud);
		ABR_supprimer(&sAG, libererNoeud);
		ABR_supprimer(&sAD, libererNoeud);
	}
}

ABR_BinaryTreeDeRecherche ABR_obtenirFilsDroit(ABR_BinaryTreeDeRecherche a) {
	assert(!ABR_estVide(a));
	return a->sAD;	
}

ABR_BinaryTreeDeRecherche ABR_obtenirFilsGauche(ABR_BinaryTreeDeRecherche a) {
	assert(!ABR_estVide(a));
	return a->sAG;
}

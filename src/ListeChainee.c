/* Arthur Hamelin - 10/12/2014 */
/* Alexandre DUVAL - 22/12/2014 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ListeChainee.h"
#include <stdio.h>

/*#define NDEBUG */
//  decommenter pour annuler les tests
//  de precondition

/* private */
void LC_supprimerR(LC_ListeChainee* lO, EC_supprimer libererElement){
	errno = 0;
	if (!LC_estVide(*lO)) {
		LC_supprimerTete(lO, libererElement);
		LC_supprimerR(lO, libererElement);
	}
}

/* public */
LC_ListeChainee LC_creerListeChainee() {
	errno = 0;
	LC_ListeChainee pNoeud = (LC_ListeChainee)malloc(sizeof(LC_Noeud));
	if (pNoeud != NULL){
		pNoeud->element = NULL;
		pNoeud->listeChaineeSuivante = NULL;
	} else {
		errno = LOE_ERREUR_MEMOIRE;
	}
	return pNoeud;
}

int LC_elementEstNull(LC_ListeChainee lO) {
	errno = 0;
	return lO->element == NULL;
}

int LC_listeSuivanteEstNull(LC_ListeChainee lO) {
	errno = 0;
	return lO->listeChaineeSuivante == NULL;
}

int LC_estVide(LC_ListeChainee lO) {
	errno = 0;
	return (lO->element == NULL) && (lO->listeChaineeSuivante == NULL);
}

void LC_ajouter(LC_ListeChainee* lO, void* source, EC_copier copierElement) {
	LC_ListeChainee pNoeud = (LC_ListeChainee)malloc(sizeof(LC_Noeud));
	void* donnee = copierElement(source);
	if ((pNoeud != NULL) || (donnee != NULL)) {
		errno = 0;

		pNoeud->element = donnee;
		pNoeud->listeChaineeSuivante = *lO;

		*lO = pNoeud;
	} else {
		errno = LOE_ERREUR_MEMOIRE;
	}
}

void* LC_obtenirElement(LC_ListeChainee lO) {
	assert(!LC_estVide(lO));
	errno = 0;
	return lO->element;
}

LC_ListeChainee LC_obtenirListeSuivante(LC_ListeChainee lO) {
	assert(!LC_estVide(lO));
	errno = 0;
	return lO->listeChaineeSuivante;
}

void LC_fixerListeSuivante(LC_ListeChainee *lO, LC_ListeChainee lOS) {
	assert(!LC_estVide(*lO));
	errno = 0;
	(*lO)->listeChaineeSuivante = lOS;
}

void LC_fixerElement(LC_ListeChainee* lO, void* source, EC_copier copierElement, EC_supprimer libererElement) {
	assert(!LC_estVide(*lO));
	errno = 0;

	void* donnee = copierElement(source);

	if (donnee != NULL) {
		if ((*lO)->element != NULL){
			libererElement((*lO)->element);
		}
		(*lO)->element = donnee;
	} else {
		errno = LOE_ERREUR_MEMOIRE;
	}
}

void LC_supprimerTete(LC_ListeChainee *lO, EC_supprimer libererElement) {
	LC_ListeChainee tmp;

	assert(!LC_estVide(*lO));

	errno = 0;

	libererElement((void*)LC_obtenirElement(*lO));
	tmp = LC_obtenirListeSuivante(*lO);
	free(*lO);
	*lO = tmp;

}

void LC_supprimer(LC_ListeChainee* lO, EC_supprimer libererElement) {

	errno = 0;
	LC_supprimerR(lO, libererElement);
	free(*lO);

}

LC_ListeChainee LC_copier(LC_ListeChainee lO, EC_copier copierElement) {
	LC_ListeChainee tmp;

	errno = 0;

	if (LC_estVide(lO)){
		return LC_creerListeChainee();
	} else {
		tmp = LC_copier(LC_obtenirListeSuivante(lO), copierElement);
		LC_ajouter(&tmp, LC_obtenirElement(lO), copierElement);

		return tmp;
	}
}

int LC_egales(LC_ListeChainee lO1, LC_ListeChainee lO2, EC_comparer comparerElement) {
	errno = 0;

	if (LC_estVide(lO1) && LC_estVide(lO2)) {
		return 1;
	} else {
		if (LC_estVide(lO1) || LC_estVide(lO2)) {
			return 0;
		} else {
			if (comparerElement(LC_obtenirElement(lO1), LC_obtenirElement(lO2))) {
				return LC_egales(LC_obtenirListeSuivante(lO1), LC_obtenirListeSuivante(lO2), comparerElement);
			} else {
				return 0;
			}
		}
	}

	return 0;
}

int LC_longueur(LC_ListeChainee lO) {
	if (LC_listeSuivanteEstNull(lO)) {
		return 0;
	} else {
		return (LC_longueur(LC_obtenirListeSuivante(lO)) + 1);
	}
}

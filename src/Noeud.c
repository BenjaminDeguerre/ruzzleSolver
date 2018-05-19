/* Arthur Hamelin - 10/12/2014 */
/* Benjamin Deguerre - 28/12/2014 */

#include <errno.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "Noeud.h"

/* fonctions privées */
int N_egal(N_Noeud n1, N_Noeud n2) {
	if (n1.valeur < n2.valeur) {
		return -1;
	} else if (n1.valeur == n2.valeur) {
		return 0;
	} else {
		return 1;
	}
}

/* fonctions publiques */
N_Noeud *N_creerNoeud(int estFin, char valeur) {
	N_Noeud *n = (N_Noeud*)malloc(sizeof(N_Noeud));
	
	if (n != NULL) {
		n->estFin = estFin;
		n->valeur = valeur; 
	
		return n;
	} else {
		errno = N_ERREUR_MEMOIRE;
		exit(errno);
	}
}

int N_estFin(N_Noeud n) {
	return n.estFin;
}

void N_definirValeur(N_Noeud *n, char valeur) {
	n->valeur = valeur;
}

void N_definirFin(N_Noeud *n, int estFin) {
	n->estFin = estFin;
} 

char N_obtenirValeur(N_Noeud n) {
	return n.valeur;
}

void N_liberer(void *n) {
	free(n);
}

void* N_copier(void *n) {
  //N_Noeud *res;
	//res->estFin = N_estFin(*((N_Noeud*)n));
	//res->valeur = N_obtenirValeur(*((N_Noeud*)n));
	N_Noeud *res = N_creerNoeud(N_estFin(*((N_Noeud*)n)),N_obtenirValeur(*((N_Noeud*)n)));
	/*memcpy((void *) res, n, sizeof(N_Noeud));*/
	return (void *)res;
}

int N_comparer(void *n1, void *n2) {
	return N_egal(*(N_Noeud *) n1, *(N_Noeud *) n2);
}

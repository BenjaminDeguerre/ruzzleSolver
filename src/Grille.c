#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#include "Grille.h"

G_Grille G_creerGrille(char *tabParams[G_TAILLE]) {

	G_Grille grille;
	C_Case *c = C_creerCase();
	int i;

	for (i = 0; i < G_TAILLE; i++) {
		C_definirCase(c, tabParams[i], i);
		grille.tabCases[i] = *c;
	}

	C_supprimer(c);
	return grille;
}

C_Case G_obtenirCase(G_Grille g, int noCase) {
	return g.tabCases[noCase];
}

LC_ListeChainee G_obtenirVoisins(G_Grille g, C_Case c) {

	int noCase = C_obtenirPosition(c);
	LC_ListeChainee lC = LC_creerListeChainee();
	int voisins[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
	int i;
	C_Case *voisin = C_creerCase();
	if (noCase % 4 == 0){ //left column of the grid
		voisins[1] = noCase - G_COTE;
		voisins[2] = noCase - G_COTE + 1;
		voisins[4] = noCase + 1;
		voisins[6] = noCase + G_COTE;
		voisins[7] = noCase + G_COTE + 1;
	} else if ((noCase+1 % 4) == 0) { // 0 is excluded thanks to the first if (right column of the grid)
		voisins[0] = noCase - G_COTE - 1;
		voisins[1] = noCase - G_COTE;
		voisins[3] = noCase - 1;
		voisins[5] = noCase + G_COTE - 1;
		voisins[6] = noCase + G_COTE;
	} else {
		voisins[0] = noCase - G_COTE - 1;
		voisins[1] = noCase - G_COTE;
		voisins[2] = noCase - G_COTE + 1;
		voisins[3] = noCase - 1;
		voisins[4] = noCase + 1;
		voisins[5] = noCase + G_COTE - 1;
		voisins[6] = noCase + G_COTE;
		voisins[7] = noCase + G_COTE + 1;
	}

	for (i = 0; i < 8; i++) {
		if ((voisins[i] >= 0) && (voisins[i] < G_TAILLE)) {
			*voisin = G_obtenirCase(g, voisins[i]);
			LC_ajouter(&lC, voisin, C_copier);
		}
	}
	C_supprimer(voisin);
	return lC;
}

void G_supprimerGrille(G_Grille g){
	int i;
	for (i=0; i<G_TAILLE ; i++){
		free(C_obtenirValeur(G_obtenirCase(g, i)));
	}
}

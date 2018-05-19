#include <string.h>
#include <assert.h>

#include "creerGrilleAResoudre.h"

G_Grille creerGrilleAResoudre(char *chParametresGrille) {

	assert(strlen(chParametresGrille) == (G_TAILLE * 4)); /* 16 fois (CARACTERE + 3*space)*/
	char* tabParams[G_TAILLE];
	int i;
	for (i = 0; i < G_TAILLE; i++) {
		tabParams[i] = sousChaine(chParametresGrille, i*G_COTE, i*G_COTE + G_COTE-1);
	}
	return G_creerGrille(tabParams);
}

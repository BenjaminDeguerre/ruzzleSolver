#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include "Case.h"

/* #define NDEBUG
   decommenter pour annuler les tests
   de precondition
*/


/* partie publique */
C_Case* C_creerCase() {
	C_Case *c = malloc(sizeof(C_Case));
	c->no = 0;
	c->valeur = NULL;
 	return c;
}

int C_estVide(C_Case c){
	errno = 0;
	return (c.valeur == NULL);
}

char *C_obtenirValeur(C_Case c) {
	return c.valeur;
}

char C_obtenirLettre(C_Case c) {
	assert(!C_estVide(c));
	return c.valeur[0];
}

int C_obtenirPosition(C_Case c) {
	assert( ! C_estVide(c) );
	return c.no ;
}

int C_obtenirNombrePoints(C_Case c) {
	assert( !C_estVide(c) );
	return c.valeur[1] ;
}

char *C_obtenirBonus(C_Case c) {
	assert( !C_estVide(c) );

	char *bonus = (char *)malloc(sizeof(char) * 3);

	/*if (bonus == NULL) {
   		errno = 1;
    	exit(errno);
	}*/

	bonus[0] = c.valeur[2];
	bonus[1] =  c.valeur[3];
	bonus[2] = '\0';

	return bonus;
}

void C_definirCase(C_Case *c, char *valeur, int noCase) {
	assert(strlen(valeur) == 4);
	assert(noCase >= 0);

	c->no = noCase;
	c->valeur = valeur;

}

void* C_copier(void* c) {
	C_Case *resultat = C_creerCase();
	memcpy((void*)resultat, (const void*)c, sizeof(C_Case));
	return (void*)resultat;
}

void C_supprimer(void *c){
	free(c);
}

int C_comparer(void *c1, void *c2){
	if (strcmp(C_obtenirValeur(*(C_Case*)c1), C_obtenirValeur(*(C_Case*)c2)) == 0){
		return 1;
	}
	else{
		return 0;
	}
}

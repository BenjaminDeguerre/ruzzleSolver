/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 17/12/2014 */

#include "resoudreRuzzle.h"
#include "lireFichier.h"
#include "ouvrirFichier.h"

#include <assert.h>
#include <string.h>

#define NB_CASES G_TAILLE

LC_ListeChainee resoudreRuzzle(char *chaineGrille, char *cheminFichierIntelligent) {

	G_Grille grilleAResoudre;
	D_Dictionnaire d;
	LC_ListeChainee loSolutions;
	
	assert(strlen(cheminFichierIntelligent) >= 4); /* .dat */

	FILE* fichierEntree = fopen(cheminFichierIntelligent, "r+");

	grilleAResoudre = creerGrilleAResoudre(chaineGrille);
	d = D_deserialiser(cheminFichierIntelligent);
	loSolutions = resoudreGrille(d, grilleAResoudre);

	return loSolutions;
}

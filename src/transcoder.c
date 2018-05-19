/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

#include "transcoder.h"

int transcoder(char *source, char *cible) {
	FILE *fichierEntree, *fichierSortie;

	fichierEntree = ouvrirFichier(source, "r+");
	fichierSortie = ouvrirFichier(cible, "w");

	return (D_serialiser(lireFichier(fichierEntree), fichierSortie) == 0);
}

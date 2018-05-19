/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 17/12/2014 */

#include "ouvrirFichier.h"

FILE* ouvrirFichier(char *nomFichier, char *modeFichier) {
  FILE * fichier;
  
  fichier = fopen(nomFichier, modeFichier);

  if (fichier == NULL) {
    fprintf(stderr, "\tERREUR : impossible d'ouvrir %s, verifiez l'existence du fichier et ses droits.\n\t (ouvrirFichier.c)\n", nomFichier);
    exit(1);
  }

  return fichier;
}
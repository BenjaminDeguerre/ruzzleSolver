/* Alexandre DUVAL - 06/12/14 */
/* Alexandre DUVAL - 13/12/14 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "resoudreRuzzle.h"


int main(int argc, char** argv) {

  // Test values, uncomment to avoid re-entering everything each time when testing
  argv[1] = "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
  argv[2] = "dico.dat";
  LC_ListeChainee lSolutions = resoudreRuzzle(argv[1], argv[2]);
  char *tabValeur[LC_longueur(lSolutions)+1];
  int taille = LC_longueur(lSolutions);
  printf("%d solutions\n", taille);
  for (int i = 0 ; i < taille; i++){
    tabValeur[i]=(char*)LC_obtenirElement(lSolutions);
    printf("%s\n", tabValeur[i] );
    lSolutions = LC_obtenirListeSuivante(lSolutions);
  }

  return EXIT_SUCCESS;
}

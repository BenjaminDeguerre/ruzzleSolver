/* Alexandre DUVAL - 07/12/14 */
/* Alexandre DUVAL - 31/12/14 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#include "Mot.h"

/* #define NDEBUG 
   decommenter pour annuler les tests
   de precondition
*/

/* fonctions privées */
char* minuscule(char *chaine) {
  char *res = (char *)malloc(sizeof(char) * strlen(chaine)+1);
  int i;
  for (i = 0 ; chaine[i] != '\0' ; i++) {
    if (chaine[i] < 97) {
      res[i] = tolower(chaine[i]);
    } else {
      res[i] = chaine[i];
    }
  }
  res[i]='\0';
  return res; 
}

/* partie publique */
M_Mot* M_creerMot(char *valeur) {
  M_Mot *mot = malloc(sizeof(M_Mot));
  
  errno = 0;

  mot->longueur = strlen(valeur);
  mot->valeur = minuscule(valeur);  //(char *)malloc(sizeof(char) * strlen(valeur)+1);
  
  if (mot->valeur == NULL) {
    errno = M_ERREUR_MEMOIRE;
    exit(errno);
  }
   
  //mot->valeur = 
	
  return mot;
}

char* M_obtenirChaine(M_Mot mot) {
  return mot.valeur;
}

char M_obtenirIemeCaractere(M_Mot mot, int position) {
  assert(position >= 0);
  assert(position < M_obtenirLongueur(mot));

  return mot.valeur[position];
}

int M_obtenirLongueur(M_Mot mot) {
  return mot.longueur;
}

void* M_copier(void* m) {
  M_Mot* resultat = M_creerMot(M_obtenirChaine(*(M_Mot*)m)); //(M_Mot*)malloc(sizeof(M_Mot));
  //memcpy((void*)resultat, (const void*)m, sizeof(M_Mot));
  return (void*)resultat ;
}

void M_effacer(void *unMot) {
  free(((M_Mot*)unMot)->valeur);  
  ((M_Mot*)unMot)->valeur = NULL;
}

void M_supprimer(void *unMot) {
  free(((M_Mot*)unMot)->valeur);  
  free(unMot);
}

int M_comparerStr(void *m1, void *m2) {
  return strcmp(M_obtenirChaine(*(M_Mot*)m1), M_obtenirChaine(*(M_Mot*)m2));
}

int M_comparer(void *m1, void *m2) {
  return (strcmp(M_obtenirChaine(*(M_Mot*)m1), M_obtenirChaine(*(M_Mot*)m2)) == 0);
}

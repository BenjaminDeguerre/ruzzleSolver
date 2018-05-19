/* Arthur HAMELIN - 10/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdio.h>

#include "Dictionnaire.h"

/* fonctions privees */
M_Mot* reduire(M_Mot m) {
  if (M_obtenirLongueur(m) == 1) {
    return M_creerMot("");
  } else {
    char *maChaine = sousChaine(M_obtenirChaine(m), 1, M_obtenirLongueur(m)-1);
    M_Mot *mot = M_creerMot(maChaine);
    free(maChaine);
    return mot;
  }
}

void inserer(M_Mot *m, AB_BinaryTree *a) {
  AB_BinaryTree aBRAux;
  AB_BinaryTree tmp;
  N_Noeud *n;
  M_Mot *mAux;
	
  if (M_obtenirLongueur(*m) > 0) {
    mAux = reduire(*m); // enleve le premier char du mot
    if (AB_estVide(*a)) {
      n = N_creerNoeud(M_obtenirLongueur(*m) == 1, M_obtenirIemeCaractere(*m, 0));
      *a = AB_ajouterRacine(AB_creerABR(), AB_creerABR(), n, (EC_copier) N_copier);
      tmp = AB_obtenirFilsGauche(*a);
      inserer(mAux, &tmp);
      if (!AB_estVide(tmp)) {
	AB_fixerFilsGauche(a, tmp);
      }
    } else {
      if (M_obtenirIemeCaractere(*m, 0) > N_obtenirValeur(*AB_obtenirRacine(*a))) {
	tmp = AB_obtenirFilsDroit(*a);
	inserer(m, &tmp);
	if (!AB_estVide(tmp)) {
	  AB_fixerFilsDroit(a, tmp);
	}
      } else {
	if (M_obtenirIemeCaractere(*m, 0) == N_obtenirValeur(*AB_obtenirRacine(*a))) {
	  N_definirFin(AB_obtenirRacine(*a), N_estFin(*AB_obtenirRacine(*a)) || (M_obtenirLongueur(*m) == 1));
	  tmp = AB_obtenirFilsGauche(*a);
	  inserer(mAux, &tmp);
	  if (!AB_estVide(tmp)) {
	    AB_fixerFilsGauche(a, tmp);
	  }
	} else { 
	  n = N_creerNoeud(M_obtenirLongueur(*m) == 1, M_obtenirIemeCaractere(*m, 0));
	  aBRAux = AB_ajouterRacine(AB_creerABR(), *a, n, (EC_copier) N_copier);
	  *a = aBRAux;
	  tmp = AB_obtenirFilsGauche(*a);
	  inserer(mAux, &tmp);
	  if (!AB_estVide(tmp)) {
	    AB_fixerFilsGauche(a, tmp);
	  }
	}
      }
    }  
    M_supprimer(mAux);
  }
}

void serialiserArbre(FILE* fichier, AB_BinaryTree *a) {
  AB_BinaryTree frere;
  AB_BinaryTree cadet;

  fprintf(fichier, "%c\n", N_obtenirValeur(*AB_obtenirRacine(*a))); 

  if (N_estFin(*AB_obtenirRacine(*a))) { 
    fprintf(fichier, ";\n");
  }

  if (AB_estVide(AB_obtenirFilsGauche(*a))) {
    fprintf(fichier, ".\n");
  } else {
    cadet = AB_obtenirFilsGauche(*a);
    serialiserArbre(fichier, &cadet);
  }

  if (AB_estVide(AB_obtenirFilsDroit(*a))) {
    fprintf(fichier, ",\n");
  } else {
    frere = AB_obtenirFilsDroit(*a);
    serialiserArbre(fichier, &frere);
  }
}

int estContenuR(char* chATester, AB_BinaryTree *a) {
  char cATester, cCourantArbre;
  char *chATesterSuivante;
  AB_BinaryTree tmp;
  int res;
	
  assert(!AB_estVide(*a));

  // conditions d'arrets
  if (strlen(chATester) == 0) {	
    res = 0;
  } else if (strlen(chATester) == 1) {
    cATester = chATester[0];
    cCourantArbre = N_obtenirValeur(*AB_obtenirRacine(*a));
    if (cATester > cCourantArbre){
      tmp = AB_obtenirFilsDroit(*a);
      if (!AB_estVide(tmp)){
	res = estContenuR(chATester, &tmp);
      } else {
	res = -1;
      }
    } else if (cATester == cCourantArbre) {	
      if (N_estFin(*AB_obtenirRacine(*a))) {
	res = 1;
      } else {
			 
	res = 0;
      }
    } else {
      res = -1;
    }
    // appels recursifs
  } else {	
    chATesterSuivante = sousChaine(chATester, 1, strlen(chATester)-1);
    cATester = chATester[0];
    cCourantArbre = N_obtenirValeur(*AB_obtenirRacine(*a));

    if (cATester > cCourantArbre) {
      tmp = AB_obtenirFilsDroit(*a);
      if (!AB_estVide(tmp)){
	res = estContenuR(chATester, &tmp);
      } else {
	res = -1;
      }
    } else if (cATester == cCourantArbre){	
      tmp = AB_obtenirFilsGauche(*a);
      if (!AB_estVide(tmp)){
	res = (estContenuR(chATesterSuivante, &tmp));
      } else {
	res = -1;
      }
    } else {
      res = -1;
    }
    free(chATesterSuivante);
  }	
  return res;
}

void deserialiserArbre(FILE* fichier, AB_BinaryTree *a){
  int LONGUEUR_LIGNE = 3;
  char ligne[LONGUEUR_LIGNE];
  //printf("plop\n");

  if (fgets(ligne, LONGUEUR_LIGNE, fichier) != NULL) {
    //printf("%c\n",ligne[0]);
    if ((ligne[0] >= 97) && (ligne[0] <= 122)) { // si ligne[0] = "[a-z]"
      if (AB_estVide(*a)) {
	N_Noeud *N1 = N_creerNoeud(0, ligne[0]);
	*a = AB_ajouterRacine(AB_creerABR(), AB_creerABR(), N1, (EC_copier) N_copier);
	N_liberer(N1);
	deserialiserArbre(fichier, a);	
      } else if (!AB_estVide(*a) && AB_estVide(AB_obtenirFilsGauche(*a)) && !AB_estTraite(a)) {
	N_Noeud *N2 = N_creerNoeud(0, ligne[0]);
	AB_fixerFilsGauche(a, AB_ajouterRacine(AB_creerABR(), AB_creerABR(), N2, (EC_copier) N_copier));
	N_liberer(N2);
	AB_BinaryTree tmp1 = AB_obtenirFilsGauche(*a);
	deserialiserArbre(fichier, &tmp1);
	AB_fixerFilsGauche(a,tmp1);
	deserialiserArbre(fichier, a);
      } else

      if (!AB_estVide(*a) && AB_estVide(AB_obtenirFilsDroit(*a))) {
	N_Noeud *N3 = N_creerNoeud(0, ligne[0]);
	AB_fixerFilsDroit(a, AB_ajouterRacine(AB_creerABR(), AB_creerABR(), N3, (EC_copier) N_copier));
	N_liberer(N3);
	AB_BinaryTree tmp2 = AB_obtenirFilsDroit(*a);
	deserialiserArbre(fichier, &tmp2);
	AB_fixerFilsDroit(a,tmp2);
      }
    }

    if (ligne[0] == ';' && ligne[1] == '\n') {
      N_definirFin(AB_obtenirRacine(*a), 1);
      deserialiserArbre(fichier, a);
    }

    if (ligne[0] == '.' && ligne[1] == '\n') {
      AB_fixerEstTraite(a, 1);
      deserialiserArbre(fichier, a);
    }
  }
}

/* fonctions publiques */
D_Dictionnaire D_creerDictionnaire() {
  errno = 0;
  D_Dictionnaire d;
	
  d.aBRMots = AB_creerABR();
  d.taille = 0;

  return d;
}

int D_estContenu(M_Mot *mot, D_Dictionnaire d) {
  char *chATester = M_obtenirChaine(*mot);
  return estContenuR(chATester, &(d.aBRMots));
}

int D_taille(D_Dictionnaire d) {
  return d.taille;
}

void D_ajouter(M_Mot *mot, D_Dictionnaire *d) {
  inserer(mot, &((*d).aBRMots));
  (*d).taille = (*d).taille + 1;
}

void D_retirer(M_Mot *mot, D_Dictionnaire *d) {

}

int D_estVide(D_Dictionnaire *d) {
  return AB_estVide((*d).aBRMots);
}

int D_serialiser(D_Dictionnaire d, FILE* fichierCible) {
  serialiserArbre(fichierCible, &(d.aBRMots));
  return 1;
}

D_Dictionnaire D_deserialiser(char *cheminFichier) {
  D_Dictionnaire d = D_creerDictionnaire();
  FILE* fichierEntree = fopen(cheminFichier, "r+");
	
  if (fichierEntree == NULL) {
    fprintf(stderr, "\tERREUR : impossible d'ouvrir %s, verifiez l'existence du fichier et ses droits.\n\t (Dictionnaire.c)\n", cheminFichier);
    exit(1);
  }
  deserialiserArbre(fichierEntree, &(d.aBRMots));

  return d;
}

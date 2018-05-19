/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 14/12/2014 */

#include "resoudreGrille.h"
/* private*/
char* append(char *s, char c) {
     
     char *res = malloc(sizeof(char)*strlen(s)+2);
     res = strcpy(res,s);
     int len = strlen(s);
     
     res[len] = c;
     res[len+1] = '\0';
     return res;
}

	

void* rG_copierMot(void* motACopier){
	char *copie = malloc(sizeof(char)*strlen(motACopier)+1);
	copie = strcpy(copie,(char*)motACopier);
	return (void*)copie;
}

void resoudreGrilleRecursif(D_Dictionnaire dico,G_Grille g,int caseUtilisee[G_TAILLE],C_Case c, char *motATester, LC_ListeChainee *l, CC_CasesContigues *cC){


	int i, position;
	C_Case *nouvelleCase;
	caseUtilisee[C_obtenirPosition(c)] = 1;
	char *newMotATester = append(motATester,C_obtenirLettre(c));
	
	CC_ajouterCase(cC, &c);
	//printf("%s\n",newMotATester);
	if (estUneSolution(&dico, newMotATester) >= 0){
		if (estUneSolution(&dico, newMotATester) == 1){
			char point[6];
			sprintf(point,"%d",CC_compterPoints(*cC));
			char *nouveauMot = malloc(sizeof(char)*(strlen(newMotATester)+7));
			nouveauMot[0]='\0';
			nouveauMot = strcat(nouveauMot,newMotATester);
			nouveauMot = strcat(nouveauMot," ");
			nouveauMot = strcat(nouveauMot,point);

			LC_ajouter(l,(void*)nouveauMot,rG_copierMot);
		
			free(nouveauMot);
		}
		LC_ListeChainee voisins = G_obtenirVoisins(g,c);
		LC_ListeChainee tmp = voisins;
		int compteur = LC_longueur(voisins);
		for(i = 0 ; i < compteur; i++){
			nouvelleCase = (C_Case*)LC_obtenirElement(tmp);
			position = C_obtenirPosition(*nouvelleCase);
			if (caseUtilisee[position] != 1){
				int *tempCaseUtilisee = malloc(sizeof(int)*G_TAILLE);
				for(int j = 0 ; j< G_TAILLE ; j++){
					tempCaseUtilisee[j] = caseUtilisee[j];
				}
				resoudreGrilleRecursif(dico, g, tempCaseUtilisee, *nouvelleCase, newMotATester, l, cC);
				CC_supprimerCase(cC);
				//printf("plop");
				free(tempCaseUtilisee);
			}
			tmp = LC_obtenirListeSuivante(tmp);
		}
		LC_supprimer(&voisins, C_supprimer);
	}
	free(newMotATester);
}

/* public*/
LC_ListeChainee resoudreGrille(D_Dictionnaire dic, G_Grille grilleAResoudre) {
	
	int i;

	LC_ListeChainee l = LC_creerListeChainee();

	for ( i = 0 ; i < 16 ; i++){
		CC_CasesContigues *cC = CC_creerCasesContigues();
		C_Case c = G_obtenirCase(grilleAResoudre,i);
		int caseUtilisee[G_TAILLE] = {0};
		char *motATester = "";
		resoudreGrilleRecursif(dic, grilleAResoudre, caseUtilisee, c, motATester, &l, cC);
	}
	
	return l;
}

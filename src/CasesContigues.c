/* Arthur Hamelin - 10/12/2014 */
/* Benjamin Deguerre - 26/12/2014 */

#include <errno.h>
#include <assert.h>
#include <stdlib.h>

#include "CasesContigues.h"

/* #define NDEBUG 
   decommenter pour annuler les tests
   de precondition
*/

/* partie privee */

int CC_retournerValeurBonusMot(char *bonus) {	
	int res;
	if (bonus[0] == 'M') {
		switch(bonus[1]) {
			case 'D' : 
				res = 2;
				break;
			case 'T' : 
				res = 3;
				break;
			default :
				res = 0;
				break;	
		} 
		}else {
			res = 0;
		}
	return res;
}

int CC_retournerValeurBonusLettre(char *bonus) {
	int res;
	if (bonus[0] == 'L') {
		switch(bonus[1]) {
			case 'D' : 
				res = 2;
				break;
			case 'T' : 
				res = 3;
				break;
			default :
				res = 0;
				break;
		}
	} else {
		res = 0;
	}
	return res;
}






/* partie publique */
CC_CasesContigues* CC_creerCasesContigues() {
	errno = 0;
	CC_CasesContigues *cC = (CC_CasesContigues*)malloc(sizeof(CC_CasesContigues)) ;
	
	cC->lCC = LC_creerListeChainee();
	cC->nbPoints = 0;
	cC->coeffBonus = 0;

	return cC;
}

LC_ListeChainee CC_obtenirVoisinsPossibles(G_Grille *g, CC_CasesContigues *cC) {
	errno = 0;
	C_Case *c = LC_obtenirElement(cC->lCC);
	LC_ListeChainee lOVoisins = G_obtenirVoisins(*g, *c);
	LC_ListeChainee lOVoisinsPossibles = LC_creerListeChainee();

	do {
		C_Case *caseACheck = LC_obtenirElement(lOVoisins);

		if (caseACheck != NULL) {
			
		}

	} while (LC_obtenirListeSuivante(lOVoisins) != NULL);		

	return lOVoisinsPossibles;
}

void CC_ajouterCase(CC_CasesContigues *cC, C_Case *c) {
	

	char *Bonus = C_obtenirBonus(*c);
	int vBonusMot = CC_retournerValeurBonusMot(Bonus);
	int vBonusLettre = CC_retournerValeurBonusLettre(Bonus);
	LC_ajouter(&(cC->lCC), (void*)c, C_copier);
	CC_setBonus(cC,CC_obtenirBonus(*cC) + vBonusMot);
	if (vBonusLettre == 0){
		CC_setNbPoints(cC,CC_obtenirNbPoints(*cC) + C_obtenirNombrePoints(*c)-48);
	} else {
		CC_setNbPoints(cC,CC_obtenirNbPoints(*cC) + (C_obtenirNombrePoints(*c)-48)*vBonusLettre);
	}
	free(Bonus);
}

void CC_supprimerCase(CC_CasesContigues *cC) {
	
	C_Case *c = CC_obtenirCase(cC,1);
	int vBonusLettre = CC_retournerValeurBonusLettre(C_obtenirBonus(*c));
	int vBonusMot = CC_retournerValeurBonusMot(C_obtenirBonus(*c));
	CC_setBonus(cC,CC_obtenirBonus(*cC) - vBonusMot);
	
	if (vBonusLettre == 0){
		CC_setNbPoints(cC,CC_obtenirNbPoints(*cC) - (C_obtenirNombrePoints(*c)-48));
	} else {
		CC_setNbPoints(cC,CC_obtenirNbPoints(*cC) - (C_obtenirNombrePoints(*c)-48)*vBonusLettre);
	}
	
	LC_supprimerTete(&(cC->lCC), C_supprimer);
}


char *CC_lireCases(CC_CasesContigues cC) {
	char *chaineForme = (char*)malloc(sizeof(char)* CC_obtenirLongueur(cC));

	return chaineForme;
}

int CC_compterPoints(CC_CasesContigues cC) {
	int	points = CC_obtenirNbPoints(cC);
	//printf("%d\n",points);
	int bonus = CC_obtenirBonus(cC);
	//printf("%d\n",bonus);
	if (bonus == 0){
		bonus = 1;
	}
	return points*bonus;
}

int CC_obtenirLongueur(CC_CasesContigues cC) {
	return LC_longueur(cC.lCC);
}

int CC_obtenirBonus(CC_CasesContigues cC) {
	return cC.coeffBonus;
}

int CC_obtenirNbPoints(CC_CasesContigues cC){
	//printf("%d\n",cC.nbPoints);
	return cC.nbPoints;
}

LC_ListeChainee* CC_obtenirListeChainee(CC_CasesContigues *cC){
	return &(cC->lCC);
}

void CC_setBonus(CC_CasesContigues *cC, int bonus){
	cC->coeffBonus = bonus;
}

void CC_setNbPoints(CC_CasesContigues *cC, int points){
	cC->nbPoints = points;
}

C_Case* CC_obtenirCase(CC_CasesContigues *cC, int no) {
	C_Case *c = NULL;
	int i;
	
	assert(no > 0);

	LC_ListeChainee *maListe = CC_obtenirListeChainee(cC);
	if (no != 1){
		for (i = 0 ; i < no-1; i++){
			*maListe = LC_obtenirListeSuivante(*maListe);
		}
	}
	c = (C_Case*)LC_obtenirElement(*maListe);
	return c;	
}

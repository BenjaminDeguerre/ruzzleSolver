/* Deguerre Benjamin - 04/01/2015 */
/* Deguerre Benjamin - 04/01/2015 */


#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <CUnit/CUnit.h>

#include "ListeChainee.h"
#include "Mot.h"

int init_suite_success (void) {
	return 0;
}


int clean_suite_success (void) {
	return 0;
}

void test_1_ListeChainee(void){
	LC_ListeChainee maListe = LC_creerListeChainee();
	CU_ASSERT(LC_estVide(maListe) == 1);
	LC_supprimer(&maListe, M_supprimer);
}

void test_2_ListeChainee(void){
	LC_ListeChainee maListe = LC_creerListeChainee();
	M_Mot *motTest = M_creerMot("plop");
	LC_ajouter(&maListe,(void*)motTest,M_copier);
	CU_ASSERT_FALSE(LC_estVide(maListe));
	LC_supprimer(&maListe, M_supprimer);
}

void test_3_ListeChainee(void){
	LC_ListeChainee maListe = LC_creerListeChainee();
	M_Mot *motTest = M_creerMot("plop");
	LC_ajouter(&maListe,(void*)motTest,M_copier);
	CU_ASSERT(M_comparer(LC_obtenirElement(maListe),(void*) motTest));
	LC_supprimer(&maListe, M_supprimer);
}

void test_4_ListeChainee(void){
	LC_ListeChainee maListe = LC_creerListeChainee();
	LC_ListeChainee maListeTemp = maListe;
	M_Mot *motTest = M_creerMot("plop");
	LC_ajouter(&maListe,(void*)motTest,M_copier);
	CU_ASSERT(LC_obtenirListeSuivante(maListe) == maListeTemp);
	LC_supprimer(&maListe, M_supprimer);
}

void test_5_ListeChainee(void){
	LC_ListeChainee maListe = LC_creerListeChainee();
	LC_ListeChainee maListe1 = LC_creerListeChainee();
	M_Mot *motTest = M_creerMot("plop");
	LC_ajouter(&maListe,(void*)motTest,M_copier);
	LC_ajouter(&maListe1,(void*)motTest,M_copier);
	CU_ASSERT(LC_egales(maListe, maListe1, M_comparer));
	LC_supprimer(&maListe, M_supprimer);
}

void test_6_ListeChainee(void){
	LC_ListeChainee maListe = LC_creerListeChainee();
	M_Mot *motTest = M_creerMot("plop");
	for(int i = 1; i <=4 ; i++){
		LC_ajouter(&maListe,(void*)motTest,M_copier);
		CU_ASSERT(LC_longueur(maListe) == i);
	}

	LC_supprimer(&maListe, M_supprimer);

}

int test_ListeChainee(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "LC_estVide(LC_creerListeOrdonne() == 1", test_1_ListeChainee)) || (NULL == CU_add_test(pSuite, "!LC_estVide(LC_ajouter(l,e,e_copier)) == 1", test_2_ListeChainee)) || (NULL == CU_add_test(pSuite, "LC_obtenirElement(LC_ajouter(l,e,e_copier)) == e ", test_3_ListeChainee)) || (NULL == CU_add_test(pSuite, "LC_obtenirListeSuivante(LC_ajouter(l,e,e_copier)) == l", test_4_ListeChainee)) || (NULL == CU_add_test(pSuite, "LC_egales(l,l) == 1", test_5_ListeChainee)) || (NULL == CU_add_test(pSuite, "LC_longeur(l)", test_6_ListeChainee)));
}


int main () {
	
	CU_pSuite pSuite = NULL;
	
	/* initialisation du registre de test */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
		
	/* ajout d’une suite de test */
	pSuite = CU_add_suite("Tests boite noire", init_suite_success , clean_suite_success ) ;
	if (NULL == pSuite) {
		CU_cleanup_registry () ;
		return CU_get_error () ;
	}
	
	/* ajout des tests à la suite de tests boite noire */
	if (test_ListeChainee(pSuite)){
		printf("plip\n");
		CU_cleanup_registry();
		return CU_get_error();
	}
		
	/* Lancement des tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list()) ;
	printf("\n\n");

}

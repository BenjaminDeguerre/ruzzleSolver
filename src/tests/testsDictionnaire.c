/* Alexandre DUVAL - 03/01/2015 */
/* Alexandre DUVAL - 03/01/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>

#include "Grille.h"
#include "Case.h"
#include "ListeChainee.h"
#include "Dictionnaire.h"
#include "BinaryTree.h"
#include "creerGrilleAResoudre.h"

int init_suite_success (void) {	return 0; }
int clean_suite_success (void) { return 0; }

void test_D_ajouter(void) {
	D_Dictionnaire d = D_creerDictionnaire();
	M_Mot *m1, *m2, *m3, *m4, *m5, *m6;

	// ajout des mots
	m1 = M_creerMot("aller");
	D_ajouter(m1, &d);
	m2 = M_creerMot("voitUre");
	D_ajouter(m2, &d);
	m3 = M_creerMot("aviAtion");
	D_ajouter(m3, &d);
	m4 = M_creerMot("motorola");
	D_ajouter(m4, &d);
	m5 = M_creerMot("moto");
	D_ajouter(m5, &d);
	m6 = M_creerMot("aller");
	D_ajouter(m6, &d);

	printf("debut test \n");
	printf("%c\n", N_obtenirValeur(*AB_obtenirRacine(d.aBRMots)));
	printf("%c\n", N_obtenirValeur(*AB_obtenirRacine(AB_obtenirFilsGauche(AB_obtenirFilsDroit(AB_obtenirFilsDroit(d.aBRMots))))));
	
	printf("fin test\n");
	
	printf("%c\n", N_obtenirValeur(*AB_obtenirRacine((d.aBRMots))));
	printf("%c\n", N_obtenirValeur(*AB_obtenirRacine(AB_obtenirFilsDroit(d.aBRMots))));
	printf("%c\n", N_obtenirValeur(*AB_obtenirRacine(AB_obtenirFilsGauche(AB_obtenirFilsDroit(d.aBRMots)))));
	printf("%c\n", N_obtenirValeur(*AB_obtenirRacine(AB_obtenirFilsGauche(AB_obtenirFilsGauche(AB_obtenirFilsDroit(d.aBRMots))))));
	printf("%c\n", N_obtenirValeur(*AB_obtenirRacine(AB_obtenirFilsGauche(AB_obtenirFilsGauche(AB_obtenirFilsGauche(AB_obtenirFilsDroit(d.aBRMots)))))));
	CU_ASSERT_TRUE(1);
}

void test_D_estContenu(void) {
	D_Dictionnaire d = D_creerDictionnaire();
	M_Mot *m1, *m2, *m3, *m4, *m5, *m6, *m7, *m8, *m9;

	// ajout des mots
	m1 = M_creerMot("voiturettE");
	D_ajouter(m1, &d);
	m2 = M_creerMot("voiture");
	D_ajouter(m2, &d);
	m3 = M_creerMot("aviation");
	D_ajouter(m3, &d);
	m4 = M_creerMot("motorola");
	D_ajouter(m4, &d);
	m5 = M_creerMot("moto");
	D_ajouter(m5, &d);
	m6 = M_creerMot("aller");
	D_ajouter(m6, &d);
	m7 = M_creerMot("Zblaaab");
	m8 = M_creerMot("Zblaaa");
	D_ajouter(m8, &d);
	m9 = M_creerMot("Zblaaa");
	D_ajouter(m9, &d);

	// tests contenu dico
	CU_ASSERT_TRUE(D_estContenu(m1, d));
	CU_ASSERT_TRUE(D_estContenu(m2, d));
	CU_ASSERT_TRUE(D_estContenu(m3, d));
	CU_ASSERT_TRUE(D_estContenu(m4, d));
	CU_ASSERT_TRUE(D_estContenu(m5, d));
	CU_ASSERT_TRUE(D_estContenu(m6, d));
	CU_ASSERT_FALSE(D_estContenu(m7, d));
	CU_ASSERT_TRUE(D_estContenu(m8, d));
	CU_ASSERT_TRUE(D_estContenu(m9, d));
}

int test_Dictionnaire(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "D_ajouter", test_D_ajouter)) || (NULL == CU_add_test(pSuite, "D_estContenu", test_D_estContenu)));
}

int main () {
	CU_pSuite pSuite = NULL;

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
		
	pSuite = CU_add_suite("Tests boite blanche", init_suite_success, clean_suite_success);
	if (NULL == pSuite) {
		CU_cleanup_registry () ;
		return CU_get_error () ;
	}
	
	if (test_Dictionnaire(pSuite)){
		CU_cleanup_registry();
		return CU_get_error();
	}
		
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list()) ;
	printf("\n\n");
}

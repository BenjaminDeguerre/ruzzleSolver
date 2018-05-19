/* Deguerre Benjamin - 28/12/2014 */
/* Deguerre Benjamin - 28/12/2014 */


#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "Noeud.h"
#include <CUnit/CUnit.h>


int init_suite_success (void) {
	return 0;
}
 
int clean_suite_success (void) {
	return 0;
}

void test_1_Noeud(void){
	N_Noeud *n = N_creerNoeud(1,'p');
	CU_ASSERT(n->valeur == 'p');
	CU_ASSERT(n->estFin);
}

void test_2_Noeud(void){
	N_Noeud *n = N_creerNoeud(1,'p');
	char test = N_obtenirValeur(*n);
	CU_ASSERT_EQUAL(test, 'p');

}


void test_3_Noeud(void){
	N_Noeud *n = N_creerNoeud(1,'a');
	CU_ASSERT(N_estFin(*n));
}

void test_4_Noeud(void){
	N_Noeud *n = N_creerNoeud(1,'p');
	N_definirValeur(n,'u');
	char test = N_obtenirValeur(*n);
	CU_ASSERT_EQUAL(test,'u');
}

void test_5_Noeud(void){
	N_Noeud *n = N_creerNoeud(1,'p');
	N_definirFin(n,0);
	int test = N_estFin(*n);
	CU_ASSERT_FALSE(test);
}


void test_6_Noeud(void){
	N_Noeud *n1 = N_creerNoeud(1,'p');
	N_Noeud *n2 = N_creerNoeud(1,'p');
	CU_ASSERT(N_comparer(n1, n2) == 0);
}

void test_7_Noeud(void){
	N_Noeud *n1 = N_creerNoeud(1,'p');
	N_Noeud *n2 = N_creerNoeud(1,'a');
	CU_ASSERT(N_comparer(n1, n2) > 0);
}

int test_Noeud(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "initialisation d'un noeud, valeur == plop, estFin == 1", test_1_Noeud)) || (NULL == CU_add_test(pSuite, "test fonction N_obtenirValeur", test_2_Noeud)) || (NULL == CU_add_test(pSuite, "test fonction N_estFin", test_3_Noeud)) || (NULL == CU_add_test(pSuite, "test fonction N_definirValeur", test_4_Noeud)) || (NULL == CU_add_test(pSuite, "test fonction N_definirFin", test_5_Noeud)) || (NULL == CU_add_test(pSuite, "test fonction N_comparer (vrai)", test_6_Noeud)) || (NULL == CU_add_test(pSuite, "test fonction N_comparer (faux)", test_7_Noeud)));
}

int main(){
	
	CU_pSuite pSuite = NULL;
	
	/* initialisation du registre de test */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
		
	/* ajout d’une suite de test */
	pSuite = CU_add_suite("Tests boite blanche", init_suite_success , clean_suite_success ) ;
	if (NULL == pSuite) {
		CU_cleanup_registry () ;
		return CU_get_error () ;
	}
	
	/* ajout des tests à la suite de tests*/
	if (test_Noeud(pSuite)){
		CU_cleanup_registry();
		return CU_get_error();
	}
		
	/* Lancement des tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list()) ;
	printf("\n\n");
	
	/*Netoyage du registre */
	CU_cleanup_registry();
	return CU_get_error();

}

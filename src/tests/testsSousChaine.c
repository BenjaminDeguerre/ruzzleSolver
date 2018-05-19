/* Deguerre Benjamin - 27/12/2014 */
/* Deguerre Benjamin - 30/12/2014 */


#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "sousChaine.h"
#include <CUnit/CUnit.h>


int init_suite_success (void) {
	return 0;
}
 
int clean_suite_success (void) {
	return 0;
}

void test_1_sousChaine(void){
	CU_ASSERT_STRING_EQUAL(sousChaine("bonjour",0,0), "b");
}

void test_2_sousChaine(void){
	CU_ASSERT_STRING_EQUAL(sousChaine("bonjour",0,2), "bon");
}


void test_3_sousChaine(void){
	CU_ASSERT_STRING_EQUAL(sousChaine("bonjour",3,6),"jour");
}


int test_sousChaine(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "sousChaine(bonjour,0,0) == b", test_1_sousChaine)) || (NULL == CU_add_test(pSuite, "sousChaine(bonjour,0,2) == bon", test_2_sousChaine)) ||(NULL == CU_add_test(pSuite, "sousChaine(bonjour,3,6) == jour", test_3_sousChaine)));
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
	if (test_sousChaine(pSuite)){
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

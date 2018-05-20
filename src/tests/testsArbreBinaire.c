/* Deguerre Benjamin - 04/01/2015 */
/* Deguerre Benjamin - 04/01/2015 */


#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "BinaryTree.h"


int init_suite_success (void) {
	return 0;
}


int clean_suite_success (void) {
	return 0;
}

void test_1_BinaryTree(void){

}

void test_2_BinaryTree(void){
	
}

void test_3_BinaryTree(void){
	
}

void test_4_BinaryTree(void){
	
}

void test_5_BinaryTree(void){
	
}

int test_BinaryTree(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "S_isEmpty(S_createSquare() == 1", test_1_BinaryTree)) || (NULL == CU_add_test(pSuite, "S_getLetter(S_defineSquare(c,b2MD) == b", test_2_BinaryTree)) || (NULL == CU_add_test(pSuite, "S_defineSquare(c,b2MD) == 2 ", test_3_BinaryTree)) || (NULL == CU_add_test(pSuite, "S_defineSquare(c,b2MD) == MD", test_4_BinaryTree)) || (NULL == CU_add_test(pSuite, "S_defineSquare(c,b2MD) == MD", test_5_BinaryTree)));
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
	if (test_BinaryTree(pSuite)){
		CU_cleanup_registry();
		return CU_get_error();
	}
		
	/* Lancement des tests */
	CU_basic_set_mode(CU_BRW_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list()) ;
	printf("\n\n");

}

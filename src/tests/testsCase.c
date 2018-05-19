/* Deguerre Benjamin - 23/12/2014 */
/* Deguerre Benjamin - 30/12/2014 */


#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "Case.h"


int init_suite_success (void) {
	return 0;
}


int clean_suite_success (void) {
	return 0;
}

void test_1_Case(void){
	C_Case *c = C_creerCase();
	CU_ASSERT_TRUE(C_estVide(*c) == 1);
	C_supprimer((void*)c);
}

void test_2_Case(void){
	C_Case *c = C_creerCase();
	C_definirCase(c,"b2MD",1);
	CU_ASSERT_TRUE(C_obtenirLettre(*c) == 'b');
	C_supprimer((void*)c);
}

void test_3_Case(void){
	C_Case *c = C_creerCase();
	C_definirCase(c,"b2MD",1);
	CU_ASSERT_TRUE(C_obtenirNombrePoints(*c) == '2' );
	C_supprimer((void*)c);
}

void test_4_Case(void){
	C_Case *c = C_creerCase();
	C_definirCase(c,"b2MD",1);
	char* test = C_obtenirBonus(*c);
	CU_ASSERT_STRING_EQUAL(test, "MD" );
	C_supprimer((void*)c);
	free(test);
}

void test_5_Case(void){
	C_Case *c1 = C_creerCase(), *c2 = C_creerCase();
	C_definirCase(c1,"b2MD",1);
	c2 = (C_Case*)C_copier((void*)c1);
	char* test1 = C_obtenirBonus(*c1);
	char* test2 = C_obtenirBonus(*c2);
	CU_ASSERT_STRING_EQUAL(test1,test2);
	CU_ASSERT_TRUE(C_obtenirPosition(*c1) == C_obtenirPosition(*c2));
	C_supprimer((void*)c1);
	C_supprimer((void*)c2);
	free(test1);
	free(test2);
}

int test_Case(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "C_estVide(C_creerCase() == 1", test_1_Case)) || (NULL == CU_add_test(pSuite, "C_obtenirLettre(C_definirCase(c,b2MD) == b", test_2_Case)) || (NULL == CU_add_test(pSuite, "C_definirCase(c,b2MD) == 2 ", test_3_Case)) || (NULL == CU_add_test(pSuite, "C_definirCase(c,b2MD) == MD", test_4_Case)) || (NULL == CU_add_test(pSuite, "C_copier", test_5_Case)));
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
	if (test_Case(pSuite)){
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

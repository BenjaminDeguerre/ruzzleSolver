/* Deguerre Benjamin - 04/01/2015 */
/* Deguerre Benjamin - 04/01/2015 */


#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "CasesContigues.h"
#include "Case.h"

int init_suite_success (void) {
	return 0;
}


int clean_suite_success (void) {
	return 0;
}

void test_1_CasesContigues(void){
	CC_CasesContigues *cC = CC_creerCasesContigues();
	CU_ASSERT(CC_obtenirBonus(*cC) == 0);
	CU_ASSERT(CC_obtenirNbPoints(*cC) == 0);
	CU_ASSERT(CC_obtenirLongueur(*cC) == 0);
}

void test_2_CasesContigues(void){
	CC_CasesContigues *cC = CC_creerCasesContigues();
	C_Case *c = C_creerCase();
	C_Case *c2 = C_creerCase();
	C_definirCase(c,"T1LD",1);
	C_definirCase(c2,"T2MD",2);
	CC_ajouterCase(cC,c);
	CU_ASSERT(CC_obtenirBonus(*cC) == 0);
	CU_ASSERT(CC_obtenirNbPoints(*cC) == 2);
	CU_ASSERT(CC_obtenirLongueur(*cC) == 1);
	CC_ajouterCase(cC,c);
	CU_ASSERT(CC_obtenirBonus(*cC) == 0);
	CU_ASSERT(CC_obtenirNbPoints(*cC) == 4);
	CU_ASSERT(CC_obtenirLongueur(*cC) == 2);
	CC_ajouterCase(cC,c2);
	CU_ASSERT(CC_obtenirBonus(*cC) == 2);
	CU_ASSERT(CC_obtenirNbPoints(*cC) == 6);
	CU_ASSERT(CC_obtenirLongueur(*cC) == 3);
	CC_supprimerCase(cC);
	CU_ASSERT(CC_obtenirBonus(*cC) == 0);
	printf("%d\n",CC_obtenirBonus(*cC));
	CU_ASSERT(CC_obtenirNbPoints(*cC) == 4);
	printf("%d\n",CC_obtenirNbPoints(*cC));
	CU_ASSERT(CC_obtenirLongueur(*cC) == 2);
	printf("%d\n",CC_obtenirLongueur(*cC));
	
}

void test_3_CasesContigues(void){
	
}

void test_4_CasesContigues(void){
	
}

void test_5_CasesContigues(void){
	
}

int test_CasesContigues(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "CC_creerCasesContigues()", test_1_CasesContigues)) || (NULL == CU_add_test(pSuite, "CC_ajouterCase(CC_CasesContigues *cC, C_Case *c)", test_2_CasesContigues)) || (NULL == CU_add_test(pSuite, "C_definirCase(c,b2MD) == 2 ", test_3_CasesContigues)) || (NULL == CU_add_test(pSuite, "C_definirCase(c,b2MD) == MD", test_4_CasesContigues)) || (NULL == CU_add_test(pSuite, "C_definirCase(c,b2MD) == MD", test_5_CasesContigues)));
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
	if (test_CasesContigues(pSuite)){
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

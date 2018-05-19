/* Alexandre DUVAL - 03/01/2015 */
/* Alexandre DUVAL - 03/01/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "Mot.h"

int init_suite_success (void) {	return 0; }
int clean_suite_success (void) { return 0; }

void test_M_global(void) {
	M_Mot *m1 = M_creerMot("avion");
	M_Mot *m2 = M_copier(m1);

	CU_ASSERT_EQUAL(M_obtenirLongueur(*m1), 5);
	CU_ASSERT_STRING_EQUAL(M_obtenirChaine(*m1), "avion");
	CU_ASSERT_EQUAL(M_obtenirIemeCaractere(*m1, 0), 'a');
	CU_ASSERT_EQUAL(M_obtenirIemeCaractere(*m1, 1), 'v');
	CU_ASSERT_EQUAL(M_obtenirIemeCaractere(*m1, 2), 'i');
	CU_ASSERT_EQUAL(M_obtenirIemeCaractere(*m1, 3), 'o');
	CU_ASSERT_EQUAL(M_obtenirIemeCaractere(*m1, 4), 'n');

	CU_ASSERT_STRING_EQUAL(M_obtenirChaine(*m1), M_obtenirChaine(*m2));
	CU_ASSERT(M_comparer(m1, m2));
}

int test_Mot(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "M_global", test_M_global)));
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
	
	if (test_Mot(pSuite)){
		CU_cleanup_registry();
		return CU_get_error();
	}
		
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list()) ;
	printf("\n\n");
}

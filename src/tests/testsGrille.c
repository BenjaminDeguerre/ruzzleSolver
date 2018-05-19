/* Deguerre Benjamin - 23/12/2014 */
/* Deguerre Benjamin - 30/12/2014 */


#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "Grille.h"
#include "Case.h"
#include "ListeChainee.h"
#include "creerGrilleAResoudre.h"

int init_suite_success (void) {
	return 0;
}


int clean_suite_success (void) {
	return 0;
}

void test_1_Grille(void){
	char *chaine = "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
	G_Grille g = creerGrilleAResoudre(chaine);
	C_Case *cTest = C_creerCase();
	C_Case *cRef = C_creerCase();
	C_definirCase(cRef,"T1LD",0);
	*cTest = G_obtenirCase(g,0);
	char *chaineTest = C_obtenirValeur(*cTest);
	printf("%s \n",chaineTest);
	char *chaineRef = C_obtenirValeur(*cRef);
	printf("%s",chaineRef);
	CU_ASSERT_STRING_EQUAL(chaineTest, chaineRef);
	C_supprimer((void*)cTest);
	C_supprimer((void*)cRef);
	G_supprimerGrille(g);
}

void test_2_Grille(void){
	char *chaine = "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
	G_Grille g = creerGrilleAResoudre(chaine);
	C_Case *cTest = C_creerCase();
	C_Case *cRef = C_creerCase();
	C_definirCase(cRef,"A1  ",2);
	*cTest = G_obtenirCase(g,2);
	char *chaineTest = C_obtenirValeur(*cTest);
	char *chaineRef = C_obtenirValeur(*cRef);
	CU_ASSERT_STRING_EQUAL(chaineTest, chaineRef);
	C_supprimer((void*)cTest);
	C_supprimer((void*)cRef);
	G_supprimerGrille(g);
}

void test_3_Grille(void){
	char *chaine = "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
	G_Grille g = creerGrilleAResoudre(chaine);
	C_Case *cTest = C_creerCase();
	C_Case *cRef = C_creerCase();
	C_definirCase(cRef,"A1  ",2);
	*cTest = G_obtenirCase(g,2);
	char *chaineTest = C_obtenirValeur(*cTest);
	char *chaineRef = C_obtenirValeur(*cRef);
	CU_ASSERT_STRING_EQUAL(chaineTest, chaineRef);
	C_supprimer((void*)cTest);
	C_supprimer((void*)cRef);
	G_supprimerGrille(g);
}

void test_4_Grille(void){
	char *chaine = "T1LDR1  A1  S1MTE1LTN1  C3LTE1  U1  R1  I1  L2MDS1  O1MDP3  S1  ";
	G_Grille g = creerGrilleAResoudre(chaine);
	C_Case *cTest = C_creerCase();
	C_Case *cRef = C_creerCase();
	C_definirCase(cRef,"A1  ",2);
	*cTest = G_obtenirCase(g,2);
	char *chaineTest = C_obtenirValeur(*cTest);
	char *chaineRef = C_obtenirValeur(*cRef);
	CU_ASSERT_STRING_EQUAL(chaineTest, chaineRef);
	C_supprimer((void*)cTest);
	C_supprimer((void*)cRef);
	G_supprimerGrille(g);
}



int test_Grille(CU_pSuite pSuite){
	return ((NULL == CU_add_test(pSuite, "G_creerGrille", test_1_Grille)) || (NULL == CU_add_test(pSuite, "extraction d'une case de la grille (troisième)", test_2_Grille)) || (NULL == CU_add_test(pSuite, "C_definirCase(c,b2MD) == 2 ", test_3_Grille)) || (NULL == CU_add_test(pSuite, "C_definirCase(c,b2MD) == MD", test_4_Grille)));
}


int main () {
	
	CU_pSuite pSuite = NULL;
	

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();
		

	pSuite = CU_add_suite("Tests boite blanche", init_suite_success , clean_suite_success ) ;
	if (NULL == pSuite) {
		CU_cleanup_registry () ;
		return CU_get_error () ;
	}
	

	if (test_Grille(pSuite)){
		CU_cleanup_registry();
		return CU_get_error();
	}
		

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list()) ;
	printf("\n\n");

}

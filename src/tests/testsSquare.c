/* Deguerre Benjamin - 23/12/2014 */
/* Deguerre Benjamin - 30/12/2014 */

#include "Square.h"
#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_suite_success(void) { return 0; }

int clean_suite_success(void) { return 0; }

void test_1_Square(void)
{
	S_SQUARE *square = S_createSquare();
	CU_ASSERT_TRUE(S_isEmpty(*square) == 1);
	S_delete((void *)square);
}

void test_2_Square(void)
{
	S_SQUARE *square = S_createSquare();
	S_defineSquare(square, "b2MD", 1);
	CU_ASSERT_TRUE(S_getLetter(*square) == 'b');
	S_delete((void *)square);
}

void test_3_Square(void)
{
	S_SQUARE *square = S_createSquare();
	S_defineSquare(square, "b2MD", 1);
	CU_ASSERT_TRUE(S_getPointsNumber(*square) == '2');
	S_delete((void *)square);
}

void test_4_Square(void)
{
	S_SQUARE *square = S_createSquare();
	S_defineSquare(square, "b2MD", 1);
	char *test = S_getBonus(*square);
	CU_ASSERT_STRING_EQUAL(test, "MD");
	S_delete((void *)square);
	free(test);
}

void test_5_Square(void)
{
	S_SQUARE *square1 = S_createSquare(), *square2 = S_createSquare();
	S_defineSquare(square1, "b2MD", 1);
	square2 = (S_SQUARE *)S_copy((void *)square1);
	char *test1 = S_getBonus(*square1);
	char *test2 = S_getBonus(*square2);
	CU_ASSERT_STRING_EQUAL(test1, test2);
	CU_ASSERT_TRUE(S_getPosition(*square1) == S_getPosition(*square2));
	S_delete((void *)square1);
	S_delete((void *)square2);
	free(test1);
	free(test2);
}

int test_Square(CU_pSuite pSuite)
{
	return (
		(NULL ==
		 CU_add_test(pSuite, "S_isEmpty(S_createSquare() == 1", test_1_Square)) ||
		(NULL == CU_add_test(pSuite, "S_getLetter(S_defineSquare(c,b2MD) == b",
							 test_2_Square)) ||
		(NULL ==
		 CU_add_test(pSuite, "S_defineSquare(c,b2MD) == 2 ", test_3_Square)) ||
		(NULL ==
		 CU_add_test(pSuite, "S_defineSquare(c,b2MD) == MD", test_4_Square)) ||
		(NULL == CU_add_test(pSuite, "S_copy", test_5_Square)));
}

int main()
{

	CU_pSuite pSuite = NULL;

	/* initialisation du registre de test */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* ajout d’une suite de test */
	pSuite = CU_add_suite("Tests boite noire", init_suite_success,
						  clean_suite_success);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* ajout des tests à la suite de tests boite noire */
	if (test_Square(pSuite))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Lancement des tests */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");
}

/* Deguerre Benjamin - 28/12/2014 */
/* Deguerre Benjamin - 28/12/2014 */

#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "Node.h"
#include <CUnit/CUnit.h>

int init_suite_success(void)
{
	return 0;
}

int clean_suite_success(void)
{
	return 0;
}

void test_1_Node(void)
{
	N_Node *n = N_createNode(1, 'p');
	CU_ASSERT(n->value == 'p');
	CU_ASSERT(n->isLast);
}

void test_2_Node(void)
{
	N_Node *n = N_createNode(1, 'p');
	char test = N_getValue(*n);
	CU_ASSERT_EQUAL(test, 'p');
}

void test_3_Node(void)
{
	N_Node *n = N_createNode(1, 'a');
	CU_ASSERT(N_isLast(*n));
}

void test_4_Node(void)
{
	N_Node *n = N_createNode(1, 'p');
	N_defineValue(n, 'u');
	char test = N_getValue(*n);
	CU_ASSERT_EQUAL(test, 'u');
}

void test_5_Node(void)
{
	N_Node *n = N_createNode(1, 'p');
	N_defineEnd(n, 0);
	int test = N_isLast(*n);
	CU_ASSERT_FALSE(test);
}

void test_6_Node(void)
{
	N_Node *node1 = N_createNode(1, 'p');
	N_Node *node2 = N_createNode(1, 'p');
	CU_ASSERT(N_compare(node1, node2) == 0);
}

void test_7_Node(void)
{
	N_Node *node1 = N_createNode(1, 'p');
	N_Node *node2 = N_createNode(1, 'a');
	CU_ASSERT(N_compare(node1, node2) > 0);
}

int test_Node(CU_pSuite pSuite)
{
	return ((NULL == CU_add_test(pSuite, "initialisation d'un node, value == plop, isLast == 1", test_1_Node)) || (NULL == CU_add_test(pSuite, "test fonction N_getValue", test_2_Node)) || (NULL == CU_add_test(pSuite, "test fonction N_isLast", test_3_Node)) || (NULL == CU_add_test(pSuite, "test fonction N_defineValue", test_4_Node)) || (NULL == CU_add_test(pSuite, "test fonction N_defineEnd", test_5_Node)) || (NULL == CU_add_test(pSuite, "test fonction N_compare (vrai)", test_6_Node)) || (NULL == CU_add_test(pSuite, "test fonction N_compare (faux)", test_7_Node)));
}

int main()
{

	CU_pSuite pSuite = NULL;

	/* initialisation du registre de test */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* ajout d’une suite de test */
	pSuite = CU_add_suite("Tests boite blanche", init_suite_success, clean_suite_success);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* ajout des tests à la suite de tests*/
	if (test_Node(pSuite))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Lancement des tests */
	CU_basic_set_mode(CU_BRW_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");

	/*Netoyage du registre */
	CU_cleanup_registry();
	return CU_get_error();
}

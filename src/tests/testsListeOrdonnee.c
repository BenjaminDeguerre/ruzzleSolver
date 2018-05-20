/* Deguerre Benjamin - 04/01/2015 */
/* Deguerre Benjamin - 04/01/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>
#include <CUnit/CUnit.h>

#include "LinkedList.h"
#include "Word.h"

int init_suite_success(void)
{
	return 0;
}

int clean_suite_success(void)
{
	return 0;
}

void test_1_LinkedList(void)
{
	LL_LinkedList maList = LL_createLinkedList();
	CU_ASSERT(LL_isEmpty(maList) == 1);
	LL_delete(&maList, W_delete);
}

void test_2_LinkedList(void)
{
	LL_LinkedList maList = LL_createLinkedList();
	W_Word *wordTest = W_createWord("plop");
	LL_add(&maList, (void *)motTest, W_copy);
	CU_ASSERT_FALSE(LL_isEmpty(maList));
	LL_delete(&maList, W_delete);
}

void test_3_LinkedList(void)
{
	LL_LinkedList maList = LL_createLinkedList();
	W_Word *wordTest = W_createWord("plop");
	LL_add(&maList, (void *)motTest, W_copy);
	CU_ASSERT(W_compare(LL_getElement(maList), (void *)motTest));
	LL_delete(&maList, W_delete);
}

void test_4_LinkedList(void)
{
	LL_LinkedList maList = LL_createLinkedList();
	LL_LinkedList maListTemp = maList;
	W_Word *wordTest = W_createWord("plop");
	LL_add(&maList, (void *)motTest, W_copy);
	CU_ASSERT(LL_getNextList(maList) == maListTemp);
	LL_delete(&maList, W_delete);
}

void test_5_LinkedList(void)
{
	LL_LinkedList maList = LL_createLinkedList();
	LL_LinkedList maList1 = LL_createLinkedList();
	W_Word *wordTest = W_createWord("plop");
	LL_add(&maList, (void *)motTest, W_copy);
	LL_add(&maList1, (void *)motTest, W_copy);
	CU_ASSERT(LL_equals(maList, maList1, W_compare));
	LL_delete(&maList, W_delete);
}

void test_6_LinkedList(void)
{
	LL_LinkedList maList = LL_createLinkedList();
	W_Word *wordTest = W_createWord("plop");
	for (int i = 1; i <= 4; i++)
	{
		LL_add(&maList, (void *)motTest, W_copy);
		CU_ASSERT(LL_length(maList) == i);
	}

	LL_delete(&maList, W_delete);
}

int test_LinkedList(CU_pSuite pSuite)
{
	return ((NULL == CU_add_test(pSuite, "LL_isEmpty(LL_createListOrdonne() == 1", test_1_LinkedList)) || (NULL == CU_add_test(pSuite, "!LL_isEmpty(LL_add(l,e,e_copy)) == 1", test_2_LinkedList)) || (NULL == CU_add_test(pSuite, "LL_getElement(LL_add(l,e,e_copy)) == e ", test_3_LinkedList)) || (NULL == CU_add_test(pSuite, "LL_getNextList(LL_add(l,e,e_copy)) == l", test_4_LinkedList)) || (NULL == CU_add_test(pSuite, "LL_equals(l,l) == 1", test_5_LinkedList)) || (NULL == CU_add_test(pSuite, "LL_longeur(l)", test_6_LinkedList)));
}

int main()
{

	CU_pSuite pSuite = NULL;

	/* initialisation du registre de test */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	/* ajout d’une suite de test */
	pSuite = CU_add_suite("Tests boite noire", init_suite_success, clean_suite_success);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* ajout des tests à la suite de tests boite noire */
	if (test_LinkedList(pSuite))
	{
		printf("plip\n");
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* Lancement des tests */
	CU_basic_set_mode(CU_BRW_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");
}

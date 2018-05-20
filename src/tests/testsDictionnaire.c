/* Alexandre DUVAL - 03/01/2015 */
/* Alexandre DUVAL - 03/01/2015 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include <string.h>

#include "Grid.h"
#include "Square.h"
#include "LinkedList.h"
#include "Dictionary.h"
#include "BinaryTree.h"
#include "createGridToSolve.h"

int init_suite_success(void) { return 0; }
int clean_suite_success(void) { return 0; }

void test_D_add(void)
{
	D_Dictionary dictionary = D_createDictionary();
	W_Word *word1, *word2, *word3, *word4, *word5, *word6;

	// ajout des mots
	m1 = W_createWord("aller");
	D_add(m1, &d);
	m2 = W_createWord("voitUre");
	D_add(m2, &d);
	m3 = W_createWord("aviAtion");
	D_add(m3, &d);
	m4 = W_createWord("motorola");
	D_add(m4, &d);
	m5 = W_createWord("moto");
	D_add(m5, &d);
	m6 = W_createWord("aller");
	D_add(m6, &d);

	printf("begin test \n");
	printf("%c\n", N_getValue(*BT_getRoot(d.wordsBT)));
	printf("%c\n", N_getValue(*BT_getRoot(BT_getLeftChild(BT_getRightChild(BT_getRightChild(d.wordsBT))))));

	printf("fin test\n");

	printf("%c\n", N_getValue(*BT_getRoot((d.wordsBT))));
	printf("%c\n", N_getValue(*BT_getRoot(BT_getRightChild(d.wordsBT))));
	printf("%c\n", N_getValue(*BT_getRoot(BT_getLeftChild(BT_getRightChild(d.wordsBT)))));
	printf("%c\n", N_getValue(*BT_getRoot(BT_getLeftChild(BT_getLeftChild(BT_getRightChild(d.wordsBT))))));
	printf("%c\n", N_getValue(*BT_getRoot(BT_getLeftChild(BT_getLeftChild(BT_getLeftChild(BT_getRightChild(d.wordsBT)))))));
	CU_ASSERT_TRUE(1);
}

void test_D_wordIsIN(void)
{
	D_Dictionary dictionary = D_createDictionary();
	W_Word *word1, *word2, *word3, *word4, *word5, *word6, *word7, *word8, *word9;

	// ajout des mots
	m1 = W_createWord("voiturettE");
	D_add(m1, &d);
	m2 = W_createWord("voiture");
	D_add(m2, &d);
	m3 = W_createWord("aviation");
	D_add(m3, &d);
	m4 = W_createWord("motorola");
	D_add(m4, &d);
	m5 = W_createWord("moto");
	D_add(m5, &d);
	m6 = W_createWord("aller");
	D_add(m6, &d);
	m7 = W_createWord("Zblaaab");
	m8 = W_createWord("Zblaaa");
	D_add(m8, &d);
	m9 = W_createWord("Zblaaa");
	D_add(m9, &d);

	// tests contenu dictionary
	CU_ASSERT_TRUE(D_wordIsIN(m1, d));
	CU_ASSERT_TRUE(D_wordIsIN(m2, d));
	CU_ASSERT_TRUE(D_wordIsIN(m3, d));
	CU_ASSERT_TRUE(D_wordIsIN(m4, d));
	CU_ASSERT_TRUE(D_wordIsIN(m5, d));
	CU_ASSERT_TRUE(D_wordIsIN(m6, d));
	CU_ASSERT_FALSE(D_wordIsIN(m7, d));
	CU_ASSERT_TRUE(D_wordIsIN(m8, d));
	CU_ASSERT_TRUE(D_wordIsIN(m9, d));
}

int test_Dictionary(CU_pSuite pSuite)
{
	return ((NULL == CU_add_test(pSuite, "D_add", test_D_add)) || (NULL == CU_add_test(pSuite, "D_wordIsIN", test_D_wordIsIN)));
}

int main()
{
	CU_pSuite pSuite = NULL;

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	pSuite = CU_add_suite("Tests boite blanche", init_suite_success, clean_suite_success);
	if (NULL == pSuite)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if (test_Dictionary(pSuite))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRW_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");
}

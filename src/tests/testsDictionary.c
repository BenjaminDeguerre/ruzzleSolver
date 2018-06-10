/* Alexandre DUVAL - 03/01/2015 */
/* Alexandre DUVAL - 03/01/2015 */

#include <CUnit/Basic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BinaryTree.h"
#include "Dictionary.h"
#include "Grid.h"
#include "LinkedList.h"
#include "Square.h"

int init_suite_success(void) { return 0; }
int clean_suite_success(void) { return 0; }

void test_D_add(void) {
  D_Dictionary dictionary = D_createDictionary();
  W_Word *word1, *word2, *word3, *word4, *word5, *word6;

  // ajout des mots
  word1 = W_createWord("aller");
  D_add(word1, &dictionary);
  word2 = W_createWord("voitUre");
  D_add(word2, &dictionary);
  word3 = W_createWord("aviAtion");
  D_add(word3, &dictionary);
  word4 = W_createWord("wordotorola");
  D_add(word4, &dictionary);
  word5 = W_createWord("wordoto");
  D_add(word5, &dictionary);
  word6 = W_createWord("aller");
  D_add(word6, &dictionary);

  printf("begin test \n");
  printf("%c\n", N_getValue(*BT_getRoot(dictionary.wordsBT)));
  printf("%c\n", N_getValue(*BT_getRoot(BT_getLeftChild(
                     BT_getRightChild(BT_getRightChild(dictionary.wordsBT))))));

  printf("fin test\n");

  printf("%c\n", N_getValue(*BT_getRoot((dictionary.wordsBT))));
  printf("%c\n", N_getValue(*BT_getRoot(BT_getRightChild(dictionary.wordsBT))));
  printf("%c\n", N_getValue(*BT_getRoot(
                     BT_getLeftChild(BT_getRightChild(dictionary.wordsBT)))));
  printf("%c\n", N_getValue(*BT_getRoot(BT_getLeftChild(
                     BT_getLeftChild(BT_getRightChild(dictionary.wordsBT))))));
  printf("%c\n", N_getValue(*BT_getRoot(BT_getLeftChild(BT_getLeftChild(
                     BT_getLeftChild(BT_getRightChild(dictionary.wordsBT)))))));
  CU_ASSERT_TRUE(1);
}

void test_D_wordIsIN(void) {
  D_Dictionary dictionary = D_createDictionary();
  W_Word *word1, *word2, *word3, *word4, *word5, *word6, *word7, *word8, *word9;

  // ajout des mots
  word1 = W_createWord("voiturettE");
  D_add(word1, &dictionary);
  word2 = W_createWord("voiture");
  D_add(word2, &dictionary);
  word3 = W_createWord("aviation");
  D_add(word3, &dictionary);
  word4 = W_createWord("wordotorola");
  D_add(word4, &dictionary);
  word5 = W_createWord("wordoto");
  D_add(word5, &dictionary);
  word6 = W_createWord("aller");
  D_add(word6, &dictionary);
  word7 = W_createWord("Zblaaab");
  word8 = W_createWord("Zblaaa");
  D_add(word8, &dictionary);
  word9 = W_createWord("Zblaaa");
  D_add(word9, &dictionary);

  // tests contenu dictionary
  CU_ASSERT_TRUE(D_wordIsIN(word1, dictionary));
  CU_ASSERT_TRUE(D_wordIsIN(word2, dictionary));
  CU_ASSERT_TRUE(D_wordIsIN(word3, dictionary));
  CU_ASSERT_TRUE(D_wordIsIN(word4, dictionary));
  CU_ASSERT_TRUE(D_wordIsIN(word5, dictionary));
  CU_ASSERT_TRUE(D_wordIsIN(word6, dictionary));
  CU_ASSERT_FALSE(D_wordIsIN(word7, dictionary));
  CU_ASSERT_TRUE(D_wordIsIN(word8, dictionary));
  CU_ASSERT_TRUE(D_wordIsIN(word9, dictionary));
}

int test_Dictionary(CU_pSuite pSuite) {
  return ((NULL == CU_add_test(pSuite, "D_add", test_D_add)) ||
          (NULL == CU_add_test(pSuite, "D_wordIsIN", test_D_wordIsIN)));
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  pSuite = CU_add_suite("Tests boite blanche", init_suite_success,
                        clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (test_Dictionary(pSuite)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");
}

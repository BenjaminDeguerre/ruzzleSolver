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
#include "Utils.h"

int init_suite_success(void) { return 0; }
int clean_suite_success(void) { return 0; }

void test_createDictionary(void) {
  D_Dictionary dictionary = D_createDictionary();

  CU_ASSERT_EQUAL(D_size(dictionary), 0);
  CU_ASSERT(D_isEmpty(dictionary));

  D_delete(dictionary);
}

void test_wordIsIN(void) {
  D_Dictionary dictionary = D_createDictionary();
  W_Word *word1, *word2, *word3, *word4, *word5, *word6, *word7, *word8, *word9,
      *word10, *word11, *word12;

  word1 = W_createWord("voiturettE");
  D_add(*word1, &dictionary);
  word2 = W_createWord("voiture");
  D_add(*word2, &dictionary);
  word3 = W_createWord("aviation");
  D_add(*word3, &dictionary);
  word4 = W_createWord("wordotorola");
  D_add(*word4, &dictionary);
  word5 = W_createWord("wordoto");
  D_add(*word5, &dictionary);
  word6 = W_createWord("aller");
  D_add(*word6, &dictionary);
  word8 = W_createWord("Zblaaa");
  D_add(*word8, &dictionary);
  word9 = W_createWord("Zblaaa");
  D_add(*word9, &dictionary);

  word7 = W_createWord("Zblaaab");
  word10 = W_createWord("azer");
  word11 = W_createWord("qsdf");
  word12 = W_createWord("qsdf");

  CU_ASSERT_TRUE(D_wordIsIn(*word1, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word2, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word3, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word4, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word5, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word6, dictionary));
  CU_ASSERT_FALSE(D_wordIsIn(*word7, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word8, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word9, dictionary));
  CU_ASSERT_FALSE(D_wordIsIn(*word10, dictionary));
  CU_ASSERT_FALSE(D_wordIsIn(*word11, dictionary));
  CU_ASSERT_FALSE(D_wordIsIn(*word12, dictionary));

  D_delete(dictionary);
  W_delete(word1);
  W_delete(word2);
  W_delete(word3);
  W_delete(word4);
  W_delete(word5);
  W_delete(word6);
  W_delete(word7);
  W_delete(word8);
  W_delete(word9);
  W_delete(word10);
  W_delete(word11);
  W_delete(word12);
}

void test_serialize_deserialize(void) {
  D_Dictionary dictionary, temp;
  W_Word *word1, *word2, *word3, *word4, *word5, *word6, *word7, *word8, *word9,
      *word10, *word11, *word12;
  FILE *inputFile, *outputFile;

  inputFile = openFile("testDic.txt", "r+");
  outputFile = openFile("outTestDic.dat", "w");

  temp = readFile(inputFile);
  D_serialize(temp, outputFile);
  fclose(inputFile);
  fclose(outputFile);
  dictionary = D_unserialize("outTestDic.dat");

  word1 = W_createWord("voiturettE");
  word2 = W_createWord("voiture");
  word3 = W_createWord("aviation");
  word4 = W_createWord("wordotorola");
  word5 = W_createWord("wordoto");
  word6 = W_createWord("aller");
  word7 = W_createWord("Zblaaab");
  word8 = W_createWord("Zblaaa");
  word9 = W_createWord("Zblaaa");
  word10 = W_createWord("azer");
  word11 = W_createWord("qsdf");
  word12 = W_createWord("qsdf");

  inputFile = fopen("testFile", "r+");

  CU_ASSERT_TRUE(D_wordIsIn(*word1, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word2, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word3, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word4, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word5, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word6, dictionary));
  CU_ASSERT_FALSE(D_wordIsIn(*word7, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word8, dictionary));
  CU_ASSERT_TRUE(D_wordIsIn(*word9, dictionary));
  CU_ASSERT_FALSE(D_wordIsIn(*word10, dictionary));
  CU_ASSERT_FALSE(D_wordIsIn(*word11, dictionary));
  CU_ASSERT_FALSE(D_wordIsIn(*word12, dictionary));

  D_delete(dictionary);
  D_delete(temp);
  W_delete(word1);
  W_delete(word2);
  W_delete(word3);
  W_delete(word4);
  W_delete(word5);
  W_delete(word6);
  W_delete(word7);
  W_delete(word8);
  W_delete(word9);
  W_delete(word10);
  W_delete(word11);
  W_delete(word12);
}

int test_Dictionary(CU_pSuite pSuite) {
  return ((NULL == CU_add_test(pSuite, "test_createDictionary",
                               test_createDictionary)) ||
          (NULL == CU_add_test(pSuite, "test_wordIsIN", test_wordIsIN)) ||
          (NULL == CU_add_test(pSuite, "test_serialize_deserialize",
                               test_serialize_deserialize)));
}

int main() {
  CU_pSuite pSuite = NULL;

  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  pSuite =
      CU_add_suite("Tests white box", init_suite_success, clean_suite_success);
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

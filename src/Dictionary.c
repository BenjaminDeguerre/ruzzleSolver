/* Arthur HAMELIN - 10/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dictionary.h"

/* private */
W_Word *reduce(W_Word word) {
  if (W_getLength(word) == 1) {
    return W_createWord("");
  } else {
    char *string = subString(W_getString(word), 1, W_getLength(word) - 1);
    W_Word *newWord = W_createWord(string);
    free(string);
    return newWord;
  }
}

void insert(W_Word *word, BT_BinaryTree *tree) {
  BT_BinaryTree newTree;
  BT_BinaryTree tmp;
  N_Node *node;
  W_Word *wordReduced;

  if (W_getLength(*word) > 0) {
    wordReduced = reduce(*word);
    if (BT_isEmpty(*tree)) {
      node = N_createNode(W_getLength(*word) == 1, W_getIthCharacter(*word, 0));
      *tree = BT_addRoot(BT_createSBT(), BT_createSBT(), node, (ES_copy)N_copy);
      tmp = BT_getLeftChild(*tree);
      insert(wordReduced, &tmp);
      if (!BT_isEmpty(tmp)) {
        BT_setLeftChild(tree, tmp);
      }
    } else {
      if (W_getIthCharacter(*word, 0) > N_getValue(*BT_getRoot(*tree))) {
        tmp = BT_getRightChild(*tree);
        insert(word, &tmp);
        if (!BT_isEmpty(tmp)) {
          BT_setRightChild(tree, tmp);
        }
      } else {
        if (W_getIthCharacter(*word, 0) == N_getValue(*BT_getRoot(*tree))) {
          N_defineEnd(BT_getRoot(*tree), N_isLast(*BT_getRoot(*tree)) ||
                                             (W_getLength(*word) == 1));
          tmp = BT_getLeftChild(*tree);
          insert(wordReduced, &tmp);
          if (!BT_isEmpty(tmp)) {
            BT_setLeftChild(tree, tmp);
          }
        } else {
          node = N_createNode(W_getLength(*word) == 1,
                              W_getIthCharacter(*word, 0));
          newTree = BT_addRoot(BT_createSBT(), *tree node, (ES_copy)N_copy);
          *tree = newTree;
          tmp = BT_getLeftChild(*tree);
          insert(wordReduced, &tmp);
          if (!BT_isEmpty(tmp)) {
            BT_setLeftChild(tree, tmp);
          }
        }
      }
    }
    W_delete(wordReduced);
  }
}

void serializeTree(FILE *file, BT_BinaryTree *tree) {
  BT_BinaryTree brother;
  BT_BinaryTree cadet;

  fprintf(file, "%c\n", N_getValue(*BT_getRoot(*tree)));

  if (N_isLast(*BT_getRoot(*tree))) {
    fprintf(file, ";\n");
  }

  if (BT_isEmpty(BT_getLeftChild(*tree))) {
    fprintf(file, ".\n");
  } else {
    cadet = BT_getLeftChild(*tree);
    serializeTree(file, &cadet);
  }

  if (BT_isEmpty(BT_getRightChild(*tree))) {
    fprintf(file, ",\n");
  } else {
    brother = BT_getRightChild(*tree);
    serializeTree(file, &brother);
  }
}

int wordIsINR(char *stringToTest, BT_BinaryTree *tree) {
  char stringToTest, adjacentCurrentTree;
  char *newtStringToTest;
  BT_BinaryTree tmp;
  int res;

  assert(!BT_isEmpty(*tree));

  if (strlen(stringToTest) == 0) {
    res = 0;
  } else if (strlen(stringToTest) == 1) {
    stringToTest = stringToTest[0];
    adjacentCurrentTree = N_getValue(*BT_getRoot(*tree));
    if (stringToTest > adjacentCurrentTree) {
      tmp = BT_getRightChild(*tree);
      if (!BT_isEmpty(tmp)) {
        res = wordIsINR(stringToTest, &tmp);
      } else {
        res = -1;
      }
    } else if (stringToTest == adjacentCurrentTree) {
      if (N_isLast(*BT_getRoot(*tree))) {
        res = 1;
      } else {

        res = 0;
      }
    } else {
      res = -1;
    }
  } else {
    newtStringToTest = subString(stringToTest, 1, strlen(stringToTest) - 1);
    stringToTest = stringToTest[0];
    adjacentCurrentTree = N_getValue(*BT_getRoot(*tree));

    if (stringToTest > adjacentCurrentTree) {
      tmp = BT_getRightChild(*tree);
      if (!BT_isEmpty(tmp)) {
        res = wordIsINR(stringToTest, &tmp);
      } else {
        res = -1;
      }
    } else if (stringToTest == adjacentCurrentTree) {
      tmp = BT_getLeftChild(*tree);
      if (!BT_isEmpty(tmp)) {
        res = (wordIsINR(newtStringToTest, &tmp));
      } else {
        res = -1;
      }
    } else {
      res = -1;
    }
    free(newtStringToTest);
  }
  return res;
}

void unserializeTree(FILE *file, BT_BinaryTree *tree) {
  int LINE_LENGTH = 3;
  char line[LINE_LENGTH];

  if (fgets(line, LINE_LENGTH, file) != NULL) {
    if ((line[0] >= 97) && (line[0] <= 122)) {
      if (BT_isEmpty(*tree)) {
        N_Node *N1 = N_createNode(0, line[0]);
        *tree = BT_addRoot(BT_createSBT(), BT_createSBT(), N1, (ES_copy)N_copy);
        N_free(N1);
        unserializeTree(file, tree);
      } else if (!BT_isEmpty(*tree) && BT_isEmpty(BT_getLeftChild(*tree)) &&
                 !BT_isProcessed(tree)) {
        N_Node *N2 = N_createNode(0, line[0]);
        BT_setLeftChild(tree, BT_addRoot(BT_createSBT(), BT_createSBT(), N2,
                                         (ES_copy)N_copy));
        N_free(N2);
        BT_BinaryTree tmp1 = BT_getLeftChild(*tree);
        unserializeTree(file, &tmp1);
        BT_setLeftChild(tree, tmp1);
        unserializeTree(file, tree);
      } else

          if (!BT_isEmpty(*tree) && BT_isEmpty(BT_getRightChild(*tree))) {
        N_Node *N3 = N_createNode(0, line[0]);
        BT_setRightChild(tree, BT_addRoot(BT_createSBT(), BT_createSBT(), N3,
                                          (ES_copy)N_copy));
        N_free(N3);
        BT_BinaryTree tmp2 = BT_getRightChild(*tree);
        unserializeTree(file, &tmp2);
        BT_setRightChild(tree, tmp2);
      }
    }

    if (line[0] == ';' && line[1] == '\n') {
      N_defineEnd(BT_getRoot(*tree), 1);
      unserializeTree(file, tree);
    }

    if (line[0] == '.' && line[1] == '\n') {
      BT_setIsProcessed(tree, 1);
      unserializeTree(file, tree);
    }
  }
}

/* public */
D_Dictionary D_createDictionary() {
  errno = 0;
  D_Dictionary dictionary;

  dictionary.wordsBT = BT_createSBT();
  dictionary.size = 0;

  return dictionary;
}

int D_wordIsIN(W_Word *word, D_Dictionary dictionary) {
  char *stringToTest = W_getString(*word);
  return wordIsINR(stringToTest, &(dictionary.wordsBT));
}

int D_size(D_Dictionary dictionary) { return dictionary.size; }

void D_add(W_Word *word, D_Dictionary *dictionary) {
  insert(word, &((*dictionary).wordsBT));
  (*dictionary).size = (*dictionary).size + 1;
}

void D_remove(W_Word *word, D_Dictionary *dictionary) {}

int D_isEmpty(D_Dictionary *dictionary) {
  return BT_isEmpty((*dictionary).wordsBT);
}

int D_serialize(D_Dictionary dictionary, FILE *targetFile) {
  serializeTree(targetFile, &(dictionary.wordsBT));
  return 1;
}

D_Dictionary D_unserialize(char *pathToFile) {
  D_Dictionary dictionary = D_createDictionary();
  FILE *inputFile = fopen(pathToFIle, "r+");

  if (inputFile == NULL) {
    fprintf(stderr, "\tERROR : impossible to open %s, check if the file exists "
                    "and the permission on it.\n\t (Dictionary.c)\n",
            pathToFIle);
    exit(1);
  }
  unserializeTree(inputFile, &(dictionary.wordsBT));

  return d;
}

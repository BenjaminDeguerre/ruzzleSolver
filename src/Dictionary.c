#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dictionary.h"
#include "Utils.h"

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

void insert(W_Word word, BT_BinaryTree *tree) {
  BT_BinaryTree tmp;
  N_Node *node;
  W_Word *wordReduced;

  if (W_getLength(word) > 0) {
    wordReduced = reduce(word);
    if (BT_isEmpty(*tree)) {
      node = N_createNode(W_getLength(word) == 1, W_getIthCharacter(word, 0));
      BT_setNode(*tree, node);
      tmp = BT_createBT();
      insert(*wordReduced, &tmp);
      if (!BT_isEmpty(tmp)) {
        BT_setLeftChild(*tree, tmp);
      } else {
        BT_delete(tmp, N_delete);
      }
      N_delete(node);
    } else if (W_getIthCharacter(word, 0) > N_getValue(*BT_getRoot(*tree))) {
      if ((*tree)->rightChild != NULL) {
        tmp = BT_getRightChild(*tree);
      } else {
        tmp = BT_createBT();
      }
      insert(word, &tmp);
      if (!BT_isEmpty(tmp)) {
        BT_setRightChild(*tree, tmp);
      } else {
        BT_delete(tmp, N_delete);
      }
    } else if (W_getIthCharacter(word, 0) == N_getValue(*BT_getRoot(*tree))) {
      N_defineEnd(BT_getRoot(*tree),
                  N_isLast(*BT_getRoot(*tree)) || (W_getLength(word) == 1));
      if ((*tree)->leftChild != NULL) {
        tmp = BT_getLeftChild(*tree);
      } else {
        tmp = BT_createBT();
      }
      insert(*wordReduced, &tmp);
      if (!BT_isEmpty(tmp)) {
        BT_setLeftChild(*tree, tmp);
      } else {
        BT_delete(tmp, N_delete);
      }
    } else {
      node = N_createNode(W_getLength(word) == 1, W_getIthCharacter(word, 0));

      *tree = BT_addRoot(BT_createBT(), *tree, node, (EC_copy)N_copy);
      tmp = BT_getLeftChild(*tree);
      insert(*wordReduced, &tmp);
      N_delete(node);
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

  if (BT_getLeftChild(*tree) == NULL) {
    fprintf(file, ".\n");
  } else {
    cadet = BT_getLeftChild(*tree);
    serializeTree(file, &cadet);
  }

  if (BT_getRightChild(*tree) == NULL) {
    fprintf(file, ",\n");
  } else {
    brother = BT_getRightChild(*tree);
    serializeTree(file, &brother);
  }
}

int wordIsINR(char *stringToTest, BT_BinaryTree *tree) {
  assert(!BT_isEmpty(*tree));

  char charToTest, nodeValue;
  char *newtStringToTest;
  BT_BinaryTree tmp;
  int res;

  if (strlen(stringToTest) == 0) {
    res = 0;
  } else if (strlen(stringToTest) == 1) {
    charToTest = stringToTest[0];
    nodeValue = N_getValue(*BT_getRoot(*tree));

    if (charToTest > nodeValue) {
      tmp = BT_getRightChild(*tree);
      if (tmp != NULL) {
        res = wordIsINR(stringToTest, &tmp);
      } else {
        res = 0;
      }
    } else if (charToTest == nodeValue) {
      if (N_isLast(*BT_getRoot(*tree))) {
        res = 1;
      } else {
        res = 0;
      }
    } else {
      res = 0;
    }
  } else {
    newtStringToTest = subString(stringToTest, 1, strlen(stringToTest) - 1);
    charToTest = stringToTest[0];
    nodeValue = N_getValue(*BT_getRoot(*tree));

    if (charToTest > nodeValue) {
      tmp = BT_getRightChild(*tree);
      if (tmp != NULL) {
        res = wordIsINR(stringToTest, &tmp);
      } else {
        res = 0;
      }
    } else if (charToTest == nodeValue) {
      tmp = BT_getLeftChild(*tree);
      if (tmp != NULL) {
        res = (wordIsINR(newtStringToTest, &tmp));
      } else {
        res = 0;
      }
    } else {
      res = 0;
    }
    free(newtStringToTest);
  }
  return res;
}

void unserializeTree(FILE *file, BT_BinaryTree *tree) {
  int LINE_LENGTH = 3;
  char line[LINE_LENGTH];
  N_Node *node;
  BT_BinaryTree tmp;

  if (fgets(line, LINE_LENGTH, file) != NULL) {
    if ((line[0] >= 97) && (line[0] <= 122)) {
      if (BT_isEmpty(*tree)) {
        node = N_createNode(0, line[0]);
        BT_setNode(*tree, node);
        N_delete(node);
        unserializeTree(file, tree);
      } else if (!BT_isProcessed(*tree) && BT_getLeftChild(*tree) == NULL) {
        node = N_createNode(0, line[0]);
        tmp = BT_createBT();
        BT_setNode(tmp, node);
        BT_setLeftChild(*tree, tmp);
        N_delete(node);

        // Process left child.
        unserializeTree(file, &tmp);
        BT_setLeftChild(*tree, tmp);
        unserializeTree(file, tree);

      } else {
        node = N_createNode(0, line[0]);
        tmp = BT_createBT();
        BT_setNode(tmp, node);
        BT_setRightChild(*tree, tmp);
        tmp = BT_getRightChild(*tree);
        N_delete(node);

        unserializeTree(file, &tmp);
        BT_setRightChild(*tree, tmp);
      }
    }
    if (line[0] == ';' && line[1] == '\n') {
      N_defineEnd(BT_getRoot(*tree), 1);
      unserializeTree(file, tree);
    }

    if (line[0] == '.' && line[1] == '\n') {
      BT_setIsProcessed(*tree, 1);
      unserializeTree(file, tree);
    }
  }
}

D_Dictionary D_createDictionary() {
  errno = 0;
  D_Dictionary dictionary;

  dictionary.wordsBT = BT_createBT();
  dictionary.size = 0;

  return dictionary;
}

int D_wordIsIN(W_Word word, D_Dictionary dictionary) {
  char *stringToTest = W_getString(word);
  return wordIsINR(stringToTest, &(dictionary.wordsBT));
}

int D_size(D_Dictionary dictionary) { return dictionary.size; }

void D_add(W_Word word, D_Dictionary *dictionary) {
  insert(word, &((*dictionary).wordsBT));
  (*dictionary).size = (*dictionary).size + 1;
}

void D_remove(W_Word *word, D_Dictionary *dictionary) {}

int D_isEmpty(D_Dictionary dictionary) {
  return BT_isEmpty(dictionary.wordsBT);
}

int D_serialize(D_Dictionary dictionary, FILE *targetFile) {
  serializeTree(targetFile, &(dictionary.wordsBT));
  return 1;
}

D_Dictionary D_unserialize(char *pathToFile) {
  D_Dictionary dictionary = D_createDictionary();
  FILE *inputFile = fopen(pathToFile, "r+");

  if (inputFile == NULL) {
    fprintf(stderr,
            "\tERROR : Unable to open %s, check if the file exists "
            "and the permission on it.\n\t",
            pathToFile);
    exit(1);
  }
  unserializeTree(inputFile, &(dictionary.wordsBT));
  fclose(inputFile);
  return dictionary;
}

void D_delete(D_Dictionary dictionary) {
  BT_delete(dictionary.wordsBT, N_delete);
}
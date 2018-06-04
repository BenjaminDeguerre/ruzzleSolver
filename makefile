SRCDIR=src
LIBDIR=lib
BINDIR=bin
TESTDIR=tests
INCLUDEDIR=include
CC=gcc
AR=ar
CFLAGS=-Wall -pedantic -g -std=c99 -I$(INCLUDEDIR)
LDFLAGS=-L$(LIBDIR)
EXECRUZZLE=ruzzleSolver
EXECTRANSCODE=transcode
TESTEXECRUZZLE=tests

all : ruzzleSolver transcode tests

transcode : $(BINDIR)/$(EXECTRANSCODE)

$(BINDIR)/$(EXECTRANSCODE) : $(LIBDIR)/libdictionary.a $(LIBDIR)/liborderedlist.a $(LIBDIR)/libsearchbinarytree.a $(SRCDIR)/mainTranscode.o $(SRCDIR)/readFile.o $(SRCDIR)/openFile.o $(SRCDIR)/subString.o $(SRCDIR)/transcode.o
	$(CC) -o $@ $(SRCDIR)/readFile.o $(SRCDIR)/openFile.o $(SRCDIR)/subString.o $(SRCDIR)/transcode.o $(SRCDIR)/mainTranscode.o $(LDFLAGS) -ldictionary -lsearchbinarytree -lorderedlist

#ruzzleSolver
ruzzleSolver : $(BINDIR)/$(EXECRUZZLE)

$(BINDIR)/$(EXECRUZZLE) : $(LIBDIR)/libdictionary.a $(LIBDIR)/liborderedlist.a $(LIBDIR)/libsearchbinarytree.a $(SRCDIR)/Square.o $(SRCDIR)/AdjacentSquares.o $(SRCDIR)/Grid.o $(SRCDIR)/readFile.o $(SRCDIR)/openFile.o $(SRCDIR)/solveRuzzle.o $(SRCDIR)/createGridToSolve.o $(SRCDIR)/solveGrid.o $(SRCDIR)/mainRuzzleSolver.o $(SRCDIR)/subString.o $(SRCDIR)/isSolution.o $(SRCDIR)/Solution.o
	$(CC) -o $@ $(SRCDIR)/Square.o $(SRCDIR)/readFile.o $(SRCDIR)/openFile.o $(SRCDIR)/AdjacentSquares.o $(SRCDIR)/Grid.o $(SRCDIR)/createGridToSolve.o $(SRCDIR)/solveGrid.o $(SRCDIR)/solveRuzzle.o $(SRCDIR)/mainRuzzleSolver.o $(SRCDIR)/subString.o $(SRCDIR)/isSolution.o $(SRCDIR)/Solution.o $(LDFLAGS) -ldictionary -lsearchbinarytree -lorderedlist

$(LIBDIR)/libdictionary.a : $(SRCDIR)/Dictionary.o $(SRCDIR)/Word.o
	$(AR) -r $@ $^

$(LIBDIR)/liborderedlist.a : $(SRCDIR)/LinkedList.o
	$(AR) -r $@ $^

$(LIBDIR)/libsearchbinarytree.a : $(SRCDIR)/BinaryTree.o $(SRCDIR)/Node.o
	$(AR) -r $@ $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

# tests
tests : testsSubString testsNode testsSquare testsGrid testsDictionary testsWord testsLinkedList testsAdjacentSquares testsSolution

testsSubString : $(TESTDIR)/testsSubString

$(TESTDIR)/testsSubString : $(SRCDIR)/$(TESTDIR)/testsSubString.o $(SRCDIR)/subString.o
	 $(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsSubString.o $(SRCDIR)/subString.o -lcunit 
	 
testsSolution : $(TESTDIR)/testsSolution
	
$(TESTDIR)/testsSolution : $(SRCDIR)/$(TESTDIR)/testsSolution.o $(SRCDIR)/Solution.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsSolution.o $(SRCDIR)/Solution.o -lcunit

testsNode : $(TESTDIR)/testsNode
	
$(TESTDIR)/testsNode : $(SRCDIR)/$(TESTDIR)/testsNode.o $(SRCDIR)/Node.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsNode.o $(SRCDIR)/Node.o -lcunit
	
testsSquare : $(TESTDIR)/testsSquare

$(TESTDIR)/testsSquare : $(SRCDIR)/$(TESTDIR)/testsSquare.o $(SRCDIR)/Square.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsSquare.o $(SRCDIR)/Square.o -lcunit
	
testsGrid : $(TESTDIR)/testsGrid

$(TESTDIR)/testsGrid : $(SRCDIR)/$(TESTDIR)/testsGrid.o $(SRCDIR)/Grid.o $(SRCDIR)/Square.o $(SRCDIR)/LinkedList.o $(SRCDIR)/subString.o $(SRCDIR)/createGridToSolve.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsGrid.o $(SRCDIR)/Grid.o $(SRCDIR)/Square.o $(SRCDIR)/LinkedList.o $(SRCDIR)/subString.o $(SRCDIR)/createGridToSolve.o -lcunit

testsDictionary : $(TESTDIR)/testsDictionary

$(TESTDIR)/testsDictionary : $(SRCDIR)/$(TESTDIR)/testsDictionary.o $(SRCDIR)/BinaryTree.o $(SRCDIR)/Node.o $(SRCDIR)/Word.o $(SRCDIR)/subString.o $(SRCDIR)/Dictionary.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsDictionary.o $(SRCDIR)/BinaryTree.o $(SRCDIR)/Node.o $(SRCDIR)/Word.o $(SRCDIR)/subString.o $(SRCDIR)/Dictionary.o -lcunit
	
testsWord : $(TESTDIR)/testsWord

$(TESTDIR)/testsWord : $(SRCDIR)/$(TESTDIR)/testsWord.o $(SRCDIR)/Word.o $(SRCDIR)/Dictionary.o $(SRCDIR)/BinaryTree.o $(SRCDIR)/Node.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsWord.o $(SRCDIR)/Word.o $(SRCDIR)/subString.o $(SRCDIR)/Dictionary.o $(SRCDIR)/BinaryTree.o $(SRCDIR)/Node.o -lcunit

testsAdjacentSquares : $(TESTDIR)/testsAdjacentSquares

$(TESTDIR)/testsAdjacentSquares : $(SRCDIR)/$(TESTDIR)/testsAdjacentSquares.o $(SRCDIR)/AdjacentSquares.o $(SRCDIR)/Square.o $(SRCDIR)/Grid.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsAdjacentSquares.o $(SRCDIR)/AdjacentSquares.o $(SRCDIR)/Grid.o $(SRCDIR)/Square.o -lcunit -lorderedlist
	
testsLinkedList : $(TESTDIR)/testsLinkedList

$(TESTDIR)/testsLinkedList : $(SRCDIR)/$(TESTDIR)/testsLinkedList.o $(SRCDIR)/Word.o 
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsLinkedList.o $(SRCDIR)/Word.o -lcunit -lorderedlist

$(SRCDIR)/$(TESTDIR)/%.o : $(SRCDIR)/$(TESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)


clean : 
	rm -f bin/* 
	rm -f src/*.o 
	rm -f lib/*.a 
	rm -f src/tests/*.o 
	rm -f tests/*
	rm -f doc/latex/*
	
doc :
	doxygen -f doxyconfig
	

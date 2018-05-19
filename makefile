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
EXECTRANSCODER=transcoder
TESTEXECRUZZLE=tests

all : ruzzleSolver transcoder tests

#transoder
transcoder : $(BINDIR)/$(EXECTRANSCODER)

$(BINDIR)/$(EXECTRANSCODER) : $(LIBDIR)/libdictionnaire.a $(LIBDIR)/liblisteordonnee.a $(LIBDIR)/libarbrebinairederecherche.a $(SRCDIR)/mainTranscoder.o $(SRCDIR)/lireFichier.o $(SRCDIR)/ouvrirFichier.o $(SRCDIR)/sousChaine.o $(SRCDIR)/transcoder.o
	$(CC) -o $@ $(SRCDIR)/lireFichier.o $(SRCDIR)/ouvrirFichier.o $(SRCDIR)/sousChaine.o $(SRCDIR)/transcoder.o $(SRCDIR)/mainTranscoder.o $(LDFLAGS) -ldictionnaire -larbrebinairederecherche -llisteordonnee

#ruzzleSolver
ruzzleSolver : $(BINDIR)/$(EXECRUZZLE)

$(BINDIR)/$(EXECRUZZLE) : $(LIBDIR)/libdictionnaire.a $(LIBDIR)/liblisteordonnee.a $(LIBDIR)/libarbrebinairederecherche.a $(SRCDIR)/Case.o $(SRCDIR)/CasesContigues.o $(SRCDIR)/Grille.o $(SRCDIR)/lireFichier.o $(SRCDIR)/ouvrirFichier.o $(SRCDIR)/resoudreRuzzle.o $(SRCDIR)/creerGrilleAResoudre.o $(SRCDIR)/resoudreGrille.o $(SRCDIR)/mainRuzzleSolver.o $(SRCDIR)/sousChaine.o $(SRCDIR)/estUneSolution.o
	$(CC) -o $@ $(SRCDIR)/Case.o $(SRCDIR)/lireFichier.o $(SRCDIR)/ouvrirFichier.o $(SRCDIR)/CasesContigues.o $(SRCDIR)/Grille.o $(SRCDIR)/creerGrilleAResoudre.o $(SRCDIR)/resoudreGrille.o $(SRCDIR)/resoudreRuzzle.o $(SRCDIR)/mainRuzzleSolver.o $(SRCDIR)/sousChaine.o $(SRCDIR)/estUneSolution.o $(LDFLAGS) -ldictionnaire -larbrebinairederecherche -llisteordonnee

$(LIBDIR)/libdictionnaire.a : $(SRCDIR)/Dictionnaire.o $(SRCDIR)/Mot.o
	$(AR) -r $@ $^

$(LIBDIR)/liblisteordonnee.a : $(SRCDIR)/ListeChainee.o
	$(AR) -r $@ $^

$(LIBDIR)/libarbrebinairederecherche.a : $(SRCDIR)/BinaryTree.o $(SRCDIR)/Noeud.o
	$(AR) -r $@ $^

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

# tests
tests : testsSousChaine testsNoeud testsCase testsGrille testsDictionnaire testsMot testsListeChainee testsCasesContigues

testsSousChaine : $(TESTDIR)/testsSousChaine

$(TESTDIR)/testsSousChaine : $(SRCDIR)/$(TESTDIR)/testsSousChaine.o $(SRCDIR)/sousChaine.o
	 $(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsSousChaine.o $(SRCDIR)/sousChaine.o -lcunit 
	
testsNoeud : $(TESTDIR)/testsNoeud
	
$(TESTDIR)/testsNoeud : $(SRCDIR)/$(TESTDIR)/testsNoeud.o $(SRCDIR)/Noeud.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsNoeud.o $(SRCDIR)/Noeud.o -lcunit
	
testsCase : $(TESTDIR)/testsCase

$(TESTDIR)/testsCase : $(SRCDIR)/$(TESTDIR)/testsCase.o $(SRCDIR)/Case.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsCase.o $(SRCDIR)/Case.o -lcunit
	
testsGrille : $(TESTDIR)/testsGrille

$(TESTDIR)/testsGrille : $(SRCDIR)/$(TESTDIR)/testsGrille.o $(SRCDIR)/Grille.o $(SRCDIR)/Case.o $(SRCDIR)/ListeChainee.o $(SRCDIR)/sousChaine.o $(SRCDIR)/creerGrilleAResoudre.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsGrille.o $(SRCDIR)/Grille.o $(SRCDIR)/Case.o $(SRCDIR)/ListeChainee.o $(SRCDIR)/sousChaine.o $(SRCDIR)/creerGrilleAResoudre.o -lcunit

testsDictionnaire : $(TESTDIR)/testsDictionnaire

$(TESTDIR)/testsDictionnaire : $(SRCDIR)/$(TESTDIR)/testsDictionnaire.o $(SRCDIR)/BinaryTree.o $(SRCDIR)/Noeud.o $(SRCDIR)/Mot.o $(SRCDIR)/sousChaine.o $(SRCDIR)/Dictionnaire.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsDictionnaire.o $(SRCDIR)/BinaryTree.o $(SRCDIR)/Noeud.o $(SRCDIR)/Mot.o $(SRCDIR)/sousChaine.o $(SRCDIR)/Dictionnaire.o -lcunit
	
testsMot : $(TESTDIR)/testsMot

$(TESTDIR)/testsMot : $(SRCDIR)/$(TESTDIR)/testsMot.o $(SRCDIR)/Mot.o $(SRCDIR)/Dictionnaire.o $(SRCDIR)/BinaryTree.o $(SRCDIR)/Noeud.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsMot.o $(SRCDIR)/Mot.o $(SRCDIR)/sousChaine.o $(SRCDIR)/Dictionnaire.o $(SRCDIR)/BinaryTree.o $(SRCDIR)/Noeud.o -lcunit

testsCasesContigues : $(TESTDIR)/testsCasesContigues

$(TESTDIR)/testsCasesContigues : $(SRCDIR)/$(TESTDIR)/testsCasesContigues.o $(SRCDIR)/CasesContigues.o $(SRCDIR)/Case.o $(SRCDIR)/Grille.o
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsCasesContigues.o $(SRCDIR)/CasesContigues.o $(SRCDIR)/Grille.o $(SRCDIR)/Case.o -lcunit -llisteordonnee
	
testsListeChainee : $(TESTDIR)/testsListeChainee

$(TESTDIR)/testsListeChainee : $(SRCDIR)/$(TESTDIR)/testsListeChainee.o $(SRCDIR)/Mot.o 
	$(CC) $(LDFLAGS) -o $@ $(SRCDIR)/$(TESTDIR)/testsListeChainee.o $(SRCDIR)/Mot.o -lcunit -llisteordonnee

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
	

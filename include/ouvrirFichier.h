/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

/** \file ouvrirFichier.h
 *	\brief Contient la fonction qui permet d'ouvrir un fichier, exit(1) en cas d'échec
 *	\version 1.0
 *	\date 28/12/2014
 */
 
#ifndef __OUVRIR_FICHIER__
#define __OUVRIR_FICHIER__

#include <stdlib.h>
#include <stdio.h>

/**
 *	\fn FILE* ouvrirFichier(char *nomFichier, char *modeFichier);
 *	\brief ouvre un fichier dans le mode passé en entrée, si echec exit(1)
 *
 *	pour plus de détails sur les mode d'ouverture voir la fonction fopen
 *	\param *nomFichier nom du fichier
 *	\param *modeFichier, mode désiré ("r", "w",...)
 *	\return FILE*
 */
FILE* ouvrirFichier(char *nomFichier, char *modeFichier);

#endif

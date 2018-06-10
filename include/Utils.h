/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */

/** \file subString.h
 *	\brief Contient la fonction qui permet d'extraire une sous string d'une string de caractère
 *	\version 1.0
 *	\date 27/12/2014
 */

#ifndef __UTILS__
#define __UTILS__

/**
 *	\fn char *subString(char *string, int begin, int end)
 *	\brief extrait la sous string commençant a la position début et se finissant à fin
 *	
 *	Le premier caractère est à 0, par exemple : soustring("bonjour",1,2) = "on". Malloc est utilisé, un free est nécéssaire
 *	\param *string notre string de caractère
 *	\param begin la position de début de la string à extraire
 *	\param fin la position de fin de la string à extraire
 *	\return char*
 */
char *subString(char *string, int begin, int end);

#endif
/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 17/12/2014 */
/* Michel CRESSANT*/

/** \file readFile(FILE *file);
 *	\brief Contient la fonction qui permet dlie un file
 *	\version 1.0
 *	\date 05/01/2015
 */

#ifndef __READ_FILE__
#define __READ_FILE__

#include <string.h>

#include "Dictionary.h"

/**
 *	\fn D_Dictionary readFile(FILE *file);
 *	\brief Permet de read un file
 *	\param *file un pointeur sur un file
 *	\return D_Dictionary
 */
D_Dictionary readFile(FILE *file);

#endif
/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

/** \file openFile.h
 *	\brief Contient la fonction qui permet d'open un file, exit(1) en cas d'échec
 *	\version 1.0
 *	\date 28/12/2014
 */

#ifndef __OPEN_FILE__
#define __OPEN_FILE__

#include <stdlib.h>
#include <stdio.h>

/**
 *	\fn FILE* openFile(char *fileName, char *mode);
 *	\brief ouvre un file dans le mode passé en entrée, si echec exit(1)
 *
 *	pour plus de détails sur les mode d'ouverture voir la fonction fopen
 *	\param *fileName nom du file
 *	\param *mode, mode désiré ("r", "w",...)
 *	\return FILE*
 */
FILE *openFile(char *fileName, char *mode);

#endif

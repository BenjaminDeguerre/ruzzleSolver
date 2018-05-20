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

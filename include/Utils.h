/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */

/** \file subString.h
 *	\brief Contains all the utils function, i.e all the function that do not
 *belong to a "type". \version 1.0 \date 10/06/2018
 */

#ifndef __UTILS__
#define __UTILS__

#include "Dictionary.h"

/**
 *	\fn char *subString(char *string, int begin, int end)
 *	\brief Extract the subString from begin to end.
 *
 *	First char is a 0. This function uses a malloc.

 *	\param *string The string to extract the substring from.
 *	\param begin Starting position.
 *	\param fin Ending position.
 *	\return char*
 */
char *subString(char *string, int begin, int end);

/**
 *	\fn D_Dictionary readFile(FILE *file);
 *	\brief Read a file from a normal dictionary.
 *
 *	\param *file Pointer to a file.
 *	\return D_Dictionary
 */
D_Dictionary readFile(FILE *file);

/**
 *	\fn FILE* openFile(char *fileName, char *mode);
 *	\brief Open a file in provided mode.
 *
 *	\param *fileName
 *	\param *mode ("r", "w",...)
 *	\return FILE*
 */
FILE *openFile(char *fileName, char *mode);

#endif

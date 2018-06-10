/* Alexandre DUVAL - 17/12/2014 */
/* Arthur Hamelin - 05/01/2015 */

/** \file transcode.h
 *	\brief Contains the function to rewrite a dictionary in an intelligent
 *format faster to process.
 *	\version 1.0
 *	\date 05/01/2015
 */

#ifndef __TRANSCODER__
#define __TRANSCODER__

#include "Dictionary.h"
#include "Utils.h"

/**
 *	\fn int transcode(char *, char *)
 *	\brief Get a file source.txt and output an other file serialized as a
 *tree.
 *
 *	\param char* pointer to file name of the dictionary not serialized.
 *	\param char* pointer to file name of the dictionary once serialized.
 *	\return 1 if all goes well
 */

int transcode(char *, char *);

#endif

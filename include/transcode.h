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

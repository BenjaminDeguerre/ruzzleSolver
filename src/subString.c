/* Michel CRESSANT - 11/12/2014 */
/* Benjamin Deguerre - 17/12/2014 */

/* #define NDEBUG 
   decommenter pour annuler les tests
   de precondition
*/

/* partie privee */

/* partie publique */

#include "subString.h"
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

char *subString(char *string, int begin, int end)
{
	char *res = malloc(sizeof(char) * (end - begin + 2));
	res[end - begin + 1] = '\0';
	int i;

	assert(end >= begin);
	assert(end <= strlen(string));
	assert(begin >= 0);

	if (res == NULL)
	{
		errno = 1;
		exit(errno);
	}

	for (i = begin; i <= end; i++)
	{
		res[i - begin] = string[i];
	}

	return res;
}

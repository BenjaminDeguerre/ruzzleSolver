/* Michel CRESSANT - 11/12/2014 */
/* Benjamin Deguerre - 17/12/2014 */


/* #define NDEBUG 
   decommenter pour annuler les tests
   de precondition
*/

/* partie privee */

/* partie publique */


#include "sousChaine.h"
#include <assert.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
	
char *sousChaine(char *ch, int debut, int fin) {
	char *res = malloc(sizeof(char)*(fin - debut + 2));
	res[fin-debut+1] = '\0';
	int i;
	
	assert(fin >= debut);
	assert(fin <= strlen(ch));
	assert(debut >= 0);
	
	if (res == NULL) {
   		errno = 1;
    	exit(errno);
  	}

	for (i = debut; i <= fin; i++){
		res[i-debut] = ch[i];					
	}

	return res;	
}

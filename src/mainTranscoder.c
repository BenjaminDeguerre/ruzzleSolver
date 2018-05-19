/* Alexandre DUVAL - 06/12/14 */
/* Alexandre DUVAL - 31/12/14 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "transcoder.h"
 
int main(int argc, char** argv) {
	if (argc == 3) {
		transcoder(argv[1], argv[2]);
	} else {
		printf("usage : transcoder <dico-ref..> <dico intelligent>\n");
	}

	return EXIT_SUCCESS;
}
/* Alexandre DUVAL - 17/12/2014 */
/* Alexandre DUVAL - 31/12/2014 */

#include <stdlib.h>

#include "lireFichier.h"

D_Dictionnaire lireFichier(FILE *fichier) {
	D_Dictionnaire d = D_creerDictionnaire();
	char *ch = (char *)malloc(100 * sizeof(char));

	while (fscanf(fichier, "%s", ch) == 1) {  
		if (strcmp(ch, "Internet") != 0) {
			if (strcmp(ch, "Länder") == 0) {
				ch = "Lander";
			}

			M_Mot *m = M_creerMot(ch);
    		D_ajouter(m, &d);
    		M_supprimer((void *)m); 
    	}

  	}

  	free(ch);

	return d;
}

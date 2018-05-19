/* Michel CRESSANT - 11/12/2014 */
/* Alexandre DUVAL - 11/12/2014 */

#include "estUneSolution.h"

int estUneSolution(D_Dictionnaire *dico, char *chATester) {
	M_Mot *m = M_creerMot(chATester);
	int res = D_estContenu(m, *dico);
	M_supprimer(m);
	return res;	
}

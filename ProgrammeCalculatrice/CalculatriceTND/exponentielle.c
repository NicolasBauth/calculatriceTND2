#include "commun.h"
#include "exponentielle.h"

double exponentielle(double x, int nbDecimales) {
	double numerateur = x;
	double resultat = 1;
	double denominateur = 1;
	int i = 1;
	double resultatPrec = 0;
	while (i < ITERRATIONMAX && !verifDecimales(resultat, resultatPrec, nbDecimales + 1)) {
		resultatPrec = resultat;
		denominateur *= i;
		resultat += numerateur / denominateur;
		numerateur *= x;
		i++;
	}
	return resultat;
}
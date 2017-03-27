#include "commun.h"
#include "sinus.h"

double sinus(double x, int nbDecimales) {
	double resultat = x;
	double resultatPrec = 0;
	double terme = resultat;
	for (int i = 1; i < ITERRATIONMAX && !verifDecimales(resultat, resultatPrec, nbDecimales + 1); i += 2) {
		resultatPrec = resultat;
		terme *= ((-x*x) / ((i + 1)*(i + 2)));
		resultat += terme;
	}
	return resultat;
}

double conversionDegreToRadiant(double degre) {
	while (degre > ANGLECERCLE && degre > 0) {
		degre -= ANGLECERCLE;
	}
	while (degre < 0 && degre < ANGLECERCLE) {
		degre += ANGLECERCLE;
	}
	return degre * PI / DEMICERCLE;
}
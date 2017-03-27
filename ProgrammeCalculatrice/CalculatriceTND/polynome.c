#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynome.h"


double newtonRaphson(double x0, double tabCoefficients[], int tailleTableau) {
	double x = x0;
	for (int i = 0; i < 20; i++) {
		x -= f(x, tabCoefficients, tailleTableau) / fprime(x, tabCoefficients, tailleTableau);
	}
	return x;
}

double f(double x, double tabCoefficients[], int tailleTableau) {
	double resultat = 0;
	for (int i = 0; i < tailleTableau; i++) {
		resultat += tabCoefficients[i] * pow(x, (tailleTableau - i - 1));
	}
	return resultat;
}

double fprime(double x, double tabCoefficients[], int tailleTableau) {
	double resultat = 0;
	for (int i = 0; i < tailleTableau; i++) {
		resultat += (tailleTableau - i) * pow(x, (tailleTableau - i - 2));
	}
	return resultat;
}

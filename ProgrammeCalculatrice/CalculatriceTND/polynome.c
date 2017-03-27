#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynome.h"


double newtonRaphson(double x0, double tabCoefficients[], int tailleTableau) {

	//printf("Iteration 0 : %.15f \n", x0);
	for (int i = 0; i < 200; i++) {
		x0 -= f(x0, tabCoefficients, tailleTableau) / fprime(x0, tabCoefficients, tailleTableau);
		//printf("Iteration %d : %.15f \n", i + 1, x0);
	}
	return x0;
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
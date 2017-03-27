//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//double polynome(double x);
//double polynomePrime(double x);
//
//double newtonRaphson(void) {
//	double x0 = 3;
//	int nbIter = 20;
//	//printf("Iteration 0 : %.15f \n", x0);
//	for (int i = 0; i < 20; i++) {
//		x0 -= f(x0) / fprime(x0);
//		//printf("Iteration %d : %.15f \n", i + 1, x0);
//	}
//	getchar();
//}
//
//double polynome(double x, double tabCoefficients[], int tailleTableau) {
//	double resultat = 0;
//	for (int i = 0; i < tailleTableau; i++)
//	{
//		resultat += tabCoefficients[i] * pow(x, (tailleTableau - i));
//	}
//	return resultat;
//}
//
//double polynomePrime(double x, double tabCoefficients[], int tailleTableau) {
//	double resultat = 0;
//	for (int i = 0; i < tailleTableau; i++) {
//		resultat += tabCoefficients[i] * (tailleTableau - i) * pow(x, tailleTableau - (i + 1));
//	}
//	return resultat;
//}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "constantes.h"
#include "prototypes.h"

void main(void) {
	bool ARecommencer = true;
	while (ARecommencer) {
		Choix operationMath = menu();
		system("cls");
		double resultat;
		double x;
		int nbDecimales;
		char continuer;
		switch (operationMath) {
			case EXPONENTIELLE:
				printf("exp(x)\n");
				printf("Valeur de x: ");
				scanf_s("%lf", &x);
				printf("Nombre de d�cimales correctes � afficher: ");
				scanf_s("%d", &nbDecimales);
				resultat = exponentielle(x, nbDecimales);
				break;
			case LOGNEPERIEN:
				printf("ln(1+x)\n");
				printf("Valeur de x: ");
				scanf_s("%lf", &x);
				while (x < -0.9) {
					printf("ln(%f+1) = ERREUR\n", x);
					printf("Valeur de x: ");
					scanf_s("%lf", &x);
				}
				printf("Nombre de d�cimales correctes � afficher: ");
				scanf_s("%d", &nbDecimales);
				resultat = logarithmeNep(x, nbDecimales);
				break;
			case SINUS:
				printf("sin(x)\n");
				printf("Valeur de x: ");
				scanf_s("%lf", &x);
				printf("Nombre de d�cimales correctes � afficher: ");
				scanf_s("%d", &nbDecimales);
				resultat = sinus(conversionDegreToRadiant(x), nbDecimales);
				break;
			case PROBABILITE:
			{
				double moyenne;
				double variance;
				printf("P(X <= x)\n");
				printf("Valeur de x:");
				scanf_s("%lf", &x);
				printf("Moyenne: ");
				scanf_s("%lf", &moyenne);
				printf("Variance: ");
				scanf_s("%lf", &variance);
				//resultat = probabilite(x, 5);
				break;
			}
			case POLYNOME:
				printf("Polynome de degre max 10");
				printf("Valeur de x0: \n");
				scanf_s("%lf", &x);
				printf("Nombre de d�cimales correctes � afficher: ");
				scanf_s("%d", &nbDecimales);
				//resultat = polynome(x, nbDecimales);
				break;
		}
		if (operationMath > 0 && operationMath < 6) {
			afficheDecimales(resultat, nbDecimales);
		}
		else {
			printf("Mauvais numero entre");
		}
		getchar();
		getchar();
		system("cls");
		printf("Voulez vous continuer (y/n)? ");
		scanf_s("%c", &continuer, 1);
		ARecommencer = tolower(continuer) != 'n';
	}

}

Choix menu(void) {
	Choix operationMath;
	printf("Calculatrice\n");
	printf("------------\n\n");
	printf("1 pour calculer exp(x)\n");
	printf("2 pour calculer ln(x+1)\n");
	printf("3 pour calculer sin(x)\n");
	printf("4 pour calculer P(X <= x)\n");
	printf("5 pour calculer un polynome de degre max 10\n");
	printf("Votre choix : ");
	scanf_s("%d", &operationMath);
	return operationMath;
}

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

double exponentielle(double x, int nbDecimales) {
	double numerateur = x;
	double resultat = 1;
	double denominateur = 1;
	int i = 1;
	double resultatPrec = 0;
	while (i < ITERRATIONMAX && !verifDecimales(resultat, resultatPrec, nbDecimales+1)) {
		resultatPrec = resultat;
		denominateur *= i;
		resultat += numerateur / denominateur;
		numerateur *= x;
		i++;
	}
	return resultat;
}

bool verifDecimales(double reel1, double reel2, int nbDecimales) {
	double puissance = pow(10, nbDecimales);
	return ((round(reel1*puissance) / puissance) == (round(reel2*puissance) / puissance));
}

void afficheDecimales(double reel, int nbDecimales) {
	printf("Resultat: %.*f \n", nbDecimales, reel);
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


double taylor(double x, int nbDecimales) {

	x -= 1;
	int degre = 1;
	double terme = x;
	double approx = terme;
	double epsilon = 0.5 * pow(10, -nbDecimales);

	while (degre < 50 && fabs(terme) > epsilon) {

		//printf("%d - %f\n", degre, approx);

		terme *= degre;
		terme *= -x;
		terme /= degre + 1;
		degre++;
		approx += terme;


	}

	return approx;
}

double logarithmeNep(double x, int nbDecimales) {
	int nbIter = 0;
	double reste = x + 1;
	while (reste > LNCALCUL) {
		reste /= LNCALCUL;
		nbIter++;

	}
	//printf("\n le nombre %f a %d fois 1.4\n", x+1, nbIter); 
	double lnA = taylor(LNCALCUL, nbDecimales);
	//printf("\n r�sultat ln(1.4) %f\n", lnA);
	double lnB = taylor(reste, nbDecimales);
	//printf("\n r�sultat ln(%f) %f\n", nb, lnB);
	double approxim = nbIter*lnA + lnB;
	return approxim;
}

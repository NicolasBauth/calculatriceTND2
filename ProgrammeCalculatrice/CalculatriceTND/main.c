#include "main.h"
#include "commun.h"
#include "exponentielle.h"
#include "logNep.h"
#include "polynome.h"
#include "sinus.h"
#include "probabilite.h"

double newtonRaphson(double x0, double tabCoefficients[], int tailleTableau);
double polynome(double x, double tabCoefficients[], int tailleTableau);
double polynomePrime(double x, double tabCoefficients[], int tailleTableau);

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
				printf("Nombre de décimales correctes à afficher: ");
				scanf_s("%d", &nbDecimales);
				resultat = exponentielle(x, nbDecimales);
				break;
			case LOGNEPERIEN:
				printf("ln(1+x)\n");
				printf("Valeur de x: ");
				scanf_s("%lf", &x);
				while (x < -0.9) {
					printf("ln(%f+1) = ERREUR\nAppuyez sur une touche pour continuer...\n", x);
					getchar();
					getchar();
					system("cls");
					printf("Valeur de x: ");
					scanf_s("%lf", &x);
				}
				printf("Nombre de décimales correctes à afficher: ");
				scanf_s("%d", &nbDecimales);
				resultat = logarithmeNep(x, nbDecimales);
				break;
			case SINUS:
				printf("sin(x)\n");
				printf("Valeur de x: ");
				scanf_s("%lf", &x);
				printf("Nombre de décimales correctes à afficher: ");
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
			{
				double tabCoefficients[11];
				double x0;
				printf("Polynome de degre max 10\n");
				printf("Valeur de x0: ");
				scanf_s("%lf", &x0);
				for (int i = 0; i < 11; i++) {
					printf("Valeur du coefficient %d: ", i+1);
					scanf_s("%lf", &tabCoefficients[i]);
				}
				printf("Nombre de décimales correctes à afficher: ");
				scanf_s("%d", &nbDecimales);
				//resultat = newtonRaphson(x, tabCoefficients, 11);
				break;
			}
		}
		if (operationMath > 0 && operationMath < 6) {
			afficheDecimales(resultat, nbDecimales);
		}
		else {
			printf("Mauvais numero entre\n");
		}
		printf("Appuyez sur une touche pour continuer...\n");
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



bool verifDecimales(double reel1, double reel2, int nbDecimales) {
	double puissance = pow(10, nbDecimales);
	return ((round(reel1*puissance) / puissance) == (round(reel2*puissance) / puissance));
}

void afficheDecimales(double reel, int nbDecimales) {
	printf("Resultat: %.*f \n", nbDecimales, reel);
}


void obtentionCoefficientsPolynome(double tabCoefficients[]) {
	for (int i = 10; i > 0; i--) {
		printf("Valeur de x%d: ", i);
		scanf_s("%lf", &tabCoefficients[i]);
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ITERRATIONMAX 200

enum choix {
	EXPONENTIELLE = 1,
	LOGNEPERIEN,
	SINUS,
	PROBABILITE,
	POLYNOME,
};

typedef enum choix Choix;

Choix menu(void);
bool verifDecimales(double reel1, double reel2, int nbDecimales);
void afficheDecimales(double reel, int nbDecimales);
double exponentielle(double x, int nbDecimales);

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
				printf("Valeur de x: \n");
				scanf_s("%lf", &x);
				printf("Nombre de décimales correctes à afficher: ");
				scanf_s("%d", &nbDecimales);
				resultat = exponentielle(x, nbDecimales);
				break;
			case LOGNEPERIEN:
				printf("ln(1+x)\n");
				printf("Valeur de x: \n");
				scanf_s("%d", &x);
				printf("Nombre de décimales correctes à afficher: ");
				scanf_s("%d", &nbDecimales);
				//resultat = logarithmeNep(x, nbDecimales);
				break;
			case SINUS:
				printf("sin(x)\n");
				printf("Valeur de x: \n");
				scanf_s("%d", &x);
				printf("Nombre de décimales correctes à afficher: ");
				scanf_s("%d", &nbDecimales);
				//resultat = sinus(x, nbDecimales);
				break;
			case PROBABILITE:
			{
				double moyenne;
				double variance;
				printf("P(X <= x)\n");
				printf("Valeur de x: \n");
				scanf_s("%d", &x);
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
				scanf_s("%d", &x);
				printf("Nombre de décimales correctes à afficher: ");
				scanf_s("%d", &nbDecimales);
				//resultat = polynome(x, nbDecimales);
				break;
		}
		afficheDecimales(resultat, nbDecimales);
		getchar();
		getchar();
		system("cls");
		printf("Voulez vous continuer (y/n)? ");
		scanf_s("%c", &continuer);
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


double exponentielle(double x, int nbDecimales) {
	double numerateur = x;
	double resultat = 1;
	double denominateur = 1;
	int i = 1;
	double resultatPrec = 0;
	while (i < ITERRATIONMAX && !verifDecimales(resultat, resultatPrec, nbDecimales)) {
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
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ITERRATIONMAX 200

bool verifDecimales(double reel1, double reel2, int nbDecimales);
void afficheDecimales(double reel, int nbDecimales);
double exp(double x, int nbDecimales);

double exp(double x, int nbDecimales) {
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
	afficheDecimales(resultat, nbDecimales);
}

bool verifDecimales(double reel1, double reel2, int nbDecimales) {
	double puissance = pow(10, nbDecimales);
	return ((round(reel1*puissance) / puissance) == (round(reel2*puissance) / puissance));
}

void afficheDecimales(double reel, int nbDecimales) {
	printf("%.*f \n", nbDecimales, reel);
}
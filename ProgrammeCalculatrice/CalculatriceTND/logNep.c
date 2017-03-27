#include "logNep.h"
#include "commun.h"

double taylor(double x, int nbDecimales) {
	x -= 1;
	int degre = 1;
	double terme = x;
	double approx = terme;
	double epsilon = 0.5 * pow(10, -nbDecimales);

	while (degre < 50 && fabs(terme) > epsilon) {
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
	double lnA = taylor(LNCALCUL, nbDecimales);
	double lnB = taylor(reste, nbDecimales);
	double approxim = nbIter*lnA + lnB;
	return approxim;
}
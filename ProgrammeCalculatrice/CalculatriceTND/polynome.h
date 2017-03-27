#ifndef POLYNOME_H

#define POLYNOME_H

double newtonRaphson(double x0, double tabCoefficients[], int tailleTableau);
double f(double x, double tabCoefficients[], int tailleTableau);
double fprime(double x, double tabCoefficients[], int tailleTableau);

#endif

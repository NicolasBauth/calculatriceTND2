#ifndef PROTOTYPES_H

#define PROTOTYPES_H
#include "enum.h"

Choix menu(void);
bool verifDecimales(double reel1, double reel2, int nbDecimales);
void afficheDecimales(double reel, int nbDecimales);
double exponentielle(double x, int nbDecimales);
double sinus(double x, int nbDecimales);
double conversionDegreToRadiant(double degre);
double taylor(double x, int nbDecimales);
double logarithmeNep(double x, int nbDecimales);

#endif
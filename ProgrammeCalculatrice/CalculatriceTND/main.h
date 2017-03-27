#ifndef MAIN_H

#define MAIN_H

#define NBCOEFFICIENTS 11

enum choix {
	EXPONENTIELLE = 1,
	LOGNEPERIEN,
	SINUS,
	PROBABILITE,
	POLYNOME,
};

typedef enum choix Choix;

Choix menu(void);
void obtentionCoefficientsPolynome(double tabCoefficients[]);

#endif
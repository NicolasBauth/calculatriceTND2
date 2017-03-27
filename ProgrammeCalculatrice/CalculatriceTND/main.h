#ifndef MAIN_H

#define MAIN_H

enum choix {
	EXPONENTIELLE = 1,
	LOGNEPERIEN,
	SINUS,
	PROBABILITE,
	POLYNOME,
};

typedef enum choix Choix;

Choix menu(void);

#endif
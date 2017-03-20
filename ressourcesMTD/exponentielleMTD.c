#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define DEGREMAX 200
void main(void)
{
	double x;
	int degre = 0;
	double approximation = 1;
	double terme = 1;

	printf("Entrez une valeur de x : ");
	scanf_s("%lf", &x);

	printf("Degre %d :  %.15f\n", degre, approximation);

	do 
	{
		degre++;
		terme *= x / degre;
		approximation += terme;		
		printf("Degre %d :  %.15f\n", degre, approximation);
	} while (degre < DEGREMAX && fabs(terme) >= 0.0000000001);
	//fabs retourne la valeur absolue de son argument

	system("pause");
}

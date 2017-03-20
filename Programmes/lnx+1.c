#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main (void){

	int x = 0;
	int nbDecimales = 0;

	printf("Entrez x\n");
	scanf("%d", &x);

        printf("Entrez nbDecimales\n");
        scanf("%d", &nbDecimales);

	int degre = 1;
	double terme = x;
	double approx = terme;
	double epsilon = 0.5 * pow(10,-nbDecimales);

	while(degre < 100 && fabs(terme) > epsilon){

		printf("%d - %f", degre, approx);
		degre++;
		terme = (terme * -x) / (degre+1);
		approx += terme;
	

	}
	

}

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double taylor(double x, int nbDecimales){
	
	x -= 1;
	int degre = 1;
        double terme = x;
        double approx = terme;
	double epsilon = 0.5 * pow(10,-nbDecimales);

	while(degre < 50 && fabs(terme) > epsilon){

                //printf("%d - %f\n", degre, approx);

                terme *= degre;
                terme *= -x;
                terme /= degre+1;
                degre++;
                approx += terme;


        }

	return approx;
}

int main (void){

	double x = -1;
        int nbDecimales = 0;

        while (x < -0.9){
                printf("Entrez x\n");
                scanf("%lf", &x);
                if(x < -0.9) printf("ln(%f+1) = ERREUR\n", x);
        }

        printf("Entrez nbDecimales\n");
        scanf("%d", &nbDecimales);

	int nbIter = 0;
	double reste = x + 1;
	while(reste > 1.4){
		reste /= 1.4;
		nbIter++;
		
	}

	//printf("\n le nombre %f a %d fois 1.4\n", x+1, nbIter); 

	double lnA = taylor(1.4, nbDecimales);

	//printf("\n résultat ln(1.4) %f\n", lnA);

	double lnB = taylor(reste, nbDecimales);

	//printf("\n résultat ln(%f) %f\n", nb, lnB);

	double approxim = nbIter*lnA+lnB;
	return approxim;

}

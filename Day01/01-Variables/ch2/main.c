#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float C = 0.0f;
    float K = 0.0f;
    

    printf("Donner la temperature en Celsius: ");
    scanf("%f", &C);

    K = C + 273.15;

    printf("la temperature en Kelvin: %.2f K", K);
	return 0;
}

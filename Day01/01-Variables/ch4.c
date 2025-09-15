#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float kph = 0.0f;
    float mps = 0.0f;
    
    printf("Donner la vitesse en kilomètres par heure (km/h): ");
    scanf("%f", &kph);
    
    mps = kph * 0.27778;
    
    printf("La vitesse en metre par seconde : %.2f m/s", mps);
    
	return 0;
}

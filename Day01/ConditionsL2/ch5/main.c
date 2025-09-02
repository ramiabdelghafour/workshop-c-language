#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, base, exposant, resultat = 1;
	
	printf("donner la base: ");
	scanf("%d", &base);
	
	printf("donner l'exposant: ");
	scanf("%d", &exposant);
	
	for(i = 1; i <= exposant; i++ ){
		resultat *= base;
	}
	printf("la resulat: %d", resultat);
	return 0;
}

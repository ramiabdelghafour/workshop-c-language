#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float L = 0.0;
	float l = 0.0;
	float S = 0.0;
	
	printf("donner la largeur: ");
	scanf("%f", &L);
	printf("donnet la longeur: ");
	scanf("%f", &l);
	
	S = L * l ;
	
	printf("la surface est: %.2f", S);
	return 0;
}

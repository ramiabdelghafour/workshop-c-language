#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a = 0, b = 0, c = 0, MG = 0;
	
	
	printf("Saisir trois nombres: \n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	MG = (a * b * c)^(1/3);
	
	printf("Moyenne géométrique: %d", MG);
	
	return 0;
}

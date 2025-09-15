#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n1, n2, n3;
	float moyenne = 0;
	printf("Donner trois nombres:\n");
	printf("Nombre 1: ");
	scanf("%d", &n1);
	printf("Nombre 2: ");
	scanf("%d", &n2);
	printf("Nombre 3: ");
	scanf("%d", &n3);
	
	moyenne = (n1 * 2 + n2 * 3 + n3 * 5)/(2 + 3 +5);
	
	printf("Le moyenne est : %.2f", moyenne);
	return 0;
}

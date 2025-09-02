#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a = 0, b = 0, x = 0;
	
	printf("Donner deux nombre:\n");
	printf("a: ");
	scanf("%d", &a);
	
	printf("b: ");
	scanf("%d", &b);
	
	x = pow(a + b, 2);
	
	printf("Sollution x = %d", x);
	
	
	return 0;
}

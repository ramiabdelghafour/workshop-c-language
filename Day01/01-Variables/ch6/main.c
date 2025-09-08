#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a;
	int b;
	
	printf("donner deux nombres: \n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	
	printf("a + b = %d\n", a + b);
	printf("a + b = %d\n", a - b);
	printf("a + b = %d\n", a * b);
	printf("a + b = %d\n", a / b);
	return 0;
}

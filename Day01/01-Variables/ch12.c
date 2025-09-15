#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	
	printf("donner un nombre a quatre chiffres: ");
	scanf("%d", &n);
	
	n1 = n % 10;
	n2 = (n/10) % 10;
	n3 = (n/100) % 10;
	n4 = (n/1000) % 10;
	
	printf("l`inverse: %d%d%d%d", n1, n2, n3, n4);
	return 0;
}

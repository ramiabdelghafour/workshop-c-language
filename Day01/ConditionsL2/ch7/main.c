#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	int resultat = 0;
	
	printf("donner un nombre: ");
	scanf("%d", &n);
	
	while(n>0){
		resultat = resultat * 10 + n % 10;
		n /= 10;
	}
	 printf("%d", resultat);
	return 0;
}

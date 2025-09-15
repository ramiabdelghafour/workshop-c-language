#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	
	printf("donner un nombre: ");
	scanf("%d", &n);
	
	if(n % 2 == 0){
		printf("le nombre est pair.");
	}else printf("le nombre est impair.");
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n;
	
	printf("Donner un nombre: ");
	scanf("%d", &n);
	
	if(n > 0){
		printf("Le nombre entrer est POSITIF.");
	}else if(n < 0){
		printf("Le nombre entrer est NEGATiVE.");
	}else printf("Le nombre entrer est NUL.");
	
	return 0;
}

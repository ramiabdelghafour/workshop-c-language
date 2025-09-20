#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i;
	int tab[n];
	int somme = 0;
	
	printf("entrer la taille du tableau:");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
		somme += tab[i];
	}
	
	
	printf("\nle tableau:\n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, tab[i]);
	}
	
	printf("la somme des elements est: %d", somme);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, n, f;
	
	printf("donner la taille du tableau: ");
	scanf("%d", &n);
	
	printf("donner la facteur: ");
	scanf("%d", &f);
	
	
	int tab[n];
	
	printf("\nenter les valeurs: \n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
	}
	
	printf("\nle tableau resultant: \n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, tab[i]*f);
	}	
	
	
	return 0;
}

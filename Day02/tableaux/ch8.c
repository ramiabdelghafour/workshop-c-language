#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i ;
	
	printf("donner la taille du tableau: ");
	scanf("%d", &n);
	
	int original[n], copie[n];
	
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &original[i]);
	}
	
	for(i = 0; i < n; i++){
	 copie[i] = original[i];
	}
	
	printf("\nle original:\n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, original[i]);
	}
	
	printf("\nla copie: \n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, copie[i]);
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void saisir(int tab[], int n){
	int i;
	for (i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
	}
}

void afficher(int tab[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, tab[i]);
	}
}

int main(int argc, char *argv[]) {
	int n1, n2;

	printf("donner la taille du 1er tab: ");
	scanf("%d", &n1);
	
	int tab1[n1];
	
	saisir(tab1, n1);
	printf("\nle 1er tableau:\n");
	afficher(tab1, n1);
	
	
	printf("donner la taille du 2eme tab: ");
	scanf("%d", &n2);
	
	int tab2[n2];
	
	saisir(tab2, n2);
	printf("\nle 2eme tableau:\n");
	afficher(tab2, n2);
	
	return 0;
}

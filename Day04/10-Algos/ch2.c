#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void saisir(int tab[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
	}
}

void afficher(int tab[], int n, char message[]){
	int i;
	printf("\n%s\n", message);
	for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, tab[i]);
	}
}

void insertionSort(int tab[], int n){
	int i, j, key;
	for(i = 1; i < n; i++){
		key = tab[i];
		j = i - 1;
		while(j >= 0 && tab[j] > key){
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = key;
	}
}


int main(int argc, char *argv[]) {
	int n;
	
	printf("enter la taille de tableau: ");
	scanf("%d", &n);
	
	int tab[n];
	
	saisir(tab, n);
	afficher(tab, n, "tableau avant le tri:");
	
	insertionSort(tab, n);
	afficher(tab, n, "tableau apres le tri:");

	return 0;
}

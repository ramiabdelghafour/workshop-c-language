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
		printf("tab[%d]: %d \n", i + 1, tab[i]);
	}
}

void selectionSort(int tab[], int n){
	int i, j, temp, min;
	for(i = 0; i < n - 1; i++){
		min = i;
		for(j = i + 1; j < n; j++){
			if(tab[j] < tab[min]){
				min = j;
			}
		}
		temp = tab[i];
		tab[i] = tab[min];
		tab[min] = temp;
	}
}

int main(int argc, char *argv[]) {
	int n;
	
	printf("enter la taille du tableau: ");
	scanf("%d", &n);
	
	int tab[n];
	
	saisir(tab, n);
	afficher(tab ,n , "le tableau avant de tri: ");
	
	selectionSort(tab, n);
	afficher(tab, n, "le tableau apres de tri: ");
	
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void saisir(int tab[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("bulle N%d: ", i + 1);
		scanf("%d", &tab[i]);
	}
}

void afficher(int tab[], int n, char message[]){
	int i;
	printf("%s", message);
	for(i = 0; i < n; i++){
		printf("bulle N%d: %d\n", i + 1, tab[i]);
	}
}

void bulleTri(int tab[], int n){
	int temp;
	int i;
	int j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n - 1; j++ ){
			if(tab[j] > tab[j+1]){
				temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp;			}
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	
	printf("donner les nombres des bulles :");
	scanf("%d", &n);
	
	int tableau[n];
	
	saisir(tableau, n);
	afficher(tableau, n, "\ntableau avant le tri:\n");
	
	bulleTri(tableau, n);
	afficher(tableau, n, "\ntableau apres le tri:\n");
	
	return 0;
}

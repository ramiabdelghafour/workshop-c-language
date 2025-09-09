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

int exister(int tab[], int n,int val){
	int i;
	for(i  = 0; i < n; i++){
		if(tab[i] == val) return 1;
	}
	return 0;
}

int fusion(int tab1[], int n1,int tab2[], int n2,int tab3[]){
	int i, k = 0;
	for(i = 0; i < n1; i++){
		if(!exister(tab3, k, tab1[i])){
			tab3[k++] = tab1[i];
		}
	}
	for(i = 0; i < n2; i++){
		if(!exister(tab3, k, tab2[i])){
			tab3[k++] = tab2[i];
		}
	}
	return k;
}

void bubbleSort(int tab[], int n){
	int i, j, temp;
	for(i = 0; i < n, i++){
		for(j = 0; i < n; j++){
			if()
		}
	}
}

int main(int argc, char *argv[]) {
	int n1, n2;

//tableau 1
	printf("donner la taille du 1er tab: ");
	scanf("%d", &n1);
	int tab1[n1];
	saisir(tab1, n1);
	printf("\n 1er tableau:\n");
	afficher(tab1, n1);

//tableau 1
	printf("\ndonner la taille du 2eme tab: ");
	scanf("%d", &n2);
	int tab2[n2];
	saisir(tab2, n2);
	printf("\n 2eme tableau:\n");
	afficher(tab2, n2);

//tableau 3	
	int tab3[n1 + n2];
	int n3 = fusion(tab1, n1, tab2, n2, tab3);
	fusion(tab1, n1, tab2, n2, tab3);
	printf("\n 3eme tableau:\n");
	afficher(tab3, n3);

//tableau trier
	
	return 0;
}

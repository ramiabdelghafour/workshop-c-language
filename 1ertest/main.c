#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i;
	
	printf("donner la taille du tableau:");
	scanf("%d", &n);
	
	int tab[n];
	
	printf("saisir les valeurs: \n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
	}
	
	int somme = 0;
	printf("\nle tableau: \n");
		for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, tab[i]);
		somme += tab[i];
	}

// minimum
	int min = tab[0];
	
	for(i = 0; i < n; i++){
		if(tab[i] < min){
			min = tab[i];
		}
	}

	printf("\nle minimum : %d", min);
	
// maximum
	int max = tab[0];
	
	for(i = 0; i < n; i++){
		if(tab[i] > max){
			max = tab[i];
		}
	}

	printf("\nle maximum : %d", max);	
	
// la somme 
	
	printf("\nla somme: %d\n", somme);

// tri
	int j, temp;
	for(i = 0; i < n; i++){
		for(j = 0; j < n - i - 1;j++){
			if(tab[j] > tab[j + 1]){
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;	
			}
		}
	}

	printf("\nle tableau: \n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, tab[i]);
	}
	
	return 0;
}

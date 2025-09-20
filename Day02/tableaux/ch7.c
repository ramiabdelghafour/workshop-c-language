#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i, j, temp;
	
	printf("donner la taille du tableau: ");
	scanf("%d", &n);
	
	int tab[n];
	
	printf("\nenter les valeurs:\n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n - i -1; j++){
			if(tab[j] > tab[j + 1] ){
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

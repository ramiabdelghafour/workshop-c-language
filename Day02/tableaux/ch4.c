#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, j, n, max;
	
	printf("donner la taille de tableau: ");
	scanf("%d", &n);
	
	int tab[n];
	
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
	}
	
	max = tab[0];
	
	for(i = 0; i < n; i++){
		if(tab[i] > max){
			max = tab[i];
		}
	}
	printf("le maximum: %d", max);

	return 0;
}

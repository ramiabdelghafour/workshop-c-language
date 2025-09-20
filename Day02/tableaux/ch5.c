#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i, min;
	
	printf("donner la taille du tableau: ");
	scanf("%d", &n);
	
	int tab[n];
	
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
	}
	
	min = tab[0];
	for(i = 0; i < n; i++){
		if(tab[i] < min){
			min = tab[i];
		}
	}
	
	printf("le minimum est: %d", min);
	return 0;
}

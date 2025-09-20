#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i, rech;
	
	printf("enter la taille du tableau: ");
	scanf("%d", &n);
	
	int tab[n];
	
	printf("enter les valeurs: \n");	
	for(i = 0; i < n; i++){
		printf("tab[%d]: ", i + 1);
		scanf("%d", &tab[i]);
	}
	
	printf("le tableau: \n");
	for(i = 0; i < n; i++){
		printf("tab[%d]: %d\n", i + 1, tab[i]);
	}
	
	printf("enter l`element a rechercher: ");
	scanf("%d", &rech);
	
	int trouve = 0;
	
	for(i = 0; i < n; i++){
		if(rech == tab[i]){
			printf("element trouver %d", tab[i]);
			trouve = 1;
			break;
		}
	}
	
	if(trouve == 0){
		printf("element non trouve");
	}
	return 0;
}

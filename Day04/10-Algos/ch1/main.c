#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	int nombre;
	int i, j, temp;
	
	printf("donner le nombres de bulles: ");
	scanf("%d", &nombre);

	int tab[nombre];
		
	for(i = 0; i < nombre ; i++){
		printf("bulle N%d: ", i + 1);
		scanf("%d", &tab[i]);
	}
	
	printf("tableau avant le tri: \n");
	for(i = 0; i < nombre; i++){
		printf("bulle N%d: %d\n", i + 1, tab[i]);
	}
	
	for(i = 0; i < nombre; i++){
		for(j = 0; j < nombre - 1; j++){
			if(tab[j] > tab[j + 1]){
				temp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = temp; 
			}
		}
	}
	
	printf("tableau apres le tri: \n");
	for(i = 0; i < nombre; i++){
		printf("bulle N%d: %d\n", i + 1, tab[i]);
	}
	
	return 0;
}

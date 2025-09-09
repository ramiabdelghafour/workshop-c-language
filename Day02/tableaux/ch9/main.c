#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	int tab[] = {1, 2, 3, 4, 5};
	
	printf("\ntableau original: \n");
	for(i = 0;i < 5; i++){
		printf("%d ", tab[i]);
	}
	
	printf("\ninverse:\n");
	
	for(i = 4; i >= 0; i--){
	printf("%d ", tab[i]);
	}
	return 0;
}

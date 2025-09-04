#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char chaine[50];
	
	printf("enter une chaîne de caractères:");
	scanf("%s", chaine);
	
	int lenght = strlen(chaine);
	int i;
	for(i = lenght - 1 ; i >= 0; i--){
		putchar(chaine[i]);
	}
	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char chaine[50];
	
	printf("enter une chaine de caractere: ");
	scanf("%s", chaine);
	
	int i;
	for(i = 0; i < strlen(chaine); i++){
		chaine[i] = tolower(chaine[i]);
		printf("%c", chaine[i]);
	}
	
	return 0;
}

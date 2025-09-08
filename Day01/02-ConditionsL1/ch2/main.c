#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char caractere = ' ';
	
	printf("saisir un caractere: ");
	scanf("%c", &caractere);
	
	switch(caractere){
		case 'a': case 'A': 
		case 'e': case 'E':
		case 'i': case 'I':
		case 'o': case 'O': 
		case 'u': case 'U':
		case 'y': case 'Y':
			printf("le caractere saisi est un voyelle.");
			break;
		default:
			printf("le caractere saisi n`est pas un voyelle.");
	}
	return 0;
}

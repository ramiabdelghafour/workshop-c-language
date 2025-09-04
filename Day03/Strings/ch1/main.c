#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char chaine[100];
	
	printf("enter un text:");
	fgets(chaine, sizeof(chaine), stdin);
	
	printf("le Text: %s", chaine);
	return 0;
}

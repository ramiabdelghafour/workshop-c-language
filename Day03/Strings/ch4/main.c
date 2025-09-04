#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char chaine1[20];
	char chaine2[20];
	
	printf("entrer deux chaine:\n");
	printf("chaine1:");
	scanf("%s", chaine1);
	printf("chaine2:");
	scanf("%s", chaine2);
	
	int cmp = strcmp(chaine1, chaine2);
	
	if(cmp == 0){
		printf("les chaines sont egales.\n");
	}else
	printf("les chaines ne sont pas egales!\n");
	return 0;
}

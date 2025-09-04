#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char chaine[100];
	int i;
	printf("entrez une chaine: ");
    gets(chaine);

    while (chaine[i] != '\0') {
        i++;
    }

    printf("longueur: %d\n", i);

	return 0;
}

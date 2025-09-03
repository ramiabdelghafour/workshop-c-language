#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int n = 0;
    int i;

    printf("donner le nombre d'elements d'un tableau: ");
    scanf("%d", &n);

    int tab[n];

    for(i = 0; i < n; i++) {
        printf("entrer element %d : ", i + 1);
        scanf("%d", &tab[i]);
    }

    for(i = 0; i < n; i++) {
        printf("%d\n", tab[i]);
    }

	
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, i, j;
	
    printf("Entrer un nombre: ");
    scanf("%d",&a);
    for(i =1;i<=10;i++){
    	j = a * i;
        printf("%d * %d = %d\n", a, i, j);
    }
	return 0;
}

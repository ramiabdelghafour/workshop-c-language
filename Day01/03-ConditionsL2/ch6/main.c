#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, z = 0;
	
	printf("donner un nombre: ");
	scanf("%d", &n);
	
	while(n>0){
		printf("%d ", z);
		z +=2;
		n --;
	}
	return 0;
}1

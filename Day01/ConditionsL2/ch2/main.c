#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i, n, facto;
	
	printf("donner un nombre: ");
	scanf("%d", &n);
	
	for(i = 1 ; i <= n; i++){
		facto *= i;
	}
	printf("%d", facto);
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a = 0, b = 0, s = 0;
	
	printf("donner deux nombre: \n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d",  &b);
	
	if(a == b){
		s = (a + b) * 3;
	}else {
		s = a + b;
	}
	printf("la resulta: %d", s);
	
	return 0;
}

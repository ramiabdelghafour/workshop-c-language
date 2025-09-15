#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a, b, c;
	double delta;
	double x , x1 , x2;
	
	printf("Donner trois nombres entiers");
	printf("\na = ");
	scanf("%d", &a);
	printf("\nb = ");
	scanf("%d", &b);
	printf("\nc = ");
	scanf("%d", &c);
	
	delta = (double)b * b - 4 * a * c;
	
	if(delta > 0){
		x1 = (-b - sqrt(delta))/(2 *a);
		x2 = (-b + sqrt(delta))/(2 *a);
		printf("l`equation a deux solutions:\n x1 = %.2lf \n x2 = %.2lf", x1 ,x2);
	}else if(delta == 0){
		x = - b/(2 *a);
		printf("L`equation a une solution:\n x = %lf", x);
	}else{
		printf("l`equetion est null");
	}
	
	return 0;
}

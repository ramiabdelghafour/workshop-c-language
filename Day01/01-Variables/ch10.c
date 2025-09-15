#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float r;
	float volume;
	float Pi = 3.14;
	
	printf("donner le rayon du sphere: ");
	scanf("%f", &r);
	volume = (4.0/3.0) * Pi * pow(r, 3);
	
	printf("le volume : %.2f", volume);
	
	
	return 0;
}

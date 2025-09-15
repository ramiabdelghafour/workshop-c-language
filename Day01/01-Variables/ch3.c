#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	    
	float distance = 0.0f;
    float yard = 0.0f;
    

    printf("Donner la distance en kilometres: ");
    scanf("%f", &distance);

    yard = distance * 1093.61;

    printf("la distance en kilometres: %.2f Yards", yard);
	
	return 0;
}

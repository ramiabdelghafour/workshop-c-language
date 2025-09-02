#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    float C = 0.0f;
    
    printf("Donner la température en Celsius: ");
    scanf("%f", &C);
    
    if(C < 0){
        printf("Solide");
    }else if(C >= 0 && C < 100){
        printf("Liquide");
    }else {
        printf("Gaz");
    }
	return 0;
}

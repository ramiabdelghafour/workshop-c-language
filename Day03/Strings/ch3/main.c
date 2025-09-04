#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

    char chaine1[100] = "you"; 
    char chaine2[] = "code";
    
    strcat(chaine1, chaine2);
    
    printf("%s \n", chaine1);
	return 0;
}

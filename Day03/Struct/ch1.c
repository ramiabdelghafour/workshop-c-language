#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct personne {
	char nom[N];
	char prenom[N];
	int age;
}personne;

int main(int argc, char *argv[]) {
	personne p;

    printf("donnez votre prenom : ");
    scanf("%s", p.prenom);  

    printf("donnez votre nom : ");
    scanf("%s", p.nom);  
        
	printf("donnez votre age : ");
    scanf("%d", &p.age);  
    
    printf("\nDonnes personal: \n");
    printf("prenom : %s\n", p.prenom);
    printf("nom : %s\n", p.nom);
    printf("age : %d\n", p.age);


	return 0;
}

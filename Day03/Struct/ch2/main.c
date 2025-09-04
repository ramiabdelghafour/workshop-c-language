#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct etudiant{
	char nom[N];
	char pernom[N];
	int note[N];
}etudiant;
int main(int argc, char *argv[]) {
	etudiant e;
	int nombre = 0;
	printf("donner votre prenom: ");
	scanf("%s", e.pernom);
	
	printf("donner votre nom: ");
	scanf("%s", e.nom);
	
	printf("donnner le nombre de vos notes: ");
	scanf("%d", &nombre);
	
	printf("votre prenom: %s\n", e.pernom);
	printf("votre nom: %s\n", e.nom);
	printf("votre : %d\n", e.note);
	
	return 0;
}

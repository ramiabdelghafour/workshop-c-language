#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct etudiant{
	char nom[N];
	char pernom[N];
	int notes[N];
}etudiant;
int main(int argc, char *argv[]) {
	etudiant e;
	int nombre = 0;
	int i;
	printf("donner votre prenom: ");
	scanf("%s", e.pernom);
	
	printf("donner votre nom: ");
	scanf("%s", e.nom);
	
	printf("donnner le nombre de vos notes: ");
	scanf("%d", &nombre);
	
	for(i = 0; i < nombre; i++){
		printf("entre N %d: ", i +1);
		scanf("%d", &e.notes[i]);
	}
	
	printf("votre prenom: %s\n", e.pernom);
	printf("votre nom: %s\n", e.nom);
	
	for(i = 0; i < nombre; i++){
		printf("note N %d: %d \n", i +1, e.notes[i]);

	}
	return 0;
}

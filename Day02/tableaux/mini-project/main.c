#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 50
#define N 50
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char titre[M][N];
	char auteur[M][N];
	int prix[N];
	int quantite[N];
	int i, n;
	int incre = 0;
	
//- Ajouter un livre au stock.

	printf("donner le nombre de livres: ");
	scanf("%d", &n);

	for(i = 0; i < n; i++){
		printf("\n-- le livre N %d --\n", i+1);
		printf("donner le titre de livre: ");
		scanf("%s", &titre[incre]);
		
		printf("donner le auteur de livre: ");
		scanf("%s", &auteur[incre]);
	
		printf("donner le prix de livre: ");
		scanf("%d", &prix[incre]);
	
		printf("donner le quantite de livre: ");
		scanf("%d", &quantite[incre]);
		incre++;
	}
	
//- Afficher tous les livres disponibles.
	printf("\n-- biblio --\n");
	for(i = 0; i < n; i++){
	
		printf("\n-- le livre N %d --\n", i+1);
		printf("le titre de livre: %s\n", titre[i]);
		
		printf("le auteur de livre: %s\n", auteur[i]);

		printf("le prix de livre: %d\n", prix[i]);
	
		printf("le quantite de livre: %d\n", quantite[i]);

	}
	
//- Rechercher un livre par son titre.
	char nom[M]; 
	
	printf("\ndonner le titre de livre: ");
	scanf("%s", nom);
	
	int search = 0;
	
	for(i = 0; i < incre ; i++){
		if(strcmp(nom, titre[i]) == 0){
			printf("\nle titre de livre: %s\n", titre[i]);
		
			printf("le auteur de livre: %s\n", auteur[i]);

			printf("le prix de livre: %d\n", prix[i]);
	
			printf("le quantite de livre: %d\n", quantite[i]);
			search=1;
		}
	}
	if(search == 0){
		printf("ce livre n'exist pas dans cette biblio!");
	}
	
//- Mettre à jour la quantité d'un livre.
	
	printf("\npour modifier la quantite d'un livre donner son titre: ");
	scanf("%s", nom);
	
	for(i = 0; i < incre ; i++){
		if(strcmp(nom, titre[i]) == 0){
			printf("\nLivre trouve:\n");
			printf("le titre de livre: %s\n", titre[i]);
			printf("le auteur de livre: %s\n", auteur[i]);
			printf("le prix de livre: %d\n", prix[i]);
			printf("le quantite de livre: %d\n", quantite[i]);
			
			int newquantite;
			printf("donner la nouvelle quantite: ");
			scanf("%d", &newquantite);
			quantite[i] = newquantite;
			
			printf("\nle titre de livre: %s\n", titre[i]);
			printf("le auteur de livre: %s\n", auteur[i]);
			printf("le prix de livre: %d\n", prix[i]);
			printf("le quantite de livre: %d\n", quantite[i]);
			
			search=1;
		}
	}
	if(search == 0){
		printf("ce livre n'exist pas dans cette biblio!");
	}
	
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
	int id;
	char nom[50];
	char prenom[50];
	int numeroMaillot;
	char poste[20];
	int age;
	int buts;
	char date_Inscription[11];
	char statut[20];
}joueur;

joueur *equipe = NULL;
int nb_joueur = 0;
int nouveau_id = 1;

void ajouter_joueur(){
	joueur j;
	j.id = nouveau_id++;
	
	printf("enter les valeurs du joueur: \n");
	printf("Nom: ");
	scanf("%s", j.nom );
	printf("Prenom:");
	scanf("%s", j.prenom);
	printf("Numero du maillot: ");
	scanf("%d", &j.numeroMaillot);
	printf("Poste: ");
	scanf("%s", j.poste);
	printf("Age: ");
	scanf("%d", &j.age);
	printf("Buts: ");
	scanf("%d", &j.buts);
	printf("Statut: ");
	scanf("%s", j.statut);
	
	// date inscription ineeded

	equipe = realloc(equipe, sizeof(joueur) * (nb_joueur + 1));
	equipe[nb_joueur++] = j;

	if(j.buts >= 10){
		printf("le Star d`equipe\n");
	}
}

void afficher_liste_joueur(){
	int i;
	if(nb_joueur == 0){
		printf("Aucun joueur dans l`equipe.\n");
		return;
	}else{
		printf("ID\tNom\tPrenom\tNumero du maillot\tPoste\tAge\tButs\tStatut\n");
		for(i = 0; i < nb_joueur; i++){
			joueur j = equipe[i];
			printf("%d\t%s\t%s\t%d\t%s\t%d\t%d\t%s\n",
			j.id, j.nom, j.prenom, j.numeroMaillot, j.poste, j.age, j.buts, j.statut);	
		}
	}
}

void modiffier_joueur(){
	int id;
	int i;
	int choix;
	
	printf("\nDonner ID du joueur:");
	scanf("%d", &id);
	
	for(i =  0;i < nb_joueur; i++){
		if(equipe[i].id == id){
			printf("ID\tNom\tPrenom\tNumero du maillot\tPoste\tAge\tButs\tStatut\n");
			printf("%d\t%s\t%s\t%d\t%s\t%d\t%d\t%s\n",equipe[i].id, equipe[i].nom, equipe[i].prenom, 
			equipe[i].numeroMaillot, equipe[i].poste, equipe[i].age, equipe[i].buts, equipe[i].statut);
			
			printf("\n1. Modifier le poste d`un joueur.\n");
			printf("2. Modifier l`age d`un joueur.\n");
			printf("3. Modifier le nombre de buts marquer par un joueur.\n");
			printf("votre choix: ");
			scanf("%d", &choix);
			
			switch(choix){
				case 1:
					printf("Poste: ");
					scanf("%s", equipe[i].poste);
					break;
				case 2:
					printf("Age: ");
					scanf("%d", &equipe[i].age);
					break;
				case 3:
					printf("Buts: ");
					scanf("%d", &equipe[i].buts);
					break;
				default:
					printf("choix invalid;");
			}
		}
	}	
}

void supprimer_joueur(){
	int id;
	int i, j;
	
	printf("\ndonner id du joueur: ");
	scanf("%d", &id);
	
	for(i = 0; i < nb_joueur; i++){
		if(equipe[i].id == id){
			for(j = i; j < nb_joueur - 1; i++){
				equipe[j] = equipe[j + 1];
			}
			nb_joueur--;
			equipe = realloc(equipe, sizeof(joueur) * nb_joueur);
			printf("joueur supprime.");
			return;	
		}else{
			printf("joueur non trouve");
		}
	}
	
}

void rechercher_joueur(){
	int id;
	char name[50];
	int choix;
	int i;
	
	printf("1. Rechercher un joueur par ID.\n");
	printf("2. Rechercher un joueur par Nom.\n");
	printf("donner voitre choix: ");
	scanf("%d", &choix);
	
	switch(choix){
		case 1:
			printf("enter ID du joueur: ");
			scanf("%d", &id);
			for(i = 0; i < nb_joueur; i++){
				if(equipe[i].id == id){
					printf("joueur touve.\n");
					printf("ID\tNom\tPrenom\tNumero du maillot\tPoste\tAge\tButs\tStatut\n");
					printf("%d\t%s\t%s\t%d\t%s\t%d\t%d\t%s\n",equipe[i].id, equipe[i].nom, equipe[i].prenom, 
					equipe[i].numeroMaillot, equipe[i].poste, equipe[i].age, equipe[i].buts, equipe[i].statut);
				}
			}
			break;
		case 2:
			printf("enter le Nom du joueur: ");
			scanf("%s", &name);
			break;
	}
}

void statistiques(){
	
}

void menu(){
	int choix;
	do{
		printf("\n--- Gestion Equipe de Football ---\n");
		printf("1. Ajouter un joueur. \n");
		printf("2. Afficher la liste des joueurs. \n");
		printf("3. Modifier un joueur. \n");
		printf("4. Supprimer un joueur. \n");
		printf("5. Rechercher un joueur. \n");
		printf("6. Statistiques.\n");
		printf("7. Quitter.\n");
		printf("votre choix: ");
		scanf("%d", &choix);
	
		switch(choix){
			case 1:
				ajouter_joueur();
				break;
			case 2:
				afficher_liste_joueur();
				break;
			case 3:
				modiffier_joueur();
				break;
			case 4:
				supprimer_joueur();
				break;
			case 5:
				rechercher_joueur();
				break;
			case 6:
				statistiques();
				break;
			case 7:
				break;
			default: 
				printf("choix invalide!");			
		}
	}while(choix != 7);
}

int main(int argc, char *argv[]) {
	menu();
	free(equipe);
	return 0;
}

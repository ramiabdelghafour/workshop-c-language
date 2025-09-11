#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
	int id;
	char nom[50];
	char prenom[50];
	int numero_maillot;
	char poste[20];
	int age;
	int buts;
	char date_inscription[11];
	char statut[20];
}joueur;

joueur *equipe = NULL;
int nb_joueur = 0;
int nouveau_id = 1;

// ajouter un joueur
void ajouter_joueur(){
	joueur j;
	j.id = nouveau_id++;
	
	printf("enter les valeurs du joueur: \n");
	printf("Nom: ");
	scanf("%s", j.nom );
	printf("Prenom:");
	scanf("%s", j.prenom);
	printf("Numero du maillot: ");
	scanf("%d", &j.numero_maillot);
	printf("Poste: ");
	scanf("%s", j.poste);
	printf("Age: ");
	scanf("%d", &j.age);
	printf("Buts: ");
	scanf("%d", &j.buts);
	printf("Statut: ");
	scanf("%s", j.statut);
	
    time_t t = time(NULL);
    strftime(j.date_inscription, sizeof(j.date_inscription), "%Y-%m-%d", localtime(&t));

	equipe = realloc(equipe, sizeof(joueur) * (nb_joueur + 1));
	equipe[nb_joueur++] = j;

	if(j.buts >= 10){
		printf("le Star d`equipe\n");
	}
}

// ajouter plusieur joueurs
void ajouter_plusieurs_joueurs(){
	int n, i;
	printf("Combien de joueurs a ajouter? ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
	 	printf("\n joueur N %d\n", i + 1);
	 	ajouter_joueur();
	}
}


// afficher la list des joueurs
void afficher_liste_joueur(){
	int i;
	if(nb_joueur == 0){
		printf("Aucun joueur dans l`equipe.\n");
		return;
	}else{
		printf("ID\tNom\tPrenom\tNumero du maillot\tPoste\tAge\tButs\t\tdate inscription\tStatut\n");
		for(i = 0; i < nb_joueur; i++){
			joueur j = equipe[i];
			printf("%d\t%s\t%s\t%d\t%s\t%d\t%d\t\t%s\t%s\n",
			j.id, j.nom, j.prenom, j.numero_maillot, j.poste, j.age, j.buts, j.date_inscription, j.statut);	
		}
	}
}

// trier par nom
void trier_par_nom(){
}

void afficher_joueur(int index){
	printf("ID\tNom\tPrenom\tNumero du maillot\tPoste\tAge\tButs\tdate inscription\tStatut\n");
	printf("%d\t%s\t%s\t%d\t%s\t%d\t%d\t%s\n",equipe[index].id, equipe[index].nom, equipe[index].prenom, 
	equipe[index].numero_maillot, equipe[index].poste, equipe[index].age, equipe[index].buts, equipe[index].date_inscription, equipe[index].statut);
}

// modifier un jouer
void modifier_joueur(){
	int id, i, choix;
	int trouve = 0;
	
	printf("\nDonner ID du joueur:");
	scanf("%d", &id);
	
	for(i =  0;i < nb_joueur; i++){
		if(equipe[i].id == id){
			trouve = 1;
			
			afficher_joueur(i);
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
	if(!trouve){
		printf("joueur non trouve.\n");
	}	
	
}

// supprimer un joueur
void supprimer_joueur(){
	int id;
	int i, j;
	int trouve = 0;
	
	printf("\ndonner id du joueur: ");
	scanf("%d", &id);
	
	for(i = 0; i < nb_joueur; i++){
		if(equipe[i].id == id){
			for(j = i; j < nb_joueur - 1; j++){
				equipe[j] = equipe[j + 1];
			}
			nb_joueur--;
			equipe = realloc(equipe, sizeof(joueur) * nb_joueur);
			printf("joueur supprime.\n");
			trouve = 1;
			break;	
		}
	}
	if(!trouve){
		printf("joueur non trouve.\n");
	}
	
}

//rechercher un joueur
void rechercher_joueur(){
	int id;
	char nom[50];
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
					afficher_joueur(i);
				return;
				}
			}
			printf("joueur non trouve.\n");
			break;
			
		case 2:			
			printf("enter le Nom du joueur: ");
			scanf("%s", nom);
			
			for(i = 0; i < nb_joueur; i++){
				if(strcmp(equipe[i].nom, nom) == 0){
					afficher_joueur(i);
				}
			}
			break;
			
	}
}

//statistiques
void statistiques(){
	
}

void menu(){
	int choix;
	do{
		printf("\n--- Gestion Equipe de Football ---\n");
		printf("1. Ajouter un joueur ou plusieurs. \n");
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
				modifier_joueur();
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

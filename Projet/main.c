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

// des joueurs existants
void initialiser_joueurs() {
    nb_joueur = 3;
    equipe = (joueur*)malloc(nb_joueur * sizeof(joueur));

    equipe[0].id = 1;
    strcpy(equipe[0].nom, "Rami");
    strcpy(equipe[0].prenom, "Abdelghafour");
    equipe[0].numero_maillot = 7;
    strcpy(equipe[0].poste, "Attaquant");
    equipe[0].age = 23;
    equipe[0].buts = 10;
    strcpy(equipe[0].date_inscription, "2025-09-11");
    strcpy(equipe[0].statut, "titulaire");

    equipe[1].id = 2;
    strcpy(equipe[1].nom, "Ahmed");
    strcpy(equipe[1].prenom, "Youssef");
    equipe[1].numero_maillot = 10;
    strcpy(equipe[1].poste, "Milieu");
    equipe[1].age = 21;
    equipe[1].buts = 5;
    strcpy(equipe[1].date_inscription, "2025-09-10");
    strcpy(equipe[1].statut, "remplaçant");

    equipe[2].id = 3;
    strcpy(equipe[2].nom, "Khalid");
    strcpy(equipe[2].prenom, "Samir");
    equipe[2].numero_maillot = 4;
    strcpy(equipe[2].poste, "Defenseur");
    equipe[2].age = 25;
    equipe[2].buts = 2; 
    strcpy(equipe[2].date_inscription, "2025-09-09");
    strcpy(equipe[2].statut, "titulaire");
    
    nouveau_id = nb_joueur + 1;
}

// ajouter un joueur
void ajouter_joueur(){
	joueur j;
	j.id = nouveau_id++;
	int choix;
	
	printf("enter les valeurs du joueur: \n");
	printf("Nom: ");
	scanf("%s", j.nom );
	printf("Prenom: ");
	scanf("%s", j.prenom);
	printf("Numero du maillot: ");
	scanf("%d", &j.numero_maillot);
	do{
		printf("Poste: ");
		printf("1. Gardien  ");
		printf("2. Defenseur  ");
		printf("3. Milieu   ");
		printf("4. Attaquant  ");
		printf("\nEntrer votre choix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				strcpy(j.poste, "Gardien");
				break;
			case 2:
				strcpy(j.poste, "Defenseur");
				break;
			case 3:
				strcpy(j.poste, "Milieu");
				break;
			case 4:
				strcpy(j.poste, "Attaquant");
				break;
				default:
					printf("Choix invalide, veuillez ressayer.\n");
	}
	}while(choix < 1 || choix > 4);
	printf("Age: ");
	scanf("%d", &j.age);
	printf("Buts: ");
	scanf("%d", &j.buts);
	do{
		printf("Statut: ");
		printf("1. Titulaire  ");
		printf("2. Remplaçant  ");
		printf("\nEntrer votre choix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				strcpy(j.statut, "Titulaire");
				break;
			case 2:
				strcpy(j.statut, "Remplaçant");
				break;
			default:
				printf("Choix invalide, veuillez ressayer.\n");
		}
		
	}while(choix < 1 || choix > 2);
	
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
	if(nb_joueur == 0){
		printf("Aucun joueur dans l`equipe.\n");
		return;
	}
	int i, j;
	for(i = 0; i < nb_joueur - 1; i++){
		for(j = i + 1; j < nb_joueur; j++){
			if(strcmp(equipe[i].nom, equipe[j].nom) > 0){
				joueur temp = equipe[i];
				equipe[i] =  equipe[j];
				equipe[j] = temp;	
			}
		}
	}
	afficher_liste_joueur();
}

// trier par age
void trier_par_age(){
	if(nb_joueur == 0){
		printf("Aucun joueur dans l`equipe.\n");
		return;
	}
	int i,j;
	for(i = 0; i < nb_joueur; i++){
		for(j = i + 1; j < nb_joueur - 1; j++){
			if(equipe[i].age < equipe[j].age){
				joueur temp = equipe[i];
				equipe[i] = equipe[j];
				equipe[j] = temp;
			}	
		}
	}
	afficher_liste_joueur();
}

// afficher un seul joueur
void afficher_joueur(int index){
	printf("ID\tNom\tPrenom\tNumero du maillot\tPoste\tAge\tButs\tdate inscription\tStatut\n");
	printf("%d\t%s\t%s\t%d\t%s\t%d\t%d\t%s\n",equipe[index].id, equipe[index].nom, equipe[index].prenom, 
	equipe[index].numero_maillot, equipe[index].poste, equipe[index].age, equipe[index].buts, equipe[index].date_inscription, equipe[index].statut);
}

// afficher par poste
void afficher_par_poste(){
	if(nb_joueur == 0){
		printf("Aucun joueur dans l`equipe.\n");
		return;
	}
	
	char poste[20];
	printf("Saisir le poste a rechercher (Gardien, Defenseur, Milieu, Attaquant): ");
	scanf("%s", poste);
	int i, p;
	int trouve = 0;
	
	for(i = 0; i < nb_joueur; i++){
		if(strcmp(equipe[i].poste, poste) == 0){
			afficher_joueur(i);
			trouve = 1;	
		}
	}
	if(!trouve){
		printf("Aucun joueur dans ce poste.\n");
	}
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
					printf("Choix invalide, veuillez ressayer.\n");
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
	
	printf("\ndonner Id du joueur: ");
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
		default:
			printf("Choix invalide, veuillez ressayer.\n");
			
	}
}

//statistiques
void statistiques(){
	
}

//                   --------------- les menus ---------------

// menu ajouter
void menu_ajouter(){
	int choix;
	do{
		printf("\n1. Ajouter un joueur.\n");
		printf("2. Ajouter plusieurs joueurs.\n");
		printf("0. Retour.\n");
		printf("Enter votre choix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				ajouter_joueur();
				break;
			case 2:
				ajouter_plusieurs_joueurs();
					break;
			default: 
				printf("Choix invalide!");	
		}
	}while(choix != 0);
}


// menu afficher
void menu_afficher(){
	int choix;
	do{
		printf("\n1. Afficher tout.\n");
		printf("2. Trier par le nom.\n");
		printf("3. Trier par l`age.\n");
		printf("4. Trier par  poste.\n");
		printf("0. Retour\n");
		printf("Enter votre choix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				afficher_liste_joueur();
				break;
			case 2:
				trier_par_nom();
				break;
			case 3:
				trier_par_age();
				break;
			case 4:
				afficher_par_poste();
				break;
			default: 
				printf("Choix invalide!");
		}
		
		
	}while(choix != 0);
}

// menu principal
void menu_principal(){
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
				menu_ajouter();
				break;
			case 2:
				menu_afficher();
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
				printf("Choix invalide!");			
		}
	}while(choix != 7);
}



// mmaaaaaaaaaaaaaaaaaain
int main(int argc, char *argv[]) {
	initialiser_joueurs();
	menu_principal();
	free(equipe);
	return 0;
}

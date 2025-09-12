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

// clear ecran
void clear_screen() {
    system("cls");
}

// des joueurs existants
void initialiser_joueurs() {
    nb_joueur = 10;
    equipe = malloc(nb_joueur * sizeof(joueur));

    equipe[0] = (joueur){1, "Rami", "Abdelghafour", 7, "Attaquant", 23, 10, "2025-09-11", "Titulaire"};
    equipe[1] = (joueur){2, "Sami", "Ahmed", 10, "Milieu", 21, 5, "2025-09-10", "Remplacant"};
    equipe[2] = (joueur){3, "Zoukrane", "Khalid", 4, "Defenseur", 25, 2, "2025-09-09", "Titulaire"};
    equipe[3] = (joueur){4, "Nbou", "Brahim", 1, "Gardien", 27, 0, "2025-09-08", "Titulaire"};
    equipe[4] = (joueur){5, "Mirrou", "Fathi", 11, "Attaquant", 22, 8, "2025-09-07", "Remplacant"};
    equipe[5] = (joueur){6, "Hachim", "Saad", 6, "Milieu", 24, 6, "2025-09-06", "Titulaire"};
    equipe[6] = (joueur){7, "Saad", "Oussama", 5, "Defenseur", 26, 1, "2025-09-05", "Titulaire"};
    equipe[7] = (joueur){8, "Fattahi", "Mehdi", 8, "Milieu", 20, 3, "2025-09-04", "Remplacant"};
    equipe[8] = (joueur){9, "Fillali", "Zouhair", 9, "Attaquant", 23, 12, "2025-09-03", "Titulaire"};
    equipe[9] = (joueur){10, "Farsi", "Ayman", 3, "Defenseur", 28, 0, "2025-09-02", "Titulaire"};

    nouveau_id = nb_joueur + 1;
}


// -------------style-------------
//header
void afficher_header() {
    printf("\n========================================================================================================================\n");
    printf("| %-3s | %-12s | %-18s | %-7s | %-10s | %-3s | %-4s | %-16s | %-10s |\n",
           "ID", "NOM", "PRENOM", "MAILLOT", "POSTE", "AGE", "BUTS", "DATE INSCRIPTION", "STATUT");
    printf("========================================================================================================================\n");
}

//row
void afficher_row(joueur j) {
    printf("| %-3d | %-12s | %-18s | %-7d | %-10s | %-3d | %-4d | %-16s | %-10s |\n",
           j.id, j.nom, j.prenom, j.numero_maillot, j.poste,
           j.age, j.buts, j.date_inscription, j.statut);
}

//footer
void afficher_footer() {
    printf("========================================================================================================================\n");
}
//            ------------- l`ajout -------------

// ajouter un joueur
void ajouter_joueur(){
	joueur j;
	j.id = nouveau_id++;
	int choix;
	
	printf("Enter les valeurs du joueur: \n");
	printf("Nom: ");
	scanf("%s", j.nom );
	printf("Prenom: ");
	scanf("%s", j.prenom);
	printf("Numero du maillot: ");
	scanf("%d", &j.numero_maillot);
	
	do{
		printf("Poste: 1.Gardien, 2.Defenseur, 3.Milieu, 4.Attaquant ");
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
		printf("2. Remplacant  ");
		printf("\nEntrer votre choix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				strcpy(j.statut, "Titulaire");
				break;
			case 2:
				strcpy(j.statut, "Remplacant");
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

//            ------------- l`affichage -------------

// afficher la list des joueurs
void afficher_liste_joueur(){
	int i;
	if(nb_joueur == 0){
		printf("Aucun joueur dans l`equipe.\n");
		return;
	}else{
		afficher_header();
		for(i = 0; i < nb_joueur; i++){
			afficher_row(equipe[i]);	
		}
		afficher_footer();
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
	for(i = 0; i < nb_joueur - 1; i++){
		for(j = i + 1; j < nb_joueur; j++){
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
void afficher_joueur(int index) {
    afficher_header();
    afficher_row(equipe[index]);
    afficher_footer();
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
	int i;
	int trouve = 0;
	afficher_header();
	for(i = 0; i < nb_joueur; i++){
		if(strcmp(equipe[i].poste, poste) == 0){
			afficher_row(equipe[i]);
			trouve = 1;	
		}
	}
	afficher_footer();
	if(!trouve){
		printf("Aucun joueur dans ce poste.\n");
	}
}



//            ------------- modification -------------

// modifier un jouer
void modifier_joueur(){
	int id, i, choix;
	joueur j;
	int trouve = 0;
	
	printf("\nDonner ID du joueur: ");
	scanf("%d", &id);
	
	for(i =  0;i < nb_joueur; i++){
		if(equipe[i].id == id){
			
			afficher_joueur(i);
			trouve = 1;
			printf("\n1. Modifier le poste d`un joueur.\n");
			printf("2. Modifier l`age d`un joueur.\n");
			printf("3. Modifier le nombre de buts marquer par un joueur.\n");
			printf("votre choix: ");
			scanf("%d", &choix);
			
			switch(choix){
				case 1:
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
								strcpy(equipe[i].poste, "Gardien");
								break;
							case 2:
								strcpy(equipe[i].poste, "Defenseur");
								break;
							case 3:
								strcpy(equipe[i].poste, "Milieu");
								break;
							case 4:
								strcpy(equipe[i].poste, "Attaquant");
								break;
								default:
									printf("Choix invalide, veuillez ressayer.\n");
					}
					}while(choix < 1 || choix > 4);
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
	int id, i, j;
	int trouve = 0;
	
	printf("\nDonner Id du joueur: ");
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
//            ------------- recherche-------------

//rechercher un joueur par id
void rechercher_par_id(){
	int id;
	int i;
	printf("Entrer l'ID du joueur: ");
	scanf("%d", &id);
	for(i = 0; i < nb_joueur; i++){
		if(equipe[i].id == id){
			printf("Joueur trouve.\n");
			afficher_joueur(i);
			return;
		}
	}
	printf("Joueur non trouve.\n");
}

//rechercher un joueur par nom
void rechercher_par_nom(){
	char nom[50];
	int i;
	int trouve = 0;
	printf("Enter le Nom du joueur: ");
	scanf("%s", nom);
	 afficher_header();
		for(i = 0; i < nb_joueur; i++){
			if(strcmp(equipe[i].nom, nom) == 0){
				 afficher_row(equipe[i]);
            	trouve = 1;
			}
		}
		afficher_footer();
		if (!trouve) {
		printf("Joueur non trouve.\n");
	}
}

//statistiques
void statistiques(){
    if (nb_joueur == 0) {
        printf("Aucun joueur dans l'equipe.\n");
        return;
    }

    int choix;
    int i;
    do {
		clear_screen();
        printf("==========================================\n");
        printf("           MENU - STATISTIQUE           \n");
        printf("==========================================\n");
        printf("[1]. Nombre total de joueurs.\n");
        printf("[2]. Age moyen des joueurs.\n");
        printf("[3]. Joueurs ayant marque plus de X buts.\n");
        printf("[4]. Meilleur buteur.\n");
        printf("[5]. Joueur le plus jeune et le plus age.\n");
        printf("[0]. Retour.\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: 
                printf("Nombre total de joueurs: %d\n", nb_joueur);
                system("pause");
                break;
            
            case 2: { 
                int somme = 0;
                for (i = 0; i < nb_joueur; i++){
                    somme += equipe[i].age;
                }
                float moyenne = (float)somme / nb_joueur;
                printf("Age moyen des joueurs: %.2f\n", moyenne);
                system("pause");
                break;
            }
            case 3: { 
                int x;
                printf("Entrer le nombre minimum de buts: ");
                scanf("%d", &x);
                int trouve = 0;
                afficher_header();
                for (i = 0; i < nb_joueur; i++){
                    if (equipe[i].buts > x){
						afficher_row(equipe[i]);
                        trouve = 1;
                    }
                }
                afficher_footer();
                if (!trouve){
                    printf("Aucun joueur n'a marque plus de %d buts.\n", x);
                }
                system("pause");
                break;
            }
            case 4: { 
                int max_buts = equipe[0].buts;
                int index = 0;
                for (i = 1; i < nb_joueur; i++){
                    if (equipe[i].buts > max_buts) {
                        max_buts = equipe[i].buts;
                        index = i;
                    }
                }
                printf("Meilleur buteur:\n");
                afficher_joueur(index);
                system("pause");
                break;
            }
            case 5: { 
                int min_age = equipe[0].age, max_age = equipe[0].age;
                int index_min = 0, index_max = 0;
                for (i = 1; i < nb_joueur; i++){
                    if (equipe[i].age < min_age){
                        min_age = equipe[i].age;
                        index_min = i;
                    }
                    if (equipe[i].age > max_age) {
                        max_age = equipe[i].age;
                        index_max = i;
                    }
                }
                printf("Joueur le plus jeune:\n");
                afficher_joueur(index_min);
                printf("Joueur le plus age:\n");
                afficher_joueur(index_max);
                system("pause");
                break;
            }
            case 0:
                break;
            default:
                printf("Choix invalide, veuillez ressayer.\n");
                system("pause");
        }
    } while (choix != 0);
}

//                   --------------- les menus ---------------

// menu ajouter
void menu_ajouter(){
	int choix;
	do{
        clear_screen();
        printf("==========================================\n");
        printf("           MENU - AJOUTER JOUEUR          \n");
        printf("==========================================\n");
        printf("[1]. Ajouter un joueur\n");
        printf("[2]. Ajouter plusieurs joueurs\n");
        printf("[0]. Retour\n");
        printf("------------------------------------------\n");
		printf("Enter votre choix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				ajouter_joueur();
				system("pause");
				break;
			case 2:
				ajouter_plusieurs_joueurs();
				system("pause");
					break;
			case 0:
                break;
			default: 
				printf("Choix invalide, veuillez ressayer.\n");	
				system("pause");
		}
	}while(choix != 0);
}

// menu afficher
void menu_afficher(){
	int choix;
	do{
		clear_screen();
        printf("==========================================\n");
        printf("          MENU - AFFICHER JOUEURS         \n");
        printf("==========================================\n");
		printf("[1]. Afficher tout.\n");
		printf("[2]. Trier par le nom.\n");
		printf("[3]. Trier par l`age.\n");
		printf("[4]. Trier par  poste.\n");
		printf("[0]. Retour\n");
		printf("Enter votre choix: ");
		scanf("%d", &choix);
		switch(choix){
			case 1:
				afficher_liste_joueur();
				system("pause");
				break;
			case 2:
				trier_par_nom();
				system("pause");
				break;
			case 3:
				trier_par_age();
				system("pause");
				break;
			case 4:
				afficher_par_poste();
				system("pause");
				break;
			case 0:
                break;
			default: 
				printf("Choix invalide, veuillez ressayer.\n");
				system("pause");
		}
	}while(choix != 0);
}

// menu rechercher
void menu_rechercher(){
	int choix;
	do{
		clear_screen();
        printf("==========================================\n");
        printf("         MENU - RECHERCHER JOUEURS         \n");
        printf("==========================================\n");	
		printf("[1]. Rechercher un joueur par ID.\n");
		printf("[2]. Rechercher un joueur par Nom.\n");
		printf("[0]. Retour\n");
		printf("Enter votre choix: ");
		scanf("%d", &choix);
			switch(choix){
				case 1:
					rechercher_par_id();
					system("pause");
						break;
				case 2:
					rechercher_par_nom();
					system("pause");
					break;
				case 0:
					break;
				default:
					printf("Choix invalide, veuillez ressayer.\n");
					system("pause");
		}
	}while(choix != 0);
}

// menu principal
void menu_principal(){
	int choix;
	do{
		clear_screen();
        printf("==========================================\n");
        printf("        GESTION EQUIPE DE FOOTBALL        \n");
        printf("==========================================\n");
		printf("[1]. Ajouter un joueur ou plusieurs. \n");
		printf("[2]. Afficher la liste des joueurs. \n");
		printf("[3]. Modifier un joueur. \n");
		printf("[4]. Supprimer un joueur. \n");
		printf("[5]. Rechercher un joueur. \n");
		printf("[6]. Statistiques.\n");
		printf("[7]. Quitter.\n");
		printf("Entrer votre choix: ");
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
				menu_rechercher();
				break;
			case 6:
				statistiques();
				break;
			case 7:
				break;
			default: 
				printf("Choix invalide, veuillez ressayer.\n");		
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

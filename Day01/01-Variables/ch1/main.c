#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	char nom[20] = "";
    char prenom[20] = "";
    int age = 0;
    char sexe[10] = "";
    char email[50] = "";

    printf("Saisir ces information suivantes:\n");

    printf("Nom: ");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';

    printf("Prenom: ");
    fgets(prenom, sizeof(prenom), stdin);
    prenom[strcspn(prenom, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &age);
    while (getchar() != '\n');
    
    printf("Sexe: ");
    fgets(sexe, sizeof(sexe), stdin);
    sexe[strcspn(sexe, "\n")] = '\0';

    printf("Email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    // printf("Nom: %s\n", nom);
    // printf("Prenom: %s\n", prenom);
    // printf("Age: %d\n", age);
    // printf("Sexe: %s\n", sexe);
    // printf("Email: %s\n", email);

    printf("Vous etes %s %s. ", nom, prenom);
    printf("Un/Une %s ", sexe);
    printf("age de %d. ", age);
    printf("Il/elle a l'adresse email suivante: %s.", email);
	return 0;
}

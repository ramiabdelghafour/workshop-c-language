#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100

typedef struct {
    char nom[50];
    char telephone[20];
    char email[50];
} Contact;

// Tableau de contacts
Contact contacts[MAX_CONTACTS];
int nombreContacts = 0;

// telephone (10 chiffres)
int telephoneValide(char tel[]) {
    int i;
    if (strlen(tel) != 10) return 0;
    for (i = 0; i < 10; i++) {
        if (!isdigit(tel[i])) return 0;
    }
    return 1;
}

// Verifier email ('@')
int emailValide(char email[]) {
    if (strchr(email, '@') != NULL) {
        return 1;
    }
    return 0;
}

// Ajouter un contact
void ajouterContact() {
    if (nombreContacts >= MAX_CONTACTS) {
        printf("Carnet plein.\n");
        return;
    }

    printf("Nom : ");
    scanf(" %[^\n]", contacts[nombreContacts].nom);

    do {
        printf("Téléphone (10 chiffres) : ");
        scanf(" %s", contacts[nombreContacts].telephone);
    } while (!telephoneValide(contacts[nombreContacts].telephone));

    do {
        printf("Email : ");
        scanf(" %s", contacts[nombreContacts].email);
    } while (!emailValide(contacts[nombreContacts].email));

    nombreContacts++;
    printf("Contact ajouté avec succès !\n");
}

// Afficher tous les contacts
void afficherContacts() {
    int i;
    if (nombreContacts == 0) {
        printf("Aucun contact à afficher.\n");
        return;
    }
    for (i = 0; i < nombreContacts; i++) {
        printf("\nContact %d\n", i + 1);
        printf("Nom      : %s\n", contacts[i].nom);
        printf("Téléphone: %s\n", contacts[i].telephone);
        printf("Email    : %s\n", contacts[i].email);
    }
}

// Rechercher un contact par nom
int rechercherContact(char nomRecherche[]) {
    int i;
    for (i = 0; i < nombreContacts; i++) {
        if (strcmp(contacts[i].nom, nomRecherche) == 0) {
            return i;
        }
    }
    return -1;
}

// Modifier un contact
void modifierContact() {
    char nomRecherche[50];
    int index;

    printf("Nom du contact à modifier : ");
    scanf(" %[^\n]", nomRecherche);

    index = rechercherContact(nomRecherche);
    if (index == -1) {
        printf("Contact non trouvé.\n");
        return;
    }

    do {
        printf("Nouveau téléphone (10 chiffres) : ");
        scanf(" %s", contacts[index].telephone);
    } while (!telephoneValide(contacts[index].telephone));

    do {
        printf("Nouvel email : ");
        scanf(" %s", contacts[index].email);
    } while (!emailValide(contacts[index].email));

    printf("Contact modifié avec succès !\n");
}

// Supprimer un contact
void supprimerContact() {
    char nomRecherche[50];
    int index, i;

    printf("Nom du contact à supprimer : ");
    scanf(" %[^\n]", nomRecherche);

    index = rechercherContact(nomRecherche);
    if (index == -1) {
        printf("Contact non trouvé.\n");
        return;
    }

    for (i = index; i < nombreContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    nombreContacts--;

    printf("Contact supprimé avec succès !\n");
}

// Rechercher un contact
void afficherContact() {
    char nomRecherche[50];
    int index;

    printf("Nom du contact à rechercher : ");
    scanf(" %[^\n]", nomRecherche);

    index = rechercherContact(nomRecherche);
    if (index == -1) {
        printf("Contact non trouvé.\n");
        return;
    }

    printf("Nom      : %s\n", contacts[index].nom);
    printf("Téléphone: %s\n", contacts[index].telephone);
    printf("Email    : %s\n", contacts[index].email);
}

// Menu
void afficherMenu() {
    printf("\n===== MENU CONTACTS =====\n");
    printf("1. Ajouter un contact\n");
    printf("2. Modifier un contact\n");
    printf("3. Supprimer un contact\n");
    printf("4. Afficher tous les contacts\n");
    printf("5. Rechercher un contact\n");
    printf("0. Quitter\n");
    printf("=========================\n");
    printf("Choix : ");
}

int main() {
    int choix;

    do {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterContact();
                break;
            case 2:
                modifierContact();
                break;
            case 3:
                supprimerContact();
                break;
            case 4:
                afficherContacts();
                break;
            case 5:
                afficherContact();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}


 


#include <stdio.h>
#include <string.h>
#define MAX_SAISIE 100
#define TAILLE_MAX_NOM_PRENOM 250

void saisie_nom_prenom(char nom_prenom[], int taille_max);

int main() {
    int a;
    char personne[TAILLE_MAX_NOM_PRENOM];

    saisie_nom_prenom(personne, TAILLE_MAX_NOM_PRENOM);
    printf("%s\n", personne);

    return 0;
}

void saisie_nom_prenom(char nom_prenom[], int taille_max)
{
    char buffer[MAX_SAISIE];

    printf("Prenom: ");
    fgets(buffer, MAX_SAISIE, stdin);
    buffer[ strlen(buffer)-1 ] = '\0';

    printf("Nom: ");
    fgets(nom_prenom, taille_max-strlen(buffer)-2, stdin);
    nom_prenom[strlen(nom_prenom)-1] = '\0';

    strcat(nom_prenom, ", ");
    strcat(nom_prenom, buffer);

}

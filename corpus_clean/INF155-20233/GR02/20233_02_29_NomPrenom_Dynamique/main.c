 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SAISIE 100
#define TAILLE_MAX_NOM_PRENOM 250

char* saisie_nom_prenom(void);

int main() {
    int a;
    char* personne;


    personne = saisie_nom_prenom();
     
    if(personne!=NULL) {
        printf("%s\n", personne);
    }

    free(personne);

    return 0;
}

char* saisie_nom_prenom(void)
{
    char buffer[MAX_SAISIE];
    char* nom_prenom;
    char* ptr_temporaire;

    nom_prenom = (char*)malloc(sizeof(char)*TAILLE_MAX_NOM_PRENOM);
    if(nom_prenom == NULL)
    {
        return NULL;
    }

    printf("Prenom: ");
    fgets(buffer, MAX_SAISIE, stdin);
    buffer[ strlen(buffer)-1 ] = '\0';

    printf("Nom: ");
    fgets(nom_prenom, TAILLE_MAX_NOM_PRENOM-strlen(buffer)-2, stdin);
    nom_prenom[strlen(nom_prenom)-1] = '\0';

    strcat(nom_prenom, ", ");
    strcat(nom_prenom, buffer);

    ptr_temporaire = (char*)realloc(nom_prenom, sizeof(char)* strlen(nom_prenom)+1);
    if(ptr_temporaire == NULL)
    {
         
         
        return nom_prenom;
    }
    nom_prenom = ptr_temporaire;

    return nom_prenom;
}

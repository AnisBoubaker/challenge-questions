#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double distance; //8 octets
    float trajet_parcouru; //4 octets
    int valeur_entiere;
    double salaire;


    distance = 1345.50;

    trajet_parcouru = (float)distance;

    valeur_entiere = (int)distance;

    printf("Contenu de valeur_entirere: %i\n", valeur_entiere);

    //Attention la variable salaire est non initialisée
    //Elle contient une valeur aléatoire.
    printf("Conetnu de salaire: %f\n", salaire);

    return EXIT_SUCCESS;
}

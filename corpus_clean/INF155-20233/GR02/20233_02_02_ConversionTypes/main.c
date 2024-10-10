#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double distance;  
    float trajet_parcouru;  
    int valeur_entiere;
    double salaire;


    distance = 1345.50;

    trajet_parcouru = (float)distance;

    valeur_entiere = (int)distance;

    printf("Contenu de valeur_entirere: %i\n", valeur_entiere);

     
     
    printf("Conetnu de salaire: %f\n", salaire);

    return EXIT_SUCCESS;
}

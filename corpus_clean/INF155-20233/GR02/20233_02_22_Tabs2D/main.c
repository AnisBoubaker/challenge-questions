#include <stdio.h>
#include <stdlib.h>
 
#include "temperatures.h"
#include "test/module_test.h"

int main(void) {
    int nb_lignes, nb_colonnes;
    double temperatures[MAX_LIGNES][MAX_COLONNES] = {
            {32, 31.5, 30, 28},
            {15, 16.5, 17, 14},
            {20, 23.5, 18}
    };

    nb_lignes = 3;
    nb_colonnes = 4;

    temperatures[2][1] = 23.5;
    printf("La case 2,1 contient: %lf\n", temperatures[2][1]);

    afficher_tab2d( temperatures, nb_lignes, nb_colonnes);

    printf("Moyenne: %.2lf",moyenne_tab2d(temperatures, nb_lignes, nb_colonnes));

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

    return EXIT_SUCCESS;
}








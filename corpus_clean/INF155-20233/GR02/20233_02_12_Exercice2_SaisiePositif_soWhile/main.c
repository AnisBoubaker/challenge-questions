#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int saisie;

     

     

    do
    {
        printf("Saisir un nombre positif: ");
        scanf("%i", &saisie);
    } while( saisie <= 0 );

    printf("La valeur saisie: %i\n", saisie);

    return EXIT_SUCCESS;
}

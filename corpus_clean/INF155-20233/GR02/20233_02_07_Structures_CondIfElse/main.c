#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int saisie;

    printf("Saisir une valeur entiere: ");
    scanf("%i", &saisie);

    if( saisie % 2 == 0 )
    {
        printf("Le nombre est pair!\n");
    }
    printf("Je continue!");
     


    return EXIT_SUCCESS;
}

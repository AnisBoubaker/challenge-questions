#include <stdio.h>
#include <stdlib.h>

int main() {

    int* entier_dynamique;

    entier_dynamique = (int*)malloc( sizeof(int) );
    if(entier_dynamique == NULL){ 
        printf("Plus de memoire...\n");
         
        exit(EXIT_FAILURE);
    }
    *entier_dynamique = 250;
    printf("La valeur de l'entier dynamique: %i\n", *entier_dynamique);

     
     
    free(entier_dynamique);

    entier_dynamique = (int*)malloc(sizeof(int));
    if(entier_dynamique==NULL)
    {
        exit(EXIT_FAILURE);
    }
    *entier_dynamique = 100;


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {

    int* entier_dynamique;

    entier_dynamique = (int*)malloc( sizeof(int) );
    if(entier_dynamique == NULL){//Toujours vérifier que le mallloc a fonctionné!
        printf("Plus de memoire...\n");
        //return EXIT_FAILURE;
        exit(EXIT_FAILURE);
    }
    *entier_dynamique = 250;
    printf("La valeur de l'entier dynamique: %i\n", *entier_dynamique);

    //Important : libérer l'espace mémoire quand on en a plus besoin
    //AVANT de perdre l'adresse !
    free(entier_dynamique);

    entier_dynamique = (int*)malloc(sizeof(int));
    if(entier_dynamique==NULL)
    {
        exit(EXIT_FAILURE);
    }
    *entier_dynamique = 100;


    return 0;
}

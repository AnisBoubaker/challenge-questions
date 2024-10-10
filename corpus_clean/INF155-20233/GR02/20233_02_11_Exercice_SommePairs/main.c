#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int debut, fin;
    int compteur;
    int somme = 0;

    printf("Saisir la valeur de debut: ");
    scanf("%i", &debut);

    printf("Saisir la valeur de fin: ");
    scanf("%i", &fin);


     
     
    for(compteur = debut; compteur<=fin; compteur++)
    {
        if(compteur %2 ==0)
        {
            somme += compteur;
        }
    }
     
    if(debut%2 == 1)  
    {
        debut = debut + 1;
    }
    for(compteur=debut; compteur<=fin; compteur=compteur + 2)
    {
        somme = somme + compteur;
    }



    printf("La somme des nombres pairs: %i\n", somme);

    return EXIT_SUCCESS;
}

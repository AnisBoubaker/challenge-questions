#include <stdio.h>
#include <stdlib.h>

 
 
#define NB_ETUDIANTS 65

int main(void) {
    double notes[NB_ETUDIANTS];
    int nb_etudiants_effectif;
    double moyenne;
    double max;

    int ma_var = 10;

 
 
 
 
 
 

    printf("Combien d'etudiants: ");
    scanf("%i", &nb_etudiants_effectif);

    for(int i=0; i<nb_etudiants_effectif ; i++)
    {
        printf("Saisir la note de l'etudiant-e num. %i: ", i+1);
        scanf("%lf", &notes[i]);
    }



    printf("La case 2 du tableau contient: %lf\n", notes[2]);

    moyenne = 0;
    for(int i=0; i < nb_etudiants_effectif; i++)
    {
        moyenne = moyenne + notes[i];
    }
    moyenne = moyenne / nb_etudiants_effectif;

    printf("La moyenne des notes est: %lf\n", moyenne);

    max = notes[0];
    for(int i=1; i<nb_etudiants_effectif ; i++)
    {
        if(notes[i] > max)
        {
            max = notes[i];
        }
         
    }
    printf("La meilleure note de la classe: %lf\n", max);



 
 
 
 
 
 
 
 
 
 



    return EXIT_SUCCESS;
}

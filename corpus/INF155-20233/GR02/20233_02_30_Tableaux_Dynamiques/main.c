#include <stdio.h>
#include <stdlib.h>

int main() {
    int nb_notes;
    double* notes;
    double notes_statique[60];

//    notes_statique[i] est equivalent à *(notes_statique+i)
//    *(notes_statique+0) = 90;
//    printf("La case 0 contient: %lf\n", notes_statique[0]);
//
//    *(notes_statique+1) = 85;
//    printf("La case 1 contient: %lf\n", notes_statique[1]);






    printf("Combien de notes: ");
    scanf("%i", &nb_notes);

    notes = (double*)malloc(sizeof(double)*nb_notes);
    //Même effet que malloc, avec en plus un remplissage
    //de l'espace avec des 0.
    //notes = (double*)calloc(nb_notes, sizeof(double));
    if(notes == NULL)
    {
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<nb_notes; i++)
    {
        printf("Saisir la note %i: ", i);
        scanf("%lf", &notes[i]);
    }

    double moyenne = 0;
    for(int i=0; i<nb_notes; i++)
    {
        moyenne+= notes[i];
    }
    moyenne /= nb_notes;
    printf("La moyenne est: %lf\n", moyenne);

    double* ptr_temporaire;
    ptr_temporaire = (double*)realloc(notes, sizeof(double)*nb_notes*2);
    if(ptr_temporaire==NULL)
    {
        exit(EXIT_FAILURE);
    }
    notes = ptr_temporaire;

    for(int i=0; i<nb_notes; i++)
    {
        printf("Note num. %i: %lf\n", i, notes[i]);
    }




//    //*(notes+0) = 90;
//    notes[0] = 90;
//    //*(notes+1) = 85;
//    notes[1] = 85;
//    //*(notes+2) = 72;
//    notes[2] = 72;

    return 0;
}

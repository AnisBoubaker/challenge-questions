#include <stdio.h>
#include <stdlib.h>

int main() {
    int nb_notes;
    double* notes;
    double notes_statique[60];

 
 
 
 
 
 






    printf("Combien de notes: ");
    scanf("%i", &nb_notes);

    notes = (double*)malloc(sizeof(double)*nb_notes);
     
     
     
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




 
 
 
 
 
 

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//Déclarer une constante, qu'on écrit entièrement en MAJ
//Pas de ; à la fin!
#define NB_ETUDIANTS 65

int main(void) {
    double notes[NB_ETUDIANTS];
    int nb_etudiants_effectif;
    double moyenne;
    double max;

    int ma_var = 10;

//    notes[0] = 90;
//    notes[1] = 80;
//    notes[2] = 89;
//    notes[3] = 75;
//    notes[4] = 65;
//    nb_etudiants_effectif = 5;

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
        //max = notes[i] > max ? notes[i] : max;
    }
    printf("La meilleure note de la classe: %lf\n", max);



//    double note_et1, note_et2, note_et3, note_et4, note_et5;
//    double moyenne;
//
//    note_et1 = 80;
//    note_et2 = 95;
//    note_et3 = 76;
//    note_et4 = 65;
//    note_et5 = 89;
//
//    moyenne = (note_et1 + note_et2 + note_et3 + note_et4 + note_et5)/5;



    return EXIT_SUCCESS;
}

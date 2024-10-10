/*
 * EXERCICE
 * Écrire la fonction `majuscules_minuscules` qui reçoit un tableau
 * de caractères en argument et qui compte le nombre de majuscules et
 * le nombre de minuscules contenues dans le tableau.
 */

#include <stdio.h>
#include <stdlib.h>

void majuscules_minuscules(char tab[], int taille, int* nb_maj, int* nb_min);

int main(void) {
    int nb_minuscules, nb_majuscules;
    char caracteres[100] = {'B', 'o', 'n', 'j', 'o', 'u', 'r', ' ', 'E', 'T', 'S'};

    majuscules_minuscules(caracteres, 11, &nb_majuscules, &nb_minuscules);

    printf("Il y a %i majuscules et %i minuscules\n", nb_majuscules, nb_minuscules);




    return EXIT_SUCCESS;
}

void majuscules_minuscules(char tab[], int taille, int* nb_maj, int* nb_min)
{
    *nb_maj = 0;
    *nb_min = 0;
    for(int i=0; i< taille; i++)
    {
        if(tab[i]>= 'A' && tab[i]<='Z')
        {
            *nb_maj+=1;
        }
        else if (tab[i]>='a' && tab[i]<='z')
        {
            (*nb_min)++;
        }
    }
}
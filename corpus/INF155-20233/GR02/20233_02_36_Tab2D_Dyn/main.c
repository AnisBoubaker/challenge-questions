#include <stdio.h>
#include <stdlib.h>

int** creer_tab2d_dyn(int nb_lignes, int nb_colonnes);

int main() {

    int tab2d[3][4];
    int** tab2d_dyn;
    int nb_lignes = 3;
    int nb_colonnes = 4;

    tab2d_dyn = creer_tab2d_dyn(nb_lignes, nb_colonnes);

    for(int i=0; i<nb_lignes; i++)
    {
        for(int j=0; j<nb_colonnes; j++)
        {
            tab2d_dyn[i][j] = i*j;
        }
    }
    // ....
    for(int i=0; i<nb_lignes; i++)
    {
        for(int j=0; j<nb_colonnes; j++)
        {
            printf("%i\t", tab2d_dyn[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int** creer_tab2d_dyn(int nb_lignes, int nb_colonnes)
{
    int** tab2d_dyn;

    tab2d_dyn = (int**)malloc(sizeof(int*)*nb_lignes);
    if(tab2d_dyn == NULL)
    {
        return NULL;
    }
    for(int i=0; i<nb_lignes; i++)
    {
        tab2d_dyn[i]=(int*)malloc(sizeof(int)*nb_colonnes);
        if(tab2d_dyn[i] == NULL)
        {
            for(int j=0; j<i; j++)
            {
                free(tab2d_dyn[j]);
            }
            free(tab2d_dyn);
            return NULL;
        }
    }

    return tab2d_dyn;
}
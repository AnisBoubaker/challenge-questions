
#include "temperatures.h"

 
void afficher_tab2d(double tab[][MAX_COLONNES], int nb_lignes, int nb_colonnes)
{
    for(int i=0; i < nb_lignes ; i++)
    {
        for(int j=0; j< nb_colonnes; j++)
        {
            printf("%.2lf\t", tab[i][j]);
        }
        printf("\n");
    }
}

 
double moyenne_tab2d(double tab[][MAX_COLONNES], int nb_lignes, int nb_colonnes)
{
    double somme = 0 ;

    for(int i=0; i< nb_lignes; i++)
    {
        for(int j =0 ; j<nb_colonnes ; j++)
        {
            somme += tab[i][j];
        }
    }
    return somme / (nb_lignes * nb_colonnes);
}

 

int temperature_excedant(double tab[][MAX_COLONNES],
                         int nb_lignes,
                         int nb_colonnes,
                         double temp_seuil)
{
    int nb_excedant = 0;

    for(int i=0; i<nb_lignes; i++)
    {
        for(int j=0; j<nb_colonnes; j++)
        {
            if(tab[i][j]>temp_seuil)
            {
                nb_excedant++;
            }
        }
    }
    return nb_excedant;
}



#include "temperatures.h"

/*
 * Lorsqu'on passe un tableau à 2 dimensions à une fonction, il
 * est obligatoire de spécifier la taille MAXIMALE en colonnes.
 */
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

/* Écrire une fonction `moyenne_tab2d` qui reçoit
 * un tableau à 2 dimensions de réels et qui retourne
 * la moyenne du tableau. */
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

/*
 * Écrire la fonction `temperatures_excedant` compter le nombre de temperatures
 * qui excèdent une température donnée
 */

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


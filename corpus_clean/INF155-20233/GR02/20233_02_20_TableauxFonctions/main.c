#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 50


void afficher_tableau(int tableau[], int taille);
double moyenne_tableau_entier(int tableau[], int taille);
void fonction_bidon(int a);
void mettre_a_zero(int tableau[], int taille);


int main(void) {
    int tab[TAILLE_MAX] = {10, 20 , 30, 40, 50};
    double tab_reels[TAILLE_MAX] = {10, 20 , 30 , 40 , 50};

 
 
 
 

    afficher_tableau( tab, 5 );

    printf("La moyenne du tableau: %lf\n", moyenne_tableau_entier(tab,5));

     
    printf("La moyenne du tableau de reels: %lf\n",
           moyenne_tableau_entier(tab_reels,5));


    int x = 5;

    mettre_a_zero(tab, 5);
    afficher_tableau(tab, 5);


    return EXIT_SUCCESS;
}

 
void afficher_tableau(int tableau[], int taille)
{
    for(int i=0; i< taille; i++)
    {
        printf("La case #%i contient: %i\n", i, tableau[i]);
    }
}

double moyenne_tableau_entier(int tableau[], int taille)
{
    double moyenne = 0;
    for(int i=0; i<taille; i++)
    {
        moyenne += tableau[i];
    }
    moyenne = moyenne / taille;
    return moyenne;
}

 
void mettre_a_zero(int tableau[], int taille)
{
    for(int i=0; i<taille; i++)
    {
        tableau[i] = 0;
    }
}

 
void fonction_bidon(int a)
{
    a = a * 20;
}
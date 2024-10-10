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

//    for(int i=0; i<5; i++)
//    {
//        printf("La case #%i contient: %i\n", i, tab[i]);
//    }

    afficher_tableau( tab, 5 );

    printf("La moyenne du tableau: %lf\n", moyenne_tableau_entier(tab,5));

    /*
     * La fonction retourne n'importe quoi car elle s'attend à
     * recevoir un tableau d'entiers, et on lui passe un tableau
     * de doubles.
     */
    printf("La moyenne du tableau de reels: %lf\n",
           moyenne_tableau_entier(tab_reels,5));


    int x = 5;

    mettre_a_zero(tab, 5);
    afficher_tableau(tab, 5);


    return EXIT_SUCCESS;
}

/*
 * TOUTE fonction qui reçoit un tableau en paramètre
 * doit obligatoirement recevoir également la taille effective
 * du tableau
 */
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

/*
 * Notez ici que la fonction va modifier le
 * tableau original, car un tableau est en
 * réalité un pointeur.
 * Toute modification dans le tableau "tableau"
 * va changer le contenu à la case correspondante
 * du tableau qui a été passé en paramètre lors
 * de l'appel de la fonction (ici on l'appelle
 * depuis le main en passant le tableau tab).
 */
void mettre_a_zero(int tableau[], int taille)
{
    for(int i=0; i<taille; i++)
    {
        tableau[i] = 0;
    }
}

/*
 * Ici notre fonction reçoit un entier
 * (pas un tableau). L'entier "a" est une variable
 * locale à la fonction. En la modifiant, on modifie
 * la valeur de cette variable locale.
 * En quittant la fonction, la variable "a" est
 * détruite et le calcul qu'on y a stocké est perdu.
 * Cette fonction n'a donc aucun intérêt.
 */
void fonction_bidon(int a)
{
    a = a * 20;
}
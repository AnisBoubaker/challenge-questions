/*
 * Module : labyrinthe.c
 * Description : Fournit l'ensemble des fonctions permettant de resoudre un labyrinthe.
 *
 * Auteur : Samy Mekkati, Daniel Atik, Jad Bizri
 *
 *
 * Date : 2023-11-12
 */

#include "labyrinthe.h"


/*
 * FONCTION: nb_aleatoire
 * Cette fonction retourne une valeur aleatoire dans l'intervalle entier
   [min, max]. Chaque valeur poss?de la meme probabilite d'etre generee.

   PARAM?TRES :
        - min : La plus petite valeur pouvant etre generee (type : int).
        - max : La plus grande valeur pouvant etre generee (type : int).

    VALEUR DE RETOUR : Une valeur se trouvant dans l'intervalle
                       [min, max]  (type : int).

    ANTECEDENTS :
        - On suppose que la fonction srand a prealablement ete appelee.
 */

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

/*
 * FONCTION: pas_a_pas
 * Cette fonction affiche la grille chaque fois qu'un deplacement est effectuee

   PARAMETRES :
        - debug : Valeur booleenne qui est vrai lorsque l'usager veut voir l'evolution des deplacements, Faux sinon.
        - grille : Tableau 2D qui represente la grille qui doit etre resolue.
        - hauteur_grille : Hauteur de la grille choisie.
        - largeur_grille : Largeur de la grille choisie.
        - pile_solution : Tableau 2D qui contient le chemin emprunte.

    VALEUR DE RETOUR : Aucune, c'est une fonction d'affichage.
 */

void pas_a_pas(int debug, int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
    if(debug == 1)
    {
        lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
        system("pause");
        system("cls");
    }
}


/*
 * FONCTION: vider_pile
 * Cette fonction vide une pile

   PARAMETRES :
        - pile : Tableau 2D representant une pile que l'on souhaite vider.

    VALEUR DE RETOUR : Aucune.
 */

void vider_pile(int pile[TAILLE_MAX_PILE][2])
{
    int taille = pile[0][1];

    for (int i = 0; i < taille; ++i)
    {
        for(int j = 0; j < 2; j++)
        {
            pile[i][j] = 0;
        }
    }
}


/*
Module: utilitaires

Auteur: Ferdaws Aljane, Milena Busuioc, Rachid Hamza et William Lavoie

Date: 12 Novembre 2023
*/

#include "utilitaires.h"
#include "labyrinthe.h"
#include "pile.h"


int deplacement_est_possible( int grille[][TAILLE_MAX_GRILLE],
                              int hauteur_grille,
                              int largeur_grille,
                              int pos_ligne,
                              int pos_colonne,
                              int solution_partielle[][2])
{
    int ligne;
    int colonne;

    //Vérifie que la coordonnée fasse partie de la grille et ne soit pas un mur
    if (pos_ligne < hauteur_grille && pos_colonne < largeur_grille && grille[pos_ligne][pos_colonne] != 1
          && pos_colonne >= 0 && pos_ligne >= 0)
    {
        //La grille a un maximum de 100*100 coordonnées
        int pile_copie[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE+1][2];
        pile_copier(solution_partielle, pile_copie);

        //On dépile la pile de solution jusqu'à trouver la coordonnée analysée ou que la
        //pile soit vide
        while (!pile_est_vide(pile_copie))
        {
            pile_depiler(pile_copie, &ligne, &colonne);
            if (ligne == pos_ligne && colonne == pos_colonne)
            {
                return 0;   //faux si la case adjacente est dans la pile_solution
            }
        }

        return 1;
    }
    return 0;
}

void effacer_terminal(void)
{
    // Si le programme est lancé sur une machine Windows, la commande CLI cls est lancée
    #ifdef _WIN32
        system("cls");

    // Autrement, sur les machines basés sur Unix (mac et Linux) la commande clear est lancée
    #else
         system("clear");
    #endif
}

void afficher_menu(int grille_chargee)
{
    //Si une grille a été chargée alors toutes les options sont disponibles
    if (grille_chargee)
    {
        printf("\t\t*************************\n");
        printf("\t\t*** LABYRINTHE EXPERT ***\n");
        printf("\t\t*************************\n\n");
        printf("\t1. Charger un labyrinthe\n");
        printf("\t2. Resoudre le labyrinthe\n");
        printf("\t3. Resoudre le labyrinthe pas-a-pas\n");
        printf("\t4. Quitter le programme\n\n");
    }

    //Si aucun labyrinthe n'est chargée, alors il est impossible de résoudre un labyrinthe
    else
    {
        printf("\t\t*************************\n");
        printf("\t\t*** LABYRINTHE EXPERT ***\n");
        printf("\t\t*************************\n\n");
        printf("\t1. Charger un labyrinthe\n");
        printf("\t2. [Indisponible] Resoudre le labyrinthe\n");
        printf("\t3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
        printf("\t4. Quitter le programme\n\n");
    }
}


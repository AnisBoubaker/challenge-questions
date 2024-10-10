//
// Created by User on 2023-11-06.
//

#include "utilitaire.h"


/* Fonction qui genere un nombre aleatoire et le retourne
 Parametres :
min : Borne inferieure delimitant la plage de nombre pouvant etre generes
max : Borne superieure delimitant la plage de nombre pouvant etre generes
Retour : Entier qui represente la valeur generee aleatoirement */

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand()/(RAND_MAX+0.001)*(max-min+1));
}


void afficher_grille_debug(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille,
                           int pile_solution[][2], int debug)
{
    // Seulement lorsque la fonction resoudre_deplacement recoit le parametre debug '1' (vrai)
    if (debug == 1)
    {
        // Effacer le dernier affichage de la grille (Incluant les \n)
        for (int i = 0; i < (hauteur_grille+1); i++)
            for (int k = 0; k < largeur_grille; k++)
                printf("\b");

        // Met à jour la grille en l'affichant avec la solution mise à jour
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }
}
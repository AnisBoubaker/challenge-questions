 


#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"



#define TAILLE_MAX_PILE 1000  
#define TAILLE_MAX 100

int main (void)
{

    char nom_fichier[TAILLE_MAX];
    int gril_le[][TAILLE_MAX] = {0};
    int pt_entree[2];
    int hauteur;
    int largeur;
    int num_grille_chargee;
    int solution [][2] = {0};
    int de_bug;
    char buf_nom_fichier1[TAILLE_MAX];
    char buf_nom_fichier2[TAILLE_MAX];
    char buf_nom_fichier3[TAILLE_MAX];
    char buf_nom_fichier4[TAILLE_MAX];
    char grille_choisie[TAILLE_MAX];


    menu_charger_labyrinthe(buf_nom_fichier1, TAILLE_MAX);
    menu_charger_labyrinthe(buf_nom_fichier2, TAILLE_MAX);
    menu_charger_labyrinthe(buf_nom_fichier3, TAILLE_MAX);
    menu_charger_labyrinthe(buf_nom_fichier4, TAILLE_MAX);

    selection_menu(num_grille_chargee);

    if (num_grille_chargee == 1)
    {
        strncpy(grille_choisie, buf_nom_fichier1, TAILLE_MAX);
    }

    if (num_grille_chargee == 2)
    {
        strncpy(grille_choisie, buf_nom_fichier2, TAILLE_MAX);
    }

    if (num_grille_chargee == 3)
    {
        strncpy(grille_choisie, buf_nom_fichier3, TAILLE_MAX);
    }

    if (num_grille_chargee == 4)
    {
        strncpy(grille_choisie, buf_nom_fichier4, TAILLE_MAX);

    }

    charger_labyrinthe(grille_choisie, gril_le, pt_entree, &hauteur, &largeur);

    lab_afficher_grille(gril_le, hauteur, largeur,solution);

    lab_resoudre_profondeur(gril_le, hauteur, largeur, pt_entree, solution, de_bug);

    system("pause");
    return EXIT_SUCCESS;
}
 
  
  

/*
TP2 - Labirynthe 
Ce projet vise � r�soudre un labyrinthe en trouvant un chemin qui nous m�ne vers
la sortie du labyrinthe en partant de son entr�e. 


Auteurs: Ken Whittom ,Anthony Carhuallanqui Nerio, Franck Kamwa

Date: 2023-11-12
*/

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

int main(void)
{
    // Declaration des variables
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];//La grille .txt que nous devons charger
    int entree[2];//L'entree du labyrinthe
    int hauteur_grille;//la hauteur du labyrinthe
    int largeur_grille;//la largeur duy labyrinthe
    int choix;//le choix du menu
    int grille_chargee =0;//L'etat de la grille charger
    char nom_fichier[TAILLE_MAX_NOM_FICHIER];//le nom du ficher .txt
    int pile_solution[TAILLE_MAX_GRILLE][2];//la pile qui contient la solution du labyrinthe

    do {

        //initialiser la pile solution
        pile_initialiser(pile_solution, TAILLE_MAX_GRILLE);

        do {
            choix = selection_menu(grille_chargee);

            //si l'utilisateur fait le choix 1 dans le menu
            if (choix ==1){
                menu_charger_labyrinthe(nom_fichier, 30);
                grille_chargee = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille, &largeur_grille);

                if (grille_chargee ==1){
                    printf("succes du chargement.\n");
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                    system("pause");
                }
            }
        } while (choix == 1 && grille_chargee ==1);

        //si l'utilisateur fait le choix 2 dans le menu
        if (choix ==2 && grille_chargee ==1){
           if(lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree, pile_solution, 0))
           {
               lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
           }
           else
           {
               printf("Erreur pas de solution trouver.\n");
           }

           //si l'utilisateur fait le choix 3 dans le menu
        } else if (choix ==3 && grille_chargee ==1){
            lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree, pile_solution, 1);

            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            if (!lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,entree,pile_solution,1))
            {
                printf("Erreur pas de solution trouver.\n");
            }

            //si l'utilisateur fait le choix 4 dans le menu
        } else if (choix ==4){
            printf("Merci d'avoir utilise le solveur de labyrinthe! \n");

            system("pause");

            return EXIT_SUCCESS;
        }
    }while(choix != 4); // sortir de la boucle par la selection 4.
}





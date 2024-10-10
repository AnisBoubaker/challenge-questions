 

 
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

 
 
#define TAILLE_MAX_PILE 1000
 
#define TAILLE_MAX_GRILLE 100

 
int main(void) {
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
    int entree[2];  
    int largeur_grille;  
    int hauteur_grille;  
    int grille_chargee=0;  
    int choix_menu=0;  
    int debug;  
    int pile_solution[TAILLE_MAX_PILE][2];  
    int solution_trouver;  
    char nom_fichier[TAILLE_MAX_NOM_FICHIER];  


     
    while (choix_menu != 4)
    {
         
        choix_menu = selection_menu(grille_chargee);

         
        switch (choix_menu)
        {

             
            case 1:
                if (grille_chargee == 0)
                {
                    do
                    {
                        menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);

                         
                        grille_chargee = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille,
                                                            &largeur_grille);
                         
                        if (grille_chargee == 0)
                        {
                            printf("Fichier introuvable\n");
                        }
                        else
                        {
                             
                            for (int i = 0; i < 4; i++)
                            {
                                for (int j = 0; j < 2; j++)
                                {
                                    pile_solution[i][j] = 0;
                                }
                            }

                             
                            printf("Grille charger avec success\n");
                            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                        }
                    }
                    while (grille_chargee != 1);
                }
                 
                else if (grille_chargee == 1)
                {
                    grille_chargee = 0;
                    do
                    {
                         
                        menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);

                        grille_chargee = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille,
                                                            &largeur_grille);
                         
                        if (grille_chargee == 0)
                        {
                            printf("Fichier introuvable\n");
                        }
                        else
                        {
                                 
                                for (int i = 0; i < 4; i++)
                                {
                                    for (int j = 0; j < 2; j++)
                                    {
                                        pile_solution[i][j] = 0;
                                    }
                                }

                                 
                                printf("Grille charger avec success\n");
                                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                        }
                    } while (grille_chargee != 1);
                }
                break;



             

            case 2:

                debug=0;
                printf("\n");
                solution_trouver = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree,
                                                           pile_solution, debug);
                 
                if(solution_trouver == 1)
                {
                    printf("Resolue\n");
                }
                 
                else
                {
                    printf("Le labyrinthe ne peut pas etre resolue.\n");
                }
                break;



             

            case 3:
                debug=1;
                printf("\n");
                solution_trouver = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille,
                                                           entree, pile_solution, debug);

                if(solution_trouver == 1)
                {
                    printf("Resolue\n");
                }
                else
                {
                    printf("Le labyrinthe ne peut pas etre resolue.\n");
                }
                break;



             

            case 4:
                break;

             

            default:
                printf("Erreur, veuillez reesayer\n");
                break;
        }
    }
    system("pause");
    return EXIT_SUCCESS;
}


 

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

int main(void)
{
     
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; 
    int entree[2]; 
    int hauteur_grille; 
    int largeur_grille; 
    int choix; 
    int grille_chargee =0; 
    char nom_fichier[TAILLE_MAX_NOM_FICHIER]; 
    int pile_solution[TAILLE_MAX_GRILLE][2]; 

    do {

         
        pile_initialiser(pile_solution, TAILLE_MAX_GRILLE);

        do {
            choix = selection_menu(grille_chargee);

             
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

         
        if (choix ==2 && grille_chargee ==1){
           if(lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree, pile_solution, 0))
           {
               lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
           }
           else
           {
               printf("Erreur pas de solution trouver.\n");
           }

            
        } else if (choix ==3 && grille_chargee ==1){
            lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree, pile_solution, 1);

            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            if (!lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,entree,pile_solution,1))
            {
                printf("Erreur pas de solution trouver.\n");
            }

             
        } else if (choix ==4){
            printf("Merci d'avoir utilise le solveur de labyrinthe! \n");

            system("pause");

            return EXIT_SUCCESS;
        }
    }while(choix != 4);  
}





 


#include <stdlib.h>
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE 1000  
#define TAILLE_MAX_FICHIER 100  


int main(void)
{


    char nom_fichier[TAILLE_MAX_FICHIER] = "../";
    char fichier_saisi[TAILLE_MAX_NOM_FICHIER];
    int saisie;



	 
	 
	int la_pile[TAILLE_MAX_PILE][2];  
	int depile_x;  
	int depile_y;  


	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
	int point_entree[2];  
	int hauteur_grille, largeur_grille;  
	int succes_chargement=0;  
    int pile_solution[TAILLE_MAX_PILE][2];
    int debug = 0;

    do
    {
         
        succes_chargement = charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);

         
        if (!succes_chargement)
        {
            saisie = 0;
        }
         
        else
        {
            saisie = 1;
        }

         
        saisie = selection_menu(saisie);

         
        if (saisie == 1)
         
        {
            for(int i=0; i<TAILLE_MAX_GRILLE; i++)
            {
                for(int j=0; j<TAILLE_MAX_GRILLE; j++)
                {
                    grille[i][j] = 0;
                }
            }
            for(int i = 0; i < TAILLE_MAX_PILE; i++)
            {
                pile_solution[i][0] = 0;
                pile_solution[i][1] = 0;
            }

            strcpy(nom_fichier, "../");
            menu_charger_labyrinthe(fichier_saisi, TAILLE_MAX_NOM_FICHIER);  

             
            strcat(nom_fichier,fichier_saisi);
            succes_chargement = charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);

            if (!succes_chargement)
            {
                printf("Erreur lors du chargement de la grille.\n");  
            }
            else
            {
                printf("Grille chargee avec succes: \n");  
                lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            }
            system("pause");
        }
         
        else if (saisie == 2)
        {
            debug = 0;
            if(!lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, debug))
            {
                printf("Le labyrinthe n'a pas de sortie!\n");  
            }
            else
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);  
            }
            system("pause");
        }
             
        else if (saisie == 3)
        {
            debug = 1;
            lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, debug);
        }

    } while(saisie != 4);  


	return EXIT_SUCCESS;
}

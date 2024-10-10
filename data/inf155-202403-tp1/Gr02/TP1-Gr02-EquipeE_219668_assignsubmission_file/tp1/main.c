/*
TP2 - Labirynthe 
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée. 

Auteurs: Equipe E
Date: 2023-11-12

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"




int main(void)
{

    srand(time(NULL));

	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
	int point_entree[2]; //Stocke les coordonnées du point d'entrée du labyrinthe lors du chargement
	int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargée depuis le disque
    int choix; //entier de 1 a 4 qui s'occupe de naviguer le menu principal
    int grille_charger = 0; //on l'egale a 0 puisqu'au debut il n'y a jamais de grille chargee

    char nom_du_fichier[TAILLE_MAX_GRILLE]; //on stocke le nom du fichier dans cette chaine caractere (qui va etre saisie dans menu_charger_labyrinthe)
    int taille_du_fichier; //la taille du fichier en question

	int succes_lab; //Stocke une valeur vraie si tu as trouvee une solution, faux sinon.
    int pile_solution[TAILLE_MAX_PILE][2]; //

    choix = selection_menu(grille_charger);
    if(choix == 4)
    {
        printf("Vous avez quitte\n");  //on ecrira ce qu'on veut
        exit(EXIT_FAILURE);
    }
    if(choix == 1) //pour demander le nom du fichier
    {
        menu_charger_labyrinthe(nom_du_fichier, sizeof(nom_du_fichier));
        //afficher le nom du fichier juste pour voir
    }

    grille_charger = charger_labyrinthe(nom_du_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

    printf("Press any key to continue...\n");
    getchar();

    choix = selection_menu(grille_charger);

    if(choix == 1)
    {
        while (choix == 1)
        {
            printf("Vous avez deja chargee une grille, veuillez choisir une differente option : ");
            scanf("%d", &choix);
        }
    }
    if(choix == 2)
    {
        if(lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0))
        {

            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            printf("Press any key to continue...\n");
            getchar();
        }
        else
        {
            printf("le labyrinthe n'a pas ete resolu");
        }

        charger_labyrinthe(nom_du_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
    }
    if(choix == 3)
    {
        if(lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, 0))
        {

            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

        }
        else
        {
            printf("le labyrinthe n'a pas ete resolu");
        }

        charger_labyrinthe(nom_du_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);
    }
    if(choix == 4)
    {
        printf("Vous avez quitte\n");  //on ecrira ce qu'on veut
        exit(EXIT_FAILURE);
    }

	return EXIT_SUCCESS;
}

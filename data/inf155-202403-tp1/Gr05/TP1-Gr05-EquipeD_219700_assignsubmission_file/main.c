/*
TP2 - Labyrinthe
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée.

Auteurs:TP1-Gr05-EquipeD:
        Nadir Kaciousalah
        Francis Yelle
        Massin Ait-Bara
        François-Xavier Bédard
Date: 10-11-2023
*/

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

int main(void)
{
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
    int point_entree[2]; //Stocke les coordonnées du point d'entrée du labyrinthe lors du chargement
    int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargée depuis le disque
    int pile_solution[TAILLE_MAX_GRILLE][2]; //les solution de labyrinthe

    int succes_chargement = 0; //Stocke une valeur vraie si la grille a été chargée correctement.
    char buf_nom_fichier[200]; //pour mettre le nom de la la grille a charger
    int buf_taille=200; //pour mettte le nom de la la grille a charger
    int debug; //debug 1 on afficher solution step by step
    int solution_trouvee; //solution_trouvee == 1 ça veut dire que la solution du labyrinthe est trouvee
    int choix; //Choix de selection de menu

    pile_initialiser(pile_solution, TAILLE_MAX_Pile); // Initialiser la pile de solution

    while (1)
    {
        choix = selection_menu(succes_chargement);    //La fonction selection_menu pour faire un choix

        if (choix == 1)//Charger une labyrinthe
        {
            ////////////*  fontion menu_charger_labyrinthe *///////////////
            menu_charger_labyrinthe(buf_nom_fichier, buf_taille); //fontion menu_charger_labyrinthe pour choisir un labyrinthe
            succes_chargement=charger_labyrinthe(buf_nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille); //charger_labyrinthe une labyrinthe

            if (!succes_chargement)
            {
                printf("Une erreur s'est produite lors du chargement de la grille.\n");
                system("pause");
            }
            else
            {
                printf("Grille chargee avec succes:\n");
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution); // afficher le labyrinthe
                system("pause");
            }
        }
        else if (choix == 2)///Resoudre le labyrinthe
        {
            debug = 0;
            solution_trouvee = lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,point_entree,pile_solution,debug); //la fontion lab_resoudre_profondeur

            if (solution_trouvee == 1)//Solution trouve
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution); // afficher le labyrinthe avec le chemin parcouru
                system("pause");
            }
            else//Solution non trouve
            {
                printf("Aucune solution trouvee :-(\n");
                system("pause");
            }
        }
        else if (choix == 3)///Resoudre le labyrinthe pas a pas en affichant toutes les etapes
        {
            debug = 1;
            lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,point_entree,pile_solution,debug); //la fontion lab_resoudre_profondeur
        }
        else if (choix == 4)///Quitter le programme
        {
            return EXIT_SUCCESS;
        }
    }



}

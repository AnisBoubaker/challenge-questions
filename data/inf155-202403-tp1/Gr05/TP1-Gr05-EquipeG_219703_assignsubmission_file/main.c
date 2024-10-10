/*
TP2 - Labirynthe
Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée.

Auteurs:Francis Gignac, Rachelle Sanscartier, Maxim St-Gelais, Abraham Suarez-Santizo

Date:2023-11-12
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

/***********CONSTANTES DE COMPILATION*************/
/* La taille maximale des piles. */
#define TAILLE_MAX_PILE 1000
/* La taille maximale de la grille. */
#define TAILLE_MAX_GRILLE 100

/********* DÉFINITION DES FONCTION **************/
int main(void) {
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; /* Tableau
                                                         représentant le labyrinthe.
                                                      */
    int entree[2]; /* Tableau contenant les coordonnées
                      du point d'entrée du labyrinthe.
                   */
    int largeur_grille; /* Représente le nombre de colonnes du tableau. */
    int hauteur_grille; /* Représente le nombre de lignes du tableau. */
    int grille_chargee=0; /* Permet de savoir si une grille est chargée ou non. */
    int choix_menu=0; /* Permet de connaitre l'option choisi par l'utilisateur. */
    int debug; /* Déterminer l'affichage du labyrinthe selon le choix de l'utilisateur. */
    int pile_solution[TAILLE_MAX_PILE][2]; /*Pile contenant le trajet de notre pion. */
    int solution_trouver; /*Variable qui contient la valeur de retour
                            de la fonction lab_resoudre_profondeur.
                          */
    char nom_fichier[TAILLE_MAX_NOM_FICHIER]; /* Le nom du fichier. */


    /* Voici le menu principale. Tant qu'on ne sélectionne pas l'option 4,
       le programme fonctionne.
    */
    while (choix_menu != 4)
    {
        /* On fait apparaitre le menu avec la fonction selection_menu.
           Le menu change en fonction
           que la grille est chargee ou non. À l'ouverture du programme,
           la grille ne sera pas chargée. La fonction selection_menu va retourner la valeur
           de l'option choisit dans choix_menu.
        */
        choix_menu = selection_menu(grille_chargee);

        /* Il y a quatre choix selon la valeur de choix_menu. La première permet de charger
           une grille. Le deuxième permet de résoudre le labrinthe (si disponible).
           Le troisième permet de résoudre le labyrinthe étape par étape.
           La quatrième permet de quitter le programme.
        */
        switch (choix_menu)
        {

            /* L'option 1 permet de charger une grille. S'il n'y a pas de grille_charger,
               elle va demander la saisie du nom de fichier pour ainsi charger le labyrinthe
               et l'afficher. Si la grille est charger mais, qu'on veut changer de grille,
               on va remettre la variable grille_chargee à zéro et faire comme dans la première
               partie.
            */
            case 1:
                if (grille_chargee == 0)
                {
                    do
                    {
                        menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);

                        /* Chargement de la grille, assignation de la grille, son entrée,
                           sa hauteur et sa largeur.
                        */
                        grille_chargee = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille,
                                                            &largeur_grille);
                        /* Si la grille ne se charge pas, la console indique que le fichier est introuvable. */
                        if (grille_chargee == 0)
                        {
                            printf("Fichier introuvable\n");
                        }
                        else
                        {
                            /* Initialisation de la pile pour le premier affichage. */
                            for (int i = 0; i < 4; i++)
                            {
                                for (int j = 0; j < 2; j++)
                                {
                                    pile_solution[i][j] = 0;
                                }
                            }

                            /* Affichage du succès et du labyrinthe. */
                            printf("Grille charger avec success\n");
                            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                        }
                    }
                    while (grille_chargee != 1);
                }
                /* Si une grille est déjà chargée, mais qu'on veut changer de grille. */
                else if (grille_chargee == 1)
                {
                    grille_chargee = 0;
                    do
                    {
                        /* Chargement de la grille, assignation de la grille, son entrée,
                           sa hauteur et sa largeur.
                        */
                        menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);

                        grille_chargee = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille,
                                                            &largeur_grille);
                        /* Si la grille ne se charge pas, la console indique que le fichier est introuvable. */
                        if (grille_chargee == 0)
                        {
                            printf("Fichier introuvable\n");
                        }
                        else
                        {
                                /* Initialisation de la pile pour le premier affichage. */
                                for (int i = 0; i < 4; i++)
                                {
                                    for (int j = 0; j < 2; j++)
                                    {
                                        pile_solution[i][j] = 0;
                                    }
                                }

                                /* Affichage du succès et du labyrinthe. */
                                printf("Grille charger avec success\n");
                                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                        }
                    } while (grille_chargee != 1);
                }
                break;



            /* L'option 2 permet de montrer la résolution final du labyrinthe. */

            case 2:

                debug=0;
                printf("\n");
                solution_trouver = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, entree,
                                                           pile_solution, debug);
                /* Si la fonction lab_resoudre_profondeur renvoie 1, on affiche ce message. */
                if(solution_trouver == 1)
                {
                    printf("Resolue\n");
                }
                /* Sinon on renvoie ce message. */
                else
                {
                    printf("Le labyrinthe ne peut pas etre resolue.\n");
                }
                break;



            /* L'option 3 permet de montrer tout le chemin que parcoure le programme
               pour résoudre le labyrinthe.
            */

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



            /* L'option 4 permet de quitter le programme. */

            case 4:
                break;

            /* Si l'utilisateur met un chiffre autre que 1, 2, 3, 4,
               default envoi un message d'erreur.
            */

            default:
                printf("Erreur, veuillez reesayer\n");
                break;
        }
    }
    system("pause");
    return EXIT_SUCCESS;
}


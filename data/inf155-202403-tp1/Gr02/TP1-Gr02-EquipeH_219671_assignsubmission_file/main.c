/*
TP2 - Labyrinthe
Ce projet vise a resoudre un labyrinthe en trouvant un chemin qui nous mene vers
la sortie du labyrinthe en partant de son entree.


Auteurs:    - Étienne Lemay
 *          - Félix Caron
 *          - Julien Hémond
 *          - Louis-Pierre Fortier

Date: 12 novembre 2023

*/


#include <stdlib.h>
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE 1000 //La taille maximale des piles
#define TAILLE_MAX_FICHIER 100 //La taille maximale des grilles


int main(void)
{


    char nom_fichier[TAILLE_MAX_FICHIER] = "../";
    char fichier_saisi[TAILLE_MAX_NOM_FICHIER];
    int saisie;



	//NOTE: Ce code vous est fourni a titre d'exemple pour que vous compreniez
	//le fonctionnement d'une pile. Vous ne devez pas conserver ce code avec votre projet!
	int la_pile[TAILLE_MAX_PILE][2]; //Tableau qui sera utilise pour stocker la pile d'exemple
	int depile_x; //Stocke la coordonnee x depilee
	int depile_y; //Stocke la coordonnee y depilee


	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
	int point_entree[2]; //Stocke les coordonnees du point d'entree du labyrinthe lors du chargement
	int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargee depuis le disque
	int succes_chargement=0; //Stocke une valeur vraie si la grille a ete chargee correctement.
    int pile_solution[TAILLE_MAX_PILE][2];
    int debug = 0;

    do
    {
        /* On appelle la fonction charger_labyrinthe qui retourne 1 ou 0 */
        succes_chargement = charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);

        /* Si la fonction retourne 0, la saisie est 0, car il n'y a pas encore de fichier chargé. */
        if (!succes_chargement)
        {
            saisie = 0;
        }
        /* Si la fonction retourne 1, la saisie est 1 et un fichier a été chargé, donc la grille a été remplie,
         * avec un point d'entrée, une hauteur et une largeur définie. */
        else
        {
            saisie = 1;
        }

        /* On affiche le menu et on demande à l'utilisateur de saisir ce qu'il veut faire. */
        saisie = selection_menu(saisie);

        /* Si la saisie est 1, le fichier demandé est chargé. */
        if (saisie == 1)
        /* Pour pouvoir mettre une nouvelle grille après la résolution d'une autre, on réinitialise la grille et la pile_solution. */
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
            menu_charger_labyrinthe(fichier_saisi, TAILLE_MAX_NOM_FICHIER); // La fonction demande à l'utilisateur de saisir le fichier qu''il désire.

            /* On ajoute ../ devant le nom du fichier */
            strcat(nom_fichier,fichier_saisi);
            succes_chargement = charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);

            if (!succes_chargement)
            {
                printf("Erreur lors du chargement de la grille.\n"); // Si la grille ne charge pas, on imprime un message d'erreur.
            }
            else
            {
                printf("Grille chargee avec succes: \n"); // Si la grille se charge bien, le labyrinthe non-résolu est affiché.
                lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            }
            system("pause");
        }
        /* Si la saisie est de 2, le labyrinthe chargé est résolu. */
        else if (saisie == 2)
        {
            debug = 0;
            if(!lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, debug))
            {
                printf("Le labyrinthe n'a pas de sortie!\n"); // Si le labyrithe n'a pas d'issu, un message est affiché.
            }
            else
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution); // S'il y a une solution, le labyrinthe résolu est affiché.
            }
            system("pause");
        }
            /* Si la saisie est de 3, le labyrinthe est résolu pas à pas. */
        else if (saisie == 3)
        {
            debug = 1;
            lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, debug);
        }

    } while(saisie != 4); // Le programme s'arrête si la saisie est 4.


	return EXIT_SUCCESS;
}

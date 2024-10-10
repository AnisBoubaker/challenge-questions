/*
TP1 - Labirynthe
Ce projet vise a resoudre un labyrinthe en trouvant un chemin qui nous mene vers
la sortie du labyrinthe en partant de son entree.


Auteurs: Felix Robillard, Lancelot Leonard, Jean-Nicolas Bouchard et Vincent Vinet

Date: 2023-10-16

*/

#include <stdio.h>
#include <stdlib.h>
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


#define TAILLE_MAX_PILE 1000 //La taille maximale des piles


int main(void)
{

    srand((unsigned int)time(NULL));
    rand();

    int la_pile[TAILLE_MAX_PILE][2]; //Tableau qui sera utilise pour stocker la pile
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
    int point_entree[2]; //Stocke les coordonn�es du point d'entree du labyrinthe lors du chargement
    int hauteur_grille, largeur_grille; //Stocke la taille de la grille chargee depuis le disque
    int succes_chargement = 0; //Stocke une valeur vraie si la grille a ete chargee correctement.
    int debug = 0; //Variable qui indice si on doit afficher le reponse du tableau en 1 etape ou en plusieurs etape
    int choix = 0; // Choix de l'usager
    char nom_fich[TAILLE_MAX_NOM_FICHIER] = {};

	/*** PARTIE 1: CHARGEMENT D'UNE GRILLE DEPUIS LE DISQUE ***/
    do {
        printf("\n\n");

        do {
            choix = selection_menu(succes_chargement); // On stock le choix de l'utilisateur

            if (choix == 1) {   //Si la personne click sur 1 elle va pouvoir entrer le nom du labyrinthe qu'elle souhaite resoudre (grille1.txt ou grille2.txt ect..)
                menu_charger_labyrinthe(nom_fich, TAILLE_MAX_NOM_FICHIER);
                succes_chargement = charger_labyrinthe(nom_fich, grille, point_entree, &hauteur_grille, &largeur_grille);

                //Si le labyrinthe a bien ete charger on clear le terminal et on affiche le labyrinthe charger
                if(succes_chargement)
                {
                    system("cls");
                    printf("Grille chargee avec success!\n\n");
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, 0);
                    printf("\n");
                    system("pause");
                }

            }

        } while (choix == 1); // if choix == 1 on recommence la boucle

        if(choix == 4) { //Quand la personne click sur 4 dans le menu sa quitte le programme
            break;
        }
        else if(choix == 3) {  // Quand la personne veut loader le labyrinthe etape par etape
            debug = 1;
        } else if(choix == 2){  // Si la personne veux loader la reponse du labyrinthe d'un seul coup
            debug = 0;
        }

        //Affiche la solution du labyrinthe
        lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, la_pile, debug);

        system("cls");

    } while(choix != 4); // Tant que l'utilisateur na pas decider de quitter (clicker sur 4) on recommence a l'infini la boucle

	return EXIT_SUCCESS;
}

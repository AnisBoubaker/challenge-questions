/*
 * Fichier: TP1 - Labirynthe
 * Description: Ce fichier détermine la solution d'un labyrinthe fournit en format texte
 * Auteurs:
 *  Tommy Parent,
 *  Maude Gallant-Mercier,
 *  Camille Landry,
 *  Saguira Neysa Charles
 * Date: 2023-11-11
*/

#include <stdio.h>
#include <stdlib.h>
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "pile.h"
#include "utilitaires.h"

#define TAILLE_MAX_GRILLE 100       //La taille maximale de la grille
#define TAILLE_MAX_NOM_FICHIER 100  //La taille maximale du nom de fichier de la grille
#define TAILLE_MAX_PILE 1000        //La taille maximale des piles

int main(void){

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];   //Grille qui sera chargée depuis un fichier text
    int nb_lignes;                                      //Le nombre de lignes de la grille
    int nb_colonnes;                                    //Le nombre de colonnes de la grille
    int entree[2];                                      //Les coordonnées du point d'entrée de la grille
    int choix_menu;                                     //Le choix d'option fait par l'utilisateur dans le menu
    char buf_nom_fichier[TAILLE_MAX_NOM_FICHIER];       //Le nom du fichier de la grille
    int pile_solution[TAILLE_MAX_PILE][2];              //La pile dans laquelle sera stockée la solution
    int succes_chargement=0;                              //Valeur qui indique si la grille a bien été chargée
    int solution_trouve;                                //Valeur qui indique si la solution a été trouvée

    // Cette série de conditions permet à l'usager de saisir les options désirées dans le menu interactif
    do
    {
        //affiche le menu et demande à l'usager de choisir une option
        choix_menu = selection_menu(succes_chargement);

        //demande à l'usager de saisir le nom de la grille et charge celle-ci
        if(choix_menu == 1)
        {
            //initialise la pile solution
            pile_initialiser(pile_solution, TAILLE_MAX_PILE);

            //charge la grille du labyrinthe
            menu_charger_labyrinthe(buf_nom_fichier, TAILLE_MAX_NOM_FICHIER);
            succes_chargement = charger_labyrinthe(buf_nom_fichier, grille, entree, &nb_lignes, &nb_colonnes);

            //ces conditons affichent si le chargement a bien été effectué
            if(succes_chargement)
            {
                printf("Grille chargee avec success: \n");
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution);
            }
            else
            {
                printf("Une erreur c'est produite lors du chargement de la grille.\n");
            }
            demande_pour_continuer();
        }

        //resous le labyrinthe au complet et affiche la solution, si celle-ci existe.
        else if (choix_menu == 2)
        {
            solution_trouve = lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, pile_solution, 0);
            if(solution_trouve)
            {
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution);
            }
            else
            {
                printf("Aucune solution trouvee :-(\n");
            }
            demande_pour_continuer();
        }

        //resous la labyrinthe pas-à-pas en affichant chaque déplacement jusqu'à la sortie, si celle-ci existe.
        else if (choix_menu == 3)
        {
            solution_trouve = lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, pile_solution, 1);
            if(!solution_trouve)
            {
                printf("Aucune solution trouvee :-(\n");
            }
            system("cls");
        }

    //si l'utilisateur saisie l'option 4,le programme se ferme
    }while(choix_menu != 4);

    return EXIT_SUCCESS;
}
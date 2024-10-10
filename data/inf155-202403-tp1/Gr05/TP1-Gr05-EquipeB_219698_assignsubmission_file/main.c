/*
TP2 - Labyrinthe
Ce projet vise a resoudre un labyrinthe en trouvant un chemin qui nous mene vers
la sortie du labyrinthe en partant de son entree.

Remis a: Anis Boubaker

Cours: INF155
Groupe: 05
Equipe: B

Auteurs:    Mahamat Faïkh
            Olivier Larocque-Brault
            Leandre Tuyishime

Date: 16 octobre 2023
*/

/// Bibliotheques
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"
#include "pile.h"


/// Debut du programme principal
int main(void)
{
    // Variables
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
    int pile_solution[TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE][2]; //Pile qui contient la solution du labirynthe en coordonnees
    int point_entree[2]; //Stocke les coordonnees du point d'entree du labyrinthe lors du chargement
    int hauteur_grille, largeur_grille; //Hauteur et largeur de la grille
    int succes_chargement = 0; //Stocke une valeur vraie si la grille a ete chargee correctement.
    int solution_trouvee ; //1=Solution trouvee
    int choix_utilisateur = 0; //Saisie de l'utilisateur dans le menu
    int meilleur_score; // Meilleur score
    char nom_fichier[15]; //Nom du fichier de la grille  *.txt
    int taille_nom_fichier = sizeof(nom_fichier);

    ///Mode Debug
    int debug = 0;

    /// On initialise le generateur de nombres aleatoires
    srand((unsigned int) time(NULL));
    rand();

    ///Boucle principale
    while (choix_utilisateur < 4)
    {
        //Afficher le menu principal et demande de choisir
        choix_utilisateur = selection_menu(succes_chargement);

        //Option 1 Charger un labirynthe
        if (choix_utilisateur == 1) {

            //Vider la pile solution1
            pile_initialiser(pile_solution, TAILLE_MAX_GRILLE*TAILLE_MAX_GRILLE);
            //Reinitialiser meilleur score
            meilleur_score=0;
            //Demander le nom du fichier *.txt
            menu_charger_labyrinthe(nom_fichier, taille_nom_fichier);

            //Remplacer le Retour a la ligne par Null pour le chargement du fichier
            int length = strlen(nom_fichier);
            if (nom_fichier[length - 1] == '\n')
            {
                nom_fichier[length - 1] = '\0';
            }

            //Charger le fichier
            succes_chargement = charger_labyrinthe(nom_fichier, grille, point_entree, &hauteur_grille, &largeur_grille);

            //Afficher une erreur si erreur au chargement et quitter
            if (!succes_chargement) {
                printf("Une erreur s'est produite lors du chargement de la grille.\n\n\n");

                systemPause();
            }

            //Sinon informer du bon chargement et afficher la grille
            else if(succes_chargement)
            {
                printf("Grille chargee avez succes:\n");
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

                systemPause();
            }

        }

        //Option 2 Resoudre le labirynthe
        else if (choix_utilisateur == 2 || choix_utilisateur == 3)
        {
            int pas_a_pas=0;//Initialise la valeur pas_a_pas a 0

            if(choix_utilisateur == 3)//Lorsque le choix de l'utilisateur est de 3
            {
                pas_a_pas = 1;//Met la valeur pas_a_pas a 1
            }

            //appelle la fonction lab_resoudre_profondeur et stocke la valeur retourner dans solution trouve
            solution_trouvee = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, pile_solution, pas_a_pas, debug);

            if (solution_trouvee == 0)//Lorsque nous trouve pas de solution
            {
                printf("Aucune solution trouvee.\n");
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);//Affiche le contenu de la grille

                systemPause();
            }
            else
            {
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);//Affiche la grille
                printf("Solution trouvee en %i mouvements.\n", pile_solution[0][1]);//Affiche les solutions trouve en combien de mouvement
                printf("Le meilleur score est %i mouvements\n", meilleur_score);//Affiche le meilleur score

                if(debug){afficher_pile(pile_solution);}

                if(pile_solution[0][1]-1 < meilleur_score || meilleur_score == 0) //Enregistrer le meilleur score
                {
                    meilleur_score = pile_solution[0][1]-1;
                }

                systemPause();
            }

        }


        //Option 4 Quitter
        else if (choix_utilisateur == 4)//Quand que l'utilisateur choisie 4
        {
            return EXIT_SUCCESS;
        }

    }

    //Si jamais on sort de la boucle
    return EXIT_SUCCESS;
}

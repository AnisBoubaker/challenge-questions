/*
 * Fichier: labyrinthe.c
 * Auteur: Jean-Nicolas Bouchard, Lancelot Léonard, Félix Robillard, Vincent Vinet
 * Date : 2023-10-16
 *
 * Description: Fichier qui contient des les fonctions pour résoudre le labyrinthe
 */


#include "labyrinthe_io.h"
#include "labyrinthe.h"
#include "utilitaires.h"

void lab_afficher_grille(int tab[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2]) {
    int check =0;  //Variable pour savoir si un X a ete place a une certaine case
    int couleur = 31;  //Variable pour determiner la couleur du texte


    for (int i = 0; i < hauteur_grille; ++i)      //C'est deux for loop sont utilise pour parcourir la grille
    {
        for (int j = 0; j < largeur_grille; ++j)
        {
            if(tab[i][j] == 1)  //Si la valeur vaut 1 c'est un mur et on imprime un caractere special
            {
                printf("%c", 219);
            }
            else {     //Si il y a un espace dans la grille, on a deux options
                if (pile_solution != NULL) { //Si nous possedons une solution, nous verifions si nous avons passe par la solution
                    check = 0;

                    if (valider_coords_dans_pile(pile_solution,pile_solution[0][1],j,i) == 1) //Si un x de la solution est egale au x de la coordonnees actuelle
                    {                                                                                         //nous regardons les y de cette postion
                        printf("\033[0;%im", couleur); //Nous determinons la couleur du texte          //Si les y aussi sont egales, cela veut dire que cette case
                        printf("X");
                        printf("\033[0m");   //Nous rinitialisons la couleur du texte
                        couleur++;  //Nous fesons varier la couleur de 31 a 36
                        if (couleur == 37)
                        {
                            couleur = 31;
                        }
                        check = 1;                  //Fait parti de la solution et nous mettons un X
                    }

                    if (check == 0){            //Si nous avons pas mis de X, on met un espace
                        printf(" ");
                    }

                }
                else{
                    printf(" ");      //Si la valeur vaut 0 ce n'est pas un mur et qu'il n'y pas de solution
                }
            }

        }
        printf("\n");            // Pour changer de ligne
    }
}


void lab_calculer_deplacements_possibles(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int* nb_deplacements,
        int deplacements[4][2]
)
{
    int position_x,position_y = 0; //Initialisation des positions

    *nb_deplacements = 0;

    //On vient faire une boucle sur les 4 positions de chemins possibles (haut, bas, gauche, droite)
    for (int i = 0; i < 4; ++i) {

        switch (i) {
            case 0:
                position_x = pos_ligne - 1;
                position_y = pos_colonne;
                break;
            case 1:
                position_x = pos_ligne + 1;
                position_y = pos_colonne;
                break;
            case 2:
                position_x = pos_ligne;
                position_y = pos_colonne - 1;
                break;
            case 3:
                position_x = pos_ligne;
                position_y = pos_colonne + 1;
                break;

        }
        //On vient ensuite vérifier si la coordonées pos x, pos y est dans la grille
        if(position_x >= 0 && position_x < largeur_grille && position_y >= 0 && position_y < hauteur_grille) {

            //Si les coordonnées choisies sont un mur on change de coordonnées.
            if (grille[position_y][position_x] == 1) {
                continue;
            }
            //On vient ensuite vérifier si les coordonnées choisies sont deja dans la pile avec la fonction valider_coords_dans_pile.
            else if (valider_coords_dans_pile(solution_partielle, solution_partielle[0][1], position_x, position_y) == 1) {
                continue;
            } else {
                deplacements[*nb_deplacements][0] = position_x; //si la coordonnée fonctionne on l'ajoute a la pile déplacements.
                deplacements[*nb_deplacements][1] = position_y;
                *nb_deplacements += 1;
            }
        }
    }
}


int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles) //Revenir afin de comprendre quoi faire
{
    srand((unsigned int)time(NULL));
    rand();

    return nb_aleatoire(0,nb_deplacements_possibles-1); //Nous renvoyons un nombre aléatoires entre 0 et le nbr de deplacemtns-1
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    if(abs(case1[0] - case2[0]) + abs(case1[1] - case2[1]) == 1)  //Nous verifions si une case est adjacente a une autre
    {                                                                   //Si oui on retourne 1 sinon 0
        return 1;
    }
    return 0;
}

int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille)
{
    if((position[0] == 0 || position[1] == 0 || position[0] == largeur_grille-1 || position[1] == hauteur_grille-1) && grille[position[1]][position[0]] == 0)
    {                       //Nous verifions qu'une certaine case est une sortie
        return 1;
    }
    return 0;
}

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int entree[2],int pile_solution[][2],int debug)
{
    pile_initialiser(pile_solution,pile_solution[0][0]);  //Faut initialiser la pile de solution au depart
    int pile_chemins_alternatifs[pile_solution[0][0]][2] = {};  //Les chemins que nous pourrions prendre au cas que la hemin actuelle est un cul-de-sac
    int deplacements_possibles[4][2] = {};    //Les deplacements possibles a chaque mouvement
    int nb_deplacements =1;                   //Le nombre de deplacement a chaque mouvement
    int nouvelle_position[2] = {};            //La nouvelle position apres un cul-de-sac (chemins alternatifs)
    int success = 1;                          //Verifier si nous avons resolu le labyrinthe

    pile_initialiser(pile_chemins_alternatifs,100);  //Faut initialiser la pile de chemins alternatifs

    pile_empiler(pile_solution, entree[1],entree[0]);  //On empile l'entree dans la pile solution

    do {
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                            pile_solution[pile_solution[0][1]][0],
                                            pile_solution[pile_solution[0][1]][1],
                                            pile_solution,
                                            &nb_deplacements, deplacements_possibles); //Avant chaque deplacement regarde nos deplacements possibles

        if (nb_deplacements > 0) {  // Si nous avons des deplacements

            pile_empiler(pile_solution,     //On choisit un deplacement et l'empile dans la solution
                         deplacements_possibles[lab_choisir_deplacement(deplacements_possibles, nb_deplacements)][0],
                         deplacements_possibles[lab_choisir_deplacement(deplacements_possibles, nb_deplacements)][1]);

            for (int i = 0; i < nb_deplacements; ++i) {  //On empile les autres deplacements possibles dans la pile de chemins alternatifs
                if (pile_solution[pile_solution[0][1]][0] != deplacements_possibles[i][0] || pile_solution[pile_solution[0][1]][1] != deplacements_possibles[i][1])
                {
                    pile_empiler(pile_chemins_alternatifs,
                                 deplacements_possibles[i][0],
                                 deplacements_possibles[i][1]);
                }
            }
        }
        else if (pile_est_vide(pile_chemins_alternatifs) != 1) //Si nous avons pas de deplacements possibles et
        {                                                           //que la pile de chemins alternatifs n'est pas vide
            nouvelle_position[0] = pile_chemins_alternatifs[pile_chemins_alternatifs[0][1]][0]; //On attribue le dernier chemin
            nouvelle_position[1] = pile_chemins_alternatifs[pile_chemins_alternatifs[0][1]][1]; //alternatif a une varable intermediaire
            pile_depiler(pile_chemins_alternatifs,          //Ensuite on depile ce chemin des chemins alternatifs
                         &pile_chemins_alternatifs[pile_chemins_alternatifs[0][1]][0],
                         &pile_chemins_alternatifs[pile_chemins_alternatifs[0][1]][1]);

            do {                                     //Ensuite on depile de la solution le chemin prit jusqu'a ce
                pile_depiler(pile_solution,     //qu'on arrive a une case adjacente de la nouvelle position
                             &pile_solution[pile_solution[0][1]][0],
                             &pile_solution[pile_solution[0][1]][1]);

            } while (lab_est_cases_adjacentes(pile_solution[pile_solution[0][1]], nouvelle_position) == 0);

            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]); //On empile la nouvelle position a la solution
        }
        else  //Si nous avons pas de deplacements possibles et pas de chemins alternatifs, alors le labyrinthe ne peut pas etre resolu
        {
            success = 0;
            printf("Aucune solution trouvee :-(\n");
            system("pause");
            break;  //On sort de notre grosse do{}while
        }

        if (debug != 0)  //Si l'utilisateur a choisi le choix 3 dans le menu on affiche la solution apres chaque deplacement
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            system("pause");
        }



    }while (lab_est_une_sortie(pile_solution[pile_solution[0][1]], grille, hauteur_grille, largeur_grille) == 0);
    //On continue notre do{}while tant que nous ne trouvons pas de sortie, sauf si on detecte aucune solution

    if (debug == 0 && success == 1) //Si l'utilisateur a choisi le choix 2 dans le menu on affiche la solution a la fin
    {
        lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
    }

    if (success == 1) {
        printf("\n"                                         //On felicite l'utilisateur
               "  _____             __     __     __     __\n"
               " / ___/__  ___  ___/ / __ / /__  / /    / /\n"
               "/ (_ / _ \\/ _ \\/ _  / / // / _ \\/ _ \\  /_/ \n"
               "\\___/\\___/\\___/\\_,_/  \\___/\\___/_.__/ (_)  \n"
               "                                           \n");
        system("pause");
    }
    return success;
}





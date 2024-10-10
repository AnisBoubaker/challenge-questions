/*
titre: labyrinthe.c
Description: Implémentation des fonctions du module labyrinthe.h
Auteurs:
Tommy Parent,
Maude Gallant-Mercier,
Camille Landry,
Saguira Neysa Charles
Date: 2023-11-07
*/

/***********COMMANDES PREPROCESSEUR*************/
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"
#include "pile.h"

/*******IMPLEMENTATION DES FONCTIONS***********/
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
{
    //analyse pour chaque ligne ses colonnes et determine si il y a un mur ou un couloir
    for(int l=0;l<hauteur_grille;l++)
    {
        for(int c=0;c<largeur_grille;c++)
        {
            //si il y a une solution trouvé a cette position on affiche un X
            if(pile_contient(pile_solution, l, c) && pile_est_vide(pile_solution)==0)
            {
                printf("X");
            }
            //dans le tableau grille a cet endroit on retrouve un mur
            else if(grille[l][c] == 1)
            {
                printf("%c", 219);
            }
            //dans le tableau grille a cet endroit on retrouve un couloir
            else if(grille[l][c] == 0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void lab_calculer_deplacements_possibles( int grille[][TAILLE_MAX_GRILLE],
                                          int hauteur_grille,
                                          int largeur_grille,
                                          int pos_ligne,
                                          int pos_colonne,
                                          int solution_partielle[][2],
                                          int *nb_deplacements,
                                          int deplacements[4][2])
{
    *nb_deplacements = 0; //Remise a 0 du nombre de deplacements possibles.

    //Cette serie de conditions determine si les deplacements sont possibles a gauche, a droite, en haut, en bas.
    //Deplacement en haut.
    if(grille[pos_ligne-1][pos_colonne] != 1 && 0 == pile_contient(solution_partielle, pos_ligne-1, pos_colonne) && pos_ligne-1 >= 0)
    {
        deplacements[*nb_deplacements][0] = pos_ligne-1;
        deplacements[*nb_deplacements][1] = pos_colonne;
        (*nb_deplacements)++;
    }
    //Deplacement en bas.
    if(grille[pos_ligne+1][pos_colonne] != 1 && 0 == pile_contient(solution_partielle, pos_ligne+1,pos_colonne) && pos_ligne+1 < hauteur_grille)
    {
        deplacements[*nb_deplacements][0] = pos_ligne+1;
        deplacements[*nb_deplacements][1] = pos_colonne;
        (*nb_deplacements)++;
    }
    //Deplacement a gauche.
    if(grille[pos_ligne][pos_colonne-1] != 1 && 0 == pile_contient(solution_partielle, pos_ligne, pos_colonne-1) && pos_colonne-1 >= 0)
    {
        deplacements[*nb_deplacements][0] = pos_ligne;
        deplacements[*nb_deplacements][1] = pos_colonne-1;
        (*nb_deplacements)++;
    }
    //Deplacement a droite.
    if(grille[pos_ligne][pos_colonne+1] != 1 && 0 == pile_contient(solution_partielle, pos_ligne, pos_colonne+1) && pos_colonne+1 < largeur_grille)
    {
        deplacements[*nb_deplacements][0] = pos_ligne;
        deplacements[*nb_deplacements][1] = pos_colonne+1;
        (*nb_deplacements)++;
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    return nb_aleatoire(0, nb_deplacements_possibles-1);
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{

    // Cette conditions verifie les cases haut et bas
    if ((case1[0] == case2[0]-1 || case1[0] == case2[0]+1) && case1[1] == case2[1])
    {
        return 1;
    }
    // Cette conditions verifie les cases droite et gauche.
    else if (case1[0] == case2[0] && (case1[1] == case2[1]+1 || case1[1] == case2[1]-1))
    {
        return 1;
    }
    return 0;
}

int lab_est_une_sortie(
                int position[2],
                int grille[][TAILLE_MAX_GRILLE],
                int hauteur_grille,
                int largeur_grille)
{
    // Condition qui verifie si la position est une sortie soit d'un cote gauche ou droite, soit d'un cote en haut ou en bas.
    if((position[0] >= 0 && position[0] <= hauteur_grille-1) && (position[1] == 0 || position[1] == largeur_grille-1) || ((position[1] >= 0 && position[1] <= largeur_grille-1) && (position[0] == 0 || position[0] == hauteur_grille-1)))
    {
        return 1;
    }
    return 0;
}

int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2], int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2]; //pile qui contient les chemins alternatifs
    int deplacements_possibles[4][2];                 //tableau qui contient les déplacements possibles
    int nb_deplacements_possibles;                    //nombre de déplacement possible dans le tableau deplacements_possible
    int nouvelle_position[2];                         //la nouvelle position lorsqu'on atteint un cul-de-sac
    int haut_pile_solution[2];                        //le point qui se trouve au haut de la pile solution
    int ligne_actuelle_pile_solution;                 //la valeur de la ligne du haut de la pile solution
    int colonne_actuelle_pile_solution;               //la valeur de la colonne du haut de la pile solution
    int indice;                                       //ligne qui indique le point du tableau que nous utiliserons
    int l;                                            //ligne dependante de l'indice du prochain deplacement
    int c;                                            //colonne dependante de l'indice du prochain deplacement
    int l_nouvelle_position;                          //ligne de la nouvelle position
    int c_nouvelle_position;                          //colonne de la nouvelle position
    int c_pile_solution;                              //colonne de la coordonnee a empiler sur le haut de la pile solution
    int l_pile_solution;                              //ligne de la coordonnee a empiler sur le haut de la pile solution
    int pas_de_sortie=0;                              //variable qui suit si c'est possible de ce deplacer rendu a une coordonne

    srand((unsigned int)time(NULL));
    rand();

    //initialise les deux piles
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_PILE);

    //empile l'entre dans pile_solution
    pile_empiler(pile_solution, entree[0], entree[1]);

    //tant qu'il est possible de se deplacer et qu'une solution n'a pas ete trouvee
    do
    {
        //determine les coordonnees du haut de la pile.
        pile_haut_pile(pile_solution, &ligne_actuelle_pile_solution, &colonne_actuelle_pile_solution);

        //calcule les deplacements possibles et le nombre de deplacements en fonction des coordonees du haut de la pile.
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, ligne_actuelle_pile_solution,
                                                   colonne_actuelle_pile_solution, pile_solution,
                                                   &nb_deplacements_possibles, deplacements_possibles);

                if (nb_deplacements_possibles > 0)
                {
                    //choisir un des déplacements obtenues et l'empiler dans la solution
                    indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);
                    l = deplacements_possibles[indice][0];
                    c = deplacements_possibles[indice][1];
                    pile_empiler(pile_solution, l, c);

                    //empile les autres déplacements possibles dans la pile_chemins_alternatifs si il existe plus que 1 deplacement possible
                    if(nb_deplacements_possibles > 1)
                    {
                        for (int i = 0;i<nb_deplacements_possibles;i++)
                        {
                            if (i != indice) {
                                l = deplacements_possibles[i][0];
                                c = deplacements_possibles[i][1];
                                pile_empiler(pile_chemins_alternatifs, l, c);
                            }
                        }
                    }

                    //détermine le haut de la pile solution
                    pile_haut_pile(pile_solution, &l_pile_solution, &c_pile_solution);
                    haut_pile_solution[0] = l_pile_solution;
                    haut_pile_solution[1] = c_pile_solution;
                }

                //si pile_chemin_alternatifs n'est pas vide
                else if (!pile_est_vide(pile_chemins_alternatifs))
                {
                    //on dépile la pile_chemins_alternatifs
                    pile_depiler(pile_chemins_alternatifs, &l_nouvelle_position, &c_nouvelle_position);

                    nouvelle_position[0] = l_nouvelle_position;
                    nouvelle_position[1] = c_nouvelle_position;

                    //comparer nouvelle_position[l_nouvelle_position][c_nouvelle_position] avec les cases de pile_solution pour trouver des cases adjacentes
                    do{
                        //dépiler jusqu'à ce que le haut de la pile contient une case adjacente
                        pile_depiler(pile_solution, &l_pile_solution, &c_pile_solution);
                        pile_haut_pile(pile_solution, &l_pile_solution, &c_pile_solution);
                        haut_pile_solution[0] = l_pile_solution;
                        haut_pile_solution[1] = c_pile_solution;

                    }while(lab_est_cases_adjacentes(nouvelle_position, haut_pile_solution) != 1);

                    //empile dans la pile solution la derniere valeur de la pile chemins_alternatifs
                    pile_empiler(pile_solution, l_nouvelle_position, c_nouvelle_position);

                    //déterminer le haut de la pile solution
                    pile_haut_pile(pile_solution, &l_pile_solution, &c_pile_solution);
                    haut_pile_solution[0] = l_pile_solution;
                    haut_pile_solution[1] = c_pile_solution;
                }
                else
                {
                    //si aucune des conditions précédentes n'est vrai on conclut qu'il n'est plus possible de se déplacer
                    pas_de_sortie++;
                }

        //si on est en mode debug, on affiche le labyrinthe
        if(debug == 1)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            system("pause");
        }

    }while( !(pas_de_sortie) && !(lab_est_une_sortie(haut_pile_solution, grille, hauteur_grille, largeur_grille)));

    // si haut pile solution est une sortie la fonction renvoit vrai, sinon elle renvoit faux
    if(lab_est_une_sortie(haut_pile_solution, grille,hauteur_grille, largeur_grille))
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
/*
Titre: labyrinthe.c
Description: Implémentation des fonctions du module labyrinthe

Auteurs: Francis Gignac, Rachelle Sanscartier, Maxim St-Gelais, Abraham Suarez-Santizo
Date: 2023-11-12
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#include <stdlib.h>
#include <stdio.h>
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"
#include "time.h"

/***********CONSTANTES DE COMPILATION*************/
/* Taille maximale de la grille. */
#define TAILLE_MAX_GRILLE 100
/* Taille maximale de la pile. */
#define TAILLE_MAX_PILE 100

/********* DÉFINITION DES FONCTIONS **************/

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                         int largeur_grille, int pile_solution[][2])
{
    int colonne; /* Permet de connaitre la position de la colonne dans la grille. */
    int ligne; /* Permet de connaitre la position de la ligne dans la grille. */
    int etat_pile; /* Permet de vérifier si la pile contient la coordonnée d'entrée. */
    unsigned char mur = 219; /* Code ASCII pour un bloc. */
    char couloir = 32; /* Code ASCII pour un espace. */
    char pion = 88; /* CODE ASCII pour un X majuscule. */


    /* Si la pile_solution n'est pas vide, le programme va chercher les murs et couloirs. */
     if (pile_solution == NULL)
     {
         for (ligne = 0; ligne < hauteur_grille; ligne++)
         {
             for (colonne = 0; colonne < largeur_grille; colonne++)
             {
                 if (grille[ligne][colonne] == 1)
                 {
                     printf("%c", mur);
                 }
                 if (grille[ligne][colonne] == 0)
                 {
                     printf("%c", couloir);
                 }
             }
             printf("\n");
         }
     }
  /* Si la pile_solution n'est pas vide, la console va chercher les murs et couloirs.
     De plus, au coordonnées se trouvant
     dans la pile_solution, la console va afficher un X.
  */
    if (pile_solution != NULL)
    {
        for (ligne = 0; ligne < hauteur_grille; ligne++)
        {
            for (colonne = 0; colonne < largeur_grille; colonne++)
            {
                etat_pile = pile_contient(pile_solution,ligne, colonne);

                if (grille[ligne][colonne] == 1)
                {
                    printf("%c", mur);
                }
                if (grille[ligne][colonne] == 0 && etat_pile == 0)
                {
                    printf("%c", couloir);
                }

                if (grille[ligne][colonne] == 0 && etat_pile == 1)
                {
                    printf("%c", pion);
                }
            }
            printf("\n");
        }
    }
}


void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],
                                         int hauteur_grille, int largeur_grille,int pos_ligne,
                                         int pos_colonne, int solution_partielle[][2], int *nb_deplacements,
                                         int deplacements[4][2])
{

    int pos_temp[2] = {0}; /* Tableau pour enregistrer coordonnées de dépalcement possible. */
    int verif_sol; /* Variable pour verifier la pile solution. */

    /* Initialisation de la variable nb_deplacements. */
    *nb_deplacements = 0; /* Initialisation de la quantité de déplacements possible */

    /* Initialisation du tableau de déplacement. */
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
           deplacements[i][j] = 0;
        }
    }

    /* Verification de déplacement vers le haut. */
    /* dplc_haut permet de mettre en place les nouvelles coordonnées
       de déplacement possible.
    */
    dplc_haut(pos_temp, pos_ligne, pos_colonne);
    /* verif_sol va vérifier si la solution partielle contient le chemin possible */
    verif_sol = pile_contient(solution_partielle, pos_temp[1],pos_temp[0]);

    /* Vérification de la validité pour la nouvelle position. */
    if (pos_temp[1] >= 0 && pos_temp[1] < hauteur_grille &&
        grille[pos_temp[1]][pos_temp[0]] != 1 && verif_sol == 0)
    {
        if (pos_temp[0] >= 0 && pos_temp[0] < largeur_grille)
        {
            /* Position verticale (Pos_ligne). */
            deplacements[*nb_deplacements][0] = pos_temp[1];
            /* Position horizontale (Pos_colonne). */
            deplacements[*nb_deplacements][1] = pos_temp[0];
            /* On augmente le nombre de déplacement possible. */
            (*nb_deplacements)++;
        }
    }

        /* Vérification de déplacement vers le bas. */
        /* dplc_bas va mettre en place les nouvelles coordonnées de déplacement possible. */
        dplc_bas(pos_temp, pos_ligne, pos_colonne);
        /* verif_sol vérifie si la solution partielle contient le chemin possible */
        verif_sol = pile_contient(solution_partielle, pos_temp[1],pos_temp[0]);


        /* Vérification de la validité pour la nouvelle position. */
        if (pos_temp[1] >= 0 && pos_temp[1] < hauteur_grille &&
            grille[pos_temp[1]][pos_temp[0]] != 1 && verif_sol == 0)
        {
            if (pos_temp[0] >= 0 && pos_temp[0] < largeur_grille)
            {
                /* Position verticale (Pos_ligne). */
                deplacements[*nb_deplacements][0] = pos_temp[1];
                /* Position horizontale (Pos_colonne). */
                deplacements[*nb_deplacements][1] = pos_temp[0];
                /* On augmente le nombre de déplacement possible. */
                (*nb_deplacements)++;

            }
        }
        /* Vérification de déplacement vers la gauche. */
        /* dplc_gauche va mettre en place les nouvelles coordonnées de déplacement possible. */
        dplc_gauche(pos_temp, pos_ligne, pos_colonne);
        /* verif_sol vérifie si la solution partielle contient le chemin possible. */
        verif_sol = pile_contient(solution_partielle, pos_temp[1],pos_temp[0]);

        /* Vérification de la validité pour la nouvelle position. */
        if (pos_temp[1] >= 0 && pos_temp[1] < hauteur_grille &&
            grille[pos_temp[1]][pos_temp[0]] != 1 && verif_sol == 0)
        {
            if (pos_temp[0] >= 0 && pos_temp[0] < largeur_grille)
            {
                /* Position verticale (Pos_ligne). */
                deplacements[*nb_deplacements][0] = pos_temp[1];
                /* Position horizontale (Pos_colonne). */
                deplacements[*nb_deplacements][1] = pos_temp[0];
                /* On augmente le nombre de déplacement possible. */
                (*nb_deplacements)++;
            }
        }

        /* Vérification de déplacement vers la droite. */
        /* dplc_droite permet de mettre en place
           les nouvelles coordonnées de déplacement possible.
        */
        dplc_droite(pos_temp, pos_ligne, pos_colonne);
        /* Vérifie si la solution partielle contient le chemin possible. */
        verif_sol = pile_contient(solution_partielle, pos_temp[1],pos_temp[0]);

        /* Vérification de la validité pour la nouvelle position. */
        if (pos_temp[1] >= 0 && pos_temp[1] < hauteur_grille && grille[pos_temp[1]][pos_temp[0]] != 1 && verif_sol == 0)
        {
            if (pos_temp[0] >= 0 && pos_temp[0] < largeur_grille)
            {
                /* Position verticale (Pos_ligne). */
                deplacements[*nb_deplacements][0] = pos_temp[1];
                /* Position horizontale (Pos_colonne). */
                deplacements[*nb_deplacements][1] = pos_temp[0];
                /* On augmente le nombre de déplacement possible. */
                (*nb_deplacements)++;
             }
        }
}


int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    int choix_al; /* Choix de position aléatoire. */
    if(nb_deplacements_possibles == 1)
    {
        return 0;
    }
    else if (nb_deplacements_possibles > 1)
    {
        /* Initialisation du générateur de nombre. */
        srand((unsigned int) time(NULL));
        rand();

        choix_al = nb_aleatoire(1, nb_deplacements_possibles);
        /* Choix tirée de la génération aléatoire,
           (Position selon nbr tableau != nbr de déplacements donc le -1).
        */
        return choix_al -1;
    }
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int coordonnee_x1; /* Valeur dans la case1[0]. */
    int coordonnee_y1; /* Valeur dans la case1[1]. */
    int coordonnee_x2; /* Valeur dans la case2[0]. */
    int coordonnee_y2; /* Valeur dans la case2[1]. */

    coordonnee_x1 = case1[0]; /* Position x de la case1. */
    coordonnee_y1 = case1[1]; /* Position y de la case1. */
    coordonnee_x2 = case2[0]; /* Position x de la case2. */
    coordonnee_y2 = case2[1]; /* Position y de la case2. */

    /* Si les x sont pareils mais les y sont différents. */
    if (coordonnee_x1 == coordonnee_x2 && (coordonnee_y1 - coordonnee_y2 == -1
        || coordonnee_y1 - coordonnee_y2 == 1))
    {
        /* Renvoie VRAI si les cases sont adjacents. */
        return 1;
    }

    /* Si les y sont pareils mais les x sont différents. */
    if (coordonnee_y1 == coordonnee_y2 && (coordonnee_x1 - coordonnee_x2 == -1
        || coordonnee_x1 - coordonnee_x2 == 1))
    {
        /* Renvoie VRAI si les cases sont adjacents. */
        return 1;
    }
        /* Renvoie un FAUX si les cases ne sont pas adjacents. */
        return 0;
    }

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
    /* position[0]= position de la ligne. */
    /* position[1]= position de la colonne. */
    /* les coordonées de position sont déclaré dans le main avec pile_haut_pile. */

    /* Si la position est aux extrémités du labyrinthe on continue l'évaluation, sinon on renvoi 0.*/
    if (position[0] == 0 || position[0] == hauteur_grille - 1 || position[1] == 0
        || position[1] == largeur_grille - 1)
    {
        /* Si la position n'est pas un mur on conclus que c'est une sortie, sinon on renvoi 0. */
        if (grille[position[0]][position[1]] != 1)
        {
            /* Solution vrai. */
            return 1;
        }
        else
        {
            /* Solution faux. */
            return 0;
        }
    }
    else
    {
        /* Solution faux. */
        return 0;
    }
}



int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{
    int pos_ligne = 0; /* Numéro de ligne (Axe Y) est [0] dans le tableau pile_solution[]. */
    int pos_colonne = 0; /* Numéro de colonne (Axe X) est [1] dans le
                            tableau pile_solution[].
                         */
    int pile_historique[TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE][2]; /* Pile qui contient toute
                                                                      les positions le pion a passé par dessus
                                                                      (Pour ne pas backtrack).
                                                                   */
    int deplacements_possibles[4][2]; /* Tableau contenant les coordonnées de déplacement
                                         possible du pion selon sa position évalué pour un
                                         maximum de 4 ou [Numero de ligne][Numero de colonne].
                                      */
    int nb_deplacements_possibles = 0; /* Un entier qui contient la
                                          qté de déplacement possible du pion selon sa position évalué.
                                       */
    int deplacement_choisie; /* Choix aléatoire de la fxn lab_choisir_deplacement
                                Numéro de ligne pour le tableau deplacements_possible[4][2]). */
    int nouvelle_position[2]; /* Un tableau contenant des coordonnées
                                 d'un point sur la grille.
                              */
    int pos_a_comparer[2]; /* Tableau pour comparaison de coordonnées. */
    int sortie = 0; /* Variable qui signale si le labyrinthe possède une solution. */
    int cas = 0; /* Variable qui signal si une case est adjacente ou non. */
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE][2]; /* Une pile
                                                                               contenant les chemins alternatifs.
                                                                            */
    /* On assigne la position de départ. */
    pos_ligne=entree[0];
    pos_colonne=entree[1];

    /* On initialise les piles. */
    /* Initialisation de la pile_solution. */
    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);
    /* Initialisation de la pile_chemins_alternatifs. */
    pile_initialiser(pile_chemins_alternatifs,TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);
    /* Initialisation de la pile_historique. */
    pile_initialiser(pile_historique, TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);

    /* On empile la position d'entrée. */
    /* Entrer l'entrée dans la pile_solution. */
    pile_empiler(pile_solution, entree[0], entree[1]);
    /* Entrer l'entrée dans la pile_historique. */
    pile_empiler(pile_historique, entree[0], entree[1]);

    /* Tant que c'est possible de se déplacer et une solution n'a pas été trouvées. */
    do
    {
        /* Appel la fonction lab_calculer_deplacements_possibles. */
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, pos_ligne,
                                            pos_colonne,pile_historique,
                                            &nb_deplacements_possibles,deplacements_possibles);



        /* Si le nombre de déplacement possible est plus grand que 0. */
        if (nb_deplacements_possibles > 0)
        {
            /* On appel la fonction qui choisi un déplacement aléatoirement
               (Choix est le numéro de ligne du tableau de déplacements).
            */
            deplacement_choisie = lab_choisir_deplacement(deplacements_possibles,
                                                          nb_deplacements_possibles);

            /* Donner une valeur à la nouvelle position
               (Valeurs utilisé pour valider si la position est une sortie).
            */
            /* Position de la ligne. */
            nouvelle_position[0]=deplacements_possibles[deplacement_choisie][0];
            /* Position de la colonne. */
            nouvelle_position[1]=deplacements_possibles[deplacement_choisie][1];

            /* Assignation de la position courante du pion
               (Variables à update pour utiliser plus haut dans la fonction).
            */
            /* Si on ne fait pas de mise à jour, ça fait une boucle infini constamment à la
               même position car pos_ligne et pos_colonne change jamais.
            */
            /* Position de la ligne. */
            pos_ligne=deplacements_possibles[deplacement_choisie][0];
            /* Position de la colonne. */
            pos_colonne=deplacements_possibles[deplacement_choisie][1];

            /* On empile le déplacement choisie aléatoirement dans la pile solution et la
               pile historique.
            */
            pile_empiler(pile_solution, pos_ligne,pos_colonne);
            pile_empiler(pile_historique, pos_ligne,pos_colonne);

            /* Vérifie si la nouvelle position est une sortie ou non. */
            sortie = lab_est_une_sortie(nouvelle_position, grille, hauteur_grille, largeur_grille);

            /* Conditions pour éviter de remplir le tableau de vide. */
            if(nb_deplacements_possibles>1)
            {
                /* boucle pour emplier les autre deplacment dans chemain alternatif. */
                for (int j = 0; j <nb_deplacements_possibles; j++)
                {
                    if (j != deplacement_choisie)
                    {
                        pile_empiler(pile_chemins_alternatifs,
                                     deplacements_possibles[j][0], deplacements_possibles[j][1]);
                    }
                }
            }

            /* Affichage pas-à-pas selon la sélection de l'utilisateur. */
            if(debug==1)
            {
                printf("\n");
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            }
        }

        /* Déplacement du pion au chemin alternatif lorsque la position dernière
           n'a plus de déplacement possible et qu'elle n'est pas une sortie.
        */
        else if (pile_chemins_alternatifs != NULL)
        {

            /* Dépiler (de  pile_chemin_alternatifs). */
            pile_depiler(pile_chemins_alternatifs, &pos_ligne, &pos_colonne);

            /* stocker la coordonner de chemin alternatif dans nouvelle_position. */
            nouvelle_position[0] = pos_ligne;
            /* stocker la coordonner de chemin alternatif dans nouvelle_position. */
            nouvelle_position[1] = pos_colonne;

            /* Boucle pour continuer la dépilation jusqu'à ce que la pile solution contient
               une case adjacente à la nouvelle position choisis par les chemins alternatifs.
            */
            do
            {

                /* Vérification du haut de solution. */
                pile_haut_pile(pile_solution, &pos_ligne, &pos_colonne);
                /* Position de ligne dépilé à comparer. */
                pos_a_comparer[0]=pos_ligne;
                /* Position de colonne dépilé à comparer. */
                pos_a_comparer[1]=pos_colonne;
                /* Comparaison entre position dans la pile solution
                   et la position de chemin alternatif.
                */
                cas=lab_est_cases_adjacentes(nouvelle_position, pos_a_comparer);


                /* Dépilation de pile solution car elle n'est pas adjacente. */
                if(cas==0)
                {
                    pile_depiler(pile_solution, &pos_ligne, &pos_colonne);
                }
             /* Changement de condition pour que la case adjacente fait partie de l'historique. */
            }while(cas == 0);

            /* Empilation de la nouvelle position dans pile solution. */
            pile_empiler(pile_solution, nouvelle_position[0],nouvelle_position[1]);
            pile_empiler(pile_historique, nouvelle_position[0],nouvelle_position[1]);

            pos_ligne=nouvelle_position[0];
            pos_colonne=nouvelle_position[1];
            /*Pour verifier le nombre de déplacement possible pour rester dans la boucle*/
            lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,
                                                nouvelle_position[0], nouvelle_position[1],
                                                pile_historique, &nb_deplacements_possibles,
                                                deplacements_possibles);
        }


/* Tant que le nombre de déplacements n'est pas zéro et la sortie est ==0. */
    } while (nb_deplacements_possibles > 0 && sortie == 0);

    if(debug==0)
    {
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }
    if(debug==1)
    {
        printf("\n");
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }

    /* Vérification pour la valeur de renvoie. */
    if (sortie == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//
// Created by olarocque on 10/23/2023.
//


/***********COMMANDES PR�PROCESSEUR*************/
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int pile_solution[][2])
{

    for (int i = 0; i < hauteur_grille; i++) //boucle qui va parcourir la grille en hauteur
    {
        for (int j = 0; j < largeur_grille; j++) //boucle qui va parcourir la grille en largeur
        {
            if (grille[i][j] == 1)//si la valeur dans la grille est =1 il affiche le caractere ASCII 219 (mur)
            {

                printf("%c", 219);//Affiche un mur

            }

            else if(pile_contient(pile_solution, i, j))//Si il y a une solution dans la pile affiche la valeur
            {
                printf("X");//Affiche un X au position de la solution
            }
            else //si il n'y a rien dans la solution affiche rienif(grille[i][j]== 0 && !pile_contient(pile_solution, i, j))
            {
                printf(" ");
            }
        }
        printf("\n");//Saute une ligne
    }
}


void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,
                                         int pos_ligne,int pos_colonne,int solution_partielle[][2],
                                         int *nb_deplacements,int deplacements[4][2])
{
    pile_initialiser(deplacements, 4);
    *nb_deplacements=0;//

    // Condition pour executer un Déplacement vers le haut
    if  ((pos_ligne-1 >= 0) &&(grille[pos_ligne - 1][pos_colonne] == 0) &&(!pile_contient(solution_partielle, pos_ligne - 1, pos_colonne)))
        /* Verifier qu'on ne sort pas du labyrinthe
         * Verifier si pos_ligne-1 n'est pas un mur et si ce dernier ne se trouve pas dans la solution partiel
         */
    {
        deplacements[*nb_deplacements][0] = pos_ligne - 1;  // Nouvelle position en ligne après le déplacement vers le haut
        deplacements[*nb_deplacements][1] = pos_colonne; // La même colonne que la position actuelle
        (*nb_deplacements)++; // Incrémente le nombre de déplacements possibles
    }

    // Déplacement vers le bas
    if  ((pos_ligne + 1 < hauteur_grille) &&
         (grille[pos_ligne + 1][pos_colonne] ==0) &&
         (!pile_contient(solution_partielle, pos_ligne + 1, pos_colonne)))
        /* Verifier qu'on ne sort pas du labyrinthe
         * Verifier si pos_ligne+1 n'est pas un mur et si ce dernier ne se trouve pas dans la solution partiel
         */
    {
        deplacements[*nb_deplacements][0] = pos_ligne + 1;  // Nouvelle position en ligne après le déplacement vers le bas
        deplacements[*nb_deplacements][1] = pos_colonne; // La même colonne que la position actuelle
        (*nb_deplacements)++; // Incrémente le nombre de déplacements possibles
    }

    // Déplacement vers la gauche
    if ((pos_colonne-1 >= 0) &&
        (grille[pos_ligne][pos_colonne - 1] ==0) &&
        (!pile_contient(solution_partielle, pos_ligne, pos_colonne - 1)))
        /*  Verifier si pos_colonne-1 n'est pas un mur et si ce dernier ne se trouve pas dans la solution partiel
         */
    {
        deplacements[*nb_deplacements][0] = pos_ligne; // La même ligne que la position actuelle
        deplacements[*nb_deplacements][1] = pos_colonne - 1; // Nouvelle position en colonne après le déplacement vers la gauche
        (*nb_deplacements)++; // Incrémente le nombre de déplacements possibles
    }
    // Déplacement vers la droite
    if ((pos_colonne+1 < largeur_grille) &&
        (grille[pos_ligne][pos_colonne + 1] ==0) &&
        (!pile_contient(solution_partielle, pos_ligne, pos_colonne + 1)))
        /*  Verifier si pos_colonne+1 n'est pas un mur et si ce dernier ne se trouve pas dans la solution partiel
        */
    {
        deplacements[*nb_deplacements][0] = pos_ligne; // La même ligne que la position actuelle
        deplacements[*nb_deplacements][1] = pos_colonne + 1; // Nouvelle position en colonne après le déplacement vers la droite
        (*nb_deplacements)++; // Incrémente le nombre de déplacements possibles
    }

}


int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{
    int choix_aleatoire; // Declaration de la variable sera stock le choix aleatoire
    int debug=0;//Initiale variable debug a 0

    choix_aleatoire = nb_aleatoire(0, (nb_deplacements_possibles)-1);// Generer un indice aleatoire par les deplacemenmts possible

    if(debug)//Quand debug va valoir 1 affiche le choix aleatoire
    {
        printf("Choix aleatoire : %i\n", choix_aleatoire);
    }

    return choix_aleatoire ; // Retourne le choix aleatoire obtenue choisi pour le prochain deplacement
}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int debug = 0;//Initalise variable debug a 0

    //On verifie si la case au dessus, a droite, a gauche ou en dessous de la case 1 correspond a la case 2
    if (((case1[0] == case2[0] || case1[0] + 1 == case2[0] || case1[0] - 1 == case2[0]) &&
         (case1[1] == case2[1] || case1[1] + 1 == case2[1] || case1[1] - 1 == case2[1])) &&
        ((case1[0] == case2[0] && case1[1] != case2[1]) || (case1[0] != case2[0] && case1[1] == case2[1])))
    {
        if (debug == 1)//Quand que debug vaut 1 et que les cases sont adjacente retourne 1
        {
            printf("Les cases (%i,%i) et (%i,%i) sont adjacentes\n", case1[0], case1[1], case2[0], case2[1]) ;
        }
        return 1;
    }

    else//Si ce n'est pas une case adjacente, on renvoie faux
    {
        if (debug ==1)
        {
            printf("Les cases (%i,%i) et (%i,%i) ne sont pas adjacentes\n", case1[0], case1[1], case2[0], case2[1]) ;
        }
        return 0;
    }
}

int lab_est_une_sortie(const int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille)
{
    //Pour simplifier le code, on definit une variable qui contient ce qui se trouve dans la grille a cette position
    int val_pos_grille = grille[position[0]][position[1]];

    //On regarde si nos positions x ET y actuelles sont sur un cote du labyrinthe
    return ((position[0] == (hauteur_grille - 1) || (position[0] == 0)       //SI nous sommes sur extremite bas ou haut
             || ((position[1] == ((largeur_grille - 1))) || (position[1] == 0))) //ET nous sommes sur extremite droite ou gauche
            )&& (val_pos_grille != 2)                                        //ET la position actuelle n'est pas l'entree (E = 69 en ASCII)
           ? 1 : 0;                                                          //Renvoie 1 si Vrai, 0 si Faux
}


int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int pas_a_pas, int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE][2];
    int val_ligne, val_col;
    //On initialise nos tableaux a la case [0,0] en y inscrivant la taille maximale
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);
    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE);

    //Enregistrer l'entree a la ligne 1 de la pile solution
    pile_empiler(pile_solution, entree[0], entree[1]);//Enregistrer l'entree dans la premiere(deuxieme) ligne de la solution
    pile_haut_pile(pile_solution, &val_ligne, &val_col);
    if (debug){printf("Haut de la solution : (%i,%i)\n", val_ligne, val_col);}

    // On commence a traiter et ajouter les mouvements possibles dans la pile de solution
    // While "il y a quelque chose dans la pile", boucle jusqu'a ce qu'on Return quelque chose selon les possibilites de deplacement(on avance, prend un autre chemin, bloque ou sortie)
    while (!pile_est_vide(pile_solution))
    {
        if(pas_a_pas != 0)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            systemPause();
        }

        int nb_deplacements;
        int deplacements[4][2];
        int nouvelle_position[2]; //[0] = x ; [1] = y


        //La position actuelle est la ligne 0 de la solution
        int position_actuelle[2] = {pile_solution[pile_solution[0][1]][0], pile_solution[pile_solution[0][1]][1]};
        if (debug){printf("Position actuelle : (%i,%i)\n", position_actuelle[0], position_actuelle[1]);}

        //On regarde ou on peut aller
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, position_actuelle[0], position_actuelle[1], pile_solution, &nb_deplacements, deplacements);

        if (debug)
        {
            printf("Deplacements possibles (%i):\n", nb_deplacements);
            for (int i=0; i<nb_deplacements; i++)
            {
                printf("%i(%i,%i)\n", i, deplacements[i][0], deplacements[i][1]);
            }
        }

        //Si j'ai des deplacements possibles, avancer dans la grille au hasard selon le tableau deplacements possibles
        if (nb_deplacements > 0)
        {
            int index_choisi = lab_choisir_deplacement(deplacements, nb_deplacements);

            nouvelle_position[0] = deplacements[index_choisi][0];
            nouvelle_position[1] = deplacements[index_choisi][1];

            //On enregistre la position choisie au hasard
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            //On enregistre les autres positions dans la pile chemins alternatifs
            for(int i=0; i<nb_deplacements; i++)
            {
                if (i != index_choisi)
                {
                    pile_empiler(pile_chemins_alternatifs, deplacements[i][0], deplacements[i][1]);
                }
            }

            //Si je suis en mode debug affiche-moi la grille
            if (debug)
            {
                pile_haut_pile(pile_solution, &val_ligne, &val_col);
                printf("Haut de la solution : (%i,%i)\n", val_ligne, val_col);
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            }
        }
            //Utiliser une case des chemins alternatifs s'il en reste
        else if ((nb_deplacements == 0) && (!pile_est_vide(pile_chemins_alternatifs)))
        {
            //Obtenir la derniere position dans la pile des chemins alternatifs
            pile_depiler(pile_chemins_alternatifs, &nouvelle_position[0], &nouvelle_position[1]);
            if (debug){printf("On cherche la case : (%i,%i)\n", nouvelle_position[0], nouvelle_position[1]);}

            // On verifie que nous sommes a cote de la case proposee, sinon on recule
            // tant qu'on ne trouve pas de case correcte adjacente
            while (!pile_est_vide(pile_solution) && !lab_est_cases_adjacentes(position_actuelle, nouvelle_position))
            {
                int dummy1, dummy2;
                pile_depiler(pile_solution, &dummy1, &dummy2);
                pile_haut_pile(pile_solution, &position_actuelle[0], &position_actuelle[1]);

                //Affiche le tableau si nous sommes en debug
                if (debug)
                {
                    pile_haut_pile(pile_solution, &val_ligne, &val_col);
                    printf("Haut de la solution : (%i,%i)\n", val_ligne, val_col);
                    lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
                }
            }

            //Si on trouve une case adjacente, on l'insere dans la pile solution
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);

            //Affiche le tableau si nous sommes en debug
            if (debug)
            {
                pile_haut_pile(pile_solution, &val_ligne, &val_col);
                printf("Haut de la solution : (%i,%i)\n", val_ligne, val_col);
                lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
            }
        }
            // Les autres options ne fonctionnent pas, nous sommes bloques... On sort de la fonction
        else if (pile_est_vide(pile_chemins_alternatifs))
        {
            return 0;
        }
        //La position qu'on traite en ce moment est une sortie, nous avons gagne !
        if (lab_est_une_sortie(nouvelle_position, grille, hauteur_grille, largeur_grille))
        {
            return 1;
        }

    }
    // Au cas qu'on sorte de la boucle sans avoir trouve de solution
    return 0;
}
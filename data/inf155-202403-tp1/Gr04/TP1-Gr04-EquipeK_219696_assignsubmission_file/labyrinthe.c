/*
 * Module : labyrinthe.c
 *
 * Description : Fournit l'ensemble des fonctions permettant de resoudre un labyrinthe.
 *
 * Auteur : Samy Mekkati, Daniel Atik, Jad Bizri
 *
 * Date : 2023-11-12
 */

#include "labyrinthe.h"


void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
{
    char ascii_219 = (char)219; //Caractere qui affiche un mur

    for (int i = 0; i < hauteur_grille; i++) //Scan chaque ligne de la grille
    {
        for (int j = 0; j < largeur_grille; j++) //Scan chaque colonne de la grille
        {
            if(grille[i][j] == 1) //Si Vrai, c'est un mur
            {
                printf("%c", ascii_219);
            }
            else if (pile_contient(pile_solution,i,j)) //Si la case fait partie de la solution, c'est un X
            {
                printf("X");
            }
            else //Si la case vide ne fait pas partie de la solution, c'est un espace
            {
                printf(" ");
            }

        }
        printf("\n"); //Retour a la ligne apres avoir afficher une ligne de la grille
    }

}


void lab_calculer_deplacements_possibles(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2])
{
    int y = pos_ligne; //Declaration de la position a la ligne
    int x = pos_colonne; //Declaration de la position a la colonne
    int nb_possible = 0; //Initialisation du nombre de deplacement possible
    pile_initialiser(deplacements,4); //Reinitialiser le tableau des deplacements possibles a chaque itteration

    if(x >= 0 && x < largeur_grille && y>=0 && y<hauteur_grille) //On verifie que la coordonnee se trouve dans la grille
    {

        //Verification pour la case a droite
        if(grille[y][x+1] == 0 && !pile_contient(solution_partielle,y,(x+1)) && (x+1) < largeur_grille)
        {
            //Si Vrai, +1 au compteur de nombre de deplacements possibles
            nb_possible++;
            //On ajoute les coordonnees dans le tableau deplacements
            deplacements[nb_possible-1][0] = y;
            deplacements[nb_possible-1][1] = x+1;
        }

        //Verification pour la case en bas
        if(grille[y+1][x] == 0 && !pile_contient(solution_partielle,(y+1),x) && (y+1) < hauteur_grille)
        {
            nb_possible++;
            deplacements[nb_possible-1][0] = y+1;
            deplacements[nb_possible-1][1] = x;
        }

        //Verification pour la case en haut
        if(grille[y-1][x] == 0 && !pile_contient(solution_partielle,(y-1),x) && (y-1) >= 0)
        {
            nb_possible++;
            deplacements[nb_possible-1][0] = y-1;
            deplacements[nb_possible-1][1] = x;
        }

        //Verification pour la case a gauche
        if(grille[y][x-1] == 0 && !pile_contient(solution_partielle,y,(x-1)) && (x-1) >= 0)
        {
            nb_possible++;
            deplacements[nb_possible-1][0] = y;
            deplacements[nb_possible-1][1] = x-1;
        }


    }
    *nb_deplacements = nb_possible; //On stock le nombre de deplacements possible dans le pointeur
}

int lab_choisir_deplacement(
        int deplacements_possibles[][2],
        int nb_deplacements_possibles)
{
    int choix = 0; //Variable stockant le choix aleatoire

    //Si le tableau n'est pas vide, on effectue un choix aleatoire
    //On considere le tableau comme une pile puisqu'elle a 2 colonne
    if(pile_est_vide(deplacements_possibles) == 0)
    {
        choix = nb_aleatoire(0,nb_deplacements_possibles-1);
    }

    return choix;

}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{

    //Si les cases sont adjacentes, on renvoie Vrai
    if (case1[0] == case2[0] && abs(case1[1] - case2[1]) == 1
    || case1[1] == case2[1] && abs(case1[0] - case2[0]) == 1)
    {
        return 1;
    }

    return 0; //Faux sinon
}

int lab_est_une_sortie(
        const int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille)
{
    int y = position[0]; //Declaration de la position de la ligne
    int x = position[1]; //Declaration de la position de la colonne

    //Verification que la case ou nous sommes est a l'extremite de la grille
    if(x == 0 || x == largeur_grille - 1 || y == 0 ||y == hauteur_grille - 1) // Verification d'une coordonnee aux extremities de la grille
    {
        if (grille[y][x] == 0) //Si la case actuel est un couloir renvoie Vrai
        {
            return 1;
        }
    }

    return 0; //Faux sinon

}

int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements_possibles = 1; //il est toujours possible de se deplacer a l'entree
    int nouvelle_position[2]= {0,0};

    //Initialisation des variables qui stock la position actuel
    int x_position_actuel = 0;
    int y_position_actuel = 0;

    int choix; //Variable qui stock un des deplacements possibles
    int haut_pile_sol[2]= {0,0}; //Tableau qui stock les coordonnees du haut de la pile

    //Initialisation des variables qui stock la position en haut de la pile
    int x_haut_pile_sol = 0;
    int y_haut_pile_sol = 0;

    //Intialiser le generateur de nombre aleatoire
    srand((unsigned int)time(NULL));
    rand();

    //Initialisation des 2 piles
    pile_initialiser(pile_solution,TAILLE_MAX_PILE);
    pile_initialiser(pile_chemins_alternatifs,TAILLE_MAX_PILE);

    //Empiler l'entree dans la pile solution
    pile_empiler(pile_solution,entree[0],entree[1]);
    pile_haut_pile(pile_solution,&y_position_actuel,&x_position_actuel);

    //Mise a jour de la positiona actuel
    nouvelle_position[0] = y_position_actuel;
    nouvelle_position[1] = x_position_actuel;

    //afficher la grille apres avoir empier l'entree
    pas_a_pas(debug, grille, hauteur_grille, largeur_grille, pile_solution);


    //Empiler les solution dans la pile solution
    do{

        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,y_position_actuel,x_position_actuel,pile_solution,&nb_deplacements_possibles,deplacements_possibles);

        if(nb_deplacements_possibles > 0) //Tant qu'on peux se deplacer, on avance
        {
            //Choisir un deplacement selon ceux disponible a la position actuelle
            choix = lab_choisir_deplacement(deplacements_possibles,nb_deplacements_possibles);
            pile_empiler(pile_solution,deplacements_possibles[choix][0],deplacements_possibles[choix][1]);

            //Met a jour le haut de la pile solution
            pile_haut_pile(pile_solution,&y_haut_pile_sol,&x_haut_pile_sol);
            nouvelle_position[0] = y_haut_pile_sol;
            nouvelle_position[1] = x_haut_pile_sol;
            y_position_actuel = y_haut_pile_sol;
            x_position_actuel = x_haut_pile_sol;

            //On empile les autres deplacements possibles qui n'ont pas ete choisis dans la pile "Chemins_alternatifs"
            for(int i = 0; i < nb_deplacements_possibles; i++)
            {
                if(i != choix)
                {
                    pile_empiler(pile_chemins_alternatifs,deplacements_possibles[i][0],deplacements_possibles[i][1]);
                }
            }
        }

        else if(pile_est_vide(pile_chemins_alternatifs) == 0)//Si la pile de chemins alternatifs n'est pas vide, on essaye l'un de ses chemins
        {
            //On depile l'un des chemins alternatif
            pile_depiler(pile_chemins_alternatifs,&y_position_actuel,&x_position_actuel);
            //On stock ce chemin dans nouvelle position
            nouvelle_position[0] = y_position_actuel;
            nouvelle_position[1] = x_position_actuel;

            //Met a jour le haut de ma pile solution
            pile_haut_pile(pile_solution,haut_pile_sol,haut_pile_sol+1);

            //On depile jusqu'a ce que le haut de la pile soit adjacente a la nouvelle position
            while(lab_est_cases_adjacentes(nouvelle_position,haut_pile_sol) == 0)
            {
                pile_depiler(pile_solution,&y_haut_pile_sol,&x_haut_pile_sol);
                haut_pile_sol[0] = y_haut_pile_sol;
                haut_pile_sol[1] = x_haut_pile_sol;

            }

            //On empile les coordonnees de la nouvelle position dans pile solution
            pile_empiler(pile_solution,y_haut_pile_sol,x_haut_pile_sol);
            pile_empiler(pile_solution,y_position_actuel,x_position_actuel);
            //On pose le nombre de deplacements possible = 1 afin de pouvoir rentrer dans la boucle do while.
            nb_deplacements_possibles = 1;
        }

        //Si aucune solution est trouvee, Return Faux
        else
        {
            printf("Aucune solution trouvee :-(\n\n");
            return 0;
        }

        //Affiche a chaque fois qu'on ajoute un x si l'utilisateur nous le demande
        pas_a_pas(debug, grille, hauteur_grille, largeur_grille, pile_solution);


    }while(nb_deplacements_possibles > 0 && lab_est_une_sortie(nouvelle_position,grille,hauteur_grille,largeur_grille) == 0);


    //Lorsqu'une solution est trouvee, Return Vrai
    return 1;

}





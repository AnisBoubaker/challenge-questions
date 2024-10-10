/*
Module: labyrinthe.c
Description: Fournit l'ensemble de fonction permettant de résoudre un labyrinthe

Auteurs: Émile Yergeau
         Sabrina Poulin
         Xavier Brassard

Date: 2023-10-16
*/

/***********COMMANDES PR?PROCESSEUR*************/
#include "labyrinthe.h"

/*******IMPLEMENTATION DES FONCTIONS***********/

void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pile_solution[][2])
{
    //Boucle qui fait le tour des coordonnees de la grille
    for (int i=0; i<hauteur_grille; i++)
    {
        for (int j=0; j<largeur_grille; j++)
        {
            // On affiche un bloc s'il y a un mur
            if (grille[i][j] != 0)
            {
                printf("%c", 219);
            }
            else
            {
                // Affiche un X si la position dans la grille fait partie de la solution
                if (pile_contient(pile_solution, i, j))
                {
                    printf("X");
                }
                // Affiche un espace vide si la coordonnée n'est pas dans la solution et n'est pas un mur
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    system("pause");
}


void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int pos_ligne, int pos_colonne, int solution_partielle[][2], int *nb_deplacements, int deplacements[4][2])
{
    *nb_deplacements = 0;

    // Direction (selon pos actuelle) de la case qui va être évaluée.
    // 0: haut, 1: droite, 2: bas, 3: gauche
    int direction_evaluee;

    //Coordonnées de la case évaluée
    int case_evaluee_ligne;
    int case_evaluee_colonne;

    // Parcourir les cases adjacentes. Case adjacentes sont des cases avec soit pos_ligne ou pos_colonne +-1.
    // Maximum de 4 cases sont adjacentes
    for (direction_evaluee = 0; direction_evaluee < 4; direction_evaluee++)
    {
        /* Pour les directions haut et bas (0, 2), direction % 2 vas être 0.
         * La ligne va changer de -1 vers le haut ou +1 vers le bas, donc de direction - 1
         *
         * Pour les directions droite et gauche (1, 3), direction % 2 vas être 1.
         * La ligne va changer de +1 vers la droite ou -1 vers la gauche, donc de -(direction - 2)
        */
        case_evaluee_ligne = direction_evaluee % 2 ? pos_ligne : pos_ligne + direction_evaluee - 1;
        case_evaluee_colonne = direction_evaluee % 2 ? pos_colonne - (direction_evaluee - 2): pos_colonne;

        // On vérifie si la case fait partie du labyrinthe.
        if (0 <= case_evaluee_ligne && case_evaluee_ligne < hauteur_grille
            && 0 <= case_evaluee_colonne && case_evaluee_colonne < largeur_grille)
        {
            // On vérifie si la case est un déplacement permis (pas un mur et pas dans la solution partielle).
            // (mur: case == 1, vide: case == 0)
            if (grille[case_evaluee_ligne][case_evaluee_colonne] != 1
                && !pile_contient(solution_partielle, case_evaluee_ligne, case_evaluee_colonne))
            {
                // Ajoute la case aux déplacements possibles.
                deplacements[*nb_deplacements][0] = case_evaluee_ligne;
                deplacements[*nb_deplacements][1] = case_evaluee_colonne;
                (*nb_deplacements)++;
            }
        }
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{
    int indice_deplacement = 0; // Indice du déplacement sélectionné
    time_t temps; // variable du temps pour initialiser le générateur de nombres aléatoires

    // initialisation du générateur de nombre aléatoire
    srand((unsigned) time(&temps));

    // choisit aléatoirement un déplacement s'il y a plus qu'un déplacement possible
     if (nb_deplacements_possibles > 1)
     {
         indice_deplacement = rand() % nb_deplacements_possibles;
     }
    return(indice_deplacement);
}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int distance; //Variable de distance qui sera utile pour verifier l'etat de proximite

    //Additionne la distance en x et la distance en y des deux points
    distance = abs(case1[0] - case2[0]) + abs(case1[1]- case2[1]);

    //Retourne 1 si la distance est 1 et 0 si la distance est plus grande ou 0.
    return distance == 1;
}

int lab_est_une_sortie(int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
    // On a une sortie si on a une case vide en périphérie de la grille
    return ( (grille[position[0]][position[1]] == 0)
        && (   (position[1] == (hauteur_grille - 1))
            || (position[1] == 0)
            || (position[0] == (largeur_grille - 1))
            || (position[0] == 0)
        )
    );
}

int lab_resoudre_profondeur( int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille, int entree[2], int pile_solution[][2], int debug)
{
    int continuer = 1;
    int resolution = 0;

    int chemins_alternatifs [TAILLE_MAX_PILE][2]; // pile pour enregistrer des chemins alternatifs
    int position_alternative [2] = {0,0}; // Position alternative

    int position[2] = {0,0}; // Position actuelle

    // Tableaux des déplacements possibles
    int deplacements_possibles[4][2]= {{0,0}, {0,0}, {0,0}, {0,0}};
    int nb_deplacements_possibles; // Nombres de déplacements possibles
    int indice; // Indice du déplacement choisi

    // Initialisation des piles en empiler les premieres valeurs.
    pile_initialiser(chemins_alternatifs, TAILLE_MAX_PILE);
    pile_initialiser(pile_solution,TAILLE_MAX_PILE);
    pile_empiler(pile_solution, entree[0], entree[1]);

    // Initialisation de la première position
    position[0] = entree[0];
    position[1] = entree[1];

    // Résoudre le labyrinthe
    do {
        // calculer les déplacements possibles
        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,position[0],position[1],pile_solution, &nb_deplacements_possibles, deplacements_possibles);

        // si on a au moin 1 déplacement possible, on explore un déplacement possible
        if(nb_deplacements_possibles != 0)
        {
            // choix de la direction du deplacement
            indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);

            // mettre la direction choisie sur la pile de la solution partielle
            pile_empiler(pile_solution,deplacements_possibles[indice][0], deplacements_possibles[indice][1]);
            position[0] = deplacements_possibles[indice][0];
            position[1] = deplacements_possibles[indice][1];

            // s'il y a plus d'une direction, on les ajoute au chemin alternatif.
            if(nb_deplacements_possibles > 1)
            {
                for (int i = 0; i < nb_deplacements_possibles; i++)
                {
                    if(i != indice)
                    {
                        pile_empiler(chemins_alternatifs, deplacements_possibles[i][0], deplacements_possibles[i][1]);
                    }
                }
            }
        }
        // Si on a des chemins alternatif, on les explores
        else if (!pile_est_vide(chemins_alternatifs))
        {
            pile_depiler(chemins_alternatifs,&position_alternative[0],&position_alternative[1]);
            do
            {
                pile_depiler(pile_solution, &position[0], &position[1]);
            }while(!lab_est_cases_adjacentes(position,position_alternative));

            pile_empiler(pile_solution, position[0],position[1]);
            pile_empiler(pile_solution, position_alternative[0],position_alternative[1]);
        }
        // Sinon, aucune solution n'a été trouvée
        else
        {
            return 0;
        }

        // On prend la prochaine position
        pile_haut_pile(pile_solution,&position[0],&position[1]);

        if (lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille))
        {
            return 1;
        }

        if (debug)
        {
            lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
        }
    }while(1);
}

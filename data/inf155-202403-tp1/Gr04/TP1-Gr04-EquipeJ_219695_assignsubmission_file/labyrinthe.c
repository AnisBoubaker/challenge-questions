/***********COMMANDES PRÉPROCESSEUR*************/

#include "labyrinthe.h"
#include "Module_utilitaire.h"
/*******IMPLEMENTATION DES FONCTIONS***********/

void lab_afficher_grille(
int grille[][TAILLE_MAX_GRILLE], 
int hauteur_grille, 
int largeur_grille, 
int pile_solution[][2])
{
        for (int i = 0; i < hauteur_grille; i++) 
        {
                for (int j = 0; j < largeur_grille; j++) 
                {
                    int mur = grille[i][j] == 1;
                    int dans_solution = 0;

                    if (pile_solution != NULL) 
                    {
                        // Parcourir la pile pour verifier si la case fait partie de la solution
                        for (int p = 0; pile_solution[p][0] != -1; p++) 
                        {
                            if (pile_solution[p][0] == i && pile_solution[p][1] == j) 
                            {
                                dans_solution = 1;
                                break;
                            }
                        }
                    }

            if (dans_solution) 
            {
                printf("X");
            } 
            else if (mur) 
            {
                printf("%c", 219); // Caractère ASCII 219 pour representer un mur
            } 
            else 
            {
                printf(" "); // Espace pour representer un couloir
            }
        }
        printf("\n"); // Passer a la ligne suivante
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
        // Tableaux des mouvements possibles (haut, bas, gauche, droite)
        int dir_x[] = {0, 0, -1, 1};
        int dir_y[] = {-1, 1, 0, 0};

        //Intialisation du nombre de deplacements
        *nb_deplacements = 0; 
        
        // Parcourir les 4 directions
        for (int dir = 0; dir < 4; dir++) {
        int nouv_pos_ligne = pos_ligne + dir_x[dir];
        int nouv_pos_colonne = pos_colonne + dir_y[dir];

         // Vérifier que la nouvelle position est dans les limites de la grille       
        if (nouv_pos_ligne >= 0 && nouv_pos_ligne < hauteur_grille && nouv_pos_colonne >= 0 && nouv_pos_colonne < largeur_grille)
        {
            int mur_present = grille[nouv_pos_ligne][nouv_pos_colonne] == 0;
            int dans_solution = 0;

            // Vérifier que la case n'est pas un mur et qu'elle n'est pas déjà dans la solution partielle
            for (int i = 0; i < *nb_deplacements; i++)
            {
                if (nouv_pos_ligne == solution_partielle[i][0] && nouv_pos_colonne == solution_partielle[i][1])
                {
                    dans_solution = 1;
                    break;
                }
            }
                
            if (!mur_present && !dans_solution) {
                deplacements[*nb_deplacements][0] = nouv_pos_ligne;
                deplacements[*nb_deplacements][1] = nouv_pos_colonne;
                (*nb_deplacements)++;
            }
        }
    }  
}

int lab_choisir_deplacement(
int deplacements_possibles[][2],
int nb_deplacements_possibles)
{   
    // Générer un indice aléatoire entre 0 et nb_deplacements_possibles - 1
    int indice_choisi = nb_aleatoire(0, nb_deplacements_possibles - 1);
    return indice_choisi; // Retourner l'indice choisi comme prochain déplacement
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    //Déclaration de la variable resultat
    int resultat = 0;                                                                           //Initialisation du résultat à 0

    if(case1[0] == case2[0] && case1[1] == case2[1] )                                           //Renvoie Faux si les deux cases, case1 et la case2 sont les mêmes
    {
        resultat = 0;
    }
    else if(case1[0] == case2[0] && (((case1[1])+1 == case2[1]) ||((case1[1])-1 == case2[1]) )) //Renvoie Vrai si les deux cases, case1 et case2 sont adjacentes
    {
        resultat = 1;
    }
    else if(case1[1] == case2[1] && (((case1[0])+1 == case2[0]) ||((case1[0])-1 == case2[0]) )) //Renvoie Vrai si les deux cases, case1 et case2 sont adjacentes
    {
        resultat = 1;
    }
    else                                                                                       //Renvoie Faux si les deux cases, case1 et case2 ne sont pas adjacentes
    {
        resultat = 0;
    }

    return resultat;                                                                           //Retourne la valeur finale de resultat
}

int lab_est_une_sortie(
int position[2],
int grille[][TAILLE_MAX_GRILLE],
int hauteur_grille,
int largeur_grille)
{
    // Déclaration et initialisation des variables
    int x = position[0]; 
    int y = position[1];

    //Si la position se trouve en périphérie de la grille et qu'elle n'est pas un mur
    if (x == 0 || x == hauteur_grille - 1 || y == 0 || y == largeur_grille - 1)
    {
        if (grille[x][y] != 1)
        {
            return 1; // Renvoie vrai si la position est une sortie
        }

     }
    return 0; // Renvoie faux si la position n'est pas une sortie
}

int lab_resoudre_profondeur(
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int entree[2],
    int pile_solution[][2],
    int debug)
{
    int nb_deplacements_possibles;
    int deplacements_possibles[4][2];
    int nouvelle_position[2];
    int position[2];
    int position_ligne, position_colonne, nposition_ligne, nposition_colonne;
    int pile_chemin_alternatif[][2] = {0};
    int sortie[2];
    int ligne_sortie;
    int colonne_sortie;

    pile_initialiser(pile_chemin_alternatif, TAILLE_MAX_GRILLE);
    pile_initialiser(pile_solution, TAILLE_MAX_GRILLE);
    pile_initialiser(pile_chemin_alternatif, TAILLE_MAX_GRILLE);

    pile_empiler(pile_solution, entree[0], entree[1]);
    nouvelle_position[0] = entree[0];
    nouvelle_position[1] = entree[1];
     // Recherche des coordonnées de la sortie
    for (int i = 0; i < hauteur_grille; i++)
    {
        for (int j = 0; j < largeur_grille; j++) 
        {
            sortie[0] = i;
            sortie[1] = j;
            if (lab_est_une_sortie(sortie, grille, hauteur_grille, largeur_grille)) 
            {
                ligne_sortie = i;
                colonne_sortie = j;
                i = hauteur_grille;
                j = largeur_grille; 
            }
        }
    }
    // Boucle de résolution    
    do {
        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, nouvelle_position[0], nouvelle_position[1], pile_solution, &nb_deplacements_possibles, deplacements_possibles);
        // Calculer les déplacements possibles
        if (nb_deplacements_possibles > 0) 
        {
            int indice_choisi = lab_choisir_deplacement(deplacements_possibles, nb_deplacements_possibles);
            nouvelle_position[0] = deplacements_possibles[indice_choisi][0];
            nouvelle_position[1] = deplacements_possibles[indice_choisi][1];
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);
                
           // Empiler les autres déplacements possibles comme chemins alternatifs
            for (int i = 0; i < nb_deplacements_possibles; i++)
            {
                if (deplacements_possibles[i][0] != nouvelle_position[0] &&
                    deplacements_possibles[i][1] != nouvelle_position[1]) 
                {
                    pile_empiler(pile_chemin_alternatif, deplacements_possibles[i][0], deplacements_possibles[i][1]);
                }
            }
        } 
   // Retourner en arrière jusqu'à la dernière position avec des choix alternatifs
    else if (!pile_est_vide(pile_chemin_alternatif)) 
        {
            pile_depiler(pile_chemin_alternatif, &position_ligne, &position_colonne);
            position[0] = position_ligne;
            position[1] = position_colonne;
            // Trouver la position adjacente dans la pile de solution
            while (!lab_est_cases_adjacentes(nouvelle_position, position)) 
            {
                pile_depiler(pile_solution, &nposition_ligne, &nposition_colonne);
                nouvelle_position[0] = nposition_ligne;
                nouvelle_position[1] = nposition_colonne;
            }
            // Empiler la nouvelle position dans la solution
            pile_empiler(pile_solution, nouvelle_position[0], nouvelle_position[1]);
        } else 
        {
            nb_deplacements_possibles = 0;
        }
    } while (!pile_contient(pile_solution, ligne_sortie, colonne_sortie) && nb_deplacements_possibles != 0);
        
     // Afficher la grille en mode debug
    if (debug) 
    {
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);
    }
     // Retourner vrai si une solution est trouvée, faux sinon
    return pile_contient(pile_solution, ligne_sortie, colonne_sortie) != 0 ? 1 : 0;
}

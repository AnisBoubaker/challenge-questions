/*
 * Programme : TP1 Labyrinthe
 * Auteurs :
 * Date :
 */
#include "labyrinthe.h"


void lab_afficher_grille (int grille[][TAILLE_MAX_GRILLE],
                          int hauteur_grille,
                          int largeur_grille,
                          int pile_solution[][2])
{
    // On analyse chaque case du tableau grille
    for (int ligne = 0; ligne < hauteur_grille; ligne++)
    {
        for (int colone = 0; colone < largeur_grille; colone++)
        {
            if (grille[ligne][colone] == 1)
            {
                // Mettre le charactère de bloc s'il y a un mur (on met aussi un espace après pour avoir un tableau
                // plus lisible)
                printf("%c", 219);
                printf(" ");
            }
            if (grille[ligne][colone] == 0)
            {
                // Mettre un espace s'il y a pas de mur
                printf(" ");

                // Si une pile solution est fournie, on vérifie si la coordonnée actuelle est contenue dans la pile
                // Si oui, on remplace l'esapce par un 'x'
                if (pile_solution != NULL)
                    if (pile_contient(pile_solution, ligne, colone) == 1)
                        printf("\bx");
            }
        }
        printf("\n");
    }
}


void test_lab_afficher_grille(void)
{
    // Création d'une grille exemple pour tester la fonction lab_afficher_grille
    int grille1[7][TAILLE_MAX_GRILLE] = {{1, 0, 1, 1, 1},
                                         {1, 0, 0, 0, 1},
                                         {1, 1, 0, 1, 1},
                                         {1, 0, 0, 0, 1},
                                         {1, 0, 1, 0, 0},
                                         {1, 0, 0, 1, 1},
                                         {1, 1, 1, 1, 1}};

    // Création d'une pile solution exemple qui correspondrait à la solution de la grille exemple
    int pile_solution[10][2] = {{10, 8},
                                {0, 1},
                                {1, 1},
                                {1, 2},
                                {2, 2},
                                {3, 2},
                                {3, 3},
                                {4, 3},
                                {4, 4}};

    // Création d'une pile vide pour le test
    int pile_vide[10][2];


    // Afficher une fois la grille sans sa solution, une fois avec la solution et un test avec une grille avec
    // des valeurs de hauteurs et largeurs qui ne correspondent pas à ceux de la grille (Le test est visuel et ne
    // consiste pas au retour d'une valeur 1 ou 0)
    lab_afficher_grille(grille1, 7, 5, pile_vide);
    printf("\n\n");
    lab_afficher_grille(grille1, 7, 5, pile_solution);
    printf("\n\n");
    lab_afficher_grille(grille1, 0, 2, pile_vide);

}



int lab_choisir_deplacement(int deplacements_possibles[][2], int nb_deplacements_possibles)
{
    srand((unsigned int)time(NULL));
    rand();

    // Génère un nombre aléatoire entre 0 et le nombre de déplacements possibles et le renvoie
   return nb_aleatoire(0, nb_deplacements_possibles - 1);
}


int test_lab_choisir_deplacement(void)
{
    // Création du tableau déplacements possibles comme exemple
    int deplacements_possibles[][2] = { {1,1}, {1,0}, {0,1}, {0,0}};
    int choix;

    // Répeter le test 10 fois ainsi on peut voir si le déplacement est aléatoire ou si la valeur est toujours la même
    for (int i = 0; i < 10; i++)
    {
        choix = lab_choisir_deplacement(deplacements_possibles, 4);
        // Si le choix ne correspond pas à un indice du tableau la fonction retourne 0, sinon on fait une vérification
        // visuelle des résultats
        if ((choix < 0) || (choix >= 4))
        {
            printf("Erreur");
            return 0;
        }
        else
            printf("%d\n", choix);
    }
    return 1;
 }





void lab_calculer_deplacements_possibles (int grille[][TAILLE_MAX_GRILLE],
                                          int hauteur_grille,
                                          int largeur_grille,
                                          int pos_ligne,
                                          int pos_colonne,
                                          int solution_partielle[][2],
                                          int *nb_deplacements,
                                          int deplacements[4][2])
{
    *nb_deplacements = 0;
    int tab_pos_acc[] = {pos_ligne,
                         pos_colonne};               // Tableau qui contient les coordonnes de la position actuelle sur la grille
    int copie_grille[2];                                                // Tableau qui stocke les coordonnes d'une case de la grille a chaque iteration de boucle
    int parcours;                                                      // Entier qui represente le nombres de donnes dans le tableau de solutions partielles
    parcours = pile_taille_pile(solution_partielle);

    for (int i = 0; i < hauteur_grille; i++)                        // Traite la grille sur toute sa hauteu
    {
        for (int a = 0; a < largeur_grille; a++)                     // Traite la grille sur toute sa largeur
        {
            copie_grille[0] = a;     // Stocker coordonne en x d'une case de la grille
            copie_grille[1] = i;     // Stocker coordonne en y d'une case de la grille
            if ((lab_est_cases_adjacentes(tab_pos_acc,copie_grille)))     // Si case de postition sur la grille et une case quelconque sur la grilles// sont adjacentes
            {
                if (grille[a][i] != 1)                                                // Si la case adjacente n'est pas un mur
                {
                    // Traiter le tableau de solutions partielles sur son ensemble tout en enlevant la premiere ligne
                    // qui contient taille max et effective
                    for (int b = 0; b < (parcours -1); b++)
                    {
                        if (pile_est_vide(solution_partielle))
                        {
                            pile_empiler(deplacements, a + 1, i);

                            *nb_deplacements++;

                        }
                        // Si la solution partielle ne contient pas la case en question, l'ajouter directement au tableau deplacements
                        else if ((pile_contient(solution_partielle, a + 1, i)) == 0) // Premeier parametre commence est 'a + 1', car premiere ligne du tableau solution partielle represente
                                                                                                        // les tailles max et effective du tableau
                        {
                            pile_empiler(deplacements, a, i);
                            *nb_deplacements++;                                                 // Stocker le nombre de deplacements disponibles
                        }


                    }
                }
            }
        }
    }
}


int test_lab_deplacements_possibles(void)
{
    int hauteur_grille = 7;
    int largeur_grille = 7;

    // Generer un tableau 'grille'fictif qui represente la composition d'un labyrinthe fictif
    int grille[][TAILLE_MAX_GRILLE] = {{1, 0, 1, 1, 1, 1, 1},
                                       {1, 0, 0, 0, 0, 0, 1},
                                       {1, 1, 0, 1, 1, 0, 1},
                                       {1, 0, 0, 0, 1, 0, 1},
                                       {1, 0, 1, 1, 1, 0, 1},
                                       {1, 0, 0, 0, 0, 0, 1},
                                       {1, 1, 1, 1, 1, 0, 1}};

    // Generer une solution partielle fictive
    int solution_partielle[][2] = {{9, 4},
                                   {0, 1},
                                   {1, 1},
                                   {2, 2},
                                   {3, 2},
                                   {0, 0},
                                   {0, 0},
                                   {0, 0},
                                   {0, 0}};

    int nb_deplacements;
    int deplacements[4][2];


    lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille,3,1,
                                        solution_partielle, &nb_deplacements, deplacements);

    // Afficher le nombre de deplacements possibles suite a l'appel de la fonction
    printf("%i\n", nb_deplacements);
    printf("Déplacements possibles: \n");

    // Afficher les coordonnes des deplacements possibles trouves
    for (int k = 0; k < 4; k++)
    {
        printf("[%d, %d]\n", deplacements[k][0], deplacements[k][1]);
    }

}


int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    // Si les coordonnes x correspondent
    if(case1[0] == case2[0])
    {
        // Si coordonnes y etant liees aux coordonnes x etant adjacentes correspondent bel et bien
        if(case1[1] == (case2[1]+1) || case1[1] == (case2[1]-1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
        // Si les coordonnes y correspondent
    else if(case1[1] == case2[1])
    {
        // Si coordonnes x etant liees aux coordonnes y etant adjacentes correspondent bel et bien
        if(case1[0] == (case2[0]+1) || case1[0] == (case2[0]-1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

// Fonction qui initialise deux tableaux correspondant a des coordonnes de deux cases et qui test la fonction lab_est_cases_adjacentes
// Affiche comme resultat 1 si cases adjacentes ou 0 si cases non adjacentes
int test_lab_est_cases_adjacentes(void)
{
    // Generer deux tableaux qui contiennent deux donnees representant les coordonnes x et y de deux cases sur la grille
    int case1[] = {5,4};
    int case2[] = {5,3};

    return lab_est_cases_adjacentes(case1, case2);;

}


int lab_est_une_sortie(const int position[2], int grille[][TAILLE_MAX_GRILLE], int hauteur_grille, int largeur_grille)
{
    // Si la position se trouve sur le bord du labyrinthe et que la position représente un espace dans la grille
    // la fonction retourne la valeur vrai (c'est une sortie)

    if ((position[0] == 0) || (position[0] == largeur_grille) || (position[1] == 0) || (position[1] == hauteur_grille)
                                                                                       && (grille[position[0]][position[1]] == 0))
        return 1;

        // Sinon retourne la valeur fausse (ce n'est pas une sortie)
    else
        return 0;
}

int test_lab_est_une_sortie(void)
{
    // Cr?ation de positions qui repr?sentent les possibilit?es de la fonction lab_est_une_sortie pour une grille cr??e:
    //   - Position est sur le bord et n'est pas un mur
    //   - Position est sur le bord mais ne repr?sente pas un mur
    //   - Position n'est pas un mur mais n'est pas sur le bord
    int position1[2] = {0, 1};
    int position2[2] = {1, 1};
    int position3[2] = {1, 0};
    int exemple_grille[4][TAILLE_MAX_GRILLE] = {{1, 0, 1, 1},
                                                {1, 0, 0, 1},
                                                {1, 0, 1, 1},
                                                {1, 1, 1, 1}};

    // Si les positions qui repr?sentent bel et bien des sorties renvoient la valeur 1 et celles qui ne repr?sentent
    // pas des sorties renvoient la valeur 0, alors la fonction test renvoie la valeur VRAI, sinon renvoie FAUX
    if ((lab_est_une_sortie(position1, exemple_grille, 4, 4) == 1)
        && (lab_est_une_sortie(position2, exemple_grille, 4, 4) == 0)
        && (lab_est_une_sortie(position3, exemple_grille, 4, 4) == 0))
        return 1;

    else
        return 0;
}

int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug)
{
    int pile_chemin_alternatif[TAILLE_MAX_PILE][2];
    int deplacements_possibles[4][2];
    int nb_deplacements = 1;
    int nouvelle_position[2];

    int pile_temporaire[TAILLE_MAX_PILE][2];
    int pos_temp[2];
    int indice;

    pile_initialiser(pile_solution, TAILLE_MAX_PILE);
    pile_initialiser(pile_chemin_alternatif, TAILLE_MAX_PILE);

    pile_empiler(pile_solution, entree[0], entree[1]);
    // Si debug egal '1', on affiche une grille une première fois, puisqu'a chaque itération on efface la grille précédente
    if (debug == 1)
        lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_solution);

    // Tant qu'il est possible de se déplacer, on continue l'algorithme
    while ((nb_deplacements != 0) && (pile_solution != NULL))
    {
        pile_haut_pile(pile_solution, &nouvelle_position[0], &nouvelle_position[1]);

        lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, nouvelle_position[0],
                                            nouvelle_position[1],pile_temporaire,
                                            &nb_deplacements,deplacements_possibles);

        // Si on peut se déplacer, on se déplace dans une position aléatoire disponnible et on garde les autres
        // posibilitées dans la pile chemins alternatifs
        if (nb_deplacements > 0)
        {
            indice = lab_choisir_deplacement(deplacements_possibles, nb_deplacements);
            pile_empiler(pile_solution, deplacements_possibles[indice][0], deplacements_possibles[indice][1]);

            afficher_grille_debug(grille, hauteur_grille, largeur_grille, pile_solution, debug);

            for(int i=0; i<nb_deplacements-1; i++) // Empiler les autres chemins possibles non empruntes dans la pile chemins alternatifs
            {
                if (i != indice) {

                    pile_empiler(pile_chemin_alternatif, deplacements_possibles[i][0], deplacements_possibles[i][0]);
                    pile_chemin_alternatif[0][1]++;
                }
            }
        }
        // Sinon si il y a des chemins alternatifs, on continue à partir du dernier chemin alternatif
        else if (pile_chemin_alternatif[0][1] > 0)
        {
            pile_haut_pile(pile_chemin_alternatif, &nouvelle_position[0], &nouvelle_position[1]);

            do                 //dépiler jusqu'à arriver à un chemin qui fonctionne et qui n'a pas déja été emprunté
            {
                pile_depiler(pile_solution, &pos_temp[0], &pos_temp[1]);

            } while (lab_est_cases_adjacentes(nouvelle_position, pos_temp) == 0);

            // On empile le dernier chemin alternatif que l'on enlève aussi de la pile des chemins alternatifs et on
            // teste toutes ses possibilitées (si debug est 1 on affiche une nouvelle version de la grille)
            pile_empiler(pile_solution, pile_chemin_alternatif[pile_chemin_alternatif[0][1]][0],
                         pile_chemin_alternatif[pile_chemin_alternatif[0][1]][1]);
            afficher_grille_debug(grille, hauteur_grille, largeur_grille, pile_solution, debug);

            pile_depiler(pile_chemin_alternatif, &pos_temp[0], &pos_temp[1]);
        }
        // Si auncun déplacement n'est possible on arrette
        else
            break;
    }

    // Si la dernière case de la pile solution est la sortie, la solution à été trouvée
    int sortie[2];
    sortie[0] = pile_solution[pile_solution[0][1]][0];
    sortie[1] = pile_solution[pile_solution[0][1]][1];
    if (lab_est_une_sortie(sortie, grille, hauteur_grille, largeur_grille))
        return 1;
    else
        return 0;
}

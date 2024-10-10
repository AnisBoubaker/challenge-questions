/*
Titre: labyrinthe
Description: Fournit l'ensemble des fonctions permettant de résoudre un labyrinthe.

Auteur: Alexis Roy-Tessier, Donald Vu, Mayas Kaced
Date: 12 novembre 2023
*/


/***********COMMANDES PREPROCESSEUR*************/
#include "labyrinthe.h"
#include "Labyrinthe_io.h"
#include "pile.h"
#include "Utilitaires.h"
#define MUR 219



/*******IMPLEMENTATION DES FONCTIONS***********/
/*Fonction: LAB_AFFICHER_GRILLE
 *Description: Affiche la grille du labyrinthe dans la console avec espaces et espaces pleins.*/
void LAB_AFFICHER_GRILLE(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
{

    //Parcourir le tableau
    int contient_solution;
    for (int i=0;i<hauteur_grille;i++)
    {
        for (int j=0;j<largeur_grille;j++)
        {
            contient_solution=pile_contient(pile_solution,i,j);
            //Rencontre solution
            if (contient_solution == 1)
            {
                printf("x");
            }
            //Rencontre mur
            else if (grille[i][j] == 1)
            {
                printf("%c", MUR);
            }
            //Rencontre couloir
            else if (grille[i][j] == 0)
            {
                printf(" ");
            }

        }
        //On saute de ligne à chaque itération de i
        printf("\n");
    }
}

void LAB_CALCULER_DEPLACEMENTS_POSSIBLES(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2])
{

    int i=0;
    (*nb_deplacements)=0;
    //Un déplacement est possible si la case est un couloir non parcouru.
    //Un déplacement est impossible si la case est un mur ou si elle a déjà été parcourue.

    //On regarde vers le haut (position selon hauteur+1) si un déplacement est possible.
    if ((grille[pos_ligne+1][pos_colonne] == 0 ) && (pos_ligne+1<hauteur_grille) && (pile_contient(solution_partielle, pos_ligne+1 ,pos_colonne) == 0) )
    {
        deplacements[i][0]=pos_ligne+1;
        deplacements[i][1]=pos_colonne;
        i++;
        (*nb_deplacements)++;
    }
    //On regarde vers le bas (position selon hauteur -1) si un déplacement est possible.
    if ((grille[pos_ligne-1][pos_colonne] == 0 ) && (pos_ligne-1>=0) && (pile_contient(solution_partielle, pos_ligne-1 ,pos_colonne) == 0))
    {
        deplacements[i][0]=pos_ligne-1;
        deplacements[i][1]=pos_colonne;
        i++;
        (*nb_deplacements)++;
    }
    //On regarde vers la droite (position selon largeur +1) si un déplacement est possible.
    if ((grille[pos_ligne][pos_colonne+1] == 0 ) && (pos_colonne+1<largeur_grille) && (pile_contient(solution_partielle, pos_ligne ,pos_colonne+1) == 0))
    {
        deplacements[i][0]=pos_ligne;
        deplacements[i][1]=pos_colonne+1;
        i++;
        (*nb_deplacements)++;
    }
    //On regarde vers la gauche (position selon largeur -1) si un déplacement est possible.
    if ((grille[pos_ligne][pos_colonne-1] == 0 ) && (pos_colonne-1>=0) && (pile_contient(solution_partielle, pos_ligne ,pos_colonne-1) == 0))
    {
        deplacements[i][0]=pos_ligne;
        deplacements[i][1]=pos_colonne-1;
        i++;
        (*nb_deplacements)++;
    }
}

int LAB_CHOISIR_DEPLACEMENT(int deplacements_possibles[][2],int *nb_deplacements_possibles)
{
    int indice;  /* Reçoit l'indice de ligne du déplacement aléatoire. */

    /* On initialise le générateur d'indice de ligne du déplacement aléatoire. */
    srand((unsigned int)time(NULL));
    rand();

    if (*nb_deplacements_possibles>0)
    {
        /* On génère un déplacement dans l'intervalle. */
        indice = deplacement_aleatoire(1, *nb_deplacements_possibles);
        return indice;
    }
    else
    {
        return 0;
    }
}


int LAB_EST_CASES_ADJACENTES(int case1[2], int case2[2])
{
    int verite = 0;      //État de verité de case adjacente

    //Vérification que "y" case1 est en haut ou en bas de "y" case2.
    if (((case1[0]-1) == (case2[0])) || ((case1[0]+1) == (case2[0])))
    {
        //"x" doit être pareil pour les deux cases.
        if ((case1[1]) == (case2[1]))
        {
            verite = 1;
        }
    }

    //Vérification que "x" case1 est en haut ou en bas de "x" case2.
    else if (((case1[1]-1) == (case2[1])) || ((case1[1]+1) == (case2[1])))
    {
        //"y" doit être pareil pour les deux cases.
        if (((case1[0]) == (case2[0])))
        {
            verite = 1;
        }

    }

    return verite;
}

int LAB_EST_UNE_SORTIE(int position[2],int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,int largeur_grille)
{
    //On parcourt le long de la hauteur de la grille, aux extrêmes de la largueur,
    //pour voir si la position actuelle est une sortie(couloir).
    for(int i = 0; i < hauteur_grille; i++)
    {
        if(grille[i][0] == 0 && position[0] == i && position[1] == 0)
        {
            return 1;
        }

        else if(grille[i][largeur_grille-1] == 0 && position[0] == i && position[1] == largeur_grille-1)
        {
            return 1;
        }
    }
    //On parcourt le long de la largeur de la grille, aux extrêmes de la hauteur,
    //pour voir si la position actuelle est une sortie(couloir).
    for(int j = 0; j < largeur_grille; j++)
    {
        if(grille[0][j] == 0 && position[0] == 0 && position[1] == j)
        {
            return 1;
        }
        else if(grille[hauteur_grille-1][j] == 0 && position[0] == hauteur_grille-1 && position[1] == j)
        {
            return 1;
        }
    }
    //Aucune sortie n'est trouvée
    return 0;
}

int LAB_RESOUDRE_PROFONDEUR(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug)
{
    //On crée une nouvelle pile qui stocke des chemins alternatifs.
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];

    //On initialise les deux piles qu'on utilisera pendant la fonction.
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_PILE);
    pile_empiler(pile_solution, entree[0], entree[1]);


    int nombre_deplacements;
    int deplacements[4][2];
    int indice;

    //Pour certaines fonctions, on doit fournir la position sous forme de tableau
    //et pour d'autres,sous forme de variables.
    int position[2] = {entree[0], entree[1]};
    int pos_ligne = entree[0];
    int pos_colonne = entree[1];

    //Pour certaines fonctions, on doit fournir la position alternative sous forme de tableau
    //et pour d'autres,sous forme de variables.
    int position_alternative[2] = {0, 0};
    int pos_ligne_alternative;
    int pos_colonne_alternative;

    //La sortie doit être 0, seulement 1 quand c'est la fin du labyrinthe.
    int sortie = 0;


    while (sortie == 0)
    {
        //On calcule le nombre de déplacements possibles
        LAB_CALCULER_DEPLACEMENTS_POSSIBLES(
                grille,
                hauteur_grille,
                largeur_grille,
                position[0],
                position[1],
                pile_solution,
                &nombre_deplacements,
                deplacements);
        //On choisit aléeatoirement le déplacement à faire (indice de ligne du tableau déplacements).
        indice = LAB_CHOISIR_DEPLACEMENT(deplacements, &nombre_deplacements);

        //Après chaque déplacement, on vérifie si la position actuelle est une sortie.

        //On empile la pile solution avec le seul déplacement possible.
        if (nombre_deplacements == 1)
        {
            pile_empiler(pile_solution, deplacements[0][0], deplacements[0][1]);
            mise_a_jour_position(pile_solution, position, &pos_ligne, &pos_colonne);
            sortie = LAB_EST_UNE_SORTIE(position, grille, hauteur_grille, largeur_grille);

        }
        //On empile la pile solution avec le déplacement choisi par l'indice.
        else if (nombre_deplacements > 1)
        {
            pile_empiler(pile_solution, deplacements[indice - 1][0], deplacements[indice - 1][1]);
            mise_a_jour_position(pile_solution, position, &pos_ligne, &pos_colonne);
            sortie = LAB_EST_UNE_SORTIE(position, grille, hauteur_grille, largeur_grille);

            //On prend note des autres déplacements possibles et on les stockent dans chemins alternatifs.
            for (int i = 0; i < nombre_deplacements; i++)
            {
                if (i != indice - 1)
                {
                    pile_empiler(pile_chemins_alternatifs, deplacements[i][0], deplacements[i][1]);
                }
            }
        }
        //Quand on a aucun déplacement possible ET que la pile de chemins alternatifs est vide,
        //il n'y a aucune solution au labyrinthe.
        else if ((nombre_deplacements == 0) && pile_est_vide(pile_chemins_alternatifs))
        {
            printf("Aucune solution trouvée :-(");
            system("pause");
            sortie = 2;

        }
        //Quand on a aucun déplacement possible, on dépile la pile solution jusqu'à
        //une case adjacente entre pile solution et pile chemins alternatifs.
        else
        {
            mise_a_jour_position(pile_chemins_alternatifs,
                                 position_alternative,
                                 &pos_ligne_alternative,
                                 &pos_colonne_alternative);
            while (!LAB_EST_CASES_ADJACENTES(position_alternative, position))
            {
                pile_depiler(pile_solution, &pos_ligne, &pos_colonne);
                mise_a_jour_position(pile_solution, position, &pos_ligne, &pos_colonne);
            }
            //Par la suite, on empile le chemin alternatif choisi dans la pile solution
            //et on le dépile de la pile chemins alternatifs.
            //On met ensuite à jour la position.
            pile_empiler(pile_solution, pos_ligne_alternative, pos_colonne_alternative);
            pile_depiler(pile_chemins_alternatifs, &pos_ligne_alternative, &pos_colonne_alternative);
            mise_a_jour_position(pile_solution, position, &pos_ligne, &pos_colonne);
        }

        //Si l'utilisateur a choisi selection == 3, on entre en mode pas à pas (debug).
        //On le met à l'intérieur du while, car on veut que la grille affiche
        //à chaque empilement de la pile solution.
        if (debug == 1 && sortie != 2)
        {
            LAB_AFFICHER_GRILLE(grille, hauteur_grille, largeur_grille, pile_solution);
            system("pause");
        }
    }
    //On affiche seulement la grille et la pile solution complète quand le labyrinthe est résolu.
    if (debug == 0)
    {
        LAB_AFFICHER_GRILLE(grille, hauteur_grille, largeur_grille, pile_solution);
        system("pause");
    }
}
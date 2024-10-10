 


 
#include "labyrinthe.h"
#include "Labyrinthe_io.h"
#include "pile.h"
#include "Utilitaires.h"
#define MUR 219



 
 
void LAB_AFFICHER_GRILLE(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2])
{

     
    int contient_solution;
    for (int i=0;i<hauteur_grille;i++)
    {
        for (int j=0;j<largeur_grille;j++)
        {
            contient_solution=pile_contient(pile_solution,i,j);
             
            if (contient_solution == 1)
            {
                printf("x");
            }
             
            else if (grille[i][j] == 1)
            {
                printf("%c", MUR);
            }
             
            else if (grille[i][j] == 0)
            {
                printf(" ");
            }

        }
         
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
     
     

     
    if ((grille[pos_ligne+1][pos_colonne] == 0 ) && (pos_ligne+1<hauteur_grille) && (pile_contient(solution_partielle, pos_ligne+1 ,pos_colonne) == 0) )
    {
        deplacements[i][0]=pos_ligne+1;
        deplacements[i][1]=pos_colonne;
        i++;
        (*nb_deplacements)++;
    }
     
    if ((grille[pos_ligne-1][pos_colonne] == 0 ) && (pos_ligne-1>=0) && (pile_contient(solution_partielle, pos_ligne-1 ,pos_colonne) == 0))
    {
        deplacements[i][0]=pos_ligne-1;
        deplacements[i][1]=pos_colonne;
        i++;
        (*nb_deplacements)++;
    }
     
    if ((grille[pos_ligne][pos_colonne+1] == 0 ) && (pos_colonne+1<largeur_grille) && (pile_contient(solution_partielle, pos_ligne ,pos_colonne+1) == 0))
    {
        deplacements[i][0]=pos_ligne;
        deplacements[i][1]=pos_colonne+1;
        i++;
        (*nb_deplacements)++;
    }
     
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
    int indice;   

     
    srand((unsigned int)time(NULL));
    rand();

    if (*nb_deplacements_possibles>0)
    {
         
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
    int verite = 0;       

     
    if (((case1[0]-1) == (case2[0])) || ((case1[0]+1) == (case2[0])))
    {
         
        if ((case1[1]) == (case2[1]))
        {
            verite = 1;
        }
    }

     
    else if (((case1[1]-1) == (case2[1])) || ((case1[1]+1) == (case2[1])))
    {
         
        if (((case1[0]) == (case2[0])))
        {
            verite = 1;
        }

    }

    return verite;
}

int LAB_EST_UNE_SORTIE(int position[2],int grille[][TAILLE_MAX_GRILLE], int hauteur_grille,int largeur_grille)
{
     
     
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
     
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];

     
    pile_initialiser(pile_solution, TAILLE_MAX_PILE);
    pile_initialiser(pile_chemins_alternatifs, TAILLE_MAX_PILE);
    pile_empiler(pile_solution, entree[0], entree[1]);


    int nombre_deplacements;
    int deplacements[4][2];
    int indice;

     
     
    int position[2] = {entree[0], entree[1]};
    int pos_ligne = entree[0];
    int pos_colonne = entree[1];

     
     
    int position_alternative[2] = {0, 0};
    int pos_ligne_alternative;
    int pos_colonne_alternative;

     
    int sortie = 0;


    while (sortie == 0)
    {
         
        LAB_CALCULER_DEPLACEMENTS_POSSIBLES(
                grille,
                hauteur_grille,
                largeur_grille,
                position[0],
                position[1],
                pile_solution,
                &nombre_deplacements,
                deplacements);
         
        indice = LAB_CHOISIR_DEPLACEMENT(deplacements, &nombre_deplacements);

         

         
        if (nombre_deplacements == 1)
        {
            pile_empiler(pile_solution, deplacements[0][0], deplacements[0][1]);
            mise_a_jour_position(pile_solution, position, &pos_ligne, &pos_colonne);
            sortie = LAB_EST_UNE_SORTIE(position, grille, hauteur_grille, largeur_grille);

        }
         
        else if (nombre_deplacements > 1)
        {
            pile_empiler(pile_solution, deplacements[indice - 1][0], deplacements[indice - 1][1]);
            mise_a_jour_position(pile_solution, position, &pos_ligne, &pos_colonne);
            sortie = LAB_EST_UNE_SORTIE(position, grille, hauteur_grille, largeur_grille);

             
            for (int i = 0; i < nombre_deplacements; i++)
            {
                if (i != indice - 1)
                {
                    pile_empiler(pile_chemins_alternatifs, deplacements[i][0], deplacements[i][1]);
                }
            }
        }
         
         
        else if ((nombre_deplacements == 0) && pile_est_vide(pile_chemins_alternatifs))
        {
            printf("Aucune solution trouvée :-(");
            system("pause");
            sortie = 2;

        }
         
         
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
             
             
             
            pile_empiler(pile_solution, pos_ligne_alternative, pos_colonne_alternative);
            pile_depiler(pile_chemins_alternatifs, &pos_ligne_alternative, &pos_colonne_alternative);
            mise_a_jour_position(pile_solution, position, &pos_ligne, &pos_colonne);
        }

         
         
         
        if (debug == 1 && sortie != 2)
        {
            LAB_AFFICHER_GRILLE(grille, hauteur_grille, largeur_grille, pile_solution);
            system("pause");
        }
    }
     
    if (debug == 0)
    {
        LAB_AFFICHER_GRILLE(grille, hauteur_grille, largeur_grille, pile_solution);
        system("pause");
    }
}
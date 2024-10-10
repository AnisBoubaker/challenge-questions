 

#include <stdio.h>
#include "labyrinthe_io.h"
#include "pile.h"
#include "labyrinthe.h"



#define TAILLE_MAX_PILE 1000  


int main() {
    int nb_possibles;
    int deplacements[4][2];
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int sol_par[TAILLE_MAX_GRILLE][2];
    int succes_chargement;
    int point_entree[2];
    int hauteur_grille;
    int largeur_grille;


     

    printf("\n\n");

    succes_chargement = charger_labyrinthe("grille1.txt", grille, point_entree, &hauteur_grille, &largeur_grille);

    if (!succes_chargement) {

        printf("Une erreur s'est produite lors du chargement de la grille.\n");
        printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");


    } else {
        printf("La grille comporte: %d lignes et %d colonnes\n", hauteur_grille, largeur_grille);
        printf("Le point d'entree se trouve a la coordonn�e (%d, %d)\n", point_entree[0], point_entree[1]);;
    }


    if (grille[0][9] == 1) {
        printf("La case (0,9) est un mur.\n");
    } else {
        printf("La case (0,9) est un couloir.\n");
    }

    if (grille[3][10] == 1) {
        printf("La case (3,10) est un mur.\n");
    } else {
        printf("La case (3,10) est un couloir.\n");
    }

     

    lab_afficher_grille(grille, hauteur_grille, largeur_grille, sol_par);

     
    pile_initialiser(sol_par, TAILLE_MAX_PILE);
    pile_empiler(sol_par, point_entree[0], point_entree[1]);
    pile_empiler(sol_par, point_entree[0], point_entree[1]);
    pile_empiler(sol_par, point_entree[0], point_entree[1]);
    pile_empiler(sol_par, point_entree[0], point_entree[1]);


     

    lab_calculer_deplacements_possibles(grille, hauteur_grille, largeur_grille, point_entree[0], point_entree[1],
                                        sol_par, &nb_possibles, deplacements);
    printf("Le tableau deplacements aura les coordonnees suivantes: \n");
    for (int i = 0; i < nb_possibles; i++) {
        printf("(%d, %d) \n", deplacements[i][0], deplacements[i][1]);
    }
    printf("et le nombre de deplacements possibles aura la valeur: %d\n", nb_possibles);



     

    int choix = lab_choisir_deplacement(deplacements, nb_possibles);
    printf("Le deplacement choisi est: (%d, %d)\n", deplacements[choix][0], deplacements[choix][1]);


     

    int case1[]={1,2};
    int case2[]={2,2};
    if(lab_est_cases_adjacentes(case1, case2))
    {
        printf("Les cases sont adjacentes\n");
    }else
    {
        printf("Les cases ne sont pas adjacentes\n");
    }

     
    int position[2];
    int resultat = lab_est_une_sortie(position, grille, hauteur_grille, largeur_grille);
    if (resultat) {
        printf("La position est une sortie\n");
    } else {
        printf("La position n'est pas une sortie\n");
    }
    return 0;

}



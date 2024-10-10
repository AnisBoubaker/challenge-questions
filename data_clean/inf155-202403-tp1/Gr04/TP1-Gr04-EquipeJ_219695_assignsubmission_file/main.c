

#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "Module_utilitaire.h"

#define TAILLE_MAX_PILE 1000
#define TAILLE_MAX_GRILLE 100

int main(void)
{
    int la_pile[TAILLE_MAX_PILE][2];
    int depile_x;
    int depile_y;

    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int point_entree[2];
    int hauteur_grille, largeur_grille;
    int succes_chargement;

    char nom_fichier[100];
    int grille_chargee = 0;
    int choix = 0;
    int pile_solution;

    srand(time(NULL));

    affiche_titre();

    switch (choix = selection_menu(grille_chargee))
    {
    case 1:
        menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_GRILLE);
        succes_chargement = charger_labyrinthe("grille1.txt", grille, &point_entree, &hauteur_grille, &largeur_grille);
        grille_chargee = succes_chargement;
        if (!succes_chargement)
        {
            printf("Erreur lors du chargement du labyrinthe depuis le fichier.\n");
            printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
            return EXIT_FAILURE;
        }
        break;

    case 2:
        if (!grille_chargee)
        {
            printf("La résolution est indisponible tant que vous n'avez pas chargé un labyrinthe. Veuillez charger un labyrinthe.\n");
        }
        else
        {

            int resolu = lab_resoudre_profondeur(grille, hauteur_grille, largeur_grille, point_entree, &pile_solution, 1);
            if (resolu)
            {
                printf("Bravo! Vous avez résolu le labyrinthe!\n");
            }
            else
            {
                printf("Désolé. Impossible de résoudre le labyrinthe.\n");
            }
        }
        break;

    case 3:
        printf("Au revoir!\n");
        return 0;

    default:
        printf("Choix indisponible. Veuillez saisir à nouveau.\n");
        scanf("%i", &choix);
        break;
    }

    return EXIT_SUCCESS;
}

struct Node
{
    int data;
    struct Node *next;
};

void insert_at_beginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = *head_ref;

    *head_ref = new_node;
}

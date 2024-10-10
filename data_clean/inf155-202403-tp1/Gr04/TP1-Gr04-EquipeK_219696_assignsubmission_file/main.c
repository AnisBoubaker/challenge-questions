

#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

int main(void)
{
    char nom_fichier[TAILLE_MAX_NOM_FICHIER];
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int entree[2];
    int nb_lignes;
    int nb_colonnes;
    int pile_solution[TAILLE_MAX_PILE][2];
    int bien_chargee;
    int choix;

    selection_menu(charger_labyrinthe(nom_fichier, grille, entree, &nb_lignes, &nb_colonnes));

    menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);

    bien_chargee = charger_labyrinthe(nom_fichier, grille, entree, &nb_lignes, &nb_colonnes);

    while (bien_chargee == 0)
    {
        printf("Erreur lors du chargement de la grille.\n");
        system("pause");
        system("cls");
        selection_menu(charger_labyrinthe(nom_fichier, grille, entree, &nb_lignes, &nb_colonnes));
        menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);
        bien_chargee = charger_labyrinthe(nom_fichier, grille, entree, &nb_lignes, &nb_colonnes);
    }

    system("cls");
    printf("Grille chargee avec succes:\n\n");

    lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution);
    system("pause");

    system("cls");

    choix = selection_menu(charger_labyrinthe(nom_fichier, grille, entree, &nb_lignes, &nb_colonnes));

    while (choix != 4)
    {

        vider_pile(pile_solution);

        if (choix == 1)
        {
            menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);
            bien_chargee = charger_labyrinthe(nom_fichier, grille, entree, &nb_lignes, &nb_colonnes);
            system("cls");
            printf("Grille chargee avec succes:\n\n");
            lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution);
        }

        if (choix == 2)
        {
            if (lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, pile_solution, 0) == 1)
            {
                lab_afficher_grille(grille, nb_lignes, nb_colonnes, pile_solution);
            }
        }

        else if (choix == 3)
        {
            lab_resoudre_profondeur(grille, nb_lignes, nb_colonnes, entree, pile_solution, 1);
        }
        system("pause");
        system("cls");
        choix = selection_menu(charger_labyrinthe(nom_fichier, grille, entree, &nb_lignes, &nb_colonnes));
    }

    return EXIT_SUCCESS;
}

struct Node
{
    int data;
    struct Node *next;
};

void print_list(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
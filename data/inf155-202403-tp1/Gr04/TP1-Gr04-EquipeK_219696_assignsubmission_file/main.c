/*
TP2 - Labyrinthe

Ce projet vise à résoudre un labyrinthe en trouvant un chemin qui nous mène vers
la sortie du labyrinthe en partant de son entrée. 

Auteurs: Samy Mekkati, Daniel Atik, Jad Bizri

Date: 2023-11-12

*/

#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


int main(void)
{
    char nom_fichier[TAILLE_MAX_NOM_FICHIER]; //String qui contient le nom du fichier saisie
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Stock la grille choisie
    int entree[2]; //Coordonnees de l'entree de la grille
    int nb_lignes; //Stock le nombre de ligne de la grille
    int nb_colonnes;//Stock le nombre de colonne de la grille
    int pile_solution[TAILLE_MAX_PILE][2]; //Pile qui contient la solution
    int bien_chargee; //Variable qui stock si la grille est bien chargee (1) ou non(0)
    int choix; //Stock le choix fait par l'utilisateur

    //On affiche le menu
    selection_menu(charger_labyrinthe(nom_fichier,grille,entree,&nb_lignes,&nb_colonnes));

    //On demande a l'utilisateur de saisir la grille qu'il souhaite choisir la grille choisie
    menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);

    //Verifie si la grille a bien ete chargee
    bien_chargee =charger_labyrinthe(nom_fichier,grille,entree,&nb_lignes,&nb_colonnes);

    //Tant que l'utilisateur n'a pas choisie une grille existante, affiche un message d'erreur
    //Redemande de choisir une grille
    while (bien_chargee==0)
    {
        printf("Erreur lors du chargement de la grille.\n");
        system("pause");
        system("cls");
        selection_menu(charger_labyrinthe(nom_fichier,grille,entree,&nb_lignes,&nb_colonnes));
        menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);
        bien_chargee = charger_labyrinthe(nom_fichier,grille,entree,&nb_lignes,&nb_colonnes);
    }

    //Confirmation a l'utilisateur que la grille a bien ete chargee
    system("cls");
    printf("Grille chargee avec succes:\n\n");

    //Affiche la grille choisie
    lab_afficher_grille(grille,nb_lignes,nb_colonnes,pile_solution);
	system("pause");

    system("cls");

    //Demande a l'utilisateur de choisir une des 4 options
    choix = selection_menu(charger_labyrinthe(nom_fichier,grille,entree,&nb_lignes,&nb_colonnes));

    //Tant que l'utilisateur n'a pas choisie de quitter le programme (choix = 4)
    while(choix !=4)
    {
        //On vide la pile apres avoir fini de completer le labyrinthe
        vider_pile(pile_solution);

        //Choix 1 : On demande la grille que l'usager souhaite chargé, et si elle a été chargé avec succès.
        if(choix == 1)
        {
            menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);
            bien_chargee = charger_labyrinthe(nom_fichier,grille,entree,&nb_lignes,&nb_colonnes);
            system("cls");
            printf("Grille chargee avec succes:\n\n");
            lab_afficher_grille(grille,nb_lignes,nb_colonnes,pile_solution);
        }

        //Choix 2 : Le labyrinthe chargé par le choix 1 va se résoudre instantanément.
        if (choix == 2)
        {
            if(lab_resoudre_profondeur(grille,nb_lignes,nb_colonnes,entree,pile_solution,0) == 1)
            {
                lab_afficher_grille(grille,nb_lignes,nb_colonnes,pile_solution);
            }
        }

        //Choix 3 : Le labyrinthe chargé par le choix 1 va se résoudre pas par pas.
        else if(choix ==3)
        {
            lab_resoudre_profondeur(grille,nb_lignes,nb_colonnes,entree,pile_solution,1);
        }
        system("pause");
        system("cls");
        choix = selection_menu(charger_labyrinthe(nom_fichier,grille,entree,&nb_lignes,&nb_colonnes));
    }

    return EXIT_SUCCESS;
}

/*
Module: labyrinthe_io

Auteur:

Date:
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAILLE_MAX_GRILLE   100


/***********COMMANDES PR�PROCESSEUR*************/
#include "labyrinthe_io.h"

/*******IMPLEMENTATION DES FONCTIONS***********/


/*	RESUME:

    selection_menu: afficher a l’usager le menu principal et demande de faire choix de grille

             •	faire un choix et cette fonction va dire si le choix est valide ou non
             •	valide : si labyrinthe a bien été chargé et si non errroné
             •	invalide : si il n’y a pas de labyrinthe a utilisé, erroné ou mal chargé
             •	besoin de voir si grille a été chargée ou non
             •	retourne un entier valeur de choix valide donc oui ou non
             •	int selection_menu (int grille_chargee)
*/


/*  Fonction: selection_menu
    Description: Affiche le menu principal et demande a l'usager de saisir un choix. La fonction indique si certains
                 choix sont indisponibles ex: si aucun labyrinthe est charge. La fonction verifie si choix est valide
                 ou non.
    Arguments:
    -grille_chargee: valeur boleene: vrai si grille chargee, faux sinon.
    Retour: choix qui est un entier soit 1 ou 0???
    Parametre modifie: aucun
*/

//est ce que c'est bien les choix qu'on doit avoir??




int selection_menu(int grille_chargee)
    {
        int choix; //Choix que l'usager va prendre au menu principal
        char buf_nom_fichier[TAILLE_MAX_GRILLE]; // Liste de caractere a lire a partir du fichier texte

        //Affichage du menu principal
        printf("\t***********************\n");
        printf("\t***LABYRINTHE EXPERT***\n");
        printf("\t***********************\n");



        if(grille_chargee == 0)
        {
            printf("\t1. Charger un labyrinthe\n");
            printf("\t2. [INDISPONIBLE] Resoudre le labyrinthe\n");
            printf("\t3. [INDISPONIBLE] Resoudre le labyrinthe pas-a-pas\n");
            printf("\t4. Quitter le programme\n");

            printf("\t\n> ");
            scanf("%d", &choix);

            while (choix != 1 && choix != 4)
            {
                printf("\t\nChoix invalide!\n");//je veux loop pour qu'il redemande le choix sans run back
                printf("\t\n> ");
                scanf("%d", &choix);
            }

        }
            if(grille_chargee == 1)
            {
                printf("\t1. Charger un labyrinthe\n");
                printf("\t2. Resoudre le labyrinthe\n");
                printf("\t3. Resoudre le labyrinthe pas-a-pas\n");
                printf("\t4. Quitter le programme\n");

                //Choix de l'usager
                printf("\t\n> ");
                scanf("%d", &choix);


                while (choix < 1 || choix > 4)
                {
                    printf("\t\nChoix invalide!\n");//je veux loop pour qu'il redemande le choix sans run back
                    printf("\t\n> ");
                    scanf("%d", &choix);

                }

            }

                    return choix;
    }



    void menu_charger_labyrinthe(char *buf_nom_fichier, int buf_taille)
    {

        char nom_fichier[buf_taille];

        char directory[4] = "..\\";
        directory[strlen(directory)] = '\0';

        printf("Nom du fichier: ");
        FFLUSH();

        fgets(nom_fichier, TAILLE_MAX_NOM_FICHIER, stdin); //Enregistrer string de la grille choisie
        nom_fichier[strlen(nom_fichier) - 1] = '\0'; //Enlever retour chariot

        if(strlen(nom_fichier)<= buf_taille)
        {
            sprintf(buf_nom_fichier, "%s%s", directory, nom_fichier);
        }

    }

//        if ()
//        {
//
//            if(strlen(directory)+ strlen(nom_fichier) < buf_taille)
//            {
//                strcpy(buf_nom_fichier, directory);
//                strcat(buf_nom_fichier,nom_fichier);
//            }
//
//            else
//            {
//            printf("Erreur lors du chargement de la grille. Appuyer sur une touche pour continuer...");
//            getchar();
//            }
//        }
//        else
//        {
//            printf("Erreur lors du chargement de la grille. Appuyer sur une touche pour continuer...");
//        }
//
//
//    }



    int charger_labyrinthe(char *nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int *hauteur_grille,
                           int *largeur_grille){
        FILE *fichier;
        char caractere_lu;
        int i = 0, //Compteurs d'indices dans le tableau
        j = 0;
        fichier = fopen(nom_fichier, "r");
        if (!fichier) {
            return 0;
        }

        *largeur_grille = -1;
        *hauteur_grille = -1;

        while ((caractere_lu = getc(fichier)) != EOF) {
            switch (caractere_lu) {
                case '*':
                    grille[i][j] = 1;
                    j++;
                    break;
                case ' ':
                    grille[i][j] = 0;
                    j++;
                    break;
                case 'E':
                    grille[i][j] = 2;
                    point_entree[0] = i;
                    point_entree[1] = j;
                    j++;
                    break;
                case '\n':
                    if (*largeur_grille != -1 && *largeur_grille != j) {
                        printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le m�me nombre de colonnes.\n");
                        return 0;
                    }
                    *largeur_grille = j;
                    j = 0;
                    i++;
                    break;
            }
        }
        *hauteur_grille = i + 1;
        fclose(fichier);
        return 1;
    }
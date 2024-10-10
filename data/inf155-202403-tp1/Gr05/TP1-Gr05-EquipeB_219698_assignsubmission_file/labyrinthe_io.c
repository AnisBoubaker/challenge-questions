/*
Module: labyrinthe_io

Auteur: 

Date: 
*/


/***********COMMANDES PR�PROCESSEUR*************/
#include "labyrinthe_io.h"
#include "labyrinthe.h"

/*******IMPLEMENTATION DES FONCTIONS***********/

//Fonction charger labyrinthe
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE],int point_entree[2], int* hauteur_grille, int* largeur_grille)
{
    FILE* fichier;
    char caractere_lu;
    int i = 0, //Compteurs d'indices dans le tableau
    j = 0;
    fichier = fopen(nom_fichier, "r");
    if (!fichier)
    {
        return 0;
    }

    *largeur_grille = -1;
    *hauteur_grille = -1;

    while ((caractere_lu = getc(fichier)) != EOF)
    {
        switch (caractere_lu)
        {
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

//Fonction selection menu
int selection_menu(int grille_chargee)
{
    int selection;//Valeur entier du choix de l'utilisateur
    int depart = 1;//Valeur d'initialisation pour garder la boucle dans une loop infinie

    //Afficher le menu
    printf("                *************************\n");
    printf("                *** LABYRINTHE EXPERT ***\n");
    printf("                *************************\n");
    printf("        1. Charger un labyrinthe\n");


    if(grille_chargee==0)//Si la grille n'est pas chargee on affiche ce menu
    {

        printf("        2. [Indisponible] Resoudre le labyrinthe\n");
        printf("        3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");

    }

    if(grille_chargee==1) //Si la grille est chargee on affiche ce menu
    {
        printf("        2. Resoudre le labyrinthe\n");
        printf("        3. Resoudre le labyrinthe pas-a-pas\n");
    }

    printf("        4. Quitter le programme\n\n");//Va toujours afficher ce texte
    printf("        >");
    scanf("%i", &selection);//Scan la valeur lue et la place dans l'entier selection


    while(depart)//Condition pour garder la boucle dans une loop infini si l'utilisateur saisie une valeur invalide ex 9,8,15 etc
    {

        switch (selection) //Switch case pour decider quoi faire suite a la lecture de la valeur saisie par l'utilisateur (selection)
        {

            case 1 ://Quand selection est egale a 1 nous appelons automatiquement la fonction menu charger labyrinthe

                if (grille_chargee == 0) //Quand la grille n'est pas charger demande le nom du fichier a charger
                {
                    return selection;//retourne la valeur stocke dans selection
                }

                if (grille_chargee == 1) //Quand la grille est charger retourne la valeur de selection
                {
                    return selection;//retourne la valeur stocke dans selection
                }


            case 2 ://Affiche le choix est invalide car nous avons pas charger la grille

                if (grille_chargee == 0) //Quand la grille n'est pas charger il affiche "choix indisponible"
                {
                    printf("choix non disponible\n");//Affiche choix non disponible
                    break;
                }

                if (grille_chargee == 1)//Quand que la grille est charge retourne la valeur stocke dans selections dans ce case 2
                {
                    return selection;
                }


            case 3://Affiche le choix reste invalide car nous navons pas charger de grille
                if (grille_chargee == 0)//Quand la grille n'est charge
                {
                    printf("choix non disponible\n");
                    break;
                }

                if (grille_chargee == 1)//Si la grille est charge retourne la valeur stocke dans selection
                {
                    return selection;
                }
            case 4://retourne la valeur qui est stocke dans saisie

                return selection;

            case '\n'://Si il y a une espace ne fait rien et retourne au debut de la boucle
                break;

            default:
                printf("choix invalide\n");//Affiche choix invalide a tout ce qui ne fait pas parti du case

        }

        if (selection != 1) // Tant que l'on ne charge pas la grille on redemande de saisir un chiffre
        {
            printf(">");
            scanf("%i", &selection);//Scan la valeur dans la console et la place dans l'entier selection

        }

    }

}


void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    printf("Nom du fichier:");
    fflush(stdin);//Flush la valeur qui est dans la console
    fgets(buf_nom_fichier,buf_taille,stdin);//Va lire ce qui est ecrit dans la console et le mets dans la chaine de caratere buf_nom_fichier
}
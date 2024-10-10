/*
Module: labyrinthe_io

Auteur: 

Date: 
*/


/***********COMMANDES PRÉPROCESSEUR*************/
#include "labyrinthe_io.h"


/*******IMPLEMENTATION DES FONCTIONS***********/
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE],
                       int point_entree[2], int* hauteur_grille, int* largeur_grille) {
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
                grille[i][j] = 0;
                point_entree[0] = i;
                point_entree[1] = j;
                j++;
                break;
            case '\n':
                if (*largeur_grille != -1 && *largeur_grille != j) {
                    printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le même nombre de colonnes.\n");
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


int selection_menu(int grille_chargee)
{
    int choix;
    bool choix_ok = false;
    while (!choix_ok)
    {
        printf("1. Charger un labyrinthe\n");
        if(grille_chargee)
        {
            printf("2. Resoudre le labyrinthe\n");
            printf("3. Resoudre le labyrinthe pas-a-pas\n");
        }
        else
        {
            printf("2. [Indisponible] Resoudre le labyrinthe\n");
            printf("3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
        }
        printf("4. Quitter le programme\n");
        scanf("%d", &choix);
        //fflush si la personne ecrit un caractere pour ne pas faire bug
        // le programme, pour les chiffres sa ne change rien
        FFLUSH();
        if (choix>=1 && choix<=4 && grille_chargee)
        {
            choix_ok = true;
        }
        else if(choix==1 || choix==4)
        {
            choix_ok = true;
        }
        else
        {
            printf("Choix Invalide\n\n");
        }
    }
    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    char tmp[TAILLE_MAX_NOM_FICHIER];

    printf("Nom du fichier: ");
    //input pour le nom du fichier
    fgets(buf_nom_fichier,buf_taille,stdin);
    //le fgets inclut le enter a la fin alors il faut l'enlever
    buf_nom_fichier[strlen(buf_nom_fichier)-1]='\0';

    //Pour mettre dans un autre fichier, mettre le filepath entre les guillemets
    //ex ..\\FichierFournis\\ dans ce cas la
//    strcpy(tmp,"..\\FichiersFournis\\"); //Copy ..\FichiersFournis\ dans tmp
//    strcat(tmp,buf_nom_fichier); //fait tmp: ..\FichiersFournis\"buf_nom_fichier"
//    strcpy(buf_nom_fichier,tmp); //Fait que buf_nom_fichier est une copy de tmp
}
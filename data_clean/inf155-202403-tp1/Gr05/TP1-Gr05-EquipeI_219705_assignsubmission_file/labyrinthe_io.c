 


 
#include "labyrinthe_io.h"


 
int charger_labyrinthe(char *nom_fichier, int grille[][TAILLE_MAX_GRILLE],
                       int point_entree[2], int *hauteur_grille, int *largeur_grille)
{
    FILE *fichier;
    char caractere_lu;
    int i = 0,  
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
                grille[i][j] = 0;
                point_entree[0] = i;
                point_entree[1] = j;
                j++;
                break;
            case '\n':
                if (*largeur_grille != -1 && *largeur_grille != j)
                {
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


int selection_menu(int grille_chargee)
{
    int choix;
    int sortie = 0;

     
    printf("*************************\n");
    printf("*** LABYRINTHE EXPERT ***\n");
    printf("*************************\n\n");

    printf("1. Charger un labyrinthe\n");
     
    if (!grille_chargee)
    {
        printf("2. [Indisponible] Resoudre le labyrinthe\n");
        printf("3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
    }
    else
    {
        printf("2. Resoudre le labyrinthe \n");
        printf("3. Resoudre le labyrinthe pas-a-pas \n");
    }
    printf("4. Quitter le programme\n\n");

    do
    {
        printf("> ");
        scanf("%d", &choix);

         
        if (choix < 1 || choix > 4)
            printf("Choix invalide!\n\n");
        else if ((choix == 2 || choix == 3) && !grille_chargee)
            printf("Choix invalide!\n\n");
        else
            sortie = 1;
    }
    while (!sortie);
    return choix;
}


void menu_charger_labyrinthe(char *buf_nom_fichier, int buf_taille)
{
     
    printf("Nom du fichier : ");

     
    fflush(stdin);

     
    fgets(buf_nom_fichier, buf_taille, stdin);
     
    buf_nom_fichier[strlen(buf_nom_fichier) - 1] = '\0';

     
    fflush(stdin);

     
    printf("%s \n", buf_nom_fichier);

     
    if (strlen(buf_nom_fichier) >= buf_taille - 1)
    {
        printf("Erreur : le nom du fichier est trop long.\n");
        system("pause");
    }
}

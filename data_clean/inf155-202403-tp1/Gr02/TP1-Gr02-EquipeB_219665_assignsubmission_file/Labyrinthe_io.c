 


 
#include "labyrinthe_io.h"
#include "labyrinthe.h"
#include "pile.h"
#define TAILLE_NOM_FICHIER 11





 
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int* hauteur_grille, int* largeur_grille)
{
    FILE* fichier;
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

int selection_menu(int grille_chargee)
{
    grille_chargee = 0;
    char nom_fichier[TAILLE_NOM_FICHIER];
    int selection;
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int entree[2];
    int hauteur_grille, largeur_grille;
    int debug;

    int pile_solution[TAILLE_MAX_PILE][2];
    pile_initialiser(pile_solution,TAILLE_MAX_PILE);


        printf("        *************************\n"
               "        *** LABYRINTHE EXPERT ***\n"
               "        *************************\n"
               "\n"
               "1. Charger un labyrinthe\n"
               "2. [Indisponible] Resoudre le labyrinthe\n"
               "3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n"
               "4. Quitter le programme\n\n");
        scanf("%i", &selection);

     
    do
    {
        if (selection == 1)
        {
            menu_charger_labyrinthe(nom_fichier, TAILLE_NOM_FICHIER);
            grille_chargee = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille, &largeur_grille);
            if (grille_chargee == 1)
            {
                 
                LAB_AFFICHER_GRILLE(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");
            }
            else
            {
                 
                printf("%s\n", nom_fichier);
                printf("Erreur lors du chargement de la grille.\n");
                system("pause");
                selection = 0;
            }
        }
        else if (selection == 4)
        {
            return EXIT_SUCCESS;
        }
        else
        {
             
            do
            {
                printf("Choix Invalide!\n\n");
                scanf("%i", &selection);
            }while (selection !=1 && selection !=4);
        }
    }while (grille_chargee == 0);

     
    while (selection != 4)
    {
        printf("        *************************\n"
               "        *** LABYRINTHE EXPERT ***\n"
               "        *************************\n"
               "\n"
               "1. Charger un labyrinthe\n"
               "2. Resoudre le labyrinthe\n"
               "3. Resoudre le labyrinthe pas-a-pas\n"
               "4. Quitter le programme\n\n");
        printf("\n");
        scanf("%i", &selection);

        if (selection == 1)
        {
            menu_charger_labyrinthe(nom_fichier, TAILLE_MAX_NOM_FICHIER);
            grille_chargee = charger_labyrinthe(nom_fichier, grille, entree, &hauteur_grille, &largeur_grille);
            if (grille_chargee == 1)
            {
                 
                 
                pile_initialiser(pile_solution,TAILLE_MAX_PILE);
                LAB_AFFICHER_GRILLE(grille, hauteur_grille, largeur_grille, pile_solution);
                system("pause");
            }
            else
            {
                 
                printf("%s\n", nom_fichier);
                printf("Erreur lors du chargement de la grille.\n");
                system("pause");
                selection = 0;
            }
        }
        else if (selection == 2)
        {
             
            debug = 0;
            LAB_RESOUDRE_PROFONDEUR(grille, hauteur_grille, largeur_grille, entree, pile_solution, debug);
        }
        else if (selection == 3)
        {
             
            debug = 1;
            LAB_RESOUDRE_PROFONDEUR(grille, hauteur_grille, largeur_grille, entree, pile_solution, debug);
        }
        else if (selection == 4)
        {
            return EXIT_SUCCESS;
        }
        else
        {
            do
            {
                 
                printf("Choix Invalide!\n\n");
                scanf("%i", &selection);
            } while (selection > 4 && selection == 0);
        }
    }
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
     
    printf("Nom du fichier: ");
    scanf("%s", buf_nom_fichier);
}

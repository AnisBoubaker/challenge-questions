 


 
#include "labyrinthe_io.h"

 

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

    if (grille_chargee == 0)  
    {
        printf("------------------------- MENU -------------------------\n"
               "1. Charger une grille\n"
               "2. Afficher le labyrinthe(NON DISPONNIBLE)\n"
               "3. Résoudre le labyrinthe (NON DISPONNIBLE)\n"
               "4. Résoudre et afficher le labyrinthe (NON DISPONNIBLE)\n"
               "5. Quitter\n"
               "------------------------- MENU -------------------------\n\n");
        do
        {
            printf("Veuillez saisir votre choix: ");
            scanf("%d", &choix);

             
            if ((choix != 1) && (choix != 5))
            {
                printf("\033[0;31m");
                printf("Erreur - (Referez-vous au menu ci-dessus pour faire votre choix)\n\n");
                printf("\033[0m");
            }

        } while((choix != 1) && (choix != 5)); 
    }

    else if(grille_chargee == 1)  
    {
        printf("\n\n------------------------- MENU -------------------------\n"
               "1. Charger une grille\n"
               "2. Afficher le labyrinthe\n"
               "3. Résoudre le labyrinthe\n"
               "4. Résoudre et afficher le labyrinthe\n"
               "5. Quitter\n"
               "------------------------- MENU -------------------------\n\n");
        do
        {
            printf("Veuillez saisir votre choix: ");
            scanf("%d", &choix);

             
            if (choix < 1 || choix > 5)
            {
                printf("\033[0;31m");
                printf("\nErreur - (Referez-vous au menu ci-dessus pour faire votre choix)\n\n");
                printf("\033[0m");
            }
        } while(choix < 1 || choix > 5);  
    }
    else
        return 0;

    return choix;   
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    printf("Saisir un nom de fichier correspondant au fichier contenant le labyrinthe à charger:\n");
     
    scanf("%s", buf_nom_fichier);

    if (buf_nom_fichier == NULL)
    {
        printf("Mauvaise saisie");
    }
}

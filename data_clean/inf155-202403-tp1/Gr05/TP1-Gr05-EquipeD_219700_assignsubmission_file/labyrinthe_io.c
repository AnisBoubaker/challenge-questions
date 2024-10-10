 


 

#include "labyrinthe.h"
#include <stdio.h>
#include <string.h>


 
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
    char ch;
    int choix=0;  
    int i=1;  
    printf("                      ***********************\n"
                  "                      ** LABYRINTHE EXPERT **\n"
                  "                      ***********************\n\n\n");
    if (grille_chargee)  
    {
        printf("        1. Charger un labyrinthe\n"
                      "        2. Resoudre le labyrinthe\n"
                      "        3. Resoudre le labyrinthe pas-a-pas\n"
                      "        4. Quitter le programme\n\n"
                      "        > ");
    } else  
    {
        printf("        1. Charger un labyrinthe\n"
                      "        2. [Indisponible] Resoudre le labyrinthe\n"
                      "        3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n"
                      "        4. Quitter le programme\n\n"
                      "        > ");
    }


    do {
        scanf("%i",&choix);
        while ((ch = getchar()) != '\n' && ch != EOF);
        if ( (grille_chargee == 1 && choix >= 1 && choix <= 4) || (!grille_chargee && (choix == 1 || choix == 4) ) )  
        {
            i=-1;
        }
        else  
        {
            printf("Choix invalide\n"
                   "        > ");
        }
    } while (i!=-1);
    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{   int i =0;
    printf("Nom du fichier:");
    fgets(buf_nom_fichier, buf_taille, stdin);  
    i = strlen(buf_nom_fichier);
    buf_nom_fichier[i-1] = '\0';  


}
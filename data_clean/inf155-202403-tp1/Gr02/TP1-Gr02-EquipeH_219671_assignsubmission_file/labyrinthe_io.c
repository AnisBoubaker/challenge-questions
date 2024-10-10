 


 
#include "labyrinthe_io.h"
#include "labyrinthe.h"
#include "utilitaires.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FFLUSH() do{} while (getchar()!='\n')



 
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
				printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le meme nombre de colonnes.\n");
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
    laby_expert();
    int saisie;

    if(!grille_chargee)  
    {
        printf("     1. Charger un labyrinthe\n");
        printf("     2. [Indisponible] Resoudre le labyrinthe\n");
        printf("     3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
        printf("     4. Quitter le programme\n");
        do
        {
            printf("> ");
            scanf(" %i", &saisie);
        } while (saisie != 1 && saisie != 4);  
    }
    else  
    {
        printf("     1. Charger un labyrinthe\n");
        printf("     2. Resoudre le labyrinthe\n");
        printf("     3. Resoudre le labyrinthe pas-a-pas\n");
        printf("     4. Quitter le programme\n");
        printf("> ");
        scanf("  %i", &saisie);
    }
    return saisie;  
}


void menu_charger_labyrinthe(char* buf_nom_fichier,int buf_taille)
{

    printf("Saisir nom de fichier :");
    FFLUSH();
    fgets(buf_nom_fichier,buf_taille,stdin);  
    for(int i=0;i<strlen(buf_nom_fichier);i++)
    {
        if(buf_nom_fichier[i]=='\n')
        {
            buf_nom_fichier[i]='\0';  
        }
    }
}


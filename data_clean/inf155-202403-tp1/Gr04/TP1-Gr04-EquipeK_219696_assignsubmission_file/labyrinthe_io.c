 


 
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

     

    printf("\t\t*************************\n");
    printf("\t\t*** LABYRINTHE EXPERT ***\n");
    printf("\t\t*************************\n\n");
    printf("\t1. Charger un labyrinthe\n");

     
     
    if (grille_chargee == 0)
    {
        printf("\t2. [Indisponible] Resoudre le labyrinthe\n"
               "\t3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n"
               "\t4. Quitter le programme\n");

        scanf("%i", &choix);

         
         
        while(choix != 1 && choix != 4)
        {
            printf("Choix Invalide !\n");
            scanf("%i", &choix);
        }

         
        if (choix==4)
        {
            exit(0);
        }
    }

         
         
    else
    {
        printf("\t2. Resoudre le labyrinthe\n"
               "\t3. Resoudre le labyrinthe pas-a-pas\n"
               "\t4. Quitter le programme\n");
        scanf("%i", &choix);

         
        if (choix==4)
        {
            exit(0);
        }
    }
     
    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{

    char prefixe_grille[buf_taille];  
    char nom_grille[buf_taille];  


     
    strncpy(prefixe_grille, "../",buf_taille);

     
    printf("\n Nom de fichier : ");
    scanf("%s", nom_grille);

     
     
    strncat(prefixe_grille,nom_grille,buf_taille);
    strncpy(buf_nom_fichier,prefixe_grille,buf_taille);
}


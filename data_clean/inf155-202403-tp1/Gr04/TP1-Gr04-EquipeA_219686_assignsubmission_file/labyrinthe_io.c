 

 
#include "labyrinthe_io.h"
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

			    if (*largeur_grille != -1 && *largeur_grille != j)
                {

				        printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le mï¿½me nombre de colonnes.\n");
				        return 0;
                }
			    *largeur_grille = j;
			    j = 0;
			    i ++;
			    break;
		    }
    }
	*hauteur_grille = i + 1;
	fclose(fichier);
	return 1;
}

 
int selection_menu(int grille_chargee)
{

    do
    {
         
        printf("MENU\n");
        printf("Veuillez choisir l'une des 4 grilles suivantes: \n");
        printf("1- Grille 1:\n");
        printf("2- Grille 2:\n");
        printf("3- Grille 3:\n");
        printf("4- Grille 4:\n");

         
        scanf("%i", &grille_chargee);

         
        switch (grille_chargee)
        {
            case '1':
                printf("Vous avez selectionne la grille 1:\n");
                break;

            case '2':
                printf("Vous avez selectionne la grille 2.\n");
                break;

            case '3':
                printf("Vous avez selectionne la grille 3.\n");
                break;

            case '4':
                printf("Vous avez selectionne la grille 4.\n");
                break;

            default:
                printf("Le choix est invalide.");
                break;

        }

    } while(grille_chargee<0 && grille_chargee>5);

    return grille_chargee;
}

 
void menu_charger_labyrinthe (char* buf_nom_fichier, int buf_taille)
{
    printf("Entrez le nom de fichier correspondant au fichier contenant le labyrinthe a charger: ");

    fgets(buf_nom_fichier,buf_taille,stdin);

    int nb_chars= strlen(buf_nom_fichier);

    if(buf_nom_fichier[nb_chars-1]=='\n')
    { 

        buf_nom_fichier[nb_chars-1]='\0';
    }
}
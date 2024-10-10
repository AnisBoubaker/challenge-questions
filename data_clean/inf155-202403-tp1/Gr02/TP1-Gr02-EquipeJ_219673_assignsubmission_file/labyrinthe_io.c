 


 
#include "labyrinthe_io.h"
#include "labyrinthe.h"



 
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

int selection_menu(int grille_chargee) {
 
    int exit_var = 0;
    int res_lab = 0;
    int res_stp_by_stp_lab = 0;
    int choix;


    do {
         
        printf("\n--- Menu Principal ---\n");
        printf("1. Charger labyrinthe\n");
        printf("2. %sResoudre le labyrinthe\n", grille_chargee ? "" : "[Indisponible] ");
        printf("3. %sResoudre le labyrinthe pas a pas\n", grille_chargee ? "" : "[Indisponible] ");
        printf("4. Quitter le programme\n");
        printf("Veuillez choisir une option (entrer un chiffre): ");
        scanf("%i", &choix);

         
        if (choix == 1) {
            char buf_nom_fichier[12];
            fgets(buf_nom_fichier,12, stdin);
            buf_nom_fichier[ strlen(buf_nom_fichier) - 1 ] = '\0';
            res_lab += 1;
            res_stp_by_stp_lab += 1;
            exit_var++;

        } 
        if (choix == 2 && grille_chargee) {
            exit_var++;
            return choix;
        } 
        if (choix == 3 && grille_chargee) {
            exit_var++;
            return choix;
        }
         
        if (choix == 2 && !grille_chargee) {
            printf("Invalide");
        } 
        if (choix == 3 && !grille_chargee) {
            printf("Invalide");
        }

         
        if (choix == 4) {
            printf("Merci d'avoir utiliser le programme de résolution de labyrinthe");
            exit_var++;
            return choix;
        }
          
        if (choix > 4 || choix <= 0) {
            printf("Erreur lors de la saisie du message");
        }
    } while (!exit_var);
    return choix;
}





void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
    {
     
        printf("Saisir le fichier du labyrinthe:");
        fgets(buf_nom_fichier, buf_taille, stdin);
        buf_nom_fichier[ strlen(buf_nom_fichier) - 1 ] = '\0';
    }


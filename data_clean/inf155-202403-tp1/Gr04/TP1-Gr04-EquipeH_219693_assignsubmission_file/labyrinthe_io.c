 


 
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
        printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
        system("pause");
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
                system("pause");
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

    int choix = 0;  

    system("cls");  

     
    printf("\033[0;31m");  
    printf("\t\t****\033[0m*****************\033[0;31m****\n\t\t*** "
           "\033[0;41mLABYRINTHE EXPERT"
           "\033[0;31m ***\n\t\t****\033[0m*****************\033[0;31m****\n");
    printf("\033[0m");  

     
    printf("\t1. Charger un labyrinthe\n");
     
    if(grille_chargee == 0) {
        printf("\t2. [Indisponible] Resoudre le labyrinthe \n\t3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
    }
    else{
        printf("\t2. Resoudre le labyrinthe \n\t3. Resoudre le labyrinthe pas-a-pas\n");
    }
    printf("\t4. Quitter le programme\n");

     
    do {
        printf("\t>");
        scanf("%d", &choix);
         
        if(grille_chargee == 0) {
            if(choix == 2 || choix == 3) {
                choix = 0;
            }
        }
         
        if(choix != 1 && choix != 2 && choix != 3 && choix != 4) {
            printf("Choix Invalide!\n");
        }
     
    } while(choix != 1 && choix != 2 && choix != 3 && choix != 4);
     
    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille) {

     
    char fin_grille[TAILLE_MAX_NOM_FICHIER];

     
    strncpy(buf_nom_fichier, "../", TAILLE_MAX_NOM_FICHIER);

     
    printf("Nom du ficher :");
     
    scanf("%s", fin_grille);
     
    strncat(buf_nom_fichier, fin_grille, TAILLE_MAX_NOM_FICHIER);

}
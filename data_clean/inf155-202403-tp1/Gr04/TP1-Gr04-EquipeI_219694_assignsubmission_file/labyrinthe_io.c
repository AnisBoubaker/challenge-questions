 


 
#include "labyrinthe_io.h"



 
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int* hauteur_grille, int* largeur_grille)
{
	FILE * fichier;
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
    printf("                            **************************\n");
    printf("                            ** LABYRINTHE EXPERT ***\n");
    printf("                            **************************\n");

    printf("Menu principale\n\n");
    printf("    1.Charger un labyrinthe depuis le disque\n");
    printf("    2.Resoudre le labyrinthe\n");
    printf("    3.Quittez\n\n");
    printf("Veuillez saisir un choix: \n");
    scanf("%d",&choix);
    if(!grille_chargee)
    {
        printf("erronne ou non disponible... Veuillez charger un labyrinthe avant de pouvoir le resoudre\n");
    }
    while (choix<1 || choix>3 || (!grille_chargee && choix==2))
    {
        printf("le choix est invalide... Veuillez saisir un choix valide: \n");
        scanf("%d",&choix);
    }
    return choix;
}
void menu_charger_labyrinthe(char* buf_nom_ficher, int buf_taille)
{
    printf("Veuillez saisir le nom du ficher du labyrinthe a charger: \n");
    fgets(buf_nom_ficher,buf_taille,stdin);

    if(fgets(buf_nom_ficher,buf_taille,stdin)==NULL)
    {
        fprintf(stderr,"Erreur lors de la saisie du fichier.\n");
        exit(EXIT_FAILURE);
    }
    size_t longeur = strlen(buf_nom_ficher);
    if(longeur>0 && buf_nom_ficher[longeur-1]== '\n')
    {
        buf_nom_ficher[strlen(buf_nom_ficher)-1]='\0';
    }
}
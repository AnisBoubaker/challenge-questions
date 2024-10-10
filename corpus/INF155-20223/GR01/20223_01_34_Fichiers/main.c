

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	FILE* mon_fichier; 
	char ligne_lue[1000];

	mon_fichier = fopen("fichier_texte.txt", "r");
	if (mon_fichier == NULL)
	{
		printf("Erreur d'ouverture du fichier!\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	char* resultat_lecture;
	do
	{
		resultat_lecture = fgets(ligne_lue, 1000, mon_fichier);
		if (resultat_lecture != NULL)
		{
			printf("%s", ligne_lue);
		}
	} while (resultat_lecture != NULL);

	fclose(mon_fichier);


	mon_fichier = fopen("data.txt", "r");
	if (mon_fichier == NULL)
	{
		printf("Erreur d'ouverture du fichier!\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	int entier1, ewntier2;
	double reel1, reel2, reel3, reel4;
 
	while (fscanf(mon_fichier, "%d %lf %lf", &entier1, &reel1, &reel2) != -1)
	{
		printf("Ligne lue: %d %.2lf %.2lf\n", entier1, reel1, reel2);
	}

	fclose(mon_fichier);


	mon_fichier = fopen("..\\mon_fichier_a_moi.txt", "w");
	if (mon_fichier == NULL)
	{
		printf("Erreur d'ouverture du fichier!\n");
		system("pause");
		exit(EXIT_FAILURE);
	}

	int jour = 9;
	char mois[] = "Décembre";
	int annee = 2022;
	fprintf(mon_fichier, "Bonjour nous somme le %d ieme jour du mois de %s de l'an %d\n",
		jour, mois, annee);

	fclose(mon_fichier);


	system("pause");
	return EXIT_SUCCESS;
}
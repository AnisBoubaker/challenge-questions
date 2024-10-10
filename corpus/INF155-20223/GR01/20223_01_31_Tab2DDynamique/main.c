
#include <stdio.h>
#include <stdlib.h>


int** creer_tab2d_int(int nb_lignes, int nb_colonnes);

int main(void)
{
	int nb_lignes = 4; 
	int nb_colonnes = 5;

	int** tab; //Tableau à 2D d'entiers

	tab = creer_tab2d_int(4, 5);

	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			tab[i][j] = i + j * 10;
		}
	}

	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			printf("%d\t", tab[i][j]);
		}
		printf("\n");
	}


	system("pause");
	return EXIT_SUCCESS;
}


int** creer_tab2d_int(int nb_lignes, int nb_colonnes)
{
	int** tab;
	tab = (int**)malloc(sizeof(int*) * nb_lignes);
	if (tab == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < nb_lignes; i++)
	{
		tab[i] = (int*)malloc(sizeof(int) * nb_colonnes);
		if (tab[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(tab[j]);
			}
			free(tab);
			return NULL;
		}
	}

	return tab;
}
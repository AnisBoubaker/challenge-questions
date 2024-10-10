
#include "mod_tab2d.h"


void afficher_tab2d(const double tab[][NB_MAX_COLONNES],
	int nb_lignes, int nb_colonnes)
{

	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			printf("%.2lf\t", tab[i][j]);
		}
		printf("\n");
	}
}

void convertir_fahreneith(double temps[][NB_MAX_COLONNES],
	int nb_lignes, int nb_colonnes
)
{
	for (int i = 0; i < nb_lignes; i++)
	{
		for (int j = 0; j < nb_colonnes; j++)
		{
			temps[i][j] = temps[i][j] * 1.8 + 32;
		}
	}
}
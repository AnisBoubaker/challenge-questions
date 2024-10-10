
#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 100


void afficher_tab(int tab[], int taille);
void tri_insertion(int tab[], int taille);
void tri_selection(int tab[], int taille);
double mediane_tab(const int tab[], int taille);


int main(void)
{
	int mon_tableau1[TAILLE_MAX] = { 44, 10, 20, 55, 10, 24, 35 };
	int mon_tableau2[TAILLE_MAX] = { 44, 10, 20, 55, 10, 24, 35 };
	int mon_tableau3[TAILLE_MAX] = { 44, 10, 20, 55, 10, 24, 35 };
	int mon_tableau4[TAILLE_MAX] = { 44, 10, 20, 55, 10, 24, 35, 17 };

	printf("Avant le tri: \n");
	afficher_tab(mon_tableau1, 7);

	tri_insertion(mon_tableau1, 7);

	printf("Apres le tri insertion: \n");
	afficher_tab(mon_tableau1, 7);

	printf("Apres le tri selection: \n");
	tri_selection(mon_tableau2, 7);
	afficher_tab(mon_tableau2, 7);

	printf("La mediane de tab3: %.2lf\n", mediane_tab(mon_tableau3, 7));

	printf("La mediane de tab4: %.2lf\n", mediane_tab(mon_tableau4, 8));

	tri_insertion(mon_tableau4, 8);
	afficher_tab(mon_tableau4, 8);

	system("pause");
	return 0;
}

void afficher_tab(int tab[], int taille)
{
	for (int i = 0; i < taille; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}


void tri_insertion(int tab[], int taille)
{
	int i, j, x;

	for (i = 1; i < taille; i++)
	{
		x = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > x)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = x;
	}
}

void tri_selection(int tab[], int taille)
{
	int indice_min;
	for (int i = 0; i < taille; i++)
	{
		indice_min = i;
		for (int j = i + 1; j < taille; j++)
		{
			if (tab[j] < tab[indice_min])
			{
				indice_min = j;
			}
		}
		if (indice_min != i)
		{
			int copie = tab[indice_min];
			tab[indice_min] = tab[i];
			tab[i] = copie; 
		}
	}
}


/*

Écrire la fonction mediane_tab qui calcule la médiane
d'un tableau d'entiers. 

double mediane_tab(const int tab[], int taille);

*/
double mediane_tab(const int tab[], int taille)
{
	int copie[TAILLE_MAX];
	double mediane; 

	//On crée une copie du tableau pour pouvoir le trier (car const)
	for (int i = 0; i < taille; i++)
	{
		copie[i] = tab[i];
	}

	tri_selection(copie, taille);

	if (taille % 2 != 0)
	{
		mediane = copie[taille / 2];
	}
	else
	{
		mediane = (copie[taille / 2] + copie[taille / 2 - 1]) / 2.0;
	}
	return mediane;
}
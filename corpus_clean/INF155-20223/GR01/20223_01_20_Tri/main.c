
#include <stdio.h>
#include <stdlib.h>

void afficher_tab(int tab[], int taille);
void tri_insertion(int tab[], int taille);

int main(void)
{
	int mon_tableau[] = { 44, 10, 20, 55, 10, 24, 35 };

	printf("Avant le tri: \n");
	afficher_tab(mon_tableau, 7);

	tri_insertion(mon_tableau, 7);

	printf("Apres le tri: \n");
	afficher_tab(mon_tableau, 7);

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
		while (j > 0 && tab[j - 1] < x)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = x;
	}
}

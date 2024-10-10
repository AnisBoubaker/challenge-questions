/*
Écrire la fonction `trouver_val` qui identifie la position (indice)
d'une valeur 'val' dans un tableau tab d'entiers.

La fonction doit retourner une valeur vraie si la valeur `val` est
dans le tableau ou fausse sinon. De plus, la position doit être
fournie par référence (pointeur).

Si la valeur se trouve plus d'une fois dans le tableau, la fonction
doit retourner la position de la première occurence.
*/

#include <stdio.h>
#include <stdlib.h>


int trouver_val(int tab[], int taille, int val, int* position);

int main(void)
{
	//Initialise le tableau avec les valeur précisées et 0 dans le reste
	int tab[100] = {12, 15, 17, 22, 15, 11};
	//Initialise tout le tableau avec des 0.
	int tab2[50] = { 0 };
	//Le tableau aura automatiquement une taille maximale de 8
	int tab3[] = { 10, 20 , 30 , 40, 50, 60, 70, 80 };

	int la_position; 

	if ( trouver_val(tab, 6, 15, &la_position) )
	{
		printf("La valeur a ete trouvee a la position %d\n", la_position);
	}
	else
	{
		printf("La valeur ne se trouve pas dans le tableau.\n");
	}
	system("pause");
	return EXIT_SUCCESS;
	/*tab[0] = 12;
	tab[1] = 15;
	tab[2] = 17;
	tab[3] = 22;
	tab[4] = 11;*/
}

int trouver_val(int tab[], int taille, int val, int* position)
{
	int pos = 0;  //Compteur de position dans la boucle

	while (tab[pos] != val && pos < taille)
	{
		pos++;
	}
	/*
	Deux cas de figure:
	- Soit on a trouvé la valeur, pos<taille
	- Soit la valeur est introuvable, pos = taille
	*/
	if (tab[pos] == val)
	{
		*position = pos;
		return 1;
	}
	return 0;
}
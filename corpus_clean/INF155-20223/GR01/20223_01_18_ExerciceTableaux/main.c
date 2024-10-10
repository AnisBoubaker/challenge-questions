 

#include <stdio.h>
#include <stdlib.h>


int trouver_val(int tab[], int taille, int val, int* position);

int main(void)
{
	 
	int tab[100] = {12, 15, 17, 22, 15, 11};
	 
	int tab2[50] = { 0 };
	 
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
	 
}

int trouver_val(int tab[], int taille, int val, int* position)
{
	int pos = 0;   

	while (tab[pos] != val && pos < taille)
	{
		pos++;
	}
	 
	if (tab[pos] == val)
	{
		*position = pos;
		return 1;
	}
	return 0;
}
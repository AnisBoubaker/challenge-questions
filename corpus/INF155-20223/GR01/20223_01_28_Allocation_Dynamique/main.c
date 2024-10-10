
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a; 
	int* entier_alloue;
	int* foo;
	int nb_valeurs; 
	int* copie_adresse; 

	//printf("La variable a est sur %d octets\n", sizeof(int));

	entier_alloue = (int*)malloc(sizeof(int));
	*entier_alloue = 10;
	printf("La valeur stockee dans l'entier alloue: %d\n", *entier_alloue);

	printf("Combien de valeurs du veux? ");
	scanf("%d", &nb_valeurs);

	foo = (int*)malloc(sizeof(int) * nb_valeurs);
	/*
	*(foo + 0) = 25;
	*(foo + 1) = 120;
	*(foo + 2) = 250;
	*/
	foo[0] = 25;
	foo[1] = 120;
	foo[2] = 250;

	for (int i = 0; i < 3; i++)
	{
		printf("contenu de la case %d: %d\n", i, foo[i]);
	}

	copie_adresse = foo;
	copie_adresse[1] = 45;

	//IMPORTANT: Libérer l'espace alloué avant de perdre l'adresse qui nous y menait
	//Sinon l'espace devient un espace inutilisable (fuite de mémoire)
	free(foo);

	foo = (int*)malloc(sizeof(int));

	*foo = 150;

	system("pause");
	return 0;
}
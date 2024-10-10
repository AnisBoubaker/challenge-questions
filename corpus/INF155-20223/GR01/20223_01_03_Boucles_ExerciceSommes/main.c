/*
Écrire un programme qui demande à l'usager une valeur n.

Votre programme doit calculer et afficher la somme de tous les entiers
entre 1 et n. 

Exemple: 
Saisir une valeur pour n: 3
La somme des entiers entre 1 et 3 est: 6

Exemple:
Saisir une valeur pour n: 100
La somme des entiers entre 1 et 100 est: 5050

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n; //Borne maximale pour la somme des entier 
	int compteur; 
	int resultat = 0; 

	printf("Saisir la valeur de n: ");
	scanf("%d", &n);

	compteur = 1; 
	resultat = 0;
	while (compteur <= n)
	{
		resultat = resultat + compteur; 
		compteur++;
	}

	printf("La somme des valeurs entre 1 et %d est: %d\n", n, resultat);

	system("pause");
	return EXIT_SUCCESS;
}
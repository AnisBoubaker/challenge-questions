
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100

int main(void)
{
	//char salutation[8] = { 'B', 'o', 'n', 'j', 'o', 'u', 'r' };
	char salutation[TAILLE_MAX] = "Bonjour";
	char prenom[TAILLE_MAX];
	char copie_prenom[TAILLE_MAX];
	char nom[TAILLE_MAX];
	char nom_et_prenom[TAILLE_MAX];
	char prenom2[TAILLE_MAX];

	printf("%s\n", salutation);

	printf("Veuillez saisir votre prenom: ");
	//Pas de & (esperluette): un tableau c'est une adresse!
	//scanf("%s", prenom);
	//Le scanf ne lit pas les espaces, on utilise fgets à la place
	fgets(prenom, TAILLE_MAX, stdin);
	prenom[ strlen(prenom) - 1 ] = '\0';

	printf("Veuillez saisir votre nom: ");
	//Pas de & (esperluette): un tableau c'est une adresse!
	//scanf("%s", prenom);
	//Le scanf ne lit pas les espaces, on utilise fgets à la place
	fgets(nom, TAILLE_MAX, stdin);
	nom[strlen(nom) - 1] = '\0';


	printf("%s %s\n", salutation, prenom);


	//salutation = "Bonsoir";
	//ALERT: NE JAMAIS FAIRE CECI: 
	//copie_prenom = prenom;
	//On utilise strcpy
	strncpy(copie_prenom, prenom, TAILLE_MAX);
	printf("La copie du prenom: %s\n", copie_prenom);

	strcpy(salutation , "Bonsoir");
	printf("%s %s\n", salutation, prenom);

	//nom_et_prenom[0] = '\0';
	strcpy(nom_et_prenom, prenom);
	strcat(nom_et_prenom, " ");
	strcat(nom_et_prenom, nom);

	printf("Nom complet: %s\n", nom_et_prenom);

	printf("Veuillez saisir un 2e prenom: ");
	fgets(prenom2, TAILLE_MAX, stdin);
	prenom2[strlen(prenom2) - 1] = '\0';

	//On ne compare jamais les chaines de caractère avec ==
	int comparaison = strcmp(prenom, prenom2);
	if ( comparaison == 0 )
	{
		printf("Les deux prenoms sont identiques!\n");
	}
	else if(comparaison > 0 )
	{
		printf("Le 1er prenom est plus grand.!\n");
	}
	else
	{
		printf("Le 2e prenom est plus grand.!\n");
	}


	system("pause");
	return 0;
}
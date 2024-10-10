
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100

int main(void)
{
	 
	char salutation[TAILLE_MAX] = "Bonjour";
	char prenom[TAILLE_MAX];
	char copie_prenom[TAILLE_MAX];
	char nom[TAILLE_MAX];
	char nom_et_prenom[TAILLE_MAX];
	char prenom2[TAILLE_MAX];

	printf("%s\n", salutation);

	printf("Veuillez saisir votre prenom: ");
	 
	 
	 
	fgets(prenom, TAILLE_MAX, stdin);
	prenom[ strlen(prenom) - 1 ] = '\0';

	printf("Veuillez saisir votre nom: ");
	 
	 
	 
	fgets(nom, TAILLE_MAX, stdin);
	nom[strlen(nom) - 1] = '\0';


	printf("%s %s\n", salutation, prenom);


	 
	 
	 
	 
	strncpy(copie_prenom, prenom, TAILLE_MAX);
	printf("La copie du prenom: %s\n", copie_prenom);

	strcpy(salutation , "Bonsoir");
	printf("%s %s\n", salutation, prenom);

	 
	strcpy(nom_et_prenom, prenom);
	strcat(nom_et_prenom, " ");
	strcat(nom_et_prenom, nom);

	printf("Nom complet: %s\n", nom_et_prenom);

	printf("Veuillez saisir un 2e prenom: ");
	fgets(prenom2, TAILLE_MAX, stdin);
	prenom2[strlen(prenom2) - 1] = '\0';

	 
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
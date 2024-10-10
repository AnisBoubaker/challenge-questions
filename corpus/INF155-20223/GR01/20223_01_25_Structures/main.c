

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX_NOM 100
#define TAILLE_MAX_CPERM 15
#define NB_MAX_ETUDIANTS 40

typedef struct etudiant
{
	char nom[TAILLE_MAX_NOM];
	char prenom[TAILLE_MAX_NOM];
	char code_perm[TAILLE_MAX_CPERM];
	double tp1; 
	double tp2; 
	double intra; 
	double finale;
} t_etudiant;

//typedef struct etudiant t_etudiant;


/*
Déclarations de fonctions
*/
void etudiant_afficher(const t_etudiant* et);
void etudiant_saisir(t_etudiant* et);

int main(void)
{
	t_etudiant marie;
	t_etudiant jean; 
	struct etudiant marc;

	printf("l'étudiante marie consomme %d octets.\n", sizeof(marie));

	/*strcpy(marie.prenom, "Marie");
	strcpy(marie.nom, "Lafortune");
	strcpy(marie.code_perm, "LAFM19991023");
	marie.tp1 = 80;
	marie.tp2 = 95; 
	marie.intra = 90;
	marie.finale = 87;*/

	etudiant_saisir(&marie);

	/*printf("**** FICHE DE L'ETUDIANT-E ****\n");
	printf("Nom: %s\n", marie.nom);
	printf("Prenom: %s\n", marie.prenom);
	printf("Code permanent: %s\n", marie.code_perm);
	printf("TP1: %lf\n", marie.tp1);
	printf("TP2: %lf\n", marie.tp2);
	printf("Intra: %lf\n", marie.intra);
	printf("Final: %lf\n", marie.finale);*/

	etudiant_afficher(&marie);

	printf("La note du finale: %.2lf\n", marie.finale);


	jean.tp1 = 10; 

	system("pause");
	return EXIT_SUCCESS;
}


void etudiant_afficher(const t_etudiant* et)
{
	printf("**** FICHE DE L'ETUDIANT-E ****\n");
	printf("Nom: %s\n", et->nom);
	printf("Prenom: %s\n", et->prenom  );
	printf("Code permanent: %s\n", et->code_perm);
	printf("TP1: %lf\n", et->tp1);
	printf("TP2: %lf\n", (*et).tp2);
	printf("Intra: %lf\n", (*et).intra);
	printf("Final: %lf\n", (*et).finale);
	//Plus possible en raison du const
	//(*et).finale = 0;
}


/*
Écrire la fonction etudiant_saisir qui demande à l'usager de
saisir la valeur de tous les champa d'un étudiant reçu en 
paramètre.
*/

void etudiant_saisir(t_etudiant* et)
{
	printf("Nom: ");
	fgets(et->nom, TAILLE_MAX_NOM, stdin);
	et->nom[strlen(et->nom) - 1] = '\0';

	printf("Prenom: ");
	fgets(et->prenom, TAILLE_MAX_NOM, stdin);
	et->prenom[strlen(et->prenom) - 1] = '\0';

	printf("Code Perm.: ");
	fgets(et->code_perm, TAILLE_MAX_CPERM, stdin);
	et->code_perm[strlen(et->code_perm) - 1] = '\0';

	printf("TP1: ");
	scanf("%lf", &(et->tp1));
	printf("TP2: ");
	scanf("%lf", &(et->tp2));
	printf("Intra: ");
	scanf("%lf", &(et->intra));
	printf("Final: ");
	scanf("%lf", &(et->finale));
}
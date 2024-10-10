/****************************************************************************************

Auteur(e) :

	Ecrire description ici

*****************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/

#define EXEMPLE_0 0
#define EXEMPLE_1 0
#define EXEMPLE_2 0
#define EXEMPLE_3 0
#define EXEMPLE_4 0
#define EXEMPLE_5 1
#define EXEMPLE_6 0

/****************************************************************************************
*                           DEFINTION DU PROGRAMME PRINCIPALE                           *
****************************************************************************************/

#if EXEMPLE_0

	/* ESPACE BROUILLON */

	int main(void)
	{

		printf("EXEMPLE_0 = %i\n", EXEMPLE_0);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_1

	/*

		Types, limites, déclaration, affectation et affichage de base. Macro-constantes
		et macro-fonctions.

	*/

	#include <limits.h> /* UINT_MAX, INT_MIN/MAX, CHAR_MIN/MAX */
	#include <float.h>  /* DBL_MIN/MAX */

	#define CHAR_SAUT_LIGNE "\n"
	#define SAUTER_2_LIGNES {printf(CHAR_SAUT_LIGNE);\
						     printf(CHAR_SAUT_LIGNE);}

	int main(void)
	{

		/* declarations pures */
		int un_entier_signe;
		unsigned int un_entier_non_signe;
		double un_reel;
		char un_caractere;

		/* Affectations simples + transtypage */
		un_entier_signe = -1;
		un_entier_non_signe = 125;
		un_reel = 1.25;
		un_caractere = 'a';

		/*
		int un_entier_signe = -1;
		unsigned int un_entier_non_signe = 1;
		double un_reel = (double)2/3;
		char un_caractere = 'a';
		*/

		/* Affichages simple */
		printf("AFFICHAGES SIMPLES\n\n");
		printf("\tun_entier_signe     = %i\n", un_entier_signe);
		printf("\tun_entier_non_signe = %u\n", un_entier_non_signe);
		printf("\tun_reel             = %.2f\n", un_reel);
		printf("\tun_caractere        = %c\n", un_caractere);

		SAUTER_2_LIGNES

		/* Limites <limits.h> et <float.h> */
		printf("LIMITES\n\n");
		printf("\tunsigned int -> [          0,   %u]\n", UINT_MAX);
		printf("\tint          -> [%10i,  %11i]\n", INT_MIN, INT_MAX);
		printf("\tdouble       -> [%.4e, %.5e]\n", DBL_MIN, DBL_MAX);
		printf("\tchar         -> [%11i, %12i] -> [%c, %c]\n", CHAR_MIN, CHAR_MAX, CHAR_MIN, CHAR_MAX);

		SAUTER_2_LIGNES

		/* Conversions implicites */
		printf("CONVERSIONS IMPLICITES\n\n");
		printf("\t2/3    = %.2f\n", 2 / 3);
		printf("\t2/3.0 =  %.2f\n", 2 / 3.0);

		SAUTER_2_LIGNES

		/* Conversions explicites */
		printf("CONVERSIONS EXPLICITES\n\n");
		printf("\t(double)2/3 = %.2f\n", (double)2 / 3);

		SAUTER_2_LIGNES

		/* Pertes de donnees */
		printf("PERTES DE DONNEES\n\n");
		double double_max = DBL_MAX;
		float float_double_max = (float)double_max;
		printf("\tdouble_max        = %.5e\n", double_max);
		printf("\t(float)double_max = %.5e\n", float_double_max);

		SAUTER_2_LIGNES

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_2

	/*

		Assignations composées et opérateurs d'incrémentation et de décrémentation.

	*/

	int main(void)
	{

		/* Assignations composees */
		int un_entier = 1;
		printf("ASSIGNATIONS COMPOSEES\n\n");
		printf("\t      un_entier = %i\n", un_entier);
		un_entier += 4;
		printf("\t(+ 4) un_entier = %i\n", un_entier);
		un_entier -= 3;
		printf("\t(- 3) un_entier = %i\n", un_entier);
		un_entier *= 2;
		printf("\t(%c 2) un_entier = %i\n", (char)158, un_entier);
		un_entier /= 4;
		printf("\t(%c 4) un_entier = %i\n\n", (char)246, un_entier);

		/* Pre- et post- incrementation et decrementation */
		int une_valeur = 0;
		printf("PRE- POST INCREMENTATION (++) ET DECREMENTATION (--)\n\n");
		printf("\t(AVANT) une_valeur++ = %i\n", une_valeur++);
		printf("\t(APRES) une_valeur   = %i\n", une_valeur);
		printf("\t(AVANT) ++une_valeur = %i\n", ++une_valeur);
		printf("\t(APRES) une_valeur   = %i\n\n", une_valeur);

		/* Cas interessant */
		char c = 'c';
		printf("CAS INTERESSANT\n\n");
		printf("\t\'c\'++ = %c\n\n", ++c);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_3

	/*

		Operateurs non triviaux : logiques et binaires.

	*/

	#define VRAI 1
	#define FAUX 0

	int main(void)
	{

		/* Tables de verite */

		/* Table de verite du ET logique */
		printf("Table de verite - ET logique\n\n");
		printf("\tVrai && Vrai = %i\n", VRAI && VRAI);
		printf("\tVrai && Faux = %i\n", VRAI && FAUX);
		printf("\tFaux && Vrai = %i\n", FAUX && VRAI);
		printf("\tVrai && Faux = %i\n\n", FAUX && FAUX);

		/* Table de verite du OU inclusif logique */
		printf("Table de verite - OU inclusif logique\n\n");
		printf("\tVrai || Vrai = %i\n", VRAI || VRAI);
		printf("\tVrai || Faux = %i\n", VRAI || FAUX);
		printf("\tFaux || Vrai = %i\n", FAUX || VRAI);
		printf("\tVrai || Faux = %i\n\n", FAUX || FAUX);

		/* Table de verite du OU exclusif logique */
		printf("Table de verite - OU exclusif (XOR) logique\n\n");
		printf("\tVrai ^ Vrai = %i\n", VRAI ^ VRAI);
		printf("\tVrai ^ Faux = %i\n", VRAI ^ FAUX);
		printf("\tFaux ^ Vrai = %i\n", FAUX ^ VRAI);
		printf("\tFaux ^ Faux = %i\n\n", FAUX ^ FAUX);

		/* Operateurs binaires (i.e. bit par bit) */

		printf("Operateurs binaires\n\n");

		/* 0b10101010 (170) & 0b01010101 (85) = 0b00000000 = 0 */
		printf("\t0b10101010 & 0b01010101 = %i\n", 170 & 85);

		/* 0b10101010 (170) & 0b01010101 (85) = 0b11111111 = 255 */
		printf("\t0b10101010 | 0b01010101 = %i\n\n", 170 | 85);

		/* Decalages binaires */

		printf("Decalages binaires\n\n");

		/* 0b10101010 = 170 */
		unsigned char un_char = 170;

		/* Decalage unitaire gauche : 0b10101010 << 1 = 0b01010100 = 84 */
		printf("\t%u << 1 = %u\n", un_char, (unsigned char)(un_char << 1));

		/* Decalage unitaire droit : 0b10101010 << 1 = 0b01010101 = 85 */
		printf("\t%u >> 1 = %u\n", un_char, (unsigned char)(un_char >> 1));

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_4

	/*

		Entrées (scanf) et sorties (printf) de base. Le style utilise est
		moins commun, mais illustratif de ce que vous pourriez rencontrer
		dans des en-tetes de boucles par exemple.

	*/

	int main(void)
	{

		int premiere_valeur;
		int deuxieme_valeur;
		int somme;

		/* Affichages + saisies */
		printf("%+5c = ", (char)97);
		scanf("%i", &premiere_valeur);

		printf("%+5c = ", (char)98);
		scanf("%i", &deuxieme_valeur);

		/* Afficher somme (l'affectation retourne la valeur affectee)*/
		printf("a + b = %i\n", somme = premiere_valeur + deuxieme_valeur);

		/* L'affectation precedente est valide */
		printf("somme = %i\n", somme);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_5

	/*

		Instructions de selection / choix simples et imbriquees if - [else if] - [else].

	*/

	// Symboles qui represente les operations mathematiques de base
	#define ADDITION '+'		
	#define SOUSTRACTION '-'
	#define MULTIPLICATION '*'
	#define DIVISION '/'

	// Booleens 
	#define VRAI 1
	#define FAUX 0

	int main(void)
	{

		char operation = '/';	// Operation a effectuer
		int operande_1 = 5;		// Premiere operande
		int operande_2 = 10;	// Deuxieme operande
		double resultat;		// Resultat de l'operation

		/* Assumer que l'operation est valide */
		int est_operation_valide = VRAI;

		/* Realiser l'operation si reconnue sinon basculer indicateur de non validite */
		if (operation == ADDITION)
		{
			resultat = (double)operande_1 + operande_2;
		}
		else if (operation == SOUSTRACTION)
		{
			resultat = (double)operande_1 - operande_2;
		}
		else if (operation == MULTIPLICATION)
		{
			resultat = (double)operande_1 * operande_2;
		}
		else if (operation == DIVISION)
		{
			resultat = (double)operande_1 / operande_2;
		}
		else
		{
			est_operation_valide = FAUX;
			printf("Operateur non valide!\n\n");
		}

		/* Afficher le resultat de l'operation si et seulement si valide */
		if (est_operation_valide)
		{

			/* Distinguer l'affichage d'un reel de celui d'un entier */
			if (operation == DIVISION)
			{
				printf("%i %c %i = %lf\n\n", operande_1,
											 operation,
											 operande_2,
											 resultat);
			}
			else
			{
				printf("%i %c %i = %.0lf\n\n", operande_1,
											   operation,
											   operande_2,
											   resultat);
			}

		}

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_6

	/* ATTENTION! NOUS NE NOUS SOMMES PAS RENDU JUSQU'ICI À LA PREMIÈRE SÉANCE! */

	/*

		Interrupteur switch - case - [otherwise].

	*/

	// Symboles qui represente les operations mathematiques de base
	#define ADDITION '+'		
	#define SOUSTRACTION '-'
	#define MULTIPLICATION '*'
	#define DIVISION '/'

	// Booleens 
	#define VRAI 1
	#define FAUX 0

	int main(void)
	{

		char operation = '*';	// Operation a effectuer
		int operande_1 = 5;		// Premiere operande
		int operande_2 = 10;	// Deuxieme operande
		double resultat;		// Resultat de l'operation

		/* Assumer que l'operation est valide */
		int est_operation_valide = VRAI;

		/* Realiser l'operation si reconnue sinon basculer indicateur de non validite */
		switch (operation)
		{
		case ADDITION:
			resultat = (double)operande_1 + operande_2;
			break;
		case SOUSTRACTION:
			resultat = (double)operande_1 - operande_2;
			break;
		case MULTIPLICATION:
			resultat = (double)operande_1 * operande_2;
			break;
		case DIVISION:
			resultat = (double)operande_1 / operande_2;
			break;
		default:
			est_operation_valide = FAUX;
			printf("Operateur non valide!\n\n");
		}

		/* Afficher le resultat de l'operation si et seulement si valide */
		if (est_operation_valide)
		{

			/* Distinguer l'affichage d'un reel de celui d'un entier */
			if (operation == DIVISION)
			{
				printf("%i %c %i = %lf\n\n", operande_1,
					operation,
					operande_2,
					resultat);
			}
			else
			{
				printf("%i %c %i = %.0lf\n\n", operande_1,
					operation,
					operande_2,
					resultat);
			}

		}

		system("pause");
		return EXIT_SUCCESS;

	}

#endif
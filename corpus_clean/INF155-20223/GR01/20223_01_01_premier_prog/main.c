 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

 

#define EXEMPLE_0 0
#define EXEMPLE_1 0
#define EXEMPLE_2 0
#define EXEMPLE_3 0
#define EXEMPLE_4 0
#define EXEMPLE_5 1
#define EXEMPLE_6 0

 

#if EXEMPLE_0

	 

	int main(void)
	{

		printf("EXEMPLE_0 = %i\n", EXEMPLE_0);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_1

	 

	#include <limits.h>  
	#include <float.h>   

	#define CHAR_SAUT_LIGNE "\n"
	#define SAUTER_2_LIGNES {printf(CHAR_SAUT_LIGNE);\
						     printf(CHAR_SAUT_LIGNE);}

	int main(void)
	{

		 
		int un_entier_signe;
		unsigned int un_entier_non_signe;
		double un_reel;
		char un_caractere;

		 
		un_entier_signe = -1;
		un_entier_non_signe = 125;
		un_reel = 1.25;
		un_caractere = 'a';

		 

		 
		printf("AFFICHAGES SIMPLES\n\n");
		printf("\tun_entier_signe     = %i\n", un_entier_signe);
		printf("\tun_entier_non_signe = %u\n", un_entier_non_signe);
		printf("\tun_reel             = %.2f\n", un_reel);
		printf("\tun_caractere        = %c\n", un_caractere);

		SAUTER_2_LIGNES

		 
		printf("LIMITES\n\n");
		printf("\tunsigned int -> [          0,   %u]\n", UINT_MAX);
		printf("\tint          -> [%10i,  %11i]\n", INT_MIN, INT_MAX);
		printf("\tdouble       -> [%.4e, %.5e]\n", DBL_MIN, DBL_MAX);
		printf("\tchar         -> [%11i, %12i] -> [%c, %c]\n", CHAR_MIN, CHAR_MAX, CHAR_MIN, CHAR_MAX);

		SAUTER_2_LIGNES

		 
		printf("CONVERSIONS IMPLICITES\n\n");
		printf("\t2/3    = %.2f\n", 2 / 3);
		printf("\t2/3.0 =  %.2f\n", 2 / 3.0);

		SAUTER_2_LIGNES

		 
		printf("CONVERSIONS EXPLICITES\n\n");
		printf("\t(double)2/3 = %.2f\n", (double)2 / 3);

		SAUTER_2_LIGNES

		 
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

	 

	int main(void)
	{

		 
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

		 
		int une_valeur = 0;
		printf("PRE- POST INCREMENTATION (++) ET DECREMENTATION (--)\n\n");
		printf("\t(AVANT) une_valeur++ = %i\n", une_valeur++);
		printf("\t(APRES) une_valeur   = %i\n", une_valeur);
		printf("\t(AVANT) ++une_valeur = %i\n", ++une_valeur);
		printf("\t(APRES) une_valeur   = %i\n\n", une_valeur);

		 
		char c = 'c';
		printf("CAS INTERESSANT\n\n");
		printf("\t\'c\'++ = %c\n\n", ++c);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_3

	 

	#define VRAI 1
	#define FAUX 0

	int main(void)
	{

		 

		 
		printf("Table de verite - ET logique\n\n");
		printf("\tVrai && Vrai = %i\n", VRAI && VRAI);
		printf("\tVrai && Faux = %i\n", VRAI && FAUX);
		printf("\tFaux && Vrai = %i\n", FAUX && VRAI);
		printf("\tVrai && Faux = %i\n\n", FAUX && FAUX);

		 
		printf("Table de verite - OU inclusif logique\n\n");
		printf("\tVrai || Vrai = %i\n", VRAI || VRAI);
		printf("\tVrai || Faux = %i\n", VRAI || FAUX);
		printf("\tFaux || Vrai = %i\n", FAUX || VRAI);
		printf("\tVrai || Faux = %i\n\n", FAUX || FAUX);

		 
		printf("Table de verite - OU exclusif (XOR) logique\n\n");
		printf("\tVrai ^ Vrai = %i\n", VRAI ^ VRAI);
		printf("\tVrai ^ Faux = %i\n", VRAI ^ FAUX);
		printf("\tFaux ^ Vrai = %i\n", FAUX ^ VRAI);
		printf("\tFaux ^ Faux = %i\n\n", FAUX ^ FAUX);

		 

		printf("Operateurs binaires\n\n");

		 
		printf("\t0b10101010 & 0b01010101 = %i\n", 170 & 85);

		 
		printf("\t0b10101010 | 0b01010101 = %i\n\n", 170 | 85);

		 

		printf("Decalages binaires\n\n");

		 
		unsigned char un_char = 170;

		 
		printf("\t%u << 1 = %u\n", un_char, (unsigned char)(un_char << 1));

		 
		printf("\t%u >> 1 = %u\n", un_char, (unsigned char)(un_char >> 1));

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_4

	 

	int main(void)
	{

		int premiere_valeur;
		int deuxieme_valeur;
		int somme;

		 
		printf("%+5c = ", (char)97);
		scanf("%i", &premiere_valeur);

		printf("%+5c = ", (char)98);
		scanf("%i", &deuxieme_valeur);

		 
		printf("a + b = %i\n", somme = premiere_valeur + deuxieme_valeur);

		 
		printf("somme = %i\n", somme);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif EXEMPLE_5

	 

	 
	#define ADDITION '+'		
	#define SOUSTRACTION '-'
	#define MULTIPLICATION '*'
	#define DIVISION '/'

	 
	#define VRAI 1
	#define FAUX 0

	int main(void)
	{

		char operation = '/';	 
		int operande_1 = 5;		 
		int operande_2 = 10;	 
		double resultat;		 

		 
		int est_operation_valide = VRAI;

		 
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

		 
		if (est_operation_valide)
		{

			 
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

	 

	 

	 
	#define ADDITION '+'		
	#define SOUSTRACTION '-'
	#define MULTIPLICATION '*'
	#define DIVISION '/'

	 
	#define VRAI 1
	#define FAUX 0

	int main(void)
	{

		char operation = '*';	 
		int operande_1 = 5;		 
		int operande_2 = 10;	 
		double resultat;		 

		 
		int est_operation_valide = VRAI;

		 
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

		 
		if (est_operation_valide)
		{

			 
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
/*
 * Programme qui affiche la phrase Hello, World!
 * Auteur: Anis Boubaker
 * Date: 2023-09-07
 */

// Instructions de précompilateur
#include <stdlib.h> //Standard library
#include <stdio.h>  //Standard Input/Output

int main(void)
{
    //Déclarations de variables
    unsigned int age=18; //Variable entière (4 octets) non signée
                         //0 -> 4 294 967 296
    unsigned int age2 = 10;

    double salaire= 100456.50;

    char un_caractere = 65;
    char caractere2 = 'D';

    //Debut du programme
    printf("Hello, World!\n");

    printf("La variable un_caractere contient: %i\n",un_caractere);
    printf("La variable un_caractere contient: %c\n", un_caractere);

    printf("La variable un_caractere+2 contient: %i\n",un_caractere+2);
    printf("La variable un_caractere+2 contient: %c\n", un_caractere+2);

    printf("La variable caractere2 contient: %c\n", caractere2);
    printf("La variable caractere2 contient: %i\n", caractere2);

    printf("La variable age contient: %i\n", age);
    age = 17;
    printf("La variable age contient: %i\n", age);
    age2 = age - 5;

    printf("La variable age2 contient: %i\n", age2);

    age = age + 5;
    printf("La variable age contient: %i\n", age);

    return EXIT_SUCCESS;
}

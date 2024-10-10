#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nombre_etudiants;
    int etudiants_par_groupe; //Operandes des expressions
    int resultat; //Resultat calculé de l'expression
    int etudiants_orphelins;

    int x;
    int y;

    nombre_etudiants = 10;
    etudiants_par_groupe = 3;

    //resultat = (double)nombre_etudiants / etudiants_par_groupe;
    //resultat = nombre_etudiants*1.0 / etudiants_par_groupe;


    resultat = nombre_etudiants / etudiants_par_groupe;

    etudiants_orphelins = nombre_etudiants % etudiants_par_groupe;

    printf("Le nombre de groupes est: %i\n", resultat);
    printf("Et il reste %i etudiants malheureux.\n", etudiants_orphelins);

    x = 11;
    y = ++x / 3;

    printf("LE contenu de x: %i\n", x);
    printf("LE contenu de y: %i\n", y);




    return EXIT_SUCCESS;
}

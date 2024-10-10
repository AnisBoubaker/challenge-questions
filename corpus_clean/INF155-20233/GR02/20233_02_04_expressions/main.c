#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nombre_etudiants;
    int etudiants_par_groupe;  
    int resultat;  
    int etudiants_orphelins;

    int x;
    int y;

    nombre_etudiants = 10;
    etudiants_par_groupe = 3;

     
     


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

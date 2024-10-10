#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 100

int main() {
    char chaine[TAILLE_MAX];
    char chaine2[TAILLE_MAX];
    char resultat[TAILLE_MAX];
    int tab1[10] = {4, 5, 6, 8};
    int tab2[10];


   // chaine = {'B', 'o', 'n', 'j', 'o', 'u', 'r', '\0'};
   // chaine = "Bonjour";
   // chaine[0] = 'B';
   // chaine[1] = 'o';
   // chaine[2] = 'n';
   //STRCPY pour affecter une chaine à une autre
   //Ne jamais utiliser = avec les chaines de caracteres
    strncpy(chaine, "Bonjour ", TAILLE_MAX);
    printf("%s\n", chaine);

    strncpy(chaine2, "a tous", TAILLE_MAX);
    strncat(chaine, "a tous", TAILLE_MAX);

    int nb_etudiants = 30;

    sprintf(resultat,"%s les %i etudant-es\n", chaine, nb_etudiants);

    printf("Le resultat est: %s", resultat);

    //Concatener avec sprintf
    //sprintf(resultat, "%s%s", chaine1, chaine2);

    //Copier une chaine dans autre
    //sprintf(destination, "%s", chaine_originale);



    return 0;
}

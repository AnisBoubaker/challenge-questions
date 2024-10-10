#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 100

int main() {
    char chaine[TAILLE_MAX];
    char chaine2[TAILLE_MAX];
    char resultat[TAILLE_MAX];
    int tab1[10] = {4, 5, 6, 8};
    int tab2[10];


    
    
    
    
    
    
    
    strncpy(chaine, "Bonjour ", TAILLE_MAX);
    printf("%s\n", chaine);

    strncpy(chaine2, "a tous", TAILLE_MAX);
    strncat(chaine, "a tous", TAILLE_MAX);

    int nb_etudiants = 30;

    sprintf(resultat,"%s les %i etudant-es\n", chaine, nb_etudiants);

    printf("Le resultat est: %s", resultat);

     
     

     
     



    return 0;
}

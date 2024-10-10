#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 100

int main() {
    char chaine1[TAILLE_MAX];
    char chaine2[TAILLE_MAX];

    strcpy(chaine1, "Bonjour");
    strcpy(chaine2, "XAllo a tout le monde!");

    if(strcmp(chaine1, chaine2) == 0 )
    {
        printf("Les chaines sont identiques!\n");
    }
    else if(strcmp(chaine1, chaine2) >0 )
    {
        printf("Chaine1 est plus grande que chaine2!\n");
    }
    else
    {
        printf("Chaine1 est plus petite que chaine2!\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 100

int compter_mots(char* chaine);

int main() {
    //Tableau de caractères qui se termine par le \0
    //C'est donc une chaine de caractères
    //char salutation[TAILLE_MAX] = {'B', 'o', 'n', 'j', 'o', 'u', 'r', ' ', 'a', ' ', 't', 'o', 'u', 's', '\0'};
    //char salutation[TAILLE_MAX] = "Bonjour a tous";
    char salutation[TAILLE_MAX];
    int taille;

    printf("Saisir votre salutation: ");
    //scanf("%s", salutation);
    fgets(salutation,TAILLE_MAX, stdin);
    salutation[ strlen(salutation) - 1 ] = '\0';

    //%s : String = Chaine de caractères
    printf("%s\n", salutation);

    printf("Nombre de mots: %i\n", compter_mots(salutation));

    taille = 0;
    while(salutation[taille]!='\0')
    {
        taille ++;
    }
    printf("La taille de la chaine: %i\n", taille);
    printf("La taille de la chaine: %i\n", strlen(salutation));

    return 0;
}


/*
 * Écrire la fonction `compter_mots` qui reçoit une chaine
 * de caractères et qui compte le nombre de mots qui s'y
 * trouvent.
 *
 * Les mots sont séparés par des espaces, des points,
 * ou des virgules.
 */
int compter_mots(char* chaine)
{
    int compteur = 0;
    int taille = strlen(chaine);
    for(int i=0; i<taille; i++)
    {
        if(chaine[i]==' ' || chaine[i]=='.' || chaine[i]==',')
        {
            compteur++;
        }
    }
    return compteur+1;
}
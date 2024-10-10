#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 100

int compter_mots(char* chaine);

int main() {
     
     
     
     
    char salutation[TAILLE_MAX];
    int taille;

    printf("Saisir votre salutation: ");
     
    fgets(salutation,TAILLE_MAX, stdin);
    salutation[ strlen(salutation) - 1 ] = '\0';

     
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
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* mon_fichier;
    int caractere;
    char chaine[1000];
    char jour[20];
    double temp_min, temp_max;

    mon_fichier = fopen("../donnees.txt", "r");
    if(!mon_fichier)
    {
        printf("Erreur lors de l'ouverture\n");
        exit(EXIT_FAILURE);
    }

    while(fscanf(mon_fichier, "%s %lf %lf",
           jour, &temp_min, &temp_max) ==3){
        printf("Jour: %s, Temp. min: %.2lf, Temp. max:%.2lf\n",
               jour, temp_min, temp_max);
    }











//    mon_fichier = fopen("../exemple.txt", "r");
//    if(mon_fichier == NULL)
//    {
//        printf("Erreur lors de l'ouverture du fichier.\n");
//        exit(EXIT_FAILURE);
//    }
//    printf("Fichier ouvert avec succes!\n");
//
//    while(fgets(chaine, 1000, mon_fichier)!=NULL)
//    {
//        printf("%s", chaine);
//    }


//    do{
//        caractere = fgetc(mon_fichier);
//        if(caractere!=EOF)
//            printf("%c", caractere);
//    } while(caractere != EOF);


    //Fermer le fichier quand on n'en a plus besoin
    fclose(mon_fichier);

    return 0;
}

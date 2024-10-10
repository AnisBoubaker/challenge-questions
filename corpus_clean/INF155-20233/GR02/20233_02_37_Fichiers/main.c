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











 
 
 
 
 
 
 
 
 
 
 
 


 
 
 
 
 


     
    fclose(mon_fichier);

    return 0;
}

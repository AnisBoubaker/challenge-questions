#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* mon_fichier;

    double donnees[3][2] = {
            {10, 50}, {23, 45}, {25, 78}
    };

    mon_fichier = fopen("../data.txt", "w");
    if(mon_fichier==NULL)
    {
        printf("Impossible de creer le fichier.\n");
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<3; i++)
    {
        fprintf(mon_fichier, "Ligne%i: %.2lf %.2lf\n",
                i+1, donnees[i][0], donnees[i][1]);
    }



    fclose(mon_fichier);

    return 0;
}

 




#include "utilitaires.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Chiffre_Aleatoire(int min, int max) {
    return (rand() % (max - min + 1)) + min;  
}

int pos_est_entree(int position[2],int entree[2]){
    if(position[0] == entree[0] && position[1] == entree[1]){
        return 1;
    }
    return 0;
}
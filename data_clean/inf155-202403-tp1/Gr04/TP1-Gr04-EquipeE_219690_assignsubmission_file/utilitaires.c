 

#include "utilitaires.h"
#include <stdlib.h>

int nb_aleatoire(int min, int max) {
    return min + (int) (rand() / (RAND_MAX + 0.001) * (max - min + 1));
}
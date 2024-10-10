#include "utilitaire.h"
//nombre aleatoire pour choisir deplacement
int nb_aleatoire(int min, int max) {
    return min + (int) (rand() / (RAND_MAX + 0.001) * (max - min + 1));
}
//
// Created by Julien Tremblay on 2023-11-10.
//

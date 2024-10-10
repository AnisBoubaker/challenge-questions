
#include "utilitaires.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int nb_aleatoire(int min, int max)
{
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

int varia_sum(int count, ...)
{
    va_list args;
    int total = 0;

    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        total += va_arg(args, int);
    }

    va_end(args);

    return total;
}
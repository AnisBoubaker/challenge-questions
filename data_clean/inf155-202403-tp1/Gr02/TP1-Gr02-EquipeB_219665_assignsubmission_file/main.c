

#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"

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

int main(void)
{

    int grille_chargee = 0;
    selection_menu(grille_chargee);
}

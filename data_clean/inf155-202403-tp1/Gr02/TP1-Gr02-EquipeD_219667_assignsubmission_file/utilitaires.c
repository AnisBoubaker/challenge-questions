

#include "utilitaires.h"
#include "labyrinthe.h"
#include "pile.h"

int deplacement_est_possible(int grille[][TAILLE_MAX_GRILLE],
                             int hauteur_grille,
                             int largeur_grille,
                             int pos_ligne,
                             int pos_colonne,
                             int solution_partielle[][2])
{
    int ligne;
    int colonne;

    if (pos_ligne < hauteur_grille && pos_colonne < largeur_grille && grille[pos_ligne][pos_colonne] != 1 && pos_colonne >= 0 && pos_ligne >= 0)
    {

        int pile_copie[TAILLE_MAX_GRILLE * TAILLE_MAX_GRILLE + 1][2];
        pile_copier(solution_partielle, pile_copie);

        while (!pile_est_vide(pile_copie))
        {
            pile_depiler(pile_copie, &ligne, &colonne);
            if (ligne == pos_ligne && colonne == pos_colonne)
            {
                return 0;
            }
        }

        return 1;
    }
    return 0;
}

void effacer_terminal(void)
{

#ifdef _WIN32
    system("cls");

#else
    system("clear");
#endif
}

void afficher_menu(int grille_chargee)
{

    if (grille_chargee)
    {
        printf("\t\t*************************\n");
        printf("\t\t*** LABYRINTHE EXPERT ***\n");
        printf("\t\t*************************\n\n");
        printf("\t1. Charger un labyrinthe\n");
        printf("\t2. Resoudre le labyrinthe\n");
        printf("\t3. Resoudre le labyrinthe pas-a-pas\n");
        printf("\t4. Quitter le programme\n\n");
    }

    else
    {
        printf("\t\t*************************\n");
        printf("\t\t*** LABYRINTHE EXPERT ***\n");
        printf("\t\t*************************\n\n");
        printf("\t1. Charger un labyrinthe\n");
        printf("\t2. [Indisponible] Resoudre le labyrinthe\n");
        printf("\t3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
        printf("\t4. Quitter le programme\n\n");
    }
}

void varia_print_values(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    const char *p = format;
    while (*p != '\0')
    {
        if (*p == 'd')
        {
            int i = va_arg(args, int);
            printf("%d\n", i);
        }
        else if (*p == 'f')
        {
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
        else if (*p == 's')
        {
            const char *s = va_arg(args, const char *);
            printf("%s\n", s);
        }
        p++;
    }

    va_end(args);
}
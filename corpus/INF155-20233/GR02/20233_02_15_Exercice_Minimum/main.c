/*
 * Écrire la fonction **min_de_3** qui reçoit trois valeurs réelles
 * et retourne la valeur minimale parmi les trois
 * valeurs **en valeur absolue**
 * (La valeur retournée sera donc toujours positive).
 *
 * Par exemple, si les trois valeurs sont:
 *      35, 2 et 18 => Le minimum sera 2
 *      30, -40 et 50 => le minimum sera 30
 */

#include <stdio.h>
#include <stdlib.h>

/* Déclaration des prototypes */
/*
 * MIN_DE_3
 * Renvoie le minumum parmi trois valeurs réelles en valeur absolue
 * PARAMETRES:
 * val1, val2, val3 (réel): LEs valeur parmi lesquelles on cherche le minimum
 * RETOUR (réel): Le minimum parmi les 3 valeurs reçues
 */
double min_de_3(double val1, double val2, double val3) ;

int main(void) {

    printf("%lf\n", min_de_3(32, 2, 18) );
    printf("%lf\n", min_de_3(30, -40, 50) );

    return 0;
}

double min_de_3(double val1, double val2, double val3)
{
    double val1_abs, val2_abs, val3_abs;
    double min;

    /*if(val1 < 0)
    {
        val1_abs = -val1;
    }
    else
    {
        val1_abs = val1;
    }*/
    val1_abs = val1<0 ? -val1 : val1;
    val2_abs = val2<0 ? -val2 : val2;
    val3_abs = val3<0 ? -val3 : val3;

    min = val1_abs;
    if(val2_abs < min )
    {
        min = val2_abs;
    }
    if(val3_abs < min )
    {
        min = val3_abs;
    }

    return min;
}
#include <stdio.h>
#include "t_lecture.h"

typedef unsigned int uint;



//struct lecture
//{
//    double temperature;
//    double humidite;
//    double co2;
//    int jour;
//    int mois;
//    int annee;
//};
//
//typedef struct lecture t_lecture;


int main() {

    t_lecture lecture1, lecture2;

    /*
     * Tableau, où chaque case contient un enregistrement COMPLET de type
     * struct lecture.
     */
    struct lecture tab_lectures[100];


    lecture1.temperature = 25.8;
    lecture1.humidite = 40.5;
    lecture1.co2 = 10.2;
    lecture1.jour = 16;
    lecture1.mois = 11;
    lecture1.annee = 2023;

    lecture2.temperature = 23.0;
    lecture2.humidite = 43.5;
    lecture2.co2 = 11.5;
    lecture2.jour = 15;
    lecture2.mois = 11;
    lecture2.annee = 2023;

    t_lecture_afficher(&lecture1);
    printf("Humidite apres appel de la fonction: %.2lf\n", lecture1.humidite);


    t_lecture_afficher(&lecture2);

    tab_lectures[0].temperature = 25.8;
    tab_lectures[0].humidite = 40.5;
    tab_lectures[0].co2 = 10.2;
    tab_lectures[0].jour = 16;
    tab_lectures[0].mois = 11;
    tab_lectures[0].annee = 2023;

    tab_lectures[1].temperature = 23.0;
    tab_lectures[1].humidite = 43.5;
    tab_lectures[1].co2 = 11.5;
    tab_lectures[1].jour = 15;
    tab_lectures[1].mois = 11;
    tab_lectures[1].annee = 2023;

    printf("Moyenne temp: %.2lf", t_lecture_moyenne_temps(tab_lectures, 2));

    return 0;
}














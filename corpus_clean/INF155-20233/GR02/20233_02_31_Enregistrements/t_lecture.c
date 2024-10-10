 
 
 

#include "t_lecture.h"

void t_lecture_afficher(const t_lecture* lec)
{
    printf("Date: %i/%i/%i\n", (*lec).jour, (*lec).mois, (*lec).annee);
    printf("Temperature: %.2lf\n", lec->temperature);
    printf("Humidite: %.2lf\n", lec->humidite);
    printf("Concentration CO2: %.2lf\n", (*lec).co2);

     

     
     
}

 
double t_lecture_moyenne_temps(t_lecture lectures[], int taille)
{
    double somme = 0;
    for(int i=0; i<taille; i++)
    {
        somme += lectures[i].temperature;
    }
    return somme / taille;
}
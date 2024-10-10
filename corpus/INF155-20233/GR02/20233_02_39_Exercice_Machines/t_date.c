//
// Created by Anis Boubaker on 2023-11-23.
//

#include "t_date.h"

/******* FONCRTIONS PRIVEES **************/
/*
 *
 */
int date_valide(int jour, int mois, int annee);

/*
 *
 */
int est_bissextile(int annee);

/*
 *
 */
int max_jours_mois(int mois, int annee);

/*************************************************/

int date_cmp(t_date date1, t_date date2)
{
    if( date1.annee != date2.annee )
    {
        return date1.annee - date2.annee;
    }
    if( date1.mois != date2.mois )
    {
        return date1.mois - date2.mois;
    }
    return date1.jour - date2.jour;
}

int date_set_date(t_date* date, int jour, int mois, int annee)
{
    if(date_valide(jour, mois, annee))
    {
        date->jour = jour;
        date->mois = mois;
        date->annee = annee;
        return 1;
    }
    return 0;
}

int est_bissextile(int annee)
{
    if(  (annee%4==0 && annee%100!=0) || annee%400==0  )
    {
        return 1;
    }
    return 0;
    // return (annee%4==0 && annee%100!=0) || annee%400==0;
}

int max_jours_mois(int mois, int annee)
{
    switch(mois)
    {
        case AVRIL:
        case JUIN:
        case SEPTEMBRE:
        case NOVEMBRE:
            return 30;
        case JANVIER:
        case MARS:
        case MAI:
        case JUILLET:
        case AOUT:
        case OCTOBRE:
        case DECEMBRE:
            return 31;
        case FEVRIER:
            return est_bissextile(annee) ? 29 : 28;
        default:
            return -1;
    }
}

int date_valide(int jour, int mois, int annee)
{
    if(jour >= 1 && jour <= max_jours_mois(mois, annee))
    {
        return 1;
    }
    return 0;
}






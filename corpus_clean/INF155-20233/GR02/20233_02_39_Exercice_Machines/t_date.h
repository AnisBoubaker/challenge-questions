 
 
 

#ifndef EXERCICE_MACHINES_T_DATE_H
#define EXERCICE_MACHINES_T_DATE_H

typedef enum mois{
    JANVIER=1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET,
    AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
} e_mois;

typedef struct t_date {
    int jour;
    e_mois mois;
    int annee;
} t_date;

 
int date_cmp(t_date date1, t_date date2);


 
int date_set_date(t_date* date, int jour, int mois, int annee);


#endif  

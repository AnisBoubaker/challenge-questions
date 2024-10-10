#include <stdio.h>


typedef struct t_cours{
    char* sigle;
    char* titre;
    int nb_credits;
    int nb_max_inscriptions;
    double pon_tp1;
    double pon_tp2;
    double pon_intra;
    double pon_final;
} t_cours;

typedef enum type_session{
    ETE, AUTOMNE, HIVER
} e_type_session;

typedef struct date{
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct session{
    e_type_session type_session;
    t_date date_debut;
    t_date date_fin;
} t_session;

//typedef t_inscription*
typedef struct etudiant{
    char* nom;
    char* prenom;
    char* code_perm;
    t_inscription** inscriptions;
    int nb_inscriptions;
} t_etudiant;

typedef struct inscription{
    t_etudiant* etudiant;
    t_cours* cours;
    t_session* session;
    double note_tp1;
    double note_tp2;
    double note_intra;
    double note_final;
} t_inscription;

typedef struct universite{
    t_etudiant** etudiants; //Tableau dynamique d'adresses de cours
    t_cours** cours;
    int nb_etudiants;
    int nb_cours;
} t_universite;





int main() {
    printf("Hello, World!\n");
    return 0;
}

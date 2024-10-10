//
// Created by Anis Boubaker on 2023-11-16.
//

#include "t_etudiant.h"

void t_etudiant_afficher(const t_etudiant* et)
{
    printf("****** FICHE DE L'ETUDIANT-E *******\n");
    printf("Nom et prenom: %s, %s\n", et->nom, et->prenom);
    printf("Code permanent: %s\n", et->code_perm);
    printf("TP1: %.2lf, TP2: %.2lf\n", et->tp1, et->tp2);
    printf("Intra: %.2lf, Final: %.2lf\n", et->intra, et->finale);
}

/*
 * La fonction constructeur d'un étudiant
 */
t_etudiant* t_etudiant_init(const char* nom, const char* prenom)
{
    t_etudiant* nouvel_etudiant = NULL;

    nouvel_etudiant = (t_etudiant*)malloc(sizeof(t_etudiant));
    if(nouvel_etudiant == NULL)
    {
        return NULL;
    }

    nouvel_etudiant->nom = (char*)malloc(sizeof(char)*(strlen(nom)+1));
    if(nouvel_etudiant->nom==NULL)
    {
        free(nouvel_etudiant);
        return NULL;
    }
    strcpy(nouvel_etudiant->nom, nom);

    nouvel_etudiant->prenom = (char*)malloc(sizeof(char)*(strlen(prenom)+1));
    if(nouvel_etudiant->prenom ==NULL)
    {
        free(nouvel_etudiant->nom);
        free(nouvel_etudiant);
        return NULL;
    }
    strcpy(nouvel_etudiant->prenom, prenom);

    return nouvel_etudiant;
}
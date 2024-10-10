/*
Module: labyrinthe
Description: Fournit l'ensemble des tests pour les fonctions permettant de résoudre un labyrinthe

Auteur:Francis Gignac,


Date:2023-10-25
*/

/***********COMMANDES PRÉPROCESSEUR*************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "labyrinthe.h"
#include "pile.h"
#include "labyrinthe_io.h"



/***********CONSTANTES DE COMPILATION*************/
#define TAILLE_MAX_GRILLE 100

///********* DÉFINITION DES FONCTIONS DE TEST **************/
/*int main(void)
{
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];
    int nb_lignes;
    int nb_colonnes;
    char nom_fichier[TAILLE_MAX_NOM_FICHIER];
    int entree[2];
    int largeur_grille;
    int hauteur_grille;
    int afficher;

    lab_afficher_grille(grille,hauteur_grille,largeur_grille, pile_contient);

    system("pause");
    return EXIT_SUCCESS;


}*/

///MAIN POUR TESTER LA FONCTION LAB_EST_UNE_SORTIE (SUCCESS)
/*

int main(void)
{

    ///Variables
    int grille_test[][TAILLE_MAX_GRILLE]=
            {
                    {1,1,1,0,1},
                    {1,0,0,0,1},
                    {1,1,0,1,1},
                    {1,1,0,1,1}
            };//lABYRINTHE TEST

    int largeur_grille=5;
    int hauteur_grille=4;

    ///NOTE///
    //pos[Numéro de ligne (Axe Y)][Numéro de colonne (Axe X)]

    int pos1[2]={3,2};//End situation
    int pos2[2]={1,1};//Dead end situation
    int pos3[2]={3,0};//Wall situation

    int status;//Value returned from function when analysing the position

    ///Cas1: Est une sortie
    status=lab_est_une_sortie(pos1,grille_test,hauteur_grille,largeur_grille);
    printf("Quand la position est une sortie on retourne %d\n", status);

    ///Cas2: Est un cul-de-sac
    status=lab_est_une_sortie(pos2,grille_test,hauteur_grille,largeur_grille);
    printf("Quand la position est un cul-de-sac on retourne %d\n", status);

    ///Cas3: Est un mur
    status=lab_est_une_sortie(pos3,grille_test,hauteur_grille,largeur_grille);
    printf("Quand la position est un mur on retourne %d\n", status);


    system("pause");
    return EXIT_SUCCESS;
}
*/

///MAIN POUR TESTER FXN Lab_calcul_deplacements & lab_choisir_deplacement (SUCCESS)
/*int main(void)
 {
    int grille_test[][TAILLE_MAX_GRILLE]=
            {
                    {1,1,0,0,1},
                    {0,0,0,0,1},
                    {1,1,0,1,1},
                    {1,1,0,1,1}
            };//lABYRINTHE TEST

    int hauteur_grille=4;
    int largeur_grille=5;

    ///NOTE Pile_solution [Pos_Ligne][Pos_Colonne]
    int pille_solution[][2]={{0,3},{1,3},{1,2}};//,{1,1}
    int pos_ligne=1;//Pos Y
    int pos_colonne=2;//Pos X

    int qty_dep=0;
    int tableau_dep[4][2];
    int choix;

    //Essai sur une position avec 2 chemins possible
    lab_calculer_deplacements_possibles(grille_test, hauteur_grille,largeur_grille,pos_ligne,pos_colonne, pille_solution, &qty_dep,tableau_dep);
    printf("%d deplacements possible a %d:%d et a %d:%d\n", qty_dep, tableau_dep[0][0], tableau_dep[0][1], tableau_dep[1][0], tableau_dep[1][1]);

    choix=lab_choisir_deplacement(tableau_dep, qty_dep);
    printf("Le choix est la coordonnee %d dans le tableau\n\n", choix);//, [%d:%d]//tableau_dep[choix][0],tableau_dep[choix][1]//


    //Essai in a dead end
    pos_ligne=1;//Pos Y
    pos_colonne=1;//Pos X
    int pille_solution2[][2]={{0,3},{1,3},{1,2},{1,1}};

    lab_calculer_deplacements_possibles(grille_test, hauteur_grille,largeur_grille,pos_ligne,pos_colonne, pille_solution2, &qty_dep,tableau_dep);

    printf("%d deplacements possible a %d:%d autres deplacements %d:%d  %d:%d  %d:%d\n", qty_dep, tableau_dep[0][0], tableau_dep[0][1], tableau_dep[1][0], tableau_dep[1][1],tableau_dep[2][0], tableau_dep[2][1],tableau_dep[3][0], tableau_dep[3][1]);

    choix=lab_choisir_deplacement(tableau_dep, qty_dep);

    printf("retour est %d\n\n", choix);

    return EXIT_SUCCESS;
}*/

///MAIN POUR TESTER FXN DE CASES ADJACENTES (SUCCESS)
/*
int main(void)
{
    int grille_test[][TAILLE_MAX_GRILLE]=
            {{1,0,1},
             {0,0,0},
             {1,0,1}};//Grille de test

    ///Positions notés comme suit [Position horizontale, Position verticale]

    //Posisition par laquelle on évalue les cases adjacentes
    int origine[2]={1,1};

    //Positions à évaluer selon l'origine
    int pos1[2]={0,0};//Diagonale
    int pos2[2]={0,1};///Vers le haut
    int pos3[2]={0,2};//Diagonale
    int pos4[2]={1,0};///Vers la gauche
    int pos5[2]={1,1};//Origine
    int pos6[2]={1,2};///Vers la droite
    int pos7[2]={2,0};//Diagonale
    int pos8[2]={2,1};///Vers le bas
    int pos9[2]={2,2};//Diagonale

    int status=0;//Status if adjacent or not

    //Évaluation des positions
    status = lab_est_cases_adjacentes(origine, pos1);
    printf("pos1 status:%d, it is a diagonal position\n", status);

    status = lab_est_cases_adjacentes(origine, pos2);
    printf("pos1 status:%d, it is an upward position\n", status);

    status = lab_est_cases_adjacentes(origine, pos3);
    printf("pos1 status:%d, it is a diagonal position\n", status);

    status = lab_est_cases_adjacentes(origine, pos4);
    printf("pos1 status:%d, it is a sideway position\n", status);

    status = lab_est_cases_adjacentes(origine, pos5);
    printf("pos1 status:%d, it the original position\n", status);

    status = lab_est_cases_adjacentes(origine, pos6);
    printf("pos1 status:%d, it is a sideway position\n", status);

    status = lab_est_cases_adjacentes(origine, pos7);
    printf("pos1 status:%d, it is a diagonal position\n", status);

    status = lab_est_cases_adjacentes(origine, pos8);
    printf("pos1 status:%d, it is a downwards position\n", status);

    status = lab_est_cases_adjacentes(origine, pos9);
    printf("pos1 status:%d, it is a diagonal position\n", status);


    system("pause");
    return EXIT_SUCCESS;

}
*/
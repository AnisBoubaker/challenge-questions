 
 
 
 
 
 
 

#ifndef INF155_TP1_EQUIPEA_UTILITAIRES_H
#define INF155_TP1_EQUIPEA_UTILITAIRES_H



 
 
int Chiffre_Aleatoire(int min, int max);

 
 
 
int pos_est_entree(int position[2],int entree[2]);

#endif  

 

 
#include <stdlib.h>
#include "pile.h"

 


 

int pile_empiler(int pile[][2], int new_ligne, int new_colonne)
{
	int top_pile = pile[0][1];
	int taille_max_pile = pile[0][0];

	 
	if (top_pile + 1 >= taille_max_pile) {
		return 0;
	}

	pile[top_pile + 1][0] = new_ligne;
	pile[top_pile + 1][1] = new_colonne;
	pile[0][1]++;

	return 1;
}

int pile_depiler(int pile[][2], int* ligne, int* colonne)
{
	if (!pile_est_vide(pile))
	{
		pile[0][1]--;
	}
	else
	{
		return 0;
	}
	*ligne = pile[pile[0][1] + 1][0];
	*colonne = pile[pile[0][1] + 1][1];

	return 1;
}

int pile_est_vide(int pile[][2])
{
	return pile[0][1] == 0;
}

int pile_contient(int pile[][2], int ligne, int colonne)
{
	int top_pile = pile[0][1];
	int i = 0;
	for (i = 0; i < top_pile; i++)
	{
		if (pile[i + 1][0] == ligne && pile[i + 1][1] == colonne)
		{
			return 1;
		}
	}
	return 0;
}

int pile_taille_pile(int pile[][2]) {
	return pile[0][1];
}

void pile_initialiser(int pile[][2], int taille_max) {
	pile[0][0] = taille_max;
	pile[0][1] = 0;
}

void pile_haut_pile(int pile[][2], int* ligne, int* colonne)
{
	if (!pile_est_vide(pile))
	{
		*ligne = pile[pile[0][1]][0];
		*colonne = pile[pile[0][1]][1];
	}
}

void pile_copier(int pile_originale[][2], int pile_copie[][2]) {
	int i;
	for (i = 0; i < pile_originale[0][1] + 1; i++) {
		pile_copie[i][0] = pile_originale[i][0];
		pile_copie[i][1] = pile_originale[i][1];
	}
}
 

#ifndef LABYRINTHE_IO_H
#define LABYRINTHE_IO_H

 
#include "labyrinthe.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

 
#define TAILLE_MAX_NOM_FICHIER 100   
#define FFLUSH() do{} while (getchar()!='\n')

 
int charger_labyrinthe(
	char* nom_fichier,
	int grille[][TAILLE_MAX_GRILLE],
	int point_entree[2],
	int* hauteur_grille,
	int* largeur_grille);


 
int selection_menu(int grille_chargee);


 
void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille);



#endif  

 
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"



 
void lab_afficher_grille(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                         int largeur_grille,int pile_solution[][2])
{
    for(int i = 0; i < hauteur_grille; i++){     
        for(int j = 0; j < largeur_grille; j++) {     
            if (grille[i][j] == 1) {       
                printf("%c", 219);                          
            }
            else if (!pile_est_vide(pile_solution) && pile_contient(pile_solution,i,j)) {
                printf("x");  
            }
            else {
                printf(" ");  
            }
        }
        printf("\n");    
    }
}

 
void lab_calculer_deplacements_possibles(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                                         int largeur_grille,int pos_ligne,
                                         int pos_colonne,int solution_partielle[][2],
                                         int *nb_deplacements,int deplacements[4][2]) {
    *nb_deplacements = 0;

     
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            deplacements[i][j] = -1;
        }
    }
     
    if (pos_ligne != hauteur_grille - 1) {
        if (grille[pos_ligne + 1][pos_colonne] == 0 && !pile_contient(solution_partielle, pos_ligne + 1,
                                                                      pos_colonne)) {
            *nb_deplacements = *nb_deplacements + 1;
             
            deplacements[0][0] = (pos_ligne + 1);
            deplacements[0][1] = (pos_colonne);
        }
    }

     
    if (pos_ligne != 0) {
        if (grille[pos_ligne - 1][pos_colonne] == 0 && !pile_contient(solution_partielle, pos_ligne - 1,
                                                                      pos_colonne)) {
            *nb_deplacements = *nb_deplacements + 1;
             
            deplacements[1][0] = (pos_ligne - 1);
            deplacements[1][1] = (pos_colonne);
        }
    }

     
    if (pos_colonne != 0) {
        if (grille[pos_ligne][pos_colonne - 1] == 0 && !pile_contient(solution_partielle, pos_ligne,
                                                                      pos_colonne - 1)) {
            *nb_deplacements = *nb_deplacements + 1;
             
            deplacements[2][0] = (pos_ligne);
            deplacements[2][1] = (pos_colonne - 1);
        }
    }

     
    if (pos_colonne != largeur_grille - 1) {
        if (grille[pos_ligne][pos_colonne + 1] == 0 && !pile_contient(solution_partielle, pos_ligne,
                                                                      pos_colonne + 1)) {
            *nb_deplacements = *nb_deplacements + 1;
             
            deplacements[3][0] = (pos_ligne);
            deplacements[3][1] = (pos_colonne + 1);
        }
    }
}

int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles)
{

    int deplacement_choisi = 3;

    while(deplacements_possibles[deplacement_choisi][1] == -1){
        deplacement_choisi--;
    }

    return deplacement_choisi;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2])
{
    int j = 1;
     
    for(int i=0; i < 2; i++)
    {
        if((case1[i] == case2[i] + 1 || case1[i] == case2[i] - 1) && case1[j] == case2[j])
        {
            return 1;
        }
        j--;
    }
    return 0;
}


int lab_est_une_sortie(int position[2],int grille[][TAILLE_MAX_GRILLE]
                       ,int hauteur_grille,int largeur_grille)
{
    if (position[0] == 0 || position[0] == hauteur_grille-1 || position[1] == 0
    || position[1]==largeur_grille-1){  
        if (grille[position[0]][position[1]]!=1){  
            return true;
        }
    }
    return false;
}

 
int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,
                            int largeur_grille,int entree[2],int pile_solution[][2],int debug)
{
    int pile_chemins_alternatifs[TAILLE_MAX_PILE][2];
    int deplacements_possible[4][2] = {{0}};
    int nb_deplacements_possibles=0;
    int nouvelle_position[2] = {entree[0],entree[1]};
    int position_actuelle[2] = {entree[0],entree[1]};
    int case_adjacentes[2];
    int deplacement_choisi;
    int ligne;
    int colonne;
    int nouvelle_ligne;
    int nouvelle_colonne;
    bool possible_de_se_deplacer = true;

    pile_initialiser(pile_solution,TAILLE_MAX_PILE);
    pile_initialiser(pile_chemins_alternatifs,TAILLE_MAX_PILE);
    pile_empiler(pile_solution, entree[0],entree[1]);

    while (possible_de_se_deplacer && (pos_est_entree(nouvelle_position,entree) ||
    !lab_est_une_sortie(position_actuelle,grille,hauteur_grille,largeur_grille)))
    {
        pile_haut_pile(pile_solution,&ligne,&colonne);
        lab_calculer_deplacements_possibles(grille,hauteur_grille,
                                            largeur_grille,ligne
                                            ,colonne,pile_solution,
                                            &nb_deplacements_possibles,
                                            deplacements_possible);
        if (nb_deplacements_possibles>0)
        {

            deplacement_choisi = lab_choisir_deplacement
                    (deplacements_possible,
                     nb_deplacements_possibles);  

             
            nouvelle_ligne = deplacements_possible[deplacement_choisi][0];
            nouvelle_colonne = deplacements_possible[deplacement_choisi][1];

            pile_empiler(pile_solution, nouvelle_ligne, nouvelle_colonne);

             
            for(int i = 0;i < 4;i++)
            {
                    if(deplacements_possible[i][0] != -1 && i != deplacement_choisi)
                    {
                        pile_empiler(pile_chemins_alternatifs,deplacements_possible[i][0],
                                     deplacements_possible[i][1]);
                    }
            }
        }
        else if (!pile_est_vide(pile_chemins_alternatifs))
        {
            pile_depiler(pile_chemins_alternatifs, &nouvelle_position[0],
                         &nouvelle_position[1]);

            do{
                pile_depiler(pile_solution, &case_adjacentes[0],
                             &case_adjacentes[1]);
            }while (!lab_est_cases_adjacentes(nouvelle_position,
                                              case_adjacentes));
            pile_empiler(pile_solution,case_adjacentes[0],case_adjacentes[1]);
            pile_empiler(pile_solution, nouvelle_position[0],
                         nouvelle_position[1]);
        }
        else
        {
            possible_de_se_deplacer = false;
        }

        if (debug)
        {
            lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_solution);
            system("pause");
        }
        pile_haut_pile(pile_solution,&position_actuelle[0],&position_actuelle[1]);
    }

    if (lab_est_une_sortie(position_actuelle,grille,hauteur_grille,largeur_grille))
    {
        return true;
    }
    return false;


}
 


#include <time.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include "utilitaires.h"


int main(void) {

     
    srand((unsigned int) time(NULL));

     
    char nom_grille[TAILLE_MAX_NOM_FICHIER]; 
    int succes_chargement = 0;  
    int la_pile[TAILLE_MAX_PILE][2];  
    int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE];  
    int point_entree[2];  
    int hauteur_grille, largeur_grille;  
    int choix_menu = 0;
    bool labyrinthe_resolu;


     
    while (choix_menu!=4) {
        choix_menu = selection_menu(succes_chargement);

         
        pile_initialiser(la_pile, TAILLE_MAX_PILE);

         
        if (choix_menu == 1) {
            menu_charger_labyrinthe(nom_grille, TAILLE_MAX_NOM_FICHIER);
            succes_chargement = charger_labyrinthe(nom_grille, grille,
                                                   point_entree, &hauteur_grille, &largeur_grille);

            if (!succes_chargement) {
                printf("Une erreur s'est produite lors du chargement de la grille.\n");
                printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
                system("pause");
            }
            else{
                printf("Grille chargee avec succes!\n");
                lab_afficher_grille(grille,hauteur_grille,largeur_grille,la_pile);
                system("pause");
            }
        }
         
         
        else if (choix_menu == 2) {
            labyrinthe_resolu = lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,
                                                        point_entree,la_pile,false);
            if (!labyrinthe_resolu){
                printf("Le labyrinthe a aucune solution!\n");
            }
            else{
                printf("Labyrinthe resolu!\n");
                lab_afficher_grille(grille,hauteur_grille,largeur_grille,la_pile);
            }
            system("pause");
        }
         
        else if (choix_menu == 3) {
            labyrinthe_resolu = lab_resoudre_profondeur(grille,hauteur_grille,largeur_grille,
                                                        point_entree,la_pile,true);
            if (!labyrinthe_resolu){
                printf("Le labyrinthe a aucune solution!\n");
            }
            system("pause");
        }
    }
	return EXIT_SUCCESS;
}

 




#include "utilitaires.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Chiffre_Aleatoire(int min, int max) {
    return (rand() % (max - min + 1)) + min;  
}

int pos_est_entree(int position[2],int entree[2]){
    if(position[0] == entree[0] && position[1] == entree[1]){
        return 1;
    }
    return 0;
}
 


#ifndef PILE_H
#define PILE_H

 
int pile_empiler(int pile[][2], int new_ligne, int new_colonne);


 
int pile_depiler(int pile[][2], int* ligne, int* colonne);


 
int pile_est_vide(int pile[][2]);

 
int pile_contient(int pile[][2], int ligne, int colonne);

 
void pile_haut_pile(int pile[][2], int* ligne, int* colonne);

 
int pile_taille_pile(int pile[][2]);

 
void pile_initialiser(int pile[][2], int taile_max);

 
void pile_copier(int pile_originale[][2], int pile_copie[][2]);


#endif

 


 
#include "labyrinthe_io.h"


 
int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE],
                       int point_entree[2], int* hauteur_grille, int* largeur_grille) {
    FILE *fichier;
    char caractere_lu;
    int i = 0,  
    j = 0;
    fichier = fopen(nom_fichier, "r");
    if (!fichier) {
        return 0;
    }

    *largeur_grille = -1;
    *hauteur_grille = -1;

    while ((caractere_lu = getc(fichier)) != EOF) {
        switch (caractere_lu) {
            case '*':
                grille[i][j] = 1;
                j++;
                break;
            case ' ':
                grille[i][j] = 0;
                j++;
                break;
            case 'E':
                grille[i][j] = 0;
                point_entree[0] = i;
                point_entree[1] = j;
                j++;
                break;
            case '\n':
                if (*largeur_grille != -1 && *largeur_grille != j) {
                    printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le même nombre de colonnes.\n");
                    return 0;
                }
                *largeur_grille = j;
                j = 0;
                i++;
                break;
        }
    }
    *hauteur_grille = i + 1;
    fclose(fichier);
    return 1;
}


int selection_menu(int grille_chargee)
{
    int choix;
    bool choix_ok = false;
    while (!choix_ok)
    {
        printf("1. Charger un labyrinthe\n");
        if(grille_chargee)
        {
            printf("2. Resoudre le labyrinthe\n");
            printf("3. Resoudre le labyrinthe pas-a-pas\n");
        }
        else
        {
            printf("2. [Indisponible] Resoudre le labyrinthe\n");
            printf("3. [Indisponible] Resoudre le labyrinthe pas-a-pas\n");
        }
        printf("4. Quitter le programme\n");
        scanf("%d", &choix);
         
         
        FFLUSH();
        if (choix>=1 && choix<=4 && grille_chargee)
        {
            choix_ok = true;
        }
        else if(choix==1 || choix==4)
        {
            choix_ok = true;
        }
        else
        {
            printf("Choix Invalide\n\n");
        }
    }
    return choix;
}

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille)
{
    char tmp[TAILLE_MAX_NOM_FICHIER];

    printf("Nom du fichier: ");
     
    fgets(buf_nom_fichier,buf_taille,stdin);
     
    buf_nom_fichier[strlen(buf_nom_fichier)-1]='\0';

     
     
 
 
 
}
 

#ifndef LABYRINTHE_H
#define LABYRINTHE_H

 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


 
#define TAILLE_MAX_GRILLE 100  
#define TAILLE_MAX_PILE 1000  

 
void lab_afficher_grille(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);



 

void lab_calculer_deplacements_possibles(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int pos_ligne,
        int pos_colonne,
        int solution_partielle[][2],
        int *nb_deplacements,
        int deplacements[4][2]);


 
int lab_choisir_deplacement(int deplacements_possibles[][2],int nb_deplacements_possibles);

 
int lab_est_cases_adjacentes(int case1[2], int case2[2]);





 
int lab_est_une_sortie(
        int position[2],
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille);



 
int lab_resoudre_profondeur(
        int grille[][TAILLE_MAX_GRILLE],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);


#endif

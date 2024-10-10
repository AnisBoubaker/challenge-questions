 

#ifndef UTILITAIRES_H
#define UTILITAIRES_H

 
 
#define TAILLE_MAX_GRILLE 100

 
int nb_aleatoire(int min, int max);

 
void dplc_haut(int coordo[], int pos_lig, int pos_col);

 
void dplc_bas(int coordo[], int pos_lig, int pos_col);


 
void dplc_gauche(int coordo[], int pos_lig, int pos_col);


 
void dplc_droite(int coordo[], int pos_lig, int pos_col);

#endif

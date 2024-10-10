/*
Module: labyrinthe_io
Description: Module de fonction d'entree/sortie en lien avec le programme du labyrinthe

Auteurs:    - Étienne Lemay
 *          - Félix Caron
 *          - Julien Hémond
 *          - Louis-Pierre Fortier

Date: 12 novembre 2023
*/

#ifndef LABYRINTHE_IO_H
#define LABYRINTHE_IO_H


//D�pendances du module
#include "labyrinthe.h"
#include <stdio.h>
#include <string.h>

//Constantes
#define TAILLE_MAX_NOM_FICHIER 100 //Taille maximale (en cracateres) du nom de fichier

/*
Fonction: CHARGER_LABYRINTHE
Description: Charge un labyrinthe depuis le disque dur et le stocke dans "grille". Si une erreur
			 se produit (fichier introuvable, fichier non-conforme), la fonction retourne faux. Sinon
			 elle retourne vrai.
Param�tres:
- nom_fichier (chaine de caracteres): Le nom du fichier sur le disque a charger. Ca doit etre un fichier
										 texte comprenant uniquement des * (pour les murs), des espaces (pour
										 les couloirs et une lettre E pour repr�senter l'entree.
- grille: (tableau 2D d'entiers): Tableau qui contiendra la topologie de la grille. Chaque case aura soit la
								  valeur 0 (pour un couloir) soit 1 (pour un mur).
- point_entree: (tableau de deux cases) Tableau dans lequel seront stockees les coordonnees du point d'entree.
- hauteur_grille: (pointeur d'entier) Adresse dans laquelle sera stockee la hauteur de la grille (nombre de lignes)
- largeur_grille: (pointeur d'entier) Adresse dans laquelle sera stockee la largeur de la grille (nombre de colonnes)
Retour : (valeur booleenne) Vrai si la grille s'est chargee correctement, faux sinon.
Parametres modifies : grille, point_entree, *hauteur_grille et *largeur_grille.
*/
int charger_labyrinthe(
	char* nom_fichier,
	int grille[][TAILLE_MAX_GRILLE],
	int point_entree[2],
	int* hauteur_grille,
	int* largeur_grille);

/* Fonction : MENU_CHARGER_LABYRINTHE
 * Descriptions : Demande à l'usager de saisir un nom de fichier correspondant au fichier contenant le labyrinthe à charger.
 * Paramètres :
 * buf_nom_fichier (chaine de caracteres) : Ce paramètre stock le nom du fichier saisi dans une chaine de caractères.
 * buf_taille (entier) : Taille maximale de la chaine de caractères à lire depuis la console.
 * retour : Aucun
 * Patamètres modifiés : buf_nom_fichier
 */

void menu_charger_labyrinthe(char* buf_nom_fichier,int buf_taille);



/*
Fonction: SELECTION_MENU
Description: Affiche le menu principal et demande à l'utilisateur de saisir un choix.
            La fonction indique si certains choix sont indisponibles: il n'est pas possible
            de résoudre le labyrinthe si aucun labyrinthe n'a été chargé depuis le disque.
            La fonction vérifie si le choix est invalide(ex.: erronné ou non disponible)
            Une fois qu'un choix valide aura été effectué, la fonction retourne le choix en
            question.
Paramètres:
- grille_chargee (entier): valeur booléenne: vrai si la grille a déjà été chargée, faux sinon.
Retour: (entier) Valeur du choix valide saisi par l'usager.
Paramètres modifiés: Aucun.
*/

int selection_menu(int grille_chargee);

/*
Fonction: MENU_CHARGER_LABYRINTHE
Description: Demande à l'usager de saisir un nom de fichier correspondant au fichier contenant
le labyrinthe à charger.
Paramètres:
- buf_nom_fichier (chaine de caractères): chaine de caractères dans laquelle sera stockée le nom du
fichier saisi.
- buf_taille (entier): Taille maximale de la chaine de caractère à lire depuis la console.
Retour: Aucun.
Paramètres modifiés: buf_nom_fichier.
*/

void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille);




#endif // !LABYRINTHE_IO_H
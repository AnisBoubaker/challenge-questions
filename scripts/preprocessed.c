






 
 
 
 
 
 
 






 
 
int Chiffre_Aleatoire(int min, int max);

 
 
 
int pos_est_entree(int position[2],int entree[2]);












typedef int size_t;
typedef int __builtin_va_list;
typedef int __gnuc_va_list;
typedef int va_list;
typedef int __int8_t;
typedef int __uint8_t;
typedef int __int16_t;
typedef int __uint16_t;
typedef int __int_least16_t;
typedef int __uint_least16_t;
typedef int __int32_t;
typedef int __uint32_t;
typedef int __int64_t;
typedef int __uint64_t;
typedef int __int_least32_t;
typedef int __uint_least32_t;
typedef int __s8;
typedef int __u8;
typedef int __s16;
typedef int __u16;
typedef int __s32;
typedef int __u32;
typedef int __s64;
typedef int __u64;
typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
typedef int _off_t;
typedef int __dev_t;
typedef int __uid_t;
typedef int __gid_t;
typedef int _off64_t;
typedef int _fpos_t;
typedef int _ssize_t;
typedef int wint_t;
typedef int _mbstate_t;
typedef int _flock_t;
typedef int _iconv_t;
typedef int __ULong;
typedef int __FILE;
typedef int ptrdiff_t;
typedef int wchar_t;
typedef int char16_t;
typedef int char32_t;
typedef int __off_t;
typedef int __pid_t;
typedef int __loff_t;
typedef int u_char;
typedef int u_short;
typedef int u_int;
typedef int u_long;
typedef int ushort;
typedef int uint;
typedef int clock_t;
typedef int time_t;
typedef int daddr_t;
typedef int caddr_t;
typedef int ino_t;
typedef int off_t;
typedef int dev_t;
typedef int uid_t;
typedef int gid_t;
typedef int pid_t;
typedef int key_t;
typedef int ssize_t;
typedef int mode_t;
typedef int nlink_t;
typedef int fd_mask;
typedef int _types_fd_set;
typedef int clockid_t;
typedef int timer_t;
typedef int useconds_t;
typedef int suseconds_t;
typedef int FILE;
typedef int fpos_t;
typedef int cookie_read_function_t;
typedef int cookie_write_function_t;
typedef int cookie_seek_function_t;
typedef int cookie_close_function_t;
typedef int cookie_io_functions_t;
typedef int div_t;
typedef int ldiv_t;
typedef int lldiv_t;
typedef int sigset_t;
typedef int __sigset_t;
typedef int _sig_func_ptr;
typedef int sig_atomic_t;
typedef int __tzrule_type;
typedef int __tzinfo_type;
typedef int mbstate_t;
typedef int sem_t;
typedef int pthread_t;
typedef int pthread_attr_t;
typedef int pthread_mutex_t;
typedef int pthread_mutexattr_t;
typedef int pthread_cond_t;
typedef int pthread_condattr_t;
typedef int pthread_key_t;
typedef int pthread_once_t;
typedef int pthread_rwlock_t;
typedef int pthread_rwlockattr_t;
typedef int pthread_spinlock_t;
typedef int pthread_barrier_t;
typedef int pthread_barrierattr_t;
typedef int jmp_buf;
typedef int rlim_t;
typedef int sa_family_t;
typedef int sigjmp_buf;
typedef int stack_t;
typedef int siginfo_t;
typedef int z_stream;


typedef int int8_t;
typedef int uint8_t;
typedef int int16_t;
typedef int uint16_t;
typedef int int32_t;
typedef int uint32_t;
typedef int int64_t;
typedef int uint64_t;


typedef int int_least8_t;
typedef int uint_least8_t;
typedef int int_least16_t;
typedef int uint_least16_t;
typedef int int_least32_t;
typedef int uint_least32_t;
typedef int int_least64_t;
typedef int uint_least64_t;


typedef int int_fast8_t;
typedef int uint_fast8_t;
typedef int int_fast16_t;
typedef int uint_fast16_t;
typedef int int_fast32_t;
typedef int uint_fast32_t;
typedef int int_fast64_t;
typedef int uint_fast64_t;


typedef int intptr_t;
typedef int uintptr_t;


typedef int intmax_t;
typedef int uintmax_t;


typedef _Bool bool;


typedef void* MirEGLNativeWindowType;
typedef void* MirEGLNativeDisplayType;
typedef struct MirConnection MirConnection;
typedef struct MirSurface MirSurface;
typedef struct MirSurfaceSpec MirSurfaceSpec;
typedef struct MirScreencast MirScreencast;
typedef struct MirPromptSession MirPromptSession;
typedef struct MirBufferStream MirBufferStream;
typedef struct MirPersistentId MirPersistentId;
typedef struct MirBlob MirBlob;
typedef struct MirDisplayConfig MirDisplayConfig;


typedef struct xcb_connection_t xcb_connection_t;
typedef uint32_t xcb_window_t;
typedef uint32_t xcb_visualid_t;


typedef _Atomic(_Bool)              atomic_bool;
typedef _Atomic(char)               atomic_char;
typedef _Atomic(signed char)        atomic_schar;
typedef _Atomic(unsigned char)      atomic_uchar;
typedef _Atomic(short)              atomic_short;
typedef _Atomic(unsigned short)     atomic_ushort;
typedef _Atomic(int)                atomic_int;
typedef _Atomic(unsigned int)       atomic_uint;
typedef _Atomic(long)               atomic_long;
typedef _Atomic(unsigned long)      atomic_ulong;
typedef _Atomic(long long)          atomic_llong;
typedef _Atomic(unsigned long long) atomic_ullong;
typedef _Atomic(uint_least16_t)     atomic_char16_t;
typedef _Atomic(uint_least32_t)     atomic_char32_t;
typedef _Atomic(wchar_t)            atomic_wchar_t;
typedef _Atomic(int_least8_t)       atomic_int_least8_t;
typedef _Atomic(uint_least8_t)      atomic_uint_least8_t;
typedef _Atomic(int_least16_t)      atomic_int_least16_t;
typedef _Atomic(uint_least16_t)     atomic_uint_least16_t;
typedef _Atomic(int_least32_t)      atomic_int_least32_t;
typedef _Atomic(uint_least32_t)     atomic_uint_least32_t;
typedef _Atomic(int_least64_t)      atomic_int_least64_t;
typedef _Atomic(uint_least64_t)     atomic_uint_least64_t;
typedef _Atomic(int_fast8_t)        atomic_int_fast8_t;
typedef _Atomic(uint_fast8_t)       atomic_uint_fast8_t;
typedef _Atomic(int_fast16_t)       atomic_int_fast16_t;
typedef _Atomic(uint_fast16_t)      atomic_uint_fast16_t;
typedef _Atomic(int_fast32_t)       atomic_int_fast32_t;
typedef _Atomic(uint_fast32_t)      atomic_uint_fast32_t;
typedef _Atomic(int_fast64_t)       atomic_int_fast64_t;
typedef _Atomic(uint_fast64_t)      atomic_uint_fast64_t;
typedef _Atomic(intptr_t)           atomic_intptr_t;
typedef _Atomic(uintptr_t)          atomic_uintptr_t;
typedef _Atomic(size_t)             atomic_size_t;
typedef _Atomic(ptrdiff_t)          atomic_ptrdiff_t;
typedef _Atomic(intmax_t)           atomic_intmax_t;
typedef _Atomic(uintmax_t)          atomic_uintmax_t;
typedef struct atomic_flag { atomic_bool _Value; } atomic_flag;
typedef enum memory_order {
  memory_order_relaxed,
  memory_order_consume,
  memory_order_acquire,
  memory_order_release,
  memory_order_acq_rel,
  memory_order_seq_cst
} memory_order;



 





 
int pile_empiler(int pile[][2], int new_ligne, int new_colonne);


 
int pile_depiler(int pile[][2], int* ligne, int* colonne);


 
int pile_est_vide(int pile[][2]);

 
int pile_contient(int pile[][2], int ligne, int colonne);

 
void pile_haut_pile(int pile[][2], int* ligne, int* colonne);

 
int pile_taille_pile(int pile[][2]);

 
void pile_initialiser(int pile[][2], int taile_max);

 
void pile_copier(int pile_originale[][2], int pile_copie[][2]);


 


 

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









 



 
void lab_afficher_grille(
        int grille[][100],
        int hauteur_grille,
        int largeur_grille,
        int pile_solution[][2]);



 

void lab_calculer_deplacements_possibles(
        int grille[][100],
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
        int grille[][100],
        int hauteur_grille,
        int largeur_grille);



 
int lab_resoudre_profondeur(
        int grille[][100],
        int hauteur_grille,
        int largeur_grille,
        int entree[2],
        int pile_solution[][2],
        int debug);








 



 
int charger_labyrinthe(
	char* nom_fichier,
	int grille[][100],
	int point_entree[2],
	int* hauteur_grille,
	int* largeur_grille);


 
int selection_menu(int grille_chargee);


 
void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille);





 
void lab_afficher_grille(int grille[][100],int hauteur_grille,
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

 
void lab_calculer_deplacements_possibles(int grille[][100],int hauteur_grille,
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


int lab_est_une_sortie(int position[2],int grille[][100]
                       ,int hauteur_grille,int largeur_grille)
{
    if (position[0] == 0 || position[0] == hauteur_grille-1 || position[1] == 0
    || position[1]==largeur_grille-1){  
        if (grille[position[0]][position[1]]!=1){  
            return 1;
        }
    }
    return 0;
}

 
int lab_resoudre_profondeur(int grille[][100],int hauteur_grille,
                            int largeur_grille,int entree[2],int pile_solution[][2],int debug)
{
    int pile_chemins_alternatifs[1000][2];
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
    bool possible_de_se_deplacer = 1;

    pile_initialiser(pile_solution,1000);
    pile_initialiser(pile_chemins_alternatifs,1000);
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
            possible_de_se_deplacer = 0;
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
        return 1;
    }
    return 0;


}








int main(void) {

     
    srand((unsigned int) time(0));

     
    char nom_grille[100]; 
    int succes_chargement = 0;  
    int la_pile[1000][2];  
    int grille[100][100];  
    int point_entree[2];  
    int hauteur_grille, largeur_grille;  
    int choix_menu = 0;
    bool labyrinthe_resolu;


     
    while (choix_menu!=4) {
        choix_menu = selection_menu(succes_chargement);

         
        pile_initialiser(la_pile, 1000);

         
        if (choix_menu == 1) {
            menu_charger_labyrinthe(nom_grille, 100);
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
                                                        point_entree,la_pile,0);
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
                                                        point_entree,la_pile,1);
            if (!labyrinthe_resolu){
                printf("Le labyrinthe a aucune solution!\n");
            }
            system("pause");
        }
    }
	return 0;
}









int Chiffre_Aleatoire(int min, int max) {
    return (rand() % (max - min + 1)) + min;  
}

int pos_est_entree(int position[2],int entree[2]){
    if(position[0] == entree[0] && position[1] == entree[1]){
        return 1;
    }
    return 0;
}





 
int charger_labyrinthe(char* nom_fichier, int grille[][100],
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
    bool choix_ok = 0;
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
         
         
        do{} while (getchar()!='\n');
        if (choix>=1 && choix<=4 && grille_chargee)
        {
            choix_ok = 1;
        }
        else if(choix==1 || choix==4)
        {
            choix_ok = 1;
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
    char tmp[100];

    printf("Nom du fichier: ");
     
    fgets(buf_nom_fichier,buf_taille,stdin);
     
    buf_nom_fichier[strlen(buf_nom_fichier)-1]='\0';

     
     
 
 
 
}
 



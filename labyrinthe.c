
#include "labyrinthe.h"
void lab_afficher_grille(
 int grille[][TAILLE_MAX_GRILLE],
 int hauteur_grille,
 int largeur_grille,
 int pile_solution[][2]);

int lab_choisir_deplacement( int deplacements_possibles[][2],int nb_deplacements_possibles);

int lab_est_cases_adjacentes(int case1[2], int case2[2]);

int lab_est_une_sortie( int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille);

int lab_resoudre_profondeur(int grille[][TAILLE_MAX_GRILLE],int hauteur_grille,int largeur_grille,int entree[2],int pile_solution[][2], int debug);




void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille);


// FONCTIONS A AJOUTER


void lab_calculer_deplacements_possibles(
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int pos_ligne,
    int pos_colonne,
    int solution_partielle[][2],
    int *nb_deplacements,
    int deplacements[4][2]) {
}

int lab_choisir_deplacement( int deplacements_possibles[][2],int nb_deplacements_possibles) {
}

int lab_est_cases_adjacentes(int case1[2], int case2[2]) {
}

int lab_est_une_sortie( int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille, int largeur_grille) {
}

int lab_resoudre_profondeur(
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int entree[2],
    int pile_solution[][2],
    int debug){
}





void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille) {
}

void lab_afficher_grille(
 int grille[][TAILLE_MAX_GRILLE],
 int hauteur_grille,
 int largeur_grille,
 int pile_solution[][2]) {

}

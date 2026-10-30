
#include "labyrinthe.h"
#include "pile.h"
#include "utilitaires.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


// FONCTIONS A AJOUTER



void lab_afficher_grille(

    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int pile_solution[][2]) {

    for (int i=0; i<hauteur_grille;i++) {
        for (int j=0; j<largeur_grille;j++) {
            if (grille[i][j]==1) {
                printf("%c",219);
            }
            else if (grille[i][j]==0) {
                printf("1");
            }
        }
        printf("\n");
    }


}

void lab_calculer_deplacements_possibles(
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int pos_ligne,
    int pos_colonne,
    int solution_partielle[][2],
    int *nb_deplacements,
    int deplacements[4][2]) {
    *nb_deplacements=0;


    //Verifier en haut
    if ( pos_ligne>0&& ((grille[pos_ligne-1][pos_colonne]==0)) && (!pile_contient(solution_partielle,pos_ligne-1,pos_colonne))){

        deplacements[*nb_deplacements][0] = pos_ligne - 1;
        deplacements[*nb_deplacements][1] = pos_colonne;
        (*nb_deplacements)++;

    }
    //Verifier en bas
    if ( pos_ligne < hauteur_grille - 1 && ((grille[pos_ligne+1][pos_colonne]==0)) && (!pile_contient(solution_partielle,pos_ligne+1,pos_colonne))){

        deplacements[*nb_deplacements][0] = pos_ligne + 1;
        deplacements[*nb_deplacements][1] = pos_colonne;
        (*nb_deplacements)++;

    }
    //Verifier à gauche
    if ( pos_colonne>0 && ((grille[pos_ligne][pos_colonne-1]==0)) && (!pile_contient(solution_partielle,pos_ligne,pos_colonne-1))){

        deplacements[*nb_deplacements][0] = pos_ligne;
        deplacements[*nb_deplacements][1] = pos_colonne-1;
        (*nb_deplacements)++;
    }

    //Verifier à droite
    if ( pos_colonne<largeur_grille-1 && ((grille[pos_ligne][pos_colonne+1]==0)) && (!pile_contient(solution_partielle,pos_ligne,pos_colonne+1))) {
        deplacements[*nb_deplacements][0] = pos_ligne;
        deplacements[*nb_deplacements][1] = pos_colonne+1;
        (*nb_deplacements)++;
    }
}

int lab_choisir_deplacement( int deplacements_possibles[][2],int nb_deplacements_possibles) {
        int indice = nb_aleatoire(0,nb_deplacements_possibles-1);
        return indice;
}

int lab_est_cases_adjacentes(int case1[2], int case2[2]) {

    if (abs(case1[0]-case2[0]) + abs(case1[1]-case2[1])==1) {
     return 1;
    }
    else {
        return 0;
    }

}

int lab_est_une_sortie( int position[2],int grille[][TAILLE_MAX_GRILLE],int hauteur_grille, int largeur_grille) {

    //Si la position en x ou en y est sur un des 4 cote de la grille et si oui alors on regarde si la coordonnees = 0 donc que ce n'est pas un mur
    if (position[0]==0 || position[0]==hauteur_grille -1 || position [1]== 0 || position [1]==largeur_grille -1) {
        if (grille[position[0]][position[1]] == 0) {
            return 1;
        }
    }
    return 0;
}

int lab_resoudre_profondeur(
    int grille[][TAILLE_MAX_GRILLE],
    int hauteur_grille,
    int largeur_grille,
    int entree[2],
    int pile_solution[][2],
    int debug){
}




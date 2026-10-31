/*
Module: labyrinthe.c
Description: Fournit l'ensemble de fonction permettant de r�soudre un labyrinthe
Auteur: Filipe Carvalho - Thomas DiPietro - Zaccarie Jetee
Date: 2026-10-29
*/

//Inclusion Headers
#include "labyrinthe.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



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

    int pile_chemin_alt[1000][2];
    int dep_possible[4][2];
    int nb_deplacement_poss=0;
    int nouvelle_pos[2];
    int position_actuelle[2];



    //INITIALISATION DES PILES
    pile_initialiser(pile_chemin_alt,1000);
    pile_initialiser(pile_solution,1000);

    //Empiler l'entree dans pile solution
    pile_empiler(pile_solution,entree[0],entree[1]);

    pile_haut_pile(pile_solution,&position_actuelle[0],&position_actuelle[1]);

    lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,entree[0],entree[1],pile_solution,&nb_deplacement_poss,dep_possible);

    while ((!lab_est_une_sortie(position_actuelle, grille, hauteur_grille, largeur_grille)
        || (position_actuelle[0] == entree[0] && position_actuelle[1] == entree[1]))
        && nb_deplacement_poss > 0) {

        pile_haut_pile(pile_solution,&position_actuelle[0],&position_actuelle[1]);
        lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,
        position_actuelle[0],position_actuelle[1],pile_solution,&nb_deplacement_poss,dep_possible);

        //Si on a des deplacements possible
        if (nb_deplacement_poss>0) {
            //EMPILER DEPLACEMENT CHOISIS
            int indice =lab_choisir_deplacement(dep_possible,nb_deplacement_poss);
            pile_empiler(pile_solution,
            dep_possible[indice][0],
            dep_possible[indice][1]);

            //EMPILER LES AUTRES DEPLACEMENTS DIFFERENTS DE L'INDICE
            for (int i=0; i<nb_deplacement_poss; i++) {
                if (i!=indice) {
                    pile_empiler(pile_chemin_alt,dep_possible[i][0],dep_possible[i][1]);
                }
            }
        }

        //Si on a encore des chemins possibles a tester
        else if (!pile_est_vide(pile_chemin_alt)){

            pile_depiler(pile_chemin_alt,&nouvelle_pos[0],&nouvelle_pos[1]);

            pile_haut_pile(pile_solution,&position_actuelle[0],&position_actuelle[1]);
            while (!lab_est_cases_adjacentes(position_actuelle,nouvelle_pos)){

                pile_depiler(pile_solution,&position_actuelle[0],&position_actuelle[1]);
                pile_haut_pile(pile_solution,&position_actuelle[0],&position_actuelle[1]);
            }

            pile_empiler(pile_solution,nouvelle_pos[0],nouvelle_pos[1]);
        }

        //Il n'y a plus de chemins possibles a tester
        else {
            //printf("Il n'est plus possible de ce deplacer!");
            break;
        }
    }

    if (lab_est_une_sortie(position_actuelle,grille,hauteur_grille,largeur_grille) && (position_actuelle[0] != entree[0] || position_actuelle[1] != entree[1] )) {
        return 1;
    }

    else {
        printf("Il n'est plus possible de ce deplacer!");
        return 0;
    }

}



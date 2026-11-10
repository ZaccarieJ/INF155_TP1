/*
TP2 - Labyrinthe
Ce projet vise a resoudre un labyrinthe en trouvant un chemin qui nous mene vers
la sortie du labyrinthe en partant de son entree.
Auteurs: Filipe Carvalho - Thomas DiPietro - Zaccarie Jetee
Date: 2026-10-29
*/

//Inclusion Headers
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"
#include <time.h>
#include "utilitaires.h"
#define TAILLE_MAX_PILE 1000 //La taille maximale des piles

int main(void)
{
	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
	int point_entree[2]; //Stocke les coordonn�es du point d'entr�e du labyrinthe lors du chargement
	int hauteur_grille, largeur_grille; //Stocke la taille de la grille charg�e depuis le disque
	int succes_chargement; //Stocke une valeur vraie si la grille a �t� charg�e correctement.
	int sol_partielle[TAILLE_MAX_GRILLE][2];
	int deplacements[4][2];
	int nb_dep_poss =0;
	int pile_sol_final[TAILLE_MAX_PILE][2];
	int debug=2;
	char nom_grille[100];
	int grille_chargee = 0;
	int test = 0;

	//Initialisation de toutes les piles
	pile_initialiser(sol_partielle,TAILLE_MAX_GRILLE);
	pile_initialiser(pile_sol_final,TAILLE_MAX_PILE);

	//Initialiser le generateur de nombre aleaoire
	srand((unsigned int)time(NULL));

// Afficher le menu et executer les choix de l'utilisateur
while (test == 0) {
	switch (selection_menu(grille_chargee)) {
		case 1:
			//charger le labyrinthe
			menu_charger_labyrinthe(nom_grille, 100);
			succes_chargement=charger_labyrinthe(nom_grille, grille, point_entree, &hauteur_grille, &largeur_grille);
			if (!succes_chargement)
			{
				printf("Une erreur s'est produite lors du chargement de la grille.\n");
				printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
				system("pause");

			}else {
				printf("Chargement de la grille fait avec succes! \n");
				lab_afficher_grille(grille, hauteur_grille, largeur_grille, pile_sol_final);
				grille_chargee=1;
			}
			break;

		case 2:
			// Afficher la grille seulement si elle a ete chargee
			if (grille_chargee == 1) {
				lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_sol_final);
				break;
			}else {
				printf("Veuillez charger la grille avant de l'afficher\n");
				break;
			}
		case 3:
			//RESOLUTION DU LABYRINTHE EN MODE NORMAL
			if (grille_chargee == 1) {
				// Lancer la resolution et recuperer son resultat
				int solution_trouver = lab_resoudre_profondeur(
					grille,
					hauteur_grille,
					largeur_grille,
					point_entree,
					pile_sol_final,
					0
				);
				// Afficher la solution si le labyrinthe est resolu
				if (solution_trouver == 1) {
					lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_sol_final);
					printf("Le labyrinthe a ete resolu!\n");
				}
				else {
					lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_sol_final);
					printf("Le labyrinthe ne peut donc pas etre resolu!\n");
				}
				system("pause");
				return EXIT_SUCCESS;
				break;
			}
		case 4:
			//RESOLUTION DU LABYRINTHE EN MODE DEBUG
			if (grille_chargee == 1) {
				int solution_trouver = lab_resoudre_profondeur(
					grille,
					hauteur_grille,
					largeur_grille,
					point_entree,
					pile_sol_final,
					1
				);
				if (solution_trouver == 1) {
					lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_sol_final);
					printf("Le labyrinthe a ete resolu!\n");
				}
				else {
					lab_afficher_grille(grille,hauteur_grille,largeur_grille,pile_sol_final);
					printf("Le labyrinthe ne peut donc pas etre resolu!\n");
				}
				system("pause");
				return EXIT_SUCCESS;
				break;
			}
			else {
				printf("Veuillez charger la grille avant de la résoudre\n");
				break;
			}
		}
	}
}


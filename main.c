/**
TP2 - Labirynthe
Ce projet vise � r�soudre un labyrinthe en trouvant un chemin qui nous mne vers
la sortie du labyrinthe en partant de son entr�e.


Auteurs: Filipe Carvalho - Thomas DiPietro - Zaccarie Jetee

Date:

**/


#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "labyrinthe.h"
#include "labyrinthe_io.h"

#define TAILLE_MAX_PILE 1000 //La taille maximale des piles
//Liste des prototypes

int main(void)
{
	//NOTE: Ce code vous est fourni � titre d'exemple pour que vous compreniez
	//le fonctionnement d'une pile. Vous ne devez pas conserver ce code avec votre projet!
	int la_pile[TAILLE_MAX_PILE][2]; //Tableau qui sera utilis� pour stocker la pile d'exemple
	int depile_x; //Stocke la coordonn�e x d�pil�e
	int depile_y; //Stocke la coordonn�e y d�pil�e

	int grille[TAILLE_MAX_GRILLE][TAILLE_MAX_GRILLE]; //Tableau 2D qui contient la grille du labyrinthe
	int point_entree[2]; //Stocke les coordonn�es du point d'entr�e du labyrinthe lors du chargement
	int hauteur_grille, largeur_grille; //Stocke la taille de la grille charg�e depuis le disque
	int succes_chargement; //Stocke une valeur vraie si la grille a �t� charg�e correctement.

	/*** PARTIE 1: FONCTIONNEMENT DE LA PILE ***/
	//On initialise la pile
	pile_initialiser(la_pile, TAILLE_MAX_PILE);

	//On empile un ensemble de valeurs...
	pile_empiler(la_pile, 10, 5);
	pile_empiler(la_pile, 11, 6);
	pile_empiler(la_pile, 12, 7);
	pile_empiler(la_pile, 19, 8);
	pile_empiler(la_pile, 5, 3);
	pile_empiler(la_pile, 0, 1);
	pile_empiler(la_pile, 21, 8);

	//ajouter par moi
	int sol_partielle[TAILLE_MAX_GRILLE][2];
	int deplacements[4][2];
	int nb_dep_poss =0;
	//On regarde ce qui se trouve en haut de la pile, sans le d�piler
	pile_haut_pile(la_pile, &depile_y, &depile_x);
	printf("Le haut de la pile contient la coordonn�e: (%d, %d)\n", depile_y, depile_x);

	//On v�rifie si certaines coordonn�es se trouvent dans la pile
	if (pile_contient(la_pile, 12, 7))
	{
		printf("La pile contient bien la coordonnee 12,7\n");
	}
	else
	{
		printf("La coordonnee 12,7 n'est pas dans la pile!\n");
	}
	if (pile_contient(la_pile, 45, 8))
	{
		printf("La pile contient bien la coordonnee 45,8\n");
	}
	else
	{
		printf("La coordonnee 45,8 n'est pas dans la pile!\n");
	}

	//On d�pile tous les �l�ments de la pile en les affichant, jusqu'� ce qu'elle soit vide.
	//Vous remarquerez que le dernier ajout� s'affiche en premier.
	printf("\n*** Contenu de la pile: ***\n");
	while (!pile_est_vide(la_pile))
	{
		pile_depiler(la_pile, &depile_y, &depile_x);
		printf("(%d, %d)\n", depile_y, depile_x);
	}

	/*** PARTIE 2: CHARGEMENT D'UNE GRILLE DEPUIS LE DISQUE ***/
	printf("\n\n");

	succes_chargement=charger_labyrinthe("../grille1.txt", grille, point_entree, &hauteur_grille, &largeur_grille);
	//AFFICHER GRILLE
	lab_afficher_grille(grille,hauteur_grille,largeur_grille,NULL);
	if (!succes_chargement)
	{
		printf("Une erreur s'est produite lors du chargement de la grille.\n");
		printf("Verifiez que le fichier de la grille se trouve bien dans le dossier du projet.\n");
		system("pause");
		return EXIT_FAILURE;
	}

	//Si on est ici, c'est que le chargement s'est bien pass�.
	printf("La grille comporte: %d lignes et %d colonnes\n", hauteur_grille, largeur_grille);
	printf("Le point d'entree se trouve � la coordonn�e (%d, %d)\n", point_entree[0], point_entree[1]);

	if (grille[0][9] == 1)
	{
		printf("La case (0,9) est un mur.\n");
	}
	else
	{
		printf("La case (0,9) est un couloir.\n");
	}

	if (grille[3][10] == 1)
	{
		printf("La case (3,10) est un mur.\n");
	}
	else
	{
		printf("La case (3,10) est un couloir.\n");
	}

	pile_initialiser(sol_partielle,TAILLE_MAX_GRILLE);
	pile_empiler(sol_partielle, 0, 10);
	pile_empiler(sol_partielle, 1, 10);
	pile_empiler(sol_partielle, 1, 9);
	pile_empiler(sol_partielle, 1, 8);
	pile_empiler(sol_partielle, 2, 8);
	pile_empiler(sol_partielle, 3, 8);
	pile_empiler(sol_partielle, 3, 9);

	//pile_empiler(sol_partielle, 3, 10);
	lab_afficher_grille(grille,hauteur_grille,largeur_grille,sol_partielle);
	lab_calculer_deplacements_possibles(grille,hauteur_grille,largeur_grille,3,8,sol_partielle,&nb_dep_poss,deplacements);

	printf("nb dep poss: %d\n",nb_dep_poss);
	for (int i=0; i<nb_dep_poss;i++) {
		printf("%d,%d\n",deplacements[i][0],deplacements[i][1]);
	}


	system("pause");
	return EXIT_SUCCESS;

}


/*
Module: labyrinthe_io
Auteur: Filipe Carvalho - Thomas DiPietro - Zaccarie Jetee
Date: 
*/

//Inclusion Headers
#include "labyrinthe_io.h"

int charger_labyrinthe(char* nom_fichier, int grille[][TAILLE_MAX_GRILLE], int point_entree[2], int* hauteur_grille, int* largeur_grille)
{
	FILE* fichier;
	char caractere_lu;
	int i = 0, //Compteurs d'indices dans le tableau
		j = 0;
	fichier = fopen(nom_fichier, "r");
	if (!fichier)
	{
		return 0;
	}
	*largeur_grille = -1;
	*hauteur_grille = -1;

	while ((caractere_lu = getc(fichier)) != EOF)
	{
		switch (caractere_lu)
		{
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
				printf("ERREUR DE LECTURE: Les lignes du labyrinthe n'ont pas toutes le m�me nombre de colonnes.\n");
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
// Demander le nom du fichier contenant le labyrinthe
void menu_charger_labyrinthe(char* buf_nom_fichier, int buf_taille) {
	printf("Veuillez saisir un nom de fichier valide(forme : ../nom de la grille.txt): ");
	// Lire le nom du fichier puis retier le "Enter"
	fgets(buf_nom_fichier, buf_taille, stdin);
	buf_nom_fichier[strlen(buf_nom_fichier) - 1] = '\0';
}
// Afficher le menu et lire le choix de l'utilisateur
int selection_menu(int grille_chargee) {
	int choix = 0;

	while (choix < 1 || choix > 4) {
		printf("\n--- MENU LABYRINTHE ---\n");
		printf("1 - Charger un labyrinthe\n");
		printf("2 - Afficher le labyrinthe\n");
		printf("3 - Resoudre le labyrinthe en mode normal\n");
		printf("4 - Resoudre le labyrinthe en mode debug\n");
		printf("Votre choix : ");
		scanf("%d", &choix);
		FFLUSH();
		return choix;
	}
}
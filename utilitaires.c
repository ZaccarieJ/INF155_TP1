/*
Module: utilitaire.c
Description: Fournit des fonctions utilies afin de resoudre le labyrinthe
Auteur: Filipe Carvalho - Thomas DiPietro - Zaccarie Jetee
Date: 2026-10-29
*/

//Inclusion Headers
#include "utilitaires.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int nb_aleatoire(int min, int max){
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}
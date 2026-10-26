#include "pile.h"
#include "utilitaires.h"
#include "labyrinthe.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int nb_aleatoire(int min, int max){
    return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}
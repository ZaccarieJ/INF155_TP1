cmake_minimum_required(VERSION 4.3)
project(INF155_TP1 C)

set(CMAKE_C_STANDARD 11)

add_executable(INF155_TP1 main.c labyrinthe.h labyrinthe_io.c labyrinthe_io.h pile.h pile.c
        labyrinthe.c
        utilitaires.c
        utilitaires.h)





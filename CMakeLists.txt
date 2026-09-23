cmake_minimum_required(VERSION 4.3)
project(PROJET C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(PROJET
        ADDITION.c
        "COMBINAISON LINEAIRE.c"
        DETERMINANT.c
        DIAGONALISATION.c
        hessenberg.c
        INVERSE.c
        main.c
        MENU.c
        "MULTIPLICATION PAR SCALAIRE.c"
        MULTIPLICATION.c
        PROTOTYPES.h
        RANG.c
        SOUSTRACTION.c
        "systeme d_equation.c"
        TRACE.c
        TRANSPOSE.c
        TRIANGULARISATION.c
        "VALEUR PROPRE2.c")

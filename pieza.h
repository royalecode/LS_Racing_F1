//
// Created by artur on 10/04/2020.
//

#ifndef GRUPO_4_PIEZA_H
#define GRUPO_4_PIEZA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones_Basicas.h"

typedef struct {
    char nombre[25];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
}Pieza;

typedef struct {
    char nombre[25];
    int cantidad;
    Pieza *piezas;
}Categoria;

typedef struct {
    int numeroCategorias;
    Categoria *categorias;
}CategoriaPiezas;

int leerPiezas(char* path, CategoriaPiezas *categoriaPiezas);

#endif //GRUPO_4_PIEZA_H

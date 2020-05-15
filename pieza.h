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
    char nombre[MAX_STRING];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
}Pieza;

typedef struct {
    char nombre[MAX_STRING];
    int cantidad;
    Pieza *piezas;
}Categoria;

typedef struct {
    int numeroCategorias;
    Categoria *categorias;
}CategoriaPiezas;


/**
 * Función que lee toda la información del fichero de piezas
 * @param path              String que contiene la ruta del fichero
 * @param categoriaPiezas   Estructura donde guardaremos la información
 * @return                  Devuelve un 1 si ha habido algún error
 */
int leerPiezas(char* path, CategoriaPiezas *categoriaPiezas);

#endif //GRUPO_4_PIEZA_H

//
// Created by artur on 10/04/2020.
//

#ifndef GRUPO_4_PIEZA_H
#define GRUPO_4_PIEZA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones_Basicas.h"

/**
 * Estructura de los atributos particulares de cada pieza
 */
typedef struct {
    char nombre[MAX_STRING];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
}Pieza;

/**
 * Estrucutra para almacenar la información de cata categoria que estara formada por un array dinàmico de x piezas
 */
typedef struct {
    char nombre[MAX_STRING];
    int cantidad;
    Pieza *piezas;
}Categoria;

/**
 * Estrucutra globla de categorias que contiene un array dinàmico con la cantidad de categorias del proyecto
 */
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

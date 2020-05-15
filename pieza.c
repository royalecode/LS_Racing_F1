//
// Created by artur on 10/04/2020.
//

#include "pieza.h"


/**
 * Lee del fichero de piezas la información de una pieza
 * @param file  Puntero del archivo de lectura
 * @param pieza Estructura donde guardaremos la información
 */
void leerPieza(FILE *file, Pieza *pieza){
    fscanfString(file, pieza->nombre);
    pieza->velocidad = fscanfNumber(file);
    pieza->aceleracion = fscanfNumber(file);
    pieza->consumo = fscanfNumber(file);
    pieza->fiabilidad = fscanfNumber(file);
}

/**
 * Lee del fichero de piezas la información de una categoria incluidas sus piezas
 * @param file          Puntero del archivo de lectura
 * @param categoria     Estructura donde guardaremos la información
 */
void leerCategoria(FILE *file, Categoria *categoria){
    int i;
    fscanfString(file, categoria->nombre);
    categoria->cantidad = fscanfNumber(file);
    categoria->piezas = (Pieza*) malloc(sizeof(Pieza)*categoria->cantidad);

    for (i = 0; i < categoria->cantidad; ++i) {
        leerPieza(file, &categoria->piezas[i]);
    }
}

/**
 * Función que lee toda la información del fichero de piezas
 * @param path              String que contiene la ruta del fichero
 * @param categoriaPiezas   Estructura donde guardaremos la información
 * @return                  Devuelve un si ha habido algun error
 */
int leerPiezas(char* path, CategoriaPiezas *categoriaPiezas){
    FILE *file;
    int i, err = 0;

    file = fopen(path, "r");
    if (file == NULL){
        err = 1;
    }else{
        categoriaPiezas->numeroCategorias = fscanfNumber(file);
        categoriaPiezas->categorias = (Categoria*) malloc(sizeof(Categoria) * categoriaPiezas->numeroCategorias);

        for (i = 0; i < categoriaPiezas->numeroCategorias; ++i) {
            leerCategoria(file, &categoriaPiezas->categorias[i]);
        }
        if (categoriaPiezas->numeroCategorias == 0) err = 2;
        fclose(file);
    }
    return err;
}





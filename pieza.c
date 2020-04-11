//
// Created by artur on 10/04/2020.
//

#include "pieza.h"

void leerPieza(FILE *file, Pieza *pieza){
    fscanfString(file, pieza->nombre);
    pieza->velocidad = fscanfNumber(file);
    pieza->aceleracion = fscanfNumber(file);
    pieza->consumo = fscanfNumber(file);
    pieza->fiabilidad = fscanfNumber(file);
}

void leerCategoria(FILE *file, Categoria *categoria){
    int i;

    fscanfString(file, categoria->nombre);
    categoria->cantidad = fscanfNumber(file);
    categoria->piezas = (Pieza*) malloc(sizeof(Pieza)*categoria->cantidad);

    for (int i = 0; i < categoria->cantidad; ++i) {
        leerPieza(file, &categoria->piezas[i]);
    }
}

int leerPiezas(char* path, CategoriaPiezas *categoriaPiezas){
    FILE *file;
    char line[1000];
    int i, err = 0;

    file = fopen(path, "r");
    if (file == NULL){
        printf("ERROR: El fichero de piezas '%s' no es accesible.\n", path);
        err = 1;
    }else{
        categoriaPiezas->numeroCategorias = fscanfNumber(file);
        categoriaPiezas->categorias = (Categoria*) malloc(sizeof(Categoria) * categoriaPiezas->numeroCategorias);

        for (i = 0; i < categoriaPiezas->numeroCategorias; ++i) {
            leerCategoria(file, &categoriaPiezas->categorias[i]);
        }
    }
    return err;
}





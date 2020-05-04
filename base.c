//
// Created by edmon on 22/4/2020.
//

#include "base.h"

/**
 * Función dedicada a leer el fichero base que recibe el programa por parámetro en el main. Proporciona estadísticas básicas
 * de los cohces
 * @param ruta      Ruta para poder abrir el fichero que se pide que leamos
 * @param base      Estructura donde guardaremos la información de las características básicas de los coches
 */
int leerBase(char* ruta, Base *base){
    FILE *file;
    int err = 0;

    file = fopen(ruta, "rb");
    if(file == NULL){
        err = 1;
    }else if(ftell(file) == 0){
        err = 2;
    }else{
        fread(base, sizeof(Base), 1, file);
        //printf("%d\n%d\n", base->fiabilidad, base->consumo);
    }
    fclose(file);
    return err;
}
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
void leerBase(char* ruta, Base *base){
    FILE *file;
    file = fopen(ruta, "rb");
    if(file == NULL){
        printf("Error. El fichero de %s no es accesible.\n", ruta);
    }else{
        fread(base, sizeof(Base), 1, file);
        //printf("%d\n%d\n", base->fiabilidad, base->consumo);
    }
    fclose(file);
}
//
// Created by artur on 12/04/2020.
//

#include "premio.h"

/**
 * Lee del fichero de GPs la información de un premio
 * @param file      Puntero del archivo de lectura
 * @param premios   Lista donde guardaremos la información
 */
void leerPremio(FILE *file, ListaGPs *premios){
    Premio premio;
    premio.posicion = fscanfNumber(file);
    fscanfString(file, premio.nombre);
    premio.velocidad = fscanfNumber(file);
    premio.aceleracion = fscanfNumber(file);
    premio.consumo = fscanfNumber(file);
    premio.fiabilidad = fscanfNumber(file);
    premio.tiempoBase = fscanfFloat(file);
    premio.tiempoPitStop = fscanfNumber(file);
    premio.numPitStop = fscanfNumber(file);
    *premios = LISTAGPS_insertaOrd(*premios, premio);
}

/**
 * Función que lee toda la información del fichero de GPs
 * @param path              String que contiene la ruta del fichero
 * @param ListaGPs          Lista ordenada donde guardaremos la información
 * @return                  Devuelve un si ha habido algun error
 */
int leerPremios(char* path, ListaGPs *premios){
    FILE *file;
    int i, err = 0;

    file = fopen(path, "r");
    if (file == NULL){
        err = 1;
    }else{
        premios->numPremios = fscanfNumber(file);

        for (i = 0; i < premios->numPremios; ++i) {
            leerPremio(file, premios);
        }
        if (premios->numPremios == 0) err = 2;
        fclose(file);
    }
    return err;
}




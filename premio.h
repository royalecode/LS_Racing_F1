//
// Created by artur on 12/04/2020.
//

#ifndef GRUPO_4_PREMIO_H
#define GRUPO_4_PREMIO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones_Basicas.h"
#include "listaGPs.h"

/**
 * Función que lee toda la información del fichero de GPs
 * @param path              String que contiene la ruta del fichero
 * @param ListaGPs          Lista ordenada donde guardaremos la información
 * @return                  Devuelve un si ha habido algun error
 */
int leerPremios(char* path, ListaGPs *premios);

#endif //GRUPO_4_PREMIO_H

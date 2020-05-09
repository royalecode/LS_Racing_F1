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

typedef struct {
    int numPremios;
    int *premios;
}Premios;

int leerPremios(char* path, ListaGPs *premios);

#endif //GRUPO_4_PREMIO_H

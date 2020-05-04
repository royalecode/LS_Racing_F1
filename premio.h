//
// Created by artur on 12/04/2020.
//

#ifndef GRUPO_4_PREMIO_H
#define GRUPO_4_PREMIO_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones_Basicas.h"

typedef struct {
    int posicion;
    char nombre[MAX_STRING];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
    float tiempoBase;
    int tiempoPitStop;
    int numPitStop;
}Premio;

typedef struct {
    int numPremios;
    Premio *premios;
}Premios;

int leerPremios(char* path, Premios *premios);

#endif //GRUPO_4_PREMIO_H

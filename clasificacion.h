//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_CLASIFICACION_H
#define GRUPO_4_CLASIFICACION_H

#include "premio.h"
#include "carrera.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LS_allegro.h"

typedef struct {
    int tiempo_carrera;
    int posicion;
    char nombre[25];
    int puntos;
}Info_Class;

typedef struct {
    char nombreGP[25];
    Info_Class *clas;
}Info_Class_GP;

typedef struct {
    Info_Class_GP *clas_GPs;
}Clasificacion;

void guardarClasificacion(Tiempos *tiempos, Premios *premios, Clasificacion *clasificacion ,int num);
void printarClasificacion(Clasificacion *clasificacion, int num);
//ordenacionPilotos();

#endif //GRUPO_4_CLASIFICACION_H

//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_CARRERA_H
#define GRUPO_4_CARRERA_H

#include <stdio.h>
#include <stdlib.h>
#include "LS_allegro.h"
#include "premio.h"
#include <time.h>
#include "corredores.h"

typedef struct{
    int tiempo_carrera;
    int tiempo_stops;
    int pixels_seg;
    int dorsal;
}Tiempos;

void printarInfoCarrera(Premios *premios, int num);
void mostrarSemaforo();
void mostrarCarrera();
void controlPitStops();
void calcularTiempo(ConjuntoCorredores *pilotos, Premios *premios, int num);
void mostrarFinalCarrera();
void cargarCarrera(Premios *premios, ConjuntoCorredores *pilotos, int num);

#endif //GRUPO_4_CARRERA_H

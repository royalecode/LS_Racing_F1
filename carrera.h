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
#include "tipos.h"
#include "tiempo.h"
#define NUM_PILOTS 8

typedef struct{
    int tiempo_carrera;
    int tiempo_stops;
    int pixels_seg;
    int dorsal;
    int num_stops;
}Tiempos;

void printarInfoCarrera(Premios *premios, int num);
void mostrarSemaforo(int vermelles);
void mostrarCarrera(Corredor *piloto, Tiempos *tiempos);
void calcularTiempo(ConjuntoCorredores *pilotos, Premios *premios, Tiempos *tiempos, Corredor *piloto, int num);
void mostrarFinalCarrera();
void cargarCarrera(Premios *premios, ConjuntoCorredores *pilotos, Tiempos *tiempos, Corredor *piloto, int num);

#endif //GRUPO_4_CARRERA_H

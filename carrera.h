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

void printarInfoCarrera(Premios *premios, int num);
void mostrarSemaforo();
void mostrarCarrera();
void controlPitStops();
void calcularRendimiento();
void mostrarFinalCarrera();
void cargarCarrera(Premios *premios, int num);

#endif //GRUPO_4_CARRERA_H

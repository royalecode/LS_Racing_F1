//
// Created by edmon on 18/4/2020.
//

#ifndef GRUPO_4_CORREDORES_H
#define GRUPO_4_CORREDORES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones_Basicas.h"

typedef struct{
    char nombre[25];
    int dorsal;
    char escuderia[25];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
    int reflejos;
    int cond_fisica;
    int temperamento;
    int gestion_neumaticos;
}Corredores;

typedef struct {
    int num_corredors;
    Corredores *corredores;
}ConjuntoCorredores;

int leerCorredores(char* path, ConjuntoCorredores *Pilotos);

#endif //GRUPO_4_CORREDORES_H

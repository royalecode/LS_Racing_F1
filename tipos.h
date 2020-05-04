//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_TIPOS_H
#define GRUPO_4_TIPOS_H

#include "funciones_Basicas.h"

typedef struct{
    char nombre[MAX_STRING];
    int dorsal;
    char escuderia[MAX_STRING];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
    int reflejos;
    int cond_fisica;
    int temperamento;
    int gestion_neumaticos;
}Corredor;

#endif //GRUPO_4_TIPOS_H

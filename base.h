//
// Created by edmon on 22/4/2020.
//
#ifndef GRUPO_4_BASE_H
#define GRUPO_4_BASE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
}Base;

void leerBase(char* ruta, Base *base);

#endif //GRUPO_4_BASE_H

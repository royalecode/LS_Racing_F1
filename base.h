//
// Created by edmon on 22/4/2020.
//
#ifndef GRUPO_4_BASE_H
#define GRUPO_4_BASE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Estructura definida para leer las estadísitcas básicas de los coches
 */
typedef struct{
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
}Base;

/**
 * Función dedicada a leer el fichero base que recibe el programa por parámetro en el main. Proporciona estadísticas básicas
 * de los cohces
 * @param ruta      Ruta para poder abrir el fichero que se pide que leamos
 * @param base      Estructura donde guardaremos la información de las características básicas de los coches
 */
int leerBase(char* ruta, Base *base);

#endif //GRUPO_4_BASE_H

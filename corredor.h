//
// Created by edmon on 18/4/2020.
//

#ifndef GRUPO_4_CORREDOR_H
#define GRUPO_4_CORREDOR_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

typedef struct {
    int num_corredors;
    Corredor *corredores;
}Corredores;

/**
 * Función para leer el fichero con la información de corredores que se pasa por parámetro en el main
 * @param path      la ruta podriamos decir para encontrar el fichero y poderlo abrir
 * @param pilotos   Estructura donde vamos a guardar la información de todos los pilotos
 * @return          Devuelve un entero que nos permitira saber si ha habido algún error a la hora de abrir el fichero
 */
int leerCorredores(char* path, Corredores *Pilotos);

#endif //GRUPO_4_CORREDOR_H

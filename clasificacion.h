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
    char nombre[MAX_STRING];
    int puntos;
    int dorsal;
}Info_Class;

typedef struct {
    char nombreGP[MAX_STRING];
    Info_Class *clas;
}Info_Class_GP;

typedef struct {
    int numClasificaciones;
    Info_Class_GP *clas_GPs;
}Clasificacion;

/**
 * Esta función se ejecuta en la opción 2 para guardar la clasificación del gran premio, para luego utilitzarla en la opción 3
 * Su función es ordenar los pilotos según el tiempo que hayan tardado en realizar la carrera, y por lo tanto determinar su posición
 * en el campeonato y darles los puntos ganados según la posición
 * @param tiempos           Estructura donde tenemos la información de timepo carrera para cada piloto
 * @param premios           Necesitamos para guardar el nombre del gran premio en concreto que se ha cursado
 * @param clasificacion     Estructura donde guardaremos la clasificación de todos los gran premios
 * @param num               Gran premio en el cual nos encontramos
 * @param posicion          Puntero para aconseguir la posición de nuestro propio piloto para más tarde printarla por pantalla
 */
void guardarClasificacion(Tiempos *tiempos, Premio premio, Clasificacion *clasificacion, int num, int *posicion);

/**
 * Función que printa por pantalla la información de la clasificación del gran premio en concreto que se le concreta por
 * parámetro
 * @param clasificacion     Estrucutra de donde extraemos la información a imprimir
 * @param num               Numero del gran premio que nos encontramos actualmente
 */
void printarClasificacion(Clasificacion *clasificacion, int num);

/**
 * Esta función es encargada de llammar la que imprime la interfaz gràfica de clasificación y a la vez controlar las teclas por
 * teclado para saber si quiere volver al menú o bien visualizar la clasificación de anteriores o posteriores gran premios
 * @param clasificacion     Estrucutra donde hay guardada todas las clasificaciones
 * @param num               Numero del gran premio que nos encontramos actualmente
 * @param max_Gp            El maximo de gran premios que se juegan en una temporada
 */
void mostrarClasificacion(Clasificacion *clasificacion, int num, int max_Gp);

/**
 * Función encargada de imprimir por pantalla la clasificación total del final de la temporada
 * @param clasificacion         Estructura donde se guarda toda la información de clasificaciones
 * @param num                   Numero del gran premio que nos encontramos actualmente
 */
void imprimirClasFinalTemp(Clasificacion *clasificacion, int num);

/**
 * Función para ordenar los pilotos y conseguir su clasificación final de temporada según los puntos que hayan conseguido
 * en total
 * @param final             Estructura donde guardaremos la clasificación final de temporada específicamente
 * @param clasificacion     Estructura donde se guarda toda la información de clasificaciones
 * @param num               Numero del gran premio que nos encontramos actualmente
 */
void ordenacionPilotos_Puntos(Info_Class_GP *final, Clasificacion *clasificacion, int num);

#endif //GRUPO_4_CLASIFICACION_H

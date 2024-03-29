#ifndef GRUPO_4_LISTAGPS_H
#define GRUPO_4_LISTAGPS_H

#include <stdio.h>
#include <stdlib.h>
#include "funciones_Basicas.h"

/**
 * Lista Ordeana adaptada a contener estructuras del tipo Premio
 */

/**
 * Estructura específica para guardar los atributos de un gran premio
 */
typedef struct {
    int posicion;
    char nombre[MAX_STRING];
    int velocidad;
    int aceleracion;
    int consumo;
    int fiabilidad;
    float tiempoBase;
    int tiempoPitStop;
    int numPitStop;
}Premio;

/**
 * Estructura que define que cada nodo de la lista va alamcenar un gran premio en particular
 */
typedef struct N {
    Premio elemento;
    struct N *sig;
} Nodo;

/**
 * Estructura para controlar con punteros la inserción y diferentes metodos de la lista ordenada
 */
typedef struct {
    int numPremios;
    Nodo *pri;
    Nodo *ant;
} ListaGPs;


ListaGPs LISTAGPS_crea();

ListaGPs LISTAGPS_insertaOrd(ListaGPs l, Premio elemento);

ListaGPs LISTAGPS_elimina(ListaGPs l);

Premio LISTAGPS_consulta(ListaGPs l);

ListaGPs LISTAGPS_avanza(ListaGPs l);

ListaGPs LISTAGPS_vesInicio(ListaGPs l);

int LISTAGPS_final(ListaGPs l);

int LISTAGPS_vacia(ListaGPs l);

ListaGPs LISTAGPS_destruye(ListaGPs l);

#endif //GRUPO_4_LISTAGPS_H

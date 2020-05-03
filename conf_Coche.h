//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_CONF_COCHE_H
#define GRUPO_4_CONF_COCHE_H

#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include <string.h>
#include "pieza.h"
#include "funciones_Basicas.h"
#include "LS_allegro.h"

/**
 * Procedimiento que pide al usuario por terminal distintos datos del piloto
 * @param piloto Esctructura donde guarda los datos
 */
void leerPiloto(Corredor *piloto);

/**
 * Procedimiento que engloba todo el garaje, desde sus controles hasta la gestion de los datos
 * @param piloto            Estructura Piloto
 * @param categoriaPiezas   Estructura Piezas
 * @param piezas            Array configuracion actual
 */
void mostrarGaraje(Corredor *piloto, CategoriaPiezas categoriaPiezas, Pieza* piezas);

#endif //GRUPO_4_CONF_COCHE_H

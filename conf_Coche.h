//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_CONF_COCHE_H
#define GRUPO_4_CONF_COCHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pieza.h"
#include "funciones_Basicas.h"
#include "LS_allegro.h"
#include "corredor.h"


/*
 * Constantes de textos
 */

#define TEXT_W "w"
#define TEXT_A "a"
#define TEXT_S "s"
#define TEXT_D "d"
#define TEXT_VEL "Velocitat"
#define TEXT_ACC "Acceleració"
#define TEXT_CON "Consum"
#define TEXT_FIA "Fiabilitat"
#define TEXT_CONF1 "CONFIGURACIO"
#define TEXT_CONF2 "ACTUAL"
#define TEXT_CONF3 "Configuración del Coche"
#define TEXT_ESC "(ESC): SALIR"


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

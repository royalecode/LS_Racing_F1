//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_MENU_H
#define GRUPO_4_MENU_H

#include <stdio.h>
#include <string.h>
#include "LS_allegro.h"
#include "funciones_Basicas.h"

/**
 * Función utilitzada para printar el menu del programa cada vez que sea necesario
 */
void printarMenu();

/**
 * Función que lee por teclado la opción que introduce el usuario, este entra una cadena de carácteres que se transforma
 * en un entero
 * @return      Devolvemos el entero que el usuario ha introducido como opción del menu
 */
int leer_opcion();

/**
 * Procedimiento que informa de los posibles errores con la lectura de ficheros inicial
 */
void printFileErr(int err);

#endif //GRUPO_4_MENU_H

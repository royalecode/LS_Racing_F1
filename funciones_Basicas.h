//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_FUNCIONES_BASICAS_H
#define GRUPO_4_FUNCIONES_BASICAS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING 25+1

/**
 * Comprueba si todos los elementos de una string són números
 * @param str
 * @return boolea
 */
int isNumber(char *str);

/**
 * Escanea un número y comprueba que este entre el max y el min definidos.
 * @param min   Valor mínimo permitido
 * @param max   Valor máximo permitido
 * @param msg   Mensaje de error
 * @return      Devuelve el valor escaneado
 */
int scanRange(int min, int max, char *msg);

/**
 * Función que escanea el numero entero de una linea de un fichero de texto
 * @param file
 * @return
 */
int fscanfNumber(FILE *file);

/**
 * Función que escanea el número decimal de una linea de un fichero de texto
 * @param file
 * @return
 */
float fscanfFloat(FILE *file);

/**
 * Función que escanea una cadena de caràcteres de una linia de un fichero de texto
 * @param file
 * @return
 */
void fscanfString(FILE *file, char *line);

#endif //GRUPO_4_FUNCIONES_BASICAS_H

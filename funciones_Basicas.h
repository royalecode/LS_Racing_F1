//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_FUNCIONES_BASICAS_H
#define GRUPO_4_FUNCIONES_BASICAS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int isNumber(char *str);
int scanRange(int min, int max, char* msg);
//int atoi(const char *cad);
int control_numero(int num, int a, int b);
int fscanfNumber(FILE* file);
float fscanfFloat(FILE* file);
void fscanfString(FILE* file, char* line);

#endif //GRUPO_4_FUNCIONES_BASICAS_H

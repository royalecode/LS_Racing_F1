//
// Created by edmon on 23/3/2020.
//

#include "funciones_Basicas.h"

//funcion que mira si un caracter es numerico o no, es decir entre el 0 y el 9
int control_numero(int num, int a, int b){
    if(num >= a && num <= b){
        return 1;
    } else{
        return 0;
    }
}

//la funcion atoi nos va a transformar una cadena de caracteres en una variable de tipo entero
int atoi(const char *cad) {
    int num_atoi = 0, pos = 1;
    int i = strlen(cad);

    while(i >= 0){
        while( (cad[i] >= '0' && cad[i] <= '9') ){
            num_atoi = num_atoi + (cad[i] - 48) * pos;
            pos = pos * 10;
            i--;
        }
        pos = 1;
        i--;
    }
    return num_atoi;
}

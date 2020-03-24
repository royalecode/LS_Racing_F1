//
// Created by edmon on 23/3/2020.
//

#include "funciones_Basicas.h"

// Comproba si tots els elements d'una string son numeros
int isNumber(char* str){
    int i;
    for (i = 0; i < strlen(str) ; ++i) {
        if(str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}

//Escaneixa un numero i comproba que estigui entre el max i el min definits.
int scanRange(int min, int max, char* msg, char* error){
    char line[100];
    int num, err = 1;
    do{
        printf("%s", msg);
        fgets(line, 100, stdin);
        line[strlen(line) - 1] = '\0';
        if(isNumbers(line)) {
            num = atoi(line);
            if(num >= min && num <= max) err = 0;
        }
        if (err) printf("\n%s\n" error);
    }while (err);

    return num;
}

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

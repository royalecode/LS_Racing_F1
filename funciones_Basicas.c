//
// Created by edmon on 23/3/2020.
//

#include "funciones_Basicas.h"

// Comproba si tots els elements d'una string son numeros
int isNumber(char *str){
    int i;
    for (i = 0; i < strlen(str) ; ++i) {
        if(str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}

//Escaneixa un numero i comproba que estigui entre el max i el min definits.
int scanRange(int min, int max, char* msg){
    char line[100];
    int num = -100, err = 1;
    do{
        printf("%s (%d-%d): ", msg, min, max);
        fgets(line, 100, stdin);
        if (strlen(line) > 1) {
            line[strlen(line)-1] = '\0';
            num = atoi(line);
            if(isNumber(line)) {
                if (num >= min && num <= max) err = 0;
            }
        }
        if (err == 1){
            printf("ERROR: El valor '%s' tiene que ser un entero entre %d y %d incluidos\n", msg, min, max);
        }
    }while (err == 1);

    return num;
}

//funcion que mira si un caracter es numerico o no, es decir entre el 0 y el 9
int control_numero(int num, int a, int b){
    if(num >= a && num <= b) return 1;
    else return 0;
}

int fscanfNumber(FILE* file){
    char line[100];
    fgets(line,100, file);
    if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
    return atoi(line);
}

float fscanfFloat(FILE* file){
    char line[100];
    float num;
    fscanf(file, "%f", &num);
    fgets(line,100, file);
    return num;
}

void fscanfString(FILE* file, char* line){
    fgets(line,25, file);
    if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
}
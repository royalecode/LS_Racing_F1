//
// Created by edmon on 23/3/2020.
//

#include "funciones_Basicas.h"


void initScreen(){

}

/**
 * Comproba si tots els elements d'una string son numeros
 * @param str
 * @return boolea
 */
int isNumber(char *str){
    int i;
    for (i = 0; i < strlen(str) ; ++i) {
        if(str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}

/**
 * Escaneixa un numero i comproba que estigui entre el max i el min definits.
 * @param min   Valor mínim permès
 * @param max   Valor màxim permès
 * @param msg   Missatge d'error
 * @return      Retorna el valor escaneijat
 */
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

/**
 * Funció que escaneija el numero enter d'una linia d'un fitxer de text
 * @param file
 * @return
 */
int fscanfNumber(FILE* file){
    char line[100];
    fgets(line,100, file);
    if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
    return atoi(line);
}


/**
 * Funció que escaneija el numero decimal d'una linia d'un fitxer de text
 * @param file
 * @return
 */
float fscanfFloat(FILE* file){
    char line[100];
    float num;
    fscanf(file, "%f", &num);
    fgets(line,100, file);
    return num;
}


/**
 * Funció que una cadena de caràcters d'una linia d'un fitxer de text
 * @param file
 * @return
 */
void fscanfString(FILE* file, char* line){
    fgets(line,25, file);
    if (line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
}
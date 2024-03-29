//
// Created by edmon on 18/4/2020.
//

#include "corredor.h"

/**
 * Cada vez que llamamos esta función, lee directamente toda la información de un corredor únicamente. Cuando la llamemos
 * otra vez va a leer el siguiente corredor
 * @param file          Fichero de donde tiene que leer la información
 * @param corredor      Estructura donde se va a guardar la información leída
 */
void leerCorredor(FILE *file, Corredor *corredor){
    fread(corredor, sizeof(Corredor), 1, file);
    //printf("%s\n", corredor->escuderia);
}

/**
 * Función para leer el fichero con la información de corredores que se pasa por parámetro en el main
 * @param path      la ruta podriamos decir para encontrar el fichero y poderlo abrir
 * @param pilotos   Estructura donde vamos a guardar la información de todos los pilotos
 * @return          Devuelve un entero que nos permitira saber si ha habido algún error a la hora de abrir el fichero
 */
int leerCorredores(char* path, Corredores *pilotos){
    FILE *file;
    int i, err = 0;

    file = fopen(path, "rb");
    if (file == NULL){
        err = 1;
    }
    else{
        pilotos->num_corredors = 7;
        pilotos->corredores = (Corredor*) malloc(sizeof(Corredor) * pilotos->num_corredors);

        for (i = 0; i < pilotos->num_corredors; ++i) {
            leerCorredor(file, &pilotos->corredores[i]);
        }
        if(pilotos->num_corredors == 0)err = 2;
        fclose(file);
    }
    return err;
}
//
// Created by edmon on 18/4/2020.
//

#include "corredores.h"

void leerCorredor(FILE *file, Corredores *corredor){
    fscanfString(file, corredor->nombre);
    corredor->dorsal = fscanfNumber(file);
    fscanfString(file, corredor->escuderia);
    corredor->velocidad = fscanfNumber(file);
    corredor->aceleracion = fscanfNumber(file);
    corredor->consumo = fscanfNumber(file);
    corredor->fiabilidad = fscanfNumber(file);
    corredor->reflejos = fscanfNumber(file);
    corredor->cond_fisica = fscanfNumber(file);
    corredor->temperamento = fscanfNumber(file);
    corredor->gestion_neumaticos = fscanfNumber(file);
}

int leerCorredores(char* path, ConjuntoCorredores *pilotos){
    FILE *file;
    char line[1000];
    int i, err = 0;

    file = fopen(path, "r");
    if (file == NULL){
        printf("ERROR: El fichero de corredores '%s' no es accesible.\n", path);
        err = 1;
    }else{
        pilotos->num_corredors = 7;
        pilotos->corredores = (Corredores*) malloc(sizeof(Corredores) * pilotos->num_corredors);

        for (i = 0; i < pilotos->num_corredors; ++i) {
            leerCorredor(file, &pilotos->corredores[i]);
        }
        fclose(file);
    }
    return err;
}
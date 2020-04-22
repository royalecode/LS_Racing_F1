//
// Created by edmon on 18/4/2020.
//

#include "corredores.h"

void leerCorredor(FILE *file, Corredores *corredor){
    fread(corredor, sizeof(Corredores), 1, file);
    //printf("%s\n", corredor->escuderia);
}

int leerCorredores(char* path, ConjuntoCorredores *pilotos){
    FILE *file;
    char line[1000];
    int i, err = 0;

    file = fopen(path, "rb");
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
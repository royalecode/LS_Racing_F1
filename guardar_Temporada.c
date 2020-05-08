//
// Created by edmon on 23/3/2020.
//

#include "guardar_Temporada.h"

void exportTemporada(Clasificacion clasificacion){
    char path[1000];
    int i;
    FILE* file;

    printf("Ruta exportación: ");
    fgets(path, 1000, stdin);
    if (path[strlen(path)-1] == '\n') path[strlen(path)-1] = '\0';

    file = fopen(path, "w");

    if(file == NULL)printf("\nError. No se ha podido acceder a la ruta '%s'", path);
    else{
        for (i = 0; i < clasificacion.numClasificaciones; ++i) {
            fprintf()
        }
    }
}

//
// Created by artur on 12/04/2020.
//

#include "premio.h"

void leerPremio(FILE *file, Premio *premio){
    premio->posicion = fscanfNumber(file);
    fscanfString(file, premio->nombre);
    premio->velocidad = fscanfNumber(file);
    premio->aceleracion = fscanfNumber(file);
    premio->consumo = fscanfNumber(file);
    premio->fiabilidad = fscanfNumber(file);
    premio->tiempoBase = fscanfFloat(file);
    premio->tiempoPitStop = fscanfNumber(file);
    premio->numPitStop = fscanfNumber(file);
}

int leerPremios(char* path, Premios *premios){
    FILE *file;
    int i, err = 0;

    file = fopen(path, "r");
    if (file == NULL){
        printf("ERROR: El fichero de GP's '%s' no es accesible.\n", path);
        err = 1;
    }else{
        premios->numPremios = fscanfNumber(file);
        premios->premios = (Premio*) malloc(sizeof(Premio) * premios->numPremios);

        for (i = 0; i < premios->numPremios; ++i) {
            leerPremio(file, &premios->premios[i]);
        }
        fclose(file);
    }
    return err;
}




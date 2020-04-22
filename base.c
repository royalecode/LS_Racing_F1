//
// Created by edmon on 22/4/2020.
//

#include "base.h"

void leerBase(char* ruta, Base *base){
    FILE *file;
    file = fopen(ruta, "rb");
    if(file == NULL){
        printf("Error. El fichero de %s no es accesible.\n", ruta);
    }else{
        fread(base, sizeof(Base), 1, file);
        //printf("%d\n%d\n", base->fiabilidad, base->consumo);
    }
    fclose(file);
}
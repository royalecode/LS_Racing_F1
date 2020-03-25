//
// Created by edmon on 23/3/2020.
//

#include "conf_Coche.h"

void leerPiloto(Corredor *piloto){
    char msg[MAX_CHAR];//, error[MAX_CHAR];
    printf("\nNombre del piloto? ");
    fgets((*piloto).nombre, MAX_CHAR, stdin);
    (*piloto).nombre[strlen((*piloto).nombre-1)] = '\0';
    printf("Nombre de la escuderia? ");
    fgets((*piloto).escuderia, MAX_CHAR, stdin);
    (*piloto).escuderia[strlen((*piloto).escuderia-1)] = '\0';
    strcpy(msg,"Dorsal");
    (*piloto).dorsal = scanRange(1,99, msg);
    strcpy(msg,"Reflejos");
    (*piloto).reflejos = scanRange(0,10,msg);
    strcpy(msg,"Condicion fisica");
    (*piloto).cond_fisica = scanRange(0,10,msg);
    strcpy(msg,"Temperamento");
    (*piloto).temperamento = scanRange(0,10,msg);
    strcpy(msg,"Gestion de neumaticos");
    (*piloto).gestion_neumaticos = scanRange(0,10,msg);
    printf("\nCargando configurador...\n");
}

/*mostrarGaraje(){

}

escogerPieza(){

}

mostrarConfActual(){

}*/
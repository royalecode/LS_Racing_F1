//
// Created by edmon on 23/3/2020.
//

#include "conf_Coche.h"

void leerPiloto(Corredor *piloto){
    char msg[MAX_CHAR];//, error[MAX_CHAR];
    printf("\nNombre del piloto: ");
    fgets((*piloto).nombre, MAX_CHAR, stdin);
    (*piloto).nombre[strlen((*piloto).nombre-1)] = '\0';
    printf("Nombre de la escuderia: ");
    fgets((*piloto).escuderia, MAX_CHAR, stdin);
    (*piloto).escuderia[strlen((*piloto).escuderia-1)] = '\0';
    (*piloto).dorsal = scanRange(1,99, "Dorsal");
    (*piloto).reflejos = scanRange(0,10,"Reflejos");
    (*piloto).cond_fisica = scanRange(0,10,"Condicion fisica");
    (*piloto).temperamento = scanRange(0,10,"Temperamento");
    (*piloto).gestion_neumaticos = scanRange(0,10,"Gestion de neumaticos");
    printf("\nCargando configurador...\n");
}

void mostrarGaraje(){
    BITMAP* garaje;
    BITMAP* fondo;
    garaje = al_load_bitmap("../imgs/boxes.png");
    fondo = al_create_bitmap(1000,1000);
    al_draw_scaled_bitmap(garaje,0,0,0);
    al_flip_display();
    blit()

    while (true);




    al_destroy_bitmap(garaje);
}

/*
escogerPieza(){

}

mostrarConfActual(){

}*/
//
// Created by edmon on 23/3/2020.
//

#include "conf_Coche.h"

void leerPiloto(Corredor *piloto) {
    char msg[MAX_CHAR];//, error[MAX_CHAR];
    printf("\nNombre del piloto: ");
    fgets((*piloto).nombre, MAX_CHAR, stdin);
    (*piloto).nombre[strlen((*piloto).nombre - 1)] = '\0';
    printf("Nombre de la escuderia: ");
    fgets((*piloto).escuderia, MAX_CHAR, stdin);
    (*piloto).escuderia[strlen((*piloto).escuderia - 1)] = '\0';
    (*piloto).dorsal = scanRange(1, 99, "Dorsal");
    (*piloto).reflejos = scanRange(0, 10, "Reflejos");
    (*piloto).cond_fisica = scanRange(0, 10, "Condicion fisica");
    (*piloto).temperamento = scanRange(0, 10, "Temperamento");
    (*piloto).gestion_neumaticos = scanRange(0, 10, "Gestion de neumaticos");
    printf("\nCargando configurador...\n");
}

void printFlechas(int x, int y, int px) {
    al_draw_filled_triangle(6 * px + x, 0 * px + y, 4 * px + x, 2 * px + y, 8 * px + x, 2 * px + y,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(0 * px + x, 6 * px + y, 2 * px + x, 4 * px + y, 2 * px + x, 8 * px + y,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(4 * px + x, 10 * px + y, 6 * px + x, 12 * px + y, 8 * px + x, 10 * px + y,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(12 * px + x, 6 * px + y, 10 * px + x, 4 * px + y, 10 * px + x, 8 * px + y,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_rectangle(5 * px + x, 2 * px + y, 7 * px + x, 4 * px + y, LS_allegro_get_color(WHITE));
    al_draw_filled_rectangle(2 * px + x, 5 * px + y, 4 * px + x, 7 * px + y, LS_allegro_get_color(WHITE));
    al_draw_filled_rectangle(8 * px + x, 5 * px + y, 10 * px + x, 7 * px + y, LS_allegro_get_color(WHITE));
    al_draw_filled_rectangle(5 * px + x, 8 * px + y, 7 * px + x, 10 * px + y, LS_allegro_get_color(WHITE));
}

void printGaraje(CategoriaPiezas categoriaPiezas, int ic, int ip) {
    ALLEGRO_BITMAP *garaje;
    garaje = al_load_bitmap("../imgs/boxes2.png");
    al_draw_scaled_bitmap(garaje, 0, 0, 492, 550, 0, 0, 600, 600, 0);
    printFlechas(625, 75, 15);

    //al_draw_filled_triangle(650,100,700,50,750,100, LS_allegro_get_color(WHITE));
    al_flip_display();
    al_destroy_bitmap(garaje);
}

void mostrarGaraje(Corredor *piloto, CategoriaPiezas categoriaPiezas) {
    int ic = 0, ip = 0;
    int exit = 0;

    printGaraje(categoriaPiezas, ic, ip);

    while (!exit) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            exit = 1;
        }
    }

}

/*
escogerPieza(){

}

mostrarConfActual(){

}*/
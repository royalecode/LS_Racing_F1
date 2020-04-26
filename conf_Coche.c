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


//Funcion que dibuja las flechas en la pocion y con el tamaño especificados
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

//Funcion que printa la informacion de la pieza seleccionada
void printPieza(CategoriaPiezas categoriaPiezas, int ic, int ip) {
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 620, 10, 0, "%s",
                  categoriaPiezas.categorias[ic].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 100, 0, "%s",
                  categoriaPiezas.categorias[ic].piezas[ip].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 120, 0, "Velocitat: %d",
                  categoriaPiezas.categorias[ic].piezas[ip].velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 140, 0, "Acceleracio: %d",
                  categoriaPiezas.categorias[ic].piezas[ip].aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 160, 0, "Consum: %d",
                  categoriaPiezas.categorias[ic].piezas[ip].consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 180, 0, "Fiabilitat: %d",
                  categoriaPiezas.categorias[ic].piezas[ip].fiabilidad);
}

/*
 *
 */
void printConf(CategoriaPiezas categoriaPiezas, Pieza *piezas) {
    int i, y;

    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 620, 300, 0, "Configuracio");
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 620, 330, 0, "actual");

    y = 0;
    for (i = 0; i < categoriaPiezas.numeroCategorias; ++i) {
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 620, 360 + y, 0, "%s: %s",
                      categoriaPiezas.categorias[i].nombre, piezas[i].nombre);
        y = y + 20;
    }
}


void printGaraje(Pieza *piezas, CategoriaPiezas categoriaPiezas, int ic, int ip) {
    ALLEGRO_BITMAP *garaje;

    garaje = al_load_bitmap("../imgs/boxes2.png");
    al_draw_scaled_bitmap(garaje, 0, 0, 492, 550, 0, 0, 600, 600, 0);
    printFlechas(625, 75, 13);
    printPieza(categoriaPiezas, ic, ip);
    printConf(categoriaPiezas, piezas);

    LS_allegro_clear_and_paint(BLACK);
    al_destroy_bitmap(garaje);
}

void mostrarGaraje(Corredor *piloto, CategoriaPiezas categoriaPiezas) {
    int i, ic = 0, ip = 0;
    int exit = 0;
    Pieza *piezas;

    piezas = (Pieza *) malloc(sizeof(Pieza) * categoriaPiezas.numeroCategorias);

    for (i = 0; i < categoriaPiezas.numeroCategorias; ++i) {
        piezas[i] = categoriaPiezas.categorias[i].piezas[0];
    }

    printGaraje(piezas, categoriaPiezas, ic, ip);

    while (!exit) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            piezas[ic] = categoriaPiezas.categorias[ic].piezas[ip];
            printGaraje(piezas, categoriaPiezas, ic, ip);
            exit = 1;
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_D)) {
            ip = abs((ip + 1) % categoriaPiezas.categorias[ic].cantidad);
            printGaraje(piezas, categoriaPiezas, ic, ip);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_A)) {
            ip = ip - 1 < 0 ? categoriaPiezas.categorias[ic].cantidad - 1 : ip - 1;
            printGaraje(piezas, categoriaPiezas, ic, ip);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_S)) {
            piezas[ic] = categoriaPiezas.categorias[ic].piezas[ip];
            ic = abs((ic + 1) % categoriaPiezas.numeroCategorias);
            ip = 0;
            printGaraje(piezas, categoriaPiezas, ic, ip);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_W)) {
            piezas[ic] = categoriaPiezas.categorias[ic].piezas[ip];
            ic = ic - 1 < 0 ? categoriaPiezas.numeroCategorias - 1 : ic - 1;
            ip = 0;
            printGaraje(piezas, categoriaPiezas, ic, ip);
        }
    }

    for (i = 0; i < categoriaPiezas.numeroCategorias; ++i) {
        printf("\n%s", piezas[i].nombre);
        printf("\n\t%d", piezas[i].fiabilidad);
        printf("\n\t%d", piezas[i].consumo);
        printf("\n\t%d", piezas[i].aceleracion);
        printf("\n\t%d", piezas[i].velocidad);
    }

    free(piezas);
}

/*
escogerPieza(){

}

mostrarConfActual(){

}*/
//
// Created by edmon on 23/3/2020.
//

#include "conf_Coche.h"

void leerPiloto(Corredor *piloto) {
    char msg[MAX_CHAR];//, error[MAX_CHAR];
    printf("\nNombre del piloto: ");
    fgets((*piloto).nombre, MAX_CHAR, stdin);
    (*piloto).nombre[strlen((*piloto).nombre) - 1] = '\0';
    printf("Nombre de la escuderia: ");
    fgets((*piloto).escuderia, MAX_CHAR, stdin);
    (*piloto).escuderia[strlen((*piloto).escuderia) - 1] = '\0';
    (*piloto).dorsal = scanRange(1, 99, "Dorsal");
    (*piloto).reflejos = scanRange(0, 10, "Reflejos");
    (*piloto).cond_fisica = scanRange(0, 10, "Condicion fisica");
    (*piloto).temperamento = scanRange(0, 10, "Temperamento");
    (*piloto).gestion_neumaticos = scanRange(0, 10, "Gestion de neumaticos");
    printf("\nCargando configurador...\n");
}


//Funcion que dibuja las flechas y la imagen de la pieza en la pocion y con el tamaño especificados
void printFlechasImg(int x, int y, int px, char *img) {
    ALLEGRO_BITMAP *photo;
    char path[100];
    float num = (float) 1.1;

    path[0] = '\0';
    strcat(path, "../imgs/");
    strcat(path, img);
    strcat(path, ".png");

    photo = al_load_bitmap(path);

    al_draw_scaled_bitmap(photo, 0, 0, 500, 500, 4 * px + x, 4 * px + y, 4 * px, 4 * px, 0);

    al_draw_filled_triangle(6 * px + x, 0 * px + y, 4 * px + x, 2 * px + y, 8 * px + x, 2 * px + y,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(0 * px + x, 6 * px + y, 2 * px + x, 4 * px + y, 2 * px + x, 8 * px + y,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(4 * px + x, 10 * px + y, 6 * px + x, 12 * px + y, 8 * px + x, 10 * px + y,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_triangle(12 * px + x, 6 * px + y, 10 * px + x, 4 * px + y, 10 * px + x, 8 * px + y,
                            LS_allegro_get_color(WHITE));
    al_draw_filled_rectangle(5 * px + x, 2 * px + y, 7 * px + x, 4 * px + y, LS_allegro_get_color(WHITE));
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), 5 * (px * num) + x, 2 * (px * num) + y, 0,
                  "w");
    al_draw_filled_rectangle(2 * px + x, 5 * px + y, 4 * px + x, 7 * px + y, LS_allegro_get_color(WHITE));
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), 2 * (px * num) + x, 5 * (px * num) + y, 0,
                  "a");
    al_draw_filled_rectangle(8 * px + x, 5 * px + y, 10 * px + x, 7 * px + y, LS_allegro_get_color(WHITE));
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), 8 * (px * num) + x, 5 * (px * num) + y, 0,
                  "d");
    al_draw_filled_rectangle(5 * px + x, 8 * px + y, 7 * px + x, 10 * px + y, LS_allegro_get_color(WHITE));
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), 5 * (px * num) + x, 8 * (px * num) + y, 0,
                  "s");

    al_destroy_bitmap(photo);

}

//Funcion que printa la informacion de la pieza seleccionada
void printPieza(CategoriaPiezas categoriaPiezas, int ic, int ip) {
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 620, 10, 0, "%s",
                  categoriaPiezas.categorias[ic].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 115, 0, "%s",
                  categoriaPiezas.categorias[ic].piezas[ip].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 135, 0, "Velocitat: %d",
                  categoriaPiezas.categorias[ic].piezas[ip].velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 155, 0, "Acceleracio: %d",
                  categoriaPiezas.categorias[ic].piezas[ip].aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 175, 0, "Consum: %d",
                  categoriaPiezas.categorias[ic].piezas[ip].consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 815, 195, 0, "Fiabilitat: %d",
                  categoriaPiezas.categorias[ic].piezas[ip].fiabilidad);
}

/*
 *
 */
void printConf(CategoriaPiezas categoriaPiezas, Pieza *piezas, int ic) {
    int i, y;

    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 620, 300, 0, "Configuracio");
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 620, 330, 0, "actual");

    y = 0;
    for (i = 0; i < categoriaPiezas.numeroCategorias; ++i) {
        if (i == ic)
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 620, 370 + y, 0, ">%s: %s",
                          categoriaPiezas.categorias[i].nombre, piezas[i].nombre);
        else
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 620, 370 + y, 0, " %s: %s",
                          categoriaPiezas.categorias[i].nombre, piezas[i].nombre);
        y = y + 20;
    }
}

int getIndexPieza(int ic, Pieza *piezas, CategoriaPiezas categoriaPiezas) {
    int i;
    for (i = 0; i < categoriaPiezas.categorias[ic].cantidad; ++i) {
        if (!strcmp(piezas[ic].nombre, categoriaPiezas.categorias[ic].piezas[i].nombre)) {
            return i;
        }
    }
    return 0;
}


void printGaraje(Pieza *piezas, CategoriaPiezas categoriaPiezas, int ic, int ip) {
    ALLEGRO_BITMAP *garaje;

    garaje = al_load_bitmap("../imgs/boxes2.png");
    al_draw_scaled_bitmap(garaje, 0, 0, 492, 550, 0, 0, 600, 600, 0);
    printFlechasImg(625, 75, 15, categoriaPiezas.categorias[ic].nombre);
    printPieza(categoriaPiezas, ic, ip);
    printConf(categoriaPiezas, piezas, ic);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 845, 580, 0, "(ESC): SALIR");


    LS_allegro_clear_and_paint(BLACK);
    al_destroy_bitmap(garaje);
}

void setInfoPiloto (Corredor *piloto, Pieza *piezas, int categorias){
    int i;

    piloto->fiabilidad = 0;
    piloto->consumo = 0;
    piloto->aceleracion = 0;
    piloto->velocidad = 0;

    for (i = 0; i < categorias; ++i) {
        piloto->fiabilidad += piezas[i].fiabilidad;
        piloto->consumo += piezas[i].consumo;
        piloto->aceleracion += piezas[i].aceleracion;
        piloto->velocidad += piezas[i].velocidad;
    }

}

void mostrarGaraje(Corredor *piloto, CategoriaPiezas categoriaPiezas, Pieza *piezas) {
    int i, ic = 0, ip = 0;
    int exit = 0;

    ip = getIndexPieza(ic, piezas, categoriaPiezas);

    printGaraje(piezas, categoriaPiezas, ic, ip);

    while (!exit) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            piezas[ic] = categoriaPiezas.categorias[ic].piezas[ip];
            printGaraje(piezas, categoriaPiezas, ic, ip);
            exit = 1;
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_D)) {
            ip = abs((ip + 1) % categoriaPiezas.categorias[ic].cantidad);
            piezas[ic] = categoriaPiezas.categorias[ic].piezas[ip];
            printGaraje(piezas, categoriaPiezas, ic, ip);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_A)) {
            ip = ip - 1 < 0 ? categoriaPiezas.categorias[ic].cantidad - 1 : ip - 1;
            piezas[ic] = categoriaPiezas.categorias[ic].piezas[ip];
            printGaraje(piezas, categoriaPiezas, ic, ip);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_S)) {
            piezas[ic] = categoriaPiezas.categorias[ic].piezas[ip];
            ic = abs((ic + 1) % categoriaPiezas.numeroCategorias);
            ip = getIndexPieza(ic, piezas, categoriaPiezas);
            printGaraje(piezas, categoriaPiezas, ic, ip);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_W)) {
            piezas[ic] = categoriaPiezas.categorias[ic].piezas[ip];
            ic = ic - 1 < 0 ? categoriaPiezas.numeroCategorias - 1 : ic - 1;
            ip = getIndexPieza(ic, piezas, categoriaPiezas);
            printGaraje(piezas, categoriaPiezas, ic, ip);
        }
    }

    setInfoPiloto(piloto,  piezas, categoriaPiezas.numeroCategorias);
}

/*
escogerPieza(){

}

mostrarConfActual(){

}*/
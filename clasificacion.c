//
// Created by edmon on 23/3/2020.
//

#include "clasificacion.h"

void guardarClasificacion(Tiempos *tiempos, Premios *premios, Clasificacion *clasificacion, int num){
    int petit, puntos_inici = 0;
    strcpy(clasificacion->clas_GPs[num].nombreGP , premios->premios[num].nombre);
    Info_Class aux;

    for (int i = 0; i < NUM_PILOTS ; ++i) {
        strcpy(clasificacion->clas_GPs[num].clas[i].nombre , tiempos->tiempos[i].nombre);
        clasificacion->clas_GPs[num].clas[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera;
        clasificacion->clas_GPs[num].clas[i].puntos = 0;
        clasificacion->clas_GPs[num].clas[i].posicion = 0;
        //printf("%s nombre piloto\n", clasificacion->clas_GPs[num].clas[i].nombre);
        //printf("%d tiempo carrera\n", clasificacion->clas_GPs[num].clas[i].tiempo_carrera);
    }
    //ordenar los pilotos segun el tiempo_carrera para saber su posición en el gran premio
    for (int j = 0; j < NUM_PILOTS; ++j) {
        petit = j;
        for (int k = j+1; k < NUM_PILOTS; ++k) {
            if(clasificacion->clas_GPs[num].clas[k].tiempo_carrera < clasificacion->clas_GPs[num].clas[j].tiempo_carrera){
                petit = k;
            }
        }
        aux = clasificacion->clas_GPs[num].clas[j];
        clasificacion->clas_GPs[num].clas[j] = clasificacion->clas_GPs[num].clas[petit];
        clasificacion->clas_GPs[num].clas[petit] = aux;
    }

    for (int l = 0; l < NUM_PILOTS; ++l) {
        printf("%s nombre piloto\n", clasificacion->clas_GPs[num].clas[l].nombre);
        printf("%d tiempo carrera\n", clasificacion->clas_GPs[num].clas[l].tiempo_carrera);
        clasificacion->clas_GPs[num].clas[l].posicion = l + 1;
        printf("%d posicion del piloto\n", clasificacion->clas_GPs[num].clas[l].posicion);
        if(clasificacion->clas_GPs[num].clas[l].posicion == 1){
            //clasificacion->clas_GPs[num].clas[l].puntos += 25;
            puntos_inici = 25;
        }else if(clasificacion->clas_GPs[num].clas[l].posicion == 2){
            //clasificacion->clas_GPs[num].clas[l].puntos += 18;
            puntos_inici = 18;
        }else if(clasificacion->clas_GPs[num].clas[l].posicion == 3){
            //clasificacion->clas_GPs[num].clas[l].puntos += 15;
            puntos_inici = 15;
        }else if(clasificacion->clas_GPs[num].clas[l].posicion == 4){
            //clasificacion->clas_GPs[num].clas[l].puntos += 10;
            puntos_inici = 10;
        }else if(clasificacion->clas_GPs[num].clas[l].posicion == 5){
            //clasificacion->clas_GPs[num].clas[l].puntos += 8;
            puntos_inici = 8;
        }else if(clasificacion->clas_GPs[num].clas[l].posicion == 6){
            //clasificacion->clas_GPs[num].clas[l].puntos += 6;
            puntos_inici = 6;
        }else if(clasificacion->clas_GPs[num].clas[l].posicion == 7){
            //clasificacion->clas_GPs[num].clas[l].puntos += 5;
            puntos_inici = 5;
        }else if(clasificacion->clas_GPs[num].clas[l].posicion == 8){
            //clasificacion->clas_GPs[num].clas[l].puntos += 3;
            puntos_inici = 3;
        }
        for (int m = 0; m < num; ++m) {
            clasificacion->clas_GPs[num].clas[l].puntos = clasificacion->clas_GPs[num].clas[l].puntos + clasificacion->clas_GPs[m].clas[l].puntos;
        }
        clasificacion->clas_GPs[num].clas[l].puntos = clasificacion->clas_GPs[num].clas[l].puntos + puntos_inici;
        printf("%d puntos del piloto\n", clasificacion->clas_GPs[num].clas[l].puntos);
        puntos_inici = 0;
    }
}

void printarClasificacion(Clasificacion *clasificacion, int num){
    int y_pilot = 90, err =0;
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE),50,50,0,"%s %s",
            "CLASSIFICACIO DE",clasificacion->clas_GPs[num].nombreGP);

    for (int i = 0; i < NUM_PILOTS ; ++i) {
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE), 100, y_pilot, 0,
                "%d. %s (%d S) -  %d PUNTS", clasificacion->clas_GPs[num].clas[i].posicion,
                clasificacion->clas_GPs[num].clas[i].nombre, clasificacion->clas_GPs[num].clas[i].tiempo_carrera,
                clasificacion->clas_GPs[num].clas[i].puntos);
        if(i==2) y_pilot += 20;
        y_pilot += 30;
    }
    LS_allegro_clear_and_paint(BLACK);
    while(err==0){
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            err = 1;
        }
    }
}
/*
ordenacionPilotos(){

}*/

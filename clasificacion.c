//
// Created by edmon on 23/3/2020.
//

#include "clasificacion.h"

/**
 * Esta función se ejecuta en la opción 2 para guardar la clasificación del gran premio, para luego utilitzarla en la opción 3
 * Su función es ordenar los pilotos según el tiempo que hayan tardado en realizar la carrera, y por lo tanto determinar su posición
 * en el campeonato y darles los puntos ganados según la posición
 * @param tiempos           Estructura donde tenemos la información de timepo carrera para cada piloto
 * @param premios           Necesitamos para guardar el nombre del gran premio en concreto que se ha cursado
 * @param clasificacion     Estructura donde guardaremos la clasificación de todos los gran premios
 * @param num               Gran premio en el cual nos encontramos
 * @param posicion          Puntero para aconseguir la posición de nuestro propio piloto para más tarde printarla por pantalla
 */
void guardarClasificacion(Tiempos *tiempos, Premio premio, Clasificacion *clasificacion, int num, int *posicion){
    int petit, puntos_inici = 0;
    strcpy(clasificacion->clas_GPs[num].nombreGP ,premio.nombre);
    Info_Class aux;

    for (int i = 0; i < NUM_PILOTS ; ++i) {
        strcpy(clasificacion->clas_GPs[num].clas[i].nombre , tiempos->tiempos[i].nombre);
        clasificacion->clas_GPs[num].clas[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera;
        clasificacion->clas_GPs[num].clas[i].puntos = 0;
        clasificacion->clas_GPs[num].clas[i].posicion = 0;
        clasificacion->clas_GPs[num].clas[i].dorsal = tiempos->tiempos[i].dorsal;
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
        clasificacion->clas_GPs[num].clas[l].posicion = l + 1;

        if (clasificacion->clas_GPs[num].clas[l].posicion == 1) {
            puntos_inici = 25;
        } else if (clasificacion->clas_GPs[num].clas[l].posicion == 2) {
            puntos_inici = 18;
        } else if (clasificacion->clas_GPs[num].clas[l].posicion == 3) {
            puntos_inici = 15;
        } else if (clasificacion->clas_GPs[num].clas[l].posicion == 4) {
            puntos_inici = 10;
        } else if (clasificacion->clas_GPs[num].clas[l].posicion == 5) {
            puntos_inici = 8;
        } else if (clasificacion->clas_GPs[num].clas[l].posicion == 6) {
            puntos_inici = 6;
        } else if (clasificacion->clas_GPs[num].clas[l].posicion == 7) {
            puntos_inici = 5;
        } else if (clasificacion->clas_GPs[num].clas[l].posicion == 8) {
            puntos_inici = 3;
        }

        if(clasificacion->clas_GPs[num].clas[l].dorsal == tiempos->tiempos[NUM_PILOTS-1].dorsal){
            *posicion = clasificacion->clas_GPs[num].clas[l].posicion; //guardar la posicion de nuestro piloto para printarla en la info final de carrera
        }
        //for que busca donde esta el piloto que analizamos en este momento en la clasificacion del anterior GP y así
        //poder saber los puntos que lleva y sumarle los nuevos puntos
        if (num != 0) {
            for (int m = 0; m < NUM_PILOTS; ++m) {
                if(clasificacion->clas_GPs[num].clas[l].dorsal == clasificacion->clas_GPs[num-1].clas[m].dorsal){
                    clasificacion->clas_GPs[num].clas[l].puntos = clasificacion->clas_GPs[num-1].clas[m].puntos + puntos_inici;
                }
            }
        } else {
            clasificacion->clas_GPs[num].clas[l].puntos = puntos_inici;
        }
        puntos_inici = 0;
    }
}

/**
 * Esta función es encargada de llammar la que imprime la interfaz gràfica de clasificación y a la vez controlar las teclas por
 * teclado para saber si quiere volver al menú o bien visualizar la clasificación de anteriores o posteriores gran premios
 * @param clasificacion     Estrucutra donde hay guardada todas las clasificaciones
 * @param num               Numero del gran premio que nos encontramos actualmente
 * @param max_Gp            El maximo de gran premios que se juegan en una temporada
 */
void mostrarClasificacion(Clasificacion *clasificacion, int num, int max_Gp){
    int err = 0, control_final = 0;

    //Inicialitzem Allegro
    LS_allegro_init(1000, 600, "Clasificacion");

    printarClasificacion(clasificacion, num);

    while(err==0){
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) err = 1;
        if(LS_allegro_key_pressed(ALLEGRO_KEY_A) && num > 0 && control_final==0){
            printarClasificacion(clasificacion, num-1);
            num--;
        }
        if(LS_allegro_key_pressed(ALLEGRO_KEY_D)){
            if(num < (clasificacion->numClasificaciones-1) && control_final==0) {
                printarClasificacion(clasificacion, num + 1);
                num++;
            }
            if(num == (max_Gp-1)){
                imprimirClasFinalTemp(clasificacion, num);
                control_final = 1;
            }
        }
    }
    //Tanquem la finestra gràfica
    LS_allegro_exit();
}

/**
 * Función que printa por pantalla la información de la clasificación del gran premio en concreto que se le concreta por
 * parámetro
 * @param clasificacion     Estrucutra de donde extraemos la información a imprimir
 * @param num               Numero del gran premio que nos encontramos actualmente
 */
void printarClasificacion(Clasificacion *clasificacion, int num){
    int y_pilot = 90;
    //LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE),50,50,0,"%s %s",
            "CLASSIFICACIO DE",clasificacion->clas_GPs[num].nombreGP);

    for (int i = 0; i < NUM_PILOTS ; ++i) {
        if (i == 0) {
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 100, y_pilot, 0,"%d. %s (%d S) -  %d PUNTS", clasificacion->clas_GPs[num].clas[i].posicion,clasificacion->clas_GPs[num].clas[i].nombre,clasificacion->clas_GPs[num].clas[i].tiempo_carrera,clasificacion->clas_GPs[num].clas[i].puntos);
        } else if (i == 1) {
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(GRAY), 100, y_pilot, 0,"%d. %s (%d S) -  %d PUNTS", clasificacion->clas_GPs[num].clas[i].posicion,clasificacion->clas_GPs[num].clas[i].nombre,clasificacion->clas_GPs[num].clas[i].tiempo_carrera,clasificacion->clas_GPs[num].clas[i].puntos);
        }else if(i==2){
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(RED), 100, y_pilot, 0,"%d. %s (%d S) -  %d PUNTS", clasificacion->clas_GPs[num].clas[i].posicion,clasificacion->clas_GPs[num].clas[i].nombre,clasificacion->clas_GPs[num].clas[i].tiempo_carrera,clasificacion->clas_GPs[num].clas[i].puntos);
        }else {
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 100, y_pilot, 0,
                          "%d. %s (%d S) -  %d PUNTS", clasificacion->clas_GPs[num].clas[i].posicion,
                          clasificacion->clas_GPs[num].clas[i].nombre,
                          clasificacion->clas_GPs[num].clas[i].tiempo_carrera,
                          clasificacion->clas_GPs[num].clas[i].puntos);
        }
        if(i==2) y_pilot += 20;
        y_pilot += 30;
    }

    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 845, 580, 0, "(ESC): SALIR");

    LS_allegro_clear_and_paint(BLACK);
}

/**
 * Función encargada de imprimir por pantalla la clasificación total del final de la temporada
 * @param clasificacion         Estructura donde se guarda toda la información de clasificaciones
 * @param num                   Numero del gran premio que nos encontramos actualmente
 */
void imprimirClasFinalTemp(Clasificacion *clasificacion, int num){
    int y_pilot = 90;
    Info_Class_GP final;
    final.clas = (Info_Class *) malloc(sizeof(Info_Class) * NUM_PILOTS);
    ordenacionPilotos_Puntos(&final, clasificacion, num);

    //LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE),50,50,0,"%s","CLASSIFICACIO FINAL DE LA TEMPORADA");
    for (int i = 0; i < NUM_PILOTS ; ++i) {
        if (i == 0) {
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 100, y_pilot, 0,"%d. %s (#%d) -  %d PUNTS", final.clas[i].posicion, final.clas[i].nombre, final.clas[i].dorsal, final.clas[i].puntos);
        } else if (i == 1) {
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(GRAY), 100, y_pilot, 0,"%d. %s (#%d) -  %d PUNTS", final.clas[i].posicion, final.clas[i].nombre, final.clas[i].dorsal, final.clas[i].puntos);
        }else if(i==2){
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(RED), 100, y_pilot, 0,"%d. %s (#%d) -  %d PUNTS", final.clas[i].posicion, final.clas[i].nombre, final.clas[i].dorsal, final.clas[i].puntos);
        }else {
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 100, y_pilot, 0,"%d. %s (#%d) -  %d PUNTS", final.clas[i].posicion, final.clas[i].nombre, final.clas[i].dorsal, final.clas[i].puntos);
        }
        if(i==2) y_pilot += 20;
        y_pilot += 30;
    }
    LS_allegro_clear_and_paint(BLACK);
    free(final.clas);
}

/**
 * Función para ordenar los pilotos y conseguir su clasificación final de temporada según los puntos que hayan conseguido
 * en total
 * @param final             Estructura donde guardaremos la clasificación final de temporada específicamente
 * @param clasificacion     Estructura donde se guarda toda la información de clasificaciones
 * @param num               Numero del gran premio que nos encontramos actualmente
 */
void ordenacionPilotos_Puntos(Info_Class_GP *final, Clasificacion *clasificacion, int num){
    int major;
    Info_Class aux;

    for (int i = 0; i < NUM_PILOTS ; ++i) {
        strcpy(final->clas[i].nombre , clasificacion->clas_GPs[num].clas[i].nombre);
        final->clas[i].dorsal = clasificacion->clas_GPs[num].clas[i].dorsal;
        final->clas[i].puntos = clasificacion->clas_GPs[num].clas[i].puntos;
        final->clas[i].posicion = clasificacion->clas_GPs[num].clas[i].posicion;
    }

    //ordenacion de los pilotos al final de la temporada según los puntos conseguidos.
    for (int j = 0; j < NUM_PILOTS; ++j) {
        major = j;
        for (int k = j+1; k < NUM_PILOTS; ++k) {
            if(final->clas[k].puntos > final->clas[j].puntos){
                major = k;
            }
        }
        aux = final->clas[j];
        final->clas[j] = final->clas[major];
        final->clas[major] = aux;
    }
}

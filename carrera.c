//
// Created by edmon on 23/3/2020.
//

#include "carrera.h"

/**
 * Funcion dedicada a llamar otras funciones que van a llevar a cabo todas las modalidades para ejecutar la opcion carrera
 * correctamente.
 * @param premios   Información de cada uno de los gran premios de la temporada
 * @param pilotos   Infromación de cada piloto y su coche
 * @param tiempos   Estructura donde guardaremos los tiempos que tarda cada piloto en un gran premio
 * @param piloto    Información solamente de nuestro propio piloto y la configuración de su coche
 * @param num       Entero que indica en que gran premio nos encontramos dentro de la temporada
 */
void cargarCarrera(Premios *premios, ConjuntoCorredores *pilotos, Tiempos *tiempos, Corredor *piloto, int num) {
    //int posicion = 1;
    printarInfoCarrera(premios, num);
    calcularTiempo(pilotos, premios, tiempos, piloto, num);
    mostrarCarrera(piloto, tiempos);
    //mostrarFinalCarrera(piloto, posicion);
}

/**
 * Funcion que implementa una serie de salidas por pantalla que muestran una información especifica del gran premio
 * @param premios   Estructura donde hay guardad la información de todos los gran premios
 * @param num       Entero que indica en que gran premio nos encontramos dentro de la temporada
 */
void printarInfoCarrera(Premios *premios, int num) {
    int err = 0, i;
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 300, 140, 0, "%s", "BENVINGUT AL ");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 460, 140, 0, "%s",
                  premios->premios[num].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 380, 190, 0, "%s", "VELOCITAT: ");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 510, 190, 0, "%d",
                  premios->premios[num].velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 380, 220, 0, "%s", "ACCELERACIO: ");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 535, 220, 0, "%d",
                  premios->premios[num].aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 380, 250, 0, "%s", "CONSUM: ");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 470, 250, 0, "%d",
                  premios->premios[num].consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 380, 280, 0, "%s", "FIABILITAT: ");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 520, 280, 0, "%d",
                  premios->premios[num].fiabilidad);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 300, 340, 0, "%s",
                  "PULSA R PER COMENCAR LA CARRERA");
    LS_allegro_clear_and_paint(BLACK);
    while (err == 0) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            for (i = 0; i < 6; ++i) {
                temporizador(1000);
                mostrarSemaforo(i);
            }
            temporizador(2000);
            mostrarSemaforo(0);
            temporizador(500);
            err = 1;
        }
    }
}

/**
 * Función con finalidad gráfica de printar el semáforo incial antes de empezar la carrera
 * @param vermelles     Entero para controlar cuando hay que poner el semáforo en rojo o no
 */
void mostrarSemaforo(int vermelles) {
    int i, j, x1 = 250, y1 = 150, x2 = 320, y2 = 350, cx = 285, cy = 175, r = 18;
    //printf("Hola vamos a printar el semaforo\n");
    float t1, t0, k = 1.0;
    LS_allegro_clear_and_paint(WHITE);
    for (i = 0; i < 5; i++) {
        al_draw_filled_rectangle(x1, y1, x2, y2, LS_allegro_get_color(BLACK));
        x1 = x1 + 90;
        x2 = x2 + 90;
        for (j = 0; j < 4; j++) {
            al_draw_filled_circle(cx, cy, r, LS_allegro_get_color(GRAY));
            cy = cy + 50;
        }
        cx = cx + 90;
        cy = 175;
    }
    cx = 285;
    for (int i = 0; i < vermelles; ++i) {
        cy = 275;
        al_draw_filled_circle(cx, cy, r, LS_allegro_get_color(RED));
        cy = cy + 50;
        al_draw_filled_circle(cx, cy, r, LS_allegro_get_color(RED));
        cx = cx + 90;
    }
    LS_allegro_clear_and_paint(WHITE);

}

/**
 * Función con finalidad matemática para averiguar cuando tarda cada uno de los pilotos en el gran premio actual en realizar
 * la carrera, según su configuración del coche y las propias habilidades del piloto
 * @param pilotos   Información individual de cada piloto y mecánica de su coche
 * @param premios   Información de las estadística del gran premio
 * @param tiempos   Estructura donde guardaremos los cálculos realizados en la función
 * @param piloto    Infromación solamento de nuestro piloto y su coche
 * @param num       Entero que indica en que gran premio nos encontramos dentro de la temporada
 */
void calcularTiempo(ConjuntoCorredores *pilotos, Premios *premios, Tiempos *tiempos, Corredor *piloto, int num) {
    int i, tiempo_base_seg, diferencias, num_pit_stops, coef_habilidad, pixeles_linea = 700;
    tiempos->tiempos = (Tiempos_Corredor *) malloc(sizeof(Tiempos_Corredor) * NUM_PILOTS);
    tiempo_base_seg = (premios->premios[num].tiempoBase) * 60;

    //printf("%d pit stops por grna premio\n", num_pit_stops);
    //printf("%d seg base\n", tiempo_base_seg);

    for (i = 0; i < pilotos->num_corredors; i++) {
        num_pit_stops = premios->premios[num].numPitStop;
        //printf("%s piloto\n", pilotos->corredores[i].nombre);
        strcpy(tiempos->tiempos[i].nombre, pilotos->corredores[i].nombre);
        tiempos->tiempos[i].dorsal = pilotos->corredores[i].dorsal;

        diferencias = ((abs(premios->premios[num].velocidad - pilotos->corredores[i].velocidad) +
                        abs(premios->premios[num].aceleracion - pilotos->corredores[i].aceleracion) +
                        abs(premios->premios[num].consumo - pilotos->corredores[i].consumo) +
                        abs(premios->premios[num].fiabilidad - pilotos->corredores[i].fiabilidad)));
        tiempos->tiempos[i].tiempo_carrera = tiempo_base_seg + diferencias;
        //printf("%d tiempo carrera\n", tiempos->tiempos[i].tiempo_carrera);

        if (pilotos->corredores[i].consumo < premios->premios[num].consumo) {
            num_pit_stops--;
            tiempos->tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        } else if (pilotos->corredores[i].consumo > premios->premios[num].consumo) {
            num_pit_stops++;
            tiempos->tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        } else {
            tiempos->tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        }
        //printf("%d tiempo carrera\n", tiempos->tiempos[i].tiempo_carrera);

        coef_habilidad = ((pilotos->corredores[i].reflejos + pilotos->corredores[i].cond_fisica +
                           pilotos->corredores[i].temperamento + pilotos->corredores[i].gestion_neumaticos) / 4) / 2;
        //printf("%d coef hability\n", coef_habilidad);

        tiempos->tiempos[i].tiempo_carrera = (tiempos->tiempos[i].tiempo_carrera - coef_habilidad);
        //printf("%d tiempo carrera\n", tiempos->tiempos[i].tiempo_carrera);
    }
    //añadimos al struct tiempo en la ultima posicion los calculos para nuestro propio piloto
    //printf("%s piloto propio\n", piloto->nombre);
    strcpy(tiempos->tiempos[i].nombre, piloto->nombre);
    tiempos->tiempos[i].dorsal = piloto->dorsal;
    diferencias = ((abs(premios->premios[num].velocidad - piloto->velocidad) +
                    abs(premios->premios[num].aceleracion - piloto->aceleracion) +
                    abs(premios->premios[num].consumo - piloto->consumo) +
                    abs(premios->premios[num].fiabilidad - piloto->fiabilidad)));
    tiempos->tiempos[i].tiempo_carrera = tiempo_base_seg + diferencias;
    //printf("%d tiempo carrera\n", tiempos->tiempos[i].tiempo_carrera);;

    num_pit_stops = premios->premios[num].numPitStop;
    if (piloto->consumo < premios->premios[num].consumo) {
        num_pit_stops--;
        tiempos->tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
        tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        tiempos->tiempos[i].num_stops = num_pit_stops;
    } else if (piloto->consumo > premios->premios[num].consumo) {
        num_pit_stops++;
        tiempos->tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
        tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        tiempos->tiempos[i].num_stops = num_pit_stops;
    } else {
        tiempos->tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
        tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        tiempos->tiempos[i].num_stops = num_pit_stops;
    }
    //printf("%d num pit stips acutalitz\n", tiempos->tiempos[i].num_stops);
    //printf("%d tiempo carrera\n", tiempos->tiempos[i].tiempo_carrera);

    coef_habilidad =
            ((piloto->reflejos + piloto->cond_fisica + piloto->temperamento + piloto->gestion_neumaticos) / 4) / 2;
    //printf("%d coef hability\n", coef_habilidad);
    tiempos->tiempos[i].tiempo_carrera = (tiempos->tiempos[i].tiempo_carrera - coef_habilidad);
    //printf("%d tiempo carrera\n", tiempos->tiempos[i].tiempo_carrera);
}

/**
 * Función dedicada al movimiento de los coches sobre la interfaz gráfica según va avanzando el tiempo. Además de controlar
 * si hay llamada de radio para entrar al pit stop
 * @param piloto    Estructura que utilzara la función gráfica para imprimir la información del piloto
 * @param tiempos   Estrucutra que permite saber cuanto tiempo va a durar la carrera
 */
void mostrarCarrera(Corredor *piloto, Tiempos *tiempos) {
    float time = 0, _clock;
    int num_stops = 0, i, y_dorsal, y_line, y_car, seg = 0, stop_valido = 0, x_line = 670;
    float x_car[NUM_PILOTS];
    ALLEGRO_BITMAP *cotxe;
    cotxe = al_load_bitmap("../imgs/cotxe.png");

    for (i = 0; i < NUM_PILOTS; i++) {
        x_car[i] = 60;
    }
    _clock = clock();
    LS_allegro_clear_and_paint(BLACK);

    while (time <= tiempos->tiempos[NUM_PILOTS - 1].tiempo_carrera) {
        y_dorsal = 30, y_line = 37, y_car = 18;
        time = ((float) clock() - _clock) / 1000;
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            stop_valido = 1;
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_P)) {
            if (num_stops == tiempos->tiempos[NUM_PILOTS - 1].num_stops) {
                //no hacemos ninguna acción, los pit stops necesarios se han realizado por lo tanto no es necesario entrar a boxes
            } else {
                if (stop_valido == 1) {
                    num_stops++;
                    stop_valido = 0;
                }
            }
        }

        interfaz_graf_carrera(piloto, tiempos, num_stops);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 870, 420, 0, "%.2f", time);

        for (i = 0; i < NUM_PILOTS; i++) {
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), 25, y_dorsal, 0, "%d",
                          tiempos->tiempos[i].dorsal);
            al_draw_line(80, y_line, 80 + x_line, y_line, LS_allegro_get_color(BLACK), 3);
            al_draw_scaled_bitmap(cotxe, 0, 0, 80, 40, x_car[i], y_car, 70, 30, 0);
            y_dorsal = y_dorsal + 65;
            if (time <= tiempos->tiempos[i].tiempo_carrera) {
                x_car[i] = (time / tiempos->tiempos[i].tiempo_carrera) * (x_line - 70) + 80;
            }
            y_car = y_car + 65;
            y_line = y_line + 65;
        }
        LS_allegro_clear_and_paint(BLACK);
        seg++;
    }

    if (num_stops < tiempos->tiempos[NUM_PILOTS - 1].num_stops) {
        tiempos->tiempos[NUM_PILOTS - 1].tiempo_carrera =
                tiempos->tiempos[NUM_PILOTS - 1].tiempo_carrera + (5 * tiempos->tiempos[NUM_PILOTS - 1].tiempo_stops);
    }
}

/**
 * Función que implementa la salida por pantalla de la posición de nuestro piloto al final de la carrera
 * @param piloto    Información de nuestro piloto para printar su nombre
 * @param posicion  Posición de la carrera en la que ha quedado nuestro piloto
 */
void mostrarFinalCarrera(Corredor *piloto, int posicion) {
    int err = 0;
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 420, 250, 0, "%s", piloto->nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 300, 280, 0, "%s", "HA FINALITZAT");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 470, 280, 0, "%s", "EN LA POSICIO");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 635, 280, 0, "%d", posicion);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 300, 350, 0, "%s",
                  "PULSA ENTER PER TORNAR AL MENU");
    LS_allegro_clear_and_paint(BLACK);
    while (err == 0) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ENTER)) {
            err = 1;
        }
    }
}

/**
 * Función especifica para printar casi toda la parte gràfica de la pantalla específica de la carrera. Como la información
 * de nuestro piloto, el tiempo transcurrido, los pit-stops...
 * @param piloto        Estructura de nuestro piloto con su información personal y mecánica del coche
 * @param tiempos       Información de los tiempos de carrera, pero en este caso también para saber los pit stops de nuestro piloto
 * @param num_stops     Entero que indica cuantos pit stops lleva durante la carrera nuestro piloto
 */
void interfaz_graf_carrera(Corredor *piloto, Tiempos *tiempos, int num_stops) {
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 20, 0, "%s", "PILOT");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 40, 0, "%s", " NOM");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 60, 0, " %s", piloto->nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 80, 0, "%s", " ESCUDERIA");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 100, 0, " %s ", piloto->escuderia);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 120, 0, "%s", " DORSAL");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 140, 0, " %d ", piloto->dorsal);

    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 160, 0, "%s", "COTXE");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 180, 0, "%s", " VELOCITAT");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 200, 0, " %d ", piloto->velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 220, 0, "%s", " ACCELERACIO");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 240, 0, " %d ", piloto->aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 260, 0, "%s", " CONSUM");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 280, 0, " %d ", piloto->consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 300, 0, "%s", " FIABILITAT");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 320, 0, " %d ", piloto->fiabilidad);

    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 565, 0, "%s", "STOPS:    / ");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 880, 565, 0, "%d", num_stops);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 960, 565, 0, "%d",
                  tiempos->tiempos[NUM_PILOTS - 1].num_stops);

    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 10, 565, 0, "%s", "RADIO (R)");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 640, 565, 0, "%s", "PIT STOP (P)");
    al_draw_filled_rectangle(0, 0, 790, 545, LS_allegro_get_color(WHITE));
    al_draw_line(790, 530, 790, 600, LS_allegro_get_color(WHITE), 1);
    al_draw_line(0, 0, 790, 0, LS_allegro_get_color(BLACK), 2);
}
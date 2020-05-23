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
void cargarCarrera(Premio premio, Corredores *pilotos, Tiempos *tiempos, Corredor *piloto) {
    //Inicialitzem Allegro
    LS_allegro_init(1000, 600, "Carrera");

    printarInfoCarrera(premio);
    calcularTiempo(pilotos, premio, tiempos, piloto);
    mostrarCarrera(piloto, tiempos);
}

/**
 * Funcion que implementa una serie de salidas por pantalla que muestran una información especifica del gran premio
 * @param premios   Estructura donde hay guardad la información de todos los gran premios
 * @param num       Entero que indica en que gran premio nos encontramos dentro de la temporada
 */
void printarInfoCarrera(Premio premio) {
    int err = 0, i;
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 300, 140, 0, "%s ", "BENVINGUT AL");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 460, 140, 0, "%s",
                  premio.nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 380, 190, 0, "%s ", VEL);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 510, 190, 0, "%d",
                  premio.velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 380, 220, 0, "%s", ACC);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 535, 220, 0, "%d",
                  premio.aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 380, 250, 0, "%s", CON);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 470, 250, 0, "%d",
                  premio.consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 380, 280, 0, "%s", FIA);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 520, 280, 0, "%d",
                  premio.fiabilidad);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 300, 340, 0, "%s",
                  "PULSA R PER COMENCAR LA CARRERA");
    LS_allegro_clear_and_paint(BLACK);
    while (err == 0) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            LS_allegro_clear_and_paint(WHITE);

            for (i = 0; i < 6; ++i) {
                mostrarSemaforo(i);
                temporizador(1000);
            }
            temporizador(1000);
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
    float t1, t0, k = 1.0;

    //Imprimimos los semaforos apagados
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

    //Imprimimos los semaforos encendidos
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
void calcularTiempo(Corredores *pilotos, Premio premio, Tiempos *tiempos, Corredor *piloto) {
    int i, tiempo_base_seg, diferencias, num_pit_stops, coef_habilidad, pixeles_linea = 700;
    tiempos->tiempos = (Tiempos_Corredor *) malloc(sizeof(Tiempos_Corredor) * NUM_PILOTS);
    tiempo_base_seg = (premio.tiempoBase) * 60;

    //bucle para guardar los tiempos de cada piloto menos el nuestro de momento
    for (i = 0; i < pilotos->num_corredors; i++) {
        num_pit_stops = premio.numPitStop;
        strcpy(tiempos->tiempos[i].nombre, pilotos->corredores[i].nombre);
        tiempos->tiempos[i].dorsal = pilotos->corredores[i].dorsal;

        //Sumamos el calculo de las diferencias al tiempo base del gran premio en particular
        diferencias = ((abs(premio.velocidad - pilotos->corredores[i].velocidad) +
                        abs(premio.aceleracion - pilotos->corredores[i].aceleracion) +
                        abs(premio.consumo - pilotos->corredores[i].consumo) +
                        abs(premio.fiabilidad - pilotos->corredores[i].fiabilidad)));
        tiempos->tiempos[i].tiempo_carrera = tiempo_base_seg + diferencias;

        //averiguamos según el consumo cuantos pit stops debe realizar cada piloto, y en función del número incrementar
        //el tiempo de carrera con el tiempo que gastara en pit stops el piloto corresponiente
        if (pilotos->corredores[i].consumo < premio.consumo) {
            num_pit_stops--;
            tiempos->tiempos[i].tiempo_stops = (premio.tiempoPitStop * num_pit_stops);
            tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        } else if (pilotos->corredores[i].consumo > premio.consumo) {
            num_pit_stops++;
            tiempos->tiempos[i].tiempo_stops = (premio.tiempoPitStop * num_pit_stops);
            tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        } else {
            tiempos->tiempos[i].tiempo_stops = (premio.tiempoPitStop * num_pit_stops);
            tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        }

        //restaremos al tiempo de carrera el calculo de las habilidadas características de cada piloto
        coef_habilidad = ((pilotos->corredores[i].reflejos + pilotos->corredores[i].cond_fisica +
                           pilotos->corredores[i].temperamento + pilotos->corredores[i].gestion_neumaticos) / 4) / 2;
        tiempos->tiempos[i].tiempo_carrera = (tiempos->tiempos[i].tiempo_carrera - coef_habilidad);
    }

    //añadimos al struct tiempo en la ultima posicion los calculos para nuestro propio piloto
    //es exactamente el mismo procedimiento y calculos hechos anteriormente para los otros pilotos, y ahora utilitzados
    //solamente para nuestro propio piloto

    strcpy(tiempos->tiempos[i].nombre, piloto->nombre);
    tiempos->tiempos[i].dorsal = piloto->dorsal;
    diferencias = ((abs(premio.velocidad - piloto->velocidad) +
                    abs(premio.aceleracion - piloto->aceleracion) +
                    abs(premio.consumo - piloto->consumo) +
                    abs(premio.fiabilidad - piloto->fiabilidad)));
    tiempos->tiempos[i].tiempo_carrera = tiempo_base_seg + diferencias;

    num_pit_stops = premio.numPitStop;
    if (piloto->consumo < premio.consumo) {
        num_pit_stops--;
        tiempos->tiempos[i].tiempo_stops = (premio.tiempoPitStop * num_pit_stops);
        tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        tiempos->tiempos[i].num_stops = num_pit_stops;
    } else if (piloto->consumo > premio.consumo) {
        num_pit_stops++;
        tiempos->tiempos[i].tiempo_stops = (premio.tiempoPitStop * num_pit_stops);
        tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        tiempos->tiempos[i].num_stops = num_pit_stops;
    } else {
        tiempos->tiempos[i].tiempo_stops = (premio.tiempoPitStop * num_pit_stops);
        tiempos->tiempos[i].tiempo_carrera = tiempos->tiempos[i].tiempo_carrera + tiempos->tiempos[i].tiempo_stops;
        tiempos->tiempos[i].num_stops = num_pit_stops;
    }

    coef_habilidad =
            ((piloto->reflejos + piloto->cond_fisica + piloto->temperamento + piloto->gestion_neumaticos) / 4) / 2;
    tiempos->tiempos[i].tiempo_carrera = (tiempos->tiempos[i].tiempo_carrera - coef_habilidad);
}

/**
 * Función dedicada al movimiento de los coches sobre la interfaz gráfica según va avanzando el tiempo. Además de controlar
 * si hay llamada de radio para entrar al pit stop
 * @param piloto    Estructura que utilzara la función gráfica para imprimir la información del piloto
 * @param tiempos   Estrucutra que permite saber cuanto tiempo va a durar la carrera
 */
void mostrarCarrera(Corredor *piloto, Tiempos *tiempos) {
    float time = 0, _clock, tiempoStop;
    int num_stops = 0, i, j = 0, y_dorsal, y_line, y_car, stop_valido = 0, x_line = 670;
    int tiempoTotal, tiempoPit, stop = 0, tiempoTotalStop = 0;
    float x_car[NUM_PILOTS];
    ALLEGRO_BITMAP *cotxe;
    cotxe = al_load_bitmap("../imgs/cotxe.png");

    for (i = 0; i < NUM_PILOTS; i++) {
        x_car[i] = 60;
    }
    _clock = clock();
    LS_allegro_clear_and_paint(BLACK);

    //tiempo que tarda nuestro piloto
    tiempoTotal = tiempos->tiempos[NUM_PILOTS - 1].tiempo_carrera - tiempos->tiempos[NUM_PILOTS - 1].tiempo_stops;

    //tiempo de cada pitStop
    tiempoPit = (int) (tiempos->tiempos[NUM_PILOTS - 1].tiempo_stops / tiempos->tiempos[NUM_PILOTS - 1].num_stops);

    while (time <= tiempoTotal) {
        y_dorsal = 30, y_line = 37, y_car = 18;

        //Tiempo transcurrido de carrera
        time = ((float) clock() - _clock) / CLOCKS_PER_SEC;

        //Si estamos en pitStop comprobamos si ha transucrrido el tiempo necesario
        if (stop && time >= tiempoStop) stop = 0;

        //Solicitud pitStop por Radio
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            stop_valido = 1;
        }

        //Solicitud pitSop
        if (LS_allegro_key_pressed(ALLEGRO_KEY_P)) {
            //Si aun no hemos echo todos los pitStops y tenemos la confirmación por radio realizamos un pitStop
            if (num_stops < tiempos->tiempos[NUM_PILOTS - 1].num_stops && stop_valido == 1) {
                num_stops++;
                stop_valido = 0;
                tiempoTotal += tiempoPit;
                tiempoStop = time + tiempoPit;
                tiempoTotalStop += tiempoPit;
                stop = 1;
            }
        }

        //imprimimos la interfaz
        interfaz_graf_carrera(piloto, tiempos, num_stops);

        //Imprimimos el timepo transcurrido
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 870, 420, 0, "%.2f", time);

        //Imprimimos cada piloto y calculamos su próxima posición
        for (i = 0; i < NUM_PILOTS; i++) {
            //Imprimimos el dorsal del piloto
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), 25, y_dorsal, 0, "%d",
                          tiempos->tiempos[i].dorsal);
            al_draw_line(80, y_line, 80 + x_line, y_line, LS_allegro_get_color(BLACK), 3);

            //Imprimimos el coche del piloto en la posición calculada
            al_draw_scaled_bitmap(cotxe, 0, 0, al_get_bitmap_width(cotxe), al_get_bitmap_height(cotxe), x_car[i], y_car,
                                  60, 30, 0);

            //calculamos su próxima posición del piloto
            if (time <= tiempos->tiempos[i].tiempo_carrera) {
                if (i == NUM_PILOTS - 1) {
                    if (stop == 0) x_car[i] = ((time - tiempoTotalStop) / (tiempoTotal - tiempoTotalStop)) *
                                              (x_line - 60) + 80;
                } else x_car[i] = (time / tiempos->tiempos[i].tiempo_carrera) * (x_line - 60) + 80;
            }
            y_dorsal += + 65;
            y_car += 65;
            y_line += 65;
        }
        LS_allegro_clear_and_paint(BLACK);
    }
    al_destroy_bitmap(cotxe);

    //Penalización por no realizar los pitStops necesarios
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
void mostrarFinalCarrera(Corredor *piloto, int *posicion) {
    int err = 0;
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE),
                  (1000 / 2) - (((int) strlen(piloto->nombre) * 12) / 2), 220, 0, "%s", piloto->nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), (1000 / 2) - ((27 * 12) / 2), 250, 0, "%s",
                  "HA FINALITZAT EN LA POSICIO");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), (1000 / 2) + ((28 * 12) / 2), 250, 0, "%d",
                  *posicion);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), (1000 / 2) - ((30 * 12) / 2), 320, 0, "%s",
                  "PULSA ENTER PER TORNAR AL MENU");
    LS_allegro_clear_and_paint(BLACK);
    while (err == 0) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ENTER)) {
            err = 1;
            //Tanquem la finestra gràfica
            LS_allegro_exit();
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
    //Imprimimos la información del piloto
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 20, 0, "%s", PIL);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 40, 0, "%s", NOM);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 60, 0, " %s", piloto->nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 80, 0, "%s", ESC);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 100, 0, " %s ", piloto->escuderia);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 120, 0, "%s", DOR);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 140, 0, " %d ", piloto->dorsal);

    //Imprimimos la imformación del coche
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 160, 0, "%s", "COTXE");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 180, 0, "%s", VEL);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 200, 0, " %d ", piloto->velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 220, 0, "%s", ACC);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 240, 0, " %d ", piloto->aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 260, 0, "%s", CON);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 280, 0, " %d ", piloto->consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 800, 300, 0, "%s", FIA);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 800, 320, 0, " %d ", piloto->fiabilidad);

    //Imprimimos los stops hechos / stops necesarios
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
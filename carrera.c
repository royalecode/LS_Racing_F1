//
// Created by edmon on 23/3/2020.
//

#include "carrera.h"

void cargarCarrera(Premios *premios, ConjuntoCorredores *pilotos, Tiempos *tiempos, Corredor *piloto, int num){
    printarInfoCarrera(premios, num);
    calcularTiempo(pilotos, premios, tiempos, piloto, num);
    mostrarCarrera(piloto, tiempos);
}
void printarInfoCarrera(Premios *premios, int num){
    int err = 0, i;
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),300,140,0,"%s","BENVINGUT AL ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),460,140,0,"%s",premios->premios[num].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),380,190,0,"%s","VELOCITAT: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),510,190,0,"%d", premios->premios[num].velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),380,220,0,"%s","ACCELERACIO: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),535,220,0,"%d", premios->premios[num].aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),380,250,0,"%s","CONSUM: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),470,250,0,"%d", premios->premios[num].consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),380,290,0,"%s","FIABILITAT: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),520,290,0,"%d", premios->premios[num].fiabilidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),300,340,0,"%s","PULSA R PER COMENCAR LA CARRERA");
    LS_allegro_clear_and_paint(BLACK);
    while(err==0){
        if(LS_allegro_key_pressed(ALLEGRO_KEY_R)){
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
void mostrarSemaforo(int vermelles){
    int i, j, x1 = 250, y1 = 150, x2 = 320, y2 = 350, cx = 285, cy = 175, r = 18;
    //printf("Hola vamos a printar el semaforo\n");
    float t1, t0, k = 1.0;
    LS_allegro_clear_and_paint(WHITE);
    for(i=0; i<5; i++){
        al_draw_filled_rectangle(x1,y1,x2,y2,LS_allegro_get_color(BLACK));
        x1 = x1+90;
        x2 = x2+90;
        for(j=0; j<4; j++){
            al_draw_filled_circle(cx,cy,r,LS_allegro_get_color(GRAY));
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

void calcularTiempo(ConjuntoCorredores *pilotos, Premios *premios, Tiempos *tiempos, Corredor *piloto, int num){
    int i, tiempo_base_seg, diferencias, num_pit_stops, coef_habilidad, pixeles_linea = 700;
    //Tiempos *tiempo;
    tiempos = (Tiempos*) malloc(sizeof(Tiempos) * (pilotos->num_corredors + 1));
    tiempo_base_seg = (premios->premios[num].tiempoBase)*60;
    num_pit_stops = premios->premios[num].numPitStop;
    printf("%d pit stops por grna premio\n", num_pit_stops);
    //printf("%d seg base\n", tiempo_base_seg);
    for(i=0; i < pilotos->num_corredors; i++){
        //printf("%s piloto", pilotos->corredores[i].nombre);
        tiempos[i].dorsal = pilotos->corredores[i].dorsal;

        diferencias = ((abs(premios->premios[num].velocidad - pilotos->corredores[i].velocidad) +
                abs(premios->premios[num].aceleracion - pilotos->corredores[i].aceleracion) +
                abs(premios->premios[num].consumo - pilotos->corredores[i].consumo) +
                abs(premios->premios[num].fiabilidad - pilotos->corredores[i].fiabilidad)));
        tiempos[i].tiempo_carrera = tiempo_base_seg + diferencias;
        //printf("%d tiempo carrera\n", tiempos[i].tiempo_carrera);

        if(pilotos->corredores[i].consumo < premios->premios[num].consumo){
            num_pit_stops--;
            tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera + tiempos[i].tiempo_stops;
        }else if(pilotos->corredores[i].consumo > premios->premios[num].consumo){
            num_pit_stops++;
            tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera + tiempos[i].tiempo_stops;
        }else{
            tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera + tiempos[i].tiempo_stops;
        }
        //printf("%d tiempo carrera\n", tiempos[i].tiempo_carrera);
        coef_habilidad = ((pilotos->corredores[i].reflejos + pilotos->corredores[i].cond_fisica +
                pilotos->corredores[i].temperamento + pilotos->corredores[i].gestion_neumaticos)/4)/2;
        //printf("%d coef hability\n", coef_habilidad);
        tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera - coef_habilidad;
        //printf("%d tiempo carrera\n", tiempos[i].tiempo_carrera);

        tiempos[i].pixels_seg = pixeles_linea/tiempos[i].tiempo_carrera;
    }
    //añadimos al struct tiempo en la ultima posicion los calculos para nuestro propio piloto
    printf("la i vale tanto %d --\n", i);
    i--;

    //printf("%s piloto propio\n", piloto->nombre);
    tiempos[i].dorsal = piloto->dorsal;
    diferencias = ((abs(premios->premios[num].velocidad - piloto->velocidad) + abs(premios->premios[num].aceleracion - piloto->aceleracion) +
            abs(premios->premios[num].consumo - piloto->consumo) + abs(premios->premios[num].fiabilidad - piloto->fiabilidad)));
    tiempos[i].tiempo_carrera = tiempo_base_seg + diferencias;
    //printf("%d tiempo carrera\n", tiempos[i].tiempo_carrera);;

    if(piloto->consumo < premios->premios[num].consumo){
        num_pit_stops--;
        tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
        tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera + tiempos[i].tiempo_stops;
        tiempos[i].num_stops = num_pit_stops;
    }else if(piloto->consumo > premios->premios[num].consumo){
        num_pit_stops++;
        tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
        tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera + tiempos[i].tiempo_stops;
        tiempos[i].num_stops = num_pit_stops;
    }else{
        tiempos[i].tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
        tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera + tiempos[i].tiempo_stops;
        tiempos[i].num_stops = num_pit_stops;
    }
    printf("%d num pit stips acutalitz\n", tiempos[i].num_stops);
    //printf("%d tiempo carrera\n", tiempos[i].tiempo_carrera);

    coef_habilidad = ((piloto->reflejos + piloto->cond_fisica + piloto->temperamento + piloto->gestion_neumaticos)/4)/2;
    //printf("%d coef hability\n", coef_habilidad);
    tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera - coef_habilidad;
    //printf("%d tiempo carrera\n", tiempos[i].tiempo_carrera);

    tiempos[i].pixels_seg = pixeles_linea/(tiempos[i].tiempo_carrera - tiempos[i].tiempo_stops);
    printf("%d pixeles por segundo\n", tiempos[i].pixels_seg);
}

void mostrarCarrera(Corredor *piloto, Tiempos *tiempos){
    int num_stops = 0, i, y_dorsal = 30, y_line = 37, y_car = 18;
    ALLEGRO_BITMAP *cotxe;
    cotxe = al_load_bitmap("../imgs/cotxe.png");
    /*printf("%d esto es el dorssl\n", piloto->dorsal);
    printf("%d numero stops\n", tiempos[7].num_stops);
    printf("%d numero drosal\n", tiempos[7].dorsal);
    printf("%s nombre\n", piloto->nombre);
    printf("%s nombre\n", piloto->escuderia);
    printf("%d nombre\n", piloto->velocidad);
    printf("%d nombre\n", piloto->aceleracion);
    printf("%d nombre\n", piloto->consumo);
    printf("%d nombre\n", piloto->fiabilidad);
    printf("%d stops----\n", num_stops);*/

    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,20,0,"%s","PILOT");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,40,0,"%s"," NOM");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,60,0," %s", piloto->nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,80,0,"%s"," ESCUDERIA");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,100,0," %s ", piloto->escuderia);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,120,0,"%s"," DORSAL");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,140,0," %d ", piloto->dorsal);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,160,0,"%s","COTXE");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,180,0,"%s"," VELOCITAT");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,200,0," %d ", piloto->velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,220,0,"%s"," ACCELERACIO");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,240,0," %d ", piloto->aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,260,0,"%s"," CONSUM");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,280,0," %d ", piloto->consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,300,0,"%s"," FIABILITAT");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,320,0," %d ", piloto->fiabilidad);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),800,565,0,"%s","STOPS:    / ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),880,565,0,"%d", num_stops);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),960,565,0,"%d", tiempos[7].num_stops);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),10,565,0,"%s","RADIO (R)");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),640,565,0,"%s","PIT STOP (P)");
    al_draw_filled_rectangle(0,0,790,545, LS_allegro_get_color(WHITE));
    al_draw_line(790,530,790,600,LS_allegro_get_color(WHITE),1);
    al_draw_line(0,0,790,0,LS_allegro_get_color(BLACK), 2);

    for(i=0; i < NUM_PILOTS; i++){
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(BLACK), 25, y_dorsal ,0, "%d", piloto->dorsal);
        al_draw_line(80, y_line, 750, y_line, LS_allegro_get_color(BLACK), 3);
        al_draw_scaled_bitmap(cotxe, 0, 0, 70, 30, 60, y_car, 70, 30, 0);
        y_dorsal = y_dorsal + 65;
        y_car = y_car + 65;
        y_line = y_line + 65;
    }

    LS_allegro_clear_and_paint(BLACK);
}

void mostrarFinalCarrera(){

}
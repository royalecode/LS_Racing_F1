//
// Created by edmon on 23/3/2020.
//

#include "carrera.h"

void cargarCarrera(Premios *premios, ConjuntoCorredores *pilotos, Tiempos *tiempos, Corredor *piloto, int num){
    printarInfoCarrera(premios, num);
    calcularTiempo(pilotos, premios, tiempos, piloto, num);
    //mostrarCarrera(piloto, tiempos);
}
void printarInfoCarrera(Premios *premios, int num){
    int err = 0, i;
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),220,100,0,"%s","BENVINGUT AL ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),380,100,0,"%s",premios->premios[num].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),300,150,0,"%s","VELOCITAT: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),430,150,0,"%d", premios->premios[num].velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),300,180,0,"%s","ACCELERACIO: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),455,180,0,"%d", premios->premios[num].aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),300,210,0,"%s","CONSUM: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),390,210,0,"%d", premios->premios[num].consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),300,240,0,"%s","FIABILITAT: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),440,240,0,"%d", premios->premios[num].fiabilidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),220,300,0,"%s","PULSA R PER COMENCAR LA CARRERA");
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
    i++;
    //incialitzo 4 variables per comprovar funcionament
    piloto->velocidad = 4;
    piloto->aceleracion = 2;
    piloto->consumo = 6;
    piloto->fiabilidad = 3;

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
    //printf("%d tiempo carrera\n", tiempos[i].tiempo_carrera);

    coef_habilidad = ((piloto->reflejos + piloto->cond_fisica + piloto->temperamento + piloto->gestion_neumaticos)/4)/2;
    //printf("%d coef hability\n", coef_habilidad);
    tiempos[i].tiempo_carrera = tiempos[i].tiempo_carrera - coef_habilidad;
    //printf("%d tiempo carrera\n", tiempos[i].tiempo_carrera);

    tiempos[i].pixels_seg = pixeles_linea/(tiempos[i].tiempo_carrera - tiempos[i].tiempo_stops);
    //printf("%d pixeles por segundo\n", tiempos[i].pixels_seg);
}

void mostrarCarrera(Corredor *piloto, Tiempos *tiempos){
    int num_stops = 0;
    LS_allegro_clear_and_paint(BLACK);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,20,0,"%s","PILOT");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,40,0,"%s"," NOM");
    //al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,30,0,"%s", piloto->nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,80,0,"%s"," ESCUDERIA");
    //al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,50,0,"%s", piloto->escuderia);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,120,0,"%s"," DORSAL");
    //printf("%d esto es el dorssl\n", piloto->dorsal);
    //al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(YELLOW),800,70,0,"%d", piloto->dorsal);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,160,0,"%s","COTXE");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,180,0,"%s"," VELOCITAT");
    //al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),800,100,0,"%s", piloto->velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,220,0,"%s"," ACCELERACIO");
    //al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),800,120,0,"%s", piloto->aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,260,0,"%s"," CONSUM");
    //al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),800,140,0,"%s", piloto->consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,300,0,"%s"," FIABILITAT");
    //al_draw_textf(LS_allegro_get_font(SMALL),LS_allegro_get_color(YELLOW),800,160,0,"%s", piloto->fiabilidad);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),600,550,0,"%s","STOPS:    / ");
    //al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),810,580,0,"%d", num_stops);
    //al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),820,580,0,"%d", tiempos[8].num_stops);

    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),10,550,0,"%s","RADIO (R)");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),500,550,0,"%s","PIT STOP (P)");
    LS_allegro_clear_and_paint(BLACK);

}

void mostrarFinalCarrera(){

}
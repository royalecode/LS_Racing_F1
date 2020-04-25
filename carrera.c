//
// Created by edmon on 23/3/2020.
//

#include "carrera.h"

void cargarCarrera(Premios *premios, ConjuntoCorredores *pilotos, int num){
    printarInfoCarrera(premios, num);
    calcularTiempo(pilotos, premios, num);
}
void printarInfoCarrera(Premios *premios, int num){
    int err = 0;
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s","BENVINGUT AL ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),300,100,0,"%s",premios->premios[num].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),220,150,0,"%s","VELOCITAT: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),350,150,0,"%d", premios->premios[num].velocidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),220,180,0,"%s","ACCELERACIO: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),375,180,0,"%d", premios->premios[num].aceleracion);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),220,210,0,"%s","CONSUM: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),310,210,0,"%d", premios->premios[num].consumo);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),220,240,0,"%s","FIABILITAT: ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),360,240,0,"%d", premios->premios[num].fiabilidad);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,300,0,"%s","PULSA R PER COMENCAR LA CARRERA");
    LS_allegro_clear_and_paint(BLACK);
    while(err==0){
        if(LS_allegro_key_pressed(ALLEGRO_KEY_R)){
            mostrarSemaforo();
            err = 1;
        }
    }
}
void mostrarSemaforo(){
    int i, j, x1 = 100, y1 = 100, x2 = 170, y2 = 300, cx = 135, cy = 125, r = 18;
    //printf("Hola vamos a printar el semaforo\n");
    float t1, t0, k = 1.0;
    LS_allegro_clear_and_paint(WHITE);
    for(i=0; i<5; i++){
        al_draw_filled_rectangle(x1,y1,x2,y2,LS_allegro_get_color(BLACK));
        x1 = x1+80;
        x2 = x2+80;
        for(j=0; j<4; j++){
            al_draw_filled_circle(cx,cy,r,LS_allegro_get_color(GRAY));
            cy = cy + 50;
        }
        cx = cx + 80;
        cy = 125;
    }
    LS_allegro_clear_and_paint(WHITE);
    /*t0 = (float) clock();
    i=0;
    cx = 135;
    while(i<5){
        cy = 225;
        t1 = (float) clock();
        if( ((t1-t0) / (float)CLOCKS_PER_SEC) >= 1.0) {
            al_draw_filled_circle(cx, cy, r, LS_allegro_get_color(RED));
            cy = cy + 50;
            al_draw_filled_circle(cx, cy, r, LS_allegro_get_color(RED));
            t0 = (float) clock();
            i++;
        }
        cx = cx + 80;
    }
    //LS_allegro_clear_and_paint(WHITE);*/
}

void calcularTiempo(ConjuntoCorredores *pilotos, Premios *premios, int num){
    int i, tiempo_base_seg, diferencias, num_pit_stops, coef_habilidad;
    Tiempos *tiempo;
    tiempo = (Tiempos*) malloc(sizeof(Tiempos) * (pilotos->num_corredors + 1));
    tiempo_base_seg = (premios->premios[num].tiempoBase)*60;
    num_pit_stops = premios->premios[num].numPitStop;

    printf("%d seg base\n", tiempo_base_seg);
    for(i=0; i < pilotos->num_corredors; i++){
        tiempo->dorsal = pilotos->corredores[i].dorsal;

        diferencias = ((abs(premios->premios[num].velocidad - pilotos->corredores[i].velocidad) +
                abs(premios->premios[num].aceleracion - pilotos->corredores[i].aceleracion) +
                abs(premios->premios[num].consumo - pilotos->corredores[i].consumo) +
                abs(premios->premios[num].fiabilidad - pilotos->corredores[i].fiabilidad)));
        tiempo->tiempo_carrera = tiempo_base_seg + diferencias;
        printf("%d tiempo carrera\n", tiempo->tiempo_carrera);

        if(pilotos->corredores[i].consumo < premios->premios[num].consumo){
            num_pit_stops--;
            tiempo->tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempo->tiempo_carrera = tiempo->tiempo_carrera + tiempo->tiempo_stops;
        }else if(pilotos->corredores[i].consumo > premios->premios[num].consumo){
            num_pit_stops++;
            tiempo->tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempo->tiempo_carrera = tiempo->tiempo_carrera + tiempo->tiempo_stops;
        }else{
            tiempo->tiempo_stops = (premios->premios[num].tiempoPitStop * num_pit_stops);
            tiempo->tiempo_carrera = tiempo->tiempo_carrera + tiempo->tiempo_stops;
        }
        printf("%d tiempo carrera\n", tiempo->tiempo_carrera);
        coef_habilidad = ((pilotos->corredores[i].reflejos + pilotos->corredores[i].cond_fisica +
                pilotos->corredores[i].temperamento + pilotos->corredores[i].gestion_neumaticos)/4)/2;
        printf("%d coef hability\n", coef_habilidad);
    }
}
void mostrarCarrera(){

}
void controlPitStops(){

}
void mostrarFinalCarrera(){

}
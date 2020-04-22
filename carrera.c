//
// Created by edmon on 23/3/2020.
//

#include "carrera.h"

void cargarCarrera(Premios *premios, int num){
    printarInfoCarrera(premios, num);

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
    printf("Hola vamos a printar el semaforo\n");
}
void mostrarCarrera(){

}
void controlPitStops(){

}
 void calcularRendimiento(){

}
void mostrarFinalCarrera(){

}
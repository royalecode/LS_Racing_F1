//
// Created by edmon on 23/3/2020.
//

#include "carrera.h"

void cargarCarrera(Premios *premios, int num){
    LS_allegro_console_clear_screen();
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s","BENVINGUT AL GP ");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s\n",premios->premios[num].nombre);
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s","PULSA R PER COMENCAR LA CARRERA");
    LS_allegro_clear_and_paint(BLACK);

}
void printarInfoCarrera(){

}
void mostrarSemaforo(){

}
void mostrarCarrera(){

}
void controlPitStops(){

}
 void calcularRendimiento(){

}
void mostrarFinalCarrera(){

}
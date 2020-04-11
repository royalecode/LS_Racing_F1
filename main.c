#include <stdio.h>
#include "LS_allegro.h"
#include "menu.h"
#include "conf_Coche.h"
#include "tipos.h"
#include "pieza.h"
#include "premio.h"

int main(int num_parametres, char** parametres){
    //sha dafegir les llibreries alegro
    int nSortir = 0, opcion = 100, controlador = 0, i, j;
    Corredor piloto;
    CategoriaPiezas categoriaPiezas;
    Premios premios;

    leerPiezas(parametres[1], &categoriaPiezas);
    leerPremios(parametres[2], &premios);

    //Inicialitzem Allegro
    LS_allegro_init(800,600,"Projecte 2");


    //Bucle infinit del joc
    while(!nSortir){

        //Escoltem el teclat esperant la tecla ESC
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }

        //Donem l'ordre d'escriure el text de benvinguda
        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s","Benvingut a Allegro! Prem ESC per sortir...");

        //Pintem la pantalla de la finestra gràfica
        LS_allegro_clear_and_paint(BLACK);


        printf("Bienvenidos a LS Racing!\n");
        while(opcion != 0){
            printarMenu();
            opcion = leer_opcion();
            switch (opcion){
                case 1:
                    if(!controlador) {
                        leerPiloto(&piloto);
                        controlador = 1;
                    }else{
                        printf("ERROR: El coche ya esta configruado.\n");
                    }
                    break;
                case 2:
                    //antes funciones de opcion 2
                    break;
                case 3:
                    //antes funciones de opcion 3
                    break;
                case 4:
                    //antes funciones de opcion 4
                    break;
                case 0:
                    printf("\nHasta Pronto!\n");
                    nSortir = 1;
                    break;
            }
        }
    }

    //Tanquem la finestra gràfica
    LS_allegro_exit();



    return 0;
}
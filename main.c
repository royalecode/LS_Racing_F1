#include <stdio.h>
#include "LS_allegro.h"
#include "menu.h"

int main(void){
    //sha dafegir les llibreries alegro
    int nSortir = 0, opcion = 100;

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
        printarMenu();
        while(opcion != 0){

            opcion = leer_opcion();
            switch (opcion){
                case 1:
                    //antes funciones de opcion 1
                    printarMenu();
                    break;
                case 2:
                    //antes funciones de opcion 2
                    printarMenu();
                    break;
                case 3:
                    //antes funciones de opcion 3
                    printarMenu();
                    break;
                case 4:
                    //antes funciones de opcion 4
                    printarMenu();
                    break;
                case 0:
                    printf("\nHasta Pronto!\n");
                    break;
            }
        }
    }


    //Tanquem la finestra gràfica
    LS_allegro_exit();



    return 0;
}
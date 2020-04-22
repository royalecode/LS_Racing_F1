#include <stdio.h>
#include "LS_allegro.h"
#include "menu.h"
#include "conf_Coche.h"
#include "tipos.h"
#include "pieza.h"
#include "premio.h"
#include "corredores.h"
#include "carrera.h"
#include "base.h"

int main(int num_parametres, char** parametres){

    int nSortir = 0, opcion = 100, controlador = 0, i, j, numOp2 = 0;
    Corredor piloto;
    ConjuntoCorredores pilotos;
    CategoriaPiezas categoriaPiezas;
    Premios premios;
    Base base;

    leerPiezas(parametres[1], &categoriaPiezas);
    leerPremios(parametres[2], &premios);
    leerCorredores(parametres[3], &pilotos);
    leerBase(parametres[4], &base);

    //Inicialitzem Allegro
    LS_allegro_init(800,600,"Projecte 2");

    //Bucle infinit del joc
    while(!nSortir){

        //Escoltem el teclat esperant la tecla ESC
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }

        al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s","Benvingut a Allegro! Prem ESC per sortir...");
        //Pintem la pantalla de la finestra gràfica
        LS_allegro_clear_and_paint(BLACK);

        if(num_parametres == 5) {
            printf("Bienvenidos a LS Racing!\n");
            while (opcion != 0) {
                printarMenu();
                opcion = leer_opcion();
                switch (opcion) {
                    case 1:
                        if (!controlador) {
                            leerPiloto(&piloto);
                            controlador = 1;
                        } else {
                            printf("ERROR: El coche ya esta configruado.\n");
                        }
                        break;
                    case 2:
                        if(numOp2 < premios.numPremios && controlador==1){
                            printf("Preparando carrera #%d: %s ...\n", numOp2+1, premios.premios[numOp2].nombre);
                            cargarCarrera(&premios, numOp2);
                            numOp2++;
                        }else{
                            if (controlador!=1){
                                printf("Aun no has configurado el coche.\n");
                            }else {
                                printf("Ya has finalizado la temporada.\n");
                            }
                        }
                        break;
                    case 3:
                        if(numOp2 > 0){
                            //llamara modulo clasificacion
                        }else{
                            printf("La temporada aun no ha empezado.\n");
                        }
                        break;
                    case 4:
                        //llamar modulo clasificacion
                        break;
                    case 0:
                        printf("\nHasta Pronto!\n");
                        nSortir = 1;
                        break;
                }
                //LS_allegro_clear_and_paint(BLACK);
            }
        }else{
            printf("Error. El programa tiene que recibir 4 argumentos.\n");
            nSortir = 1;
        }
        //LS_allegro_clear_and_paint(BLACK);
    }

    //Tanquem la finestra gràfica
    LS_allegro_exit();

    return 0;
}
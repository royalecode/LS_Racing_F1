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
#include "clasificacion.h"

int main(int num_parametres, char **parametres) {

    int nSortir = 0, opcion = 100, controlador = 0, i, numOp2 = 0, posicion = 1, err = 0;
    Corredor piloto;
    ConjuntoCorredores pilotos;
    CategoriaPiezas categoriaPiezas;
    Premios premios;
    Base base;
    Tiempos tiempos;
    Pieza *confCoche;
    Clasificacion clasificacion;

    if(num_parametres != 5) err = 3;
    if (!err) err = leerPiezas(parametres[1], &categoriaPiezas);
    if (!err) err = leerPremios(parametres[2], &premios);
    if (!err) err = leerCorredores(parametres[3], &pilotos);
    if (!err) err = leerBase(parametres[4], &base);

    printFileErr(err);

    if(!err) {
        confCoche = (Pieza *) malloc(sizeof(Pieza) * categoriaPiezas.numeroCategorias);
        for (i = 0; i < categoriaPiezas.numeroCategorias; ++i) {
            confCoche[i] = categoriaPiezas.categorias[i].piezas[0];
        }
        clasificacion.clas_GPs = (Info_Class_GP *) malloc(sizeof(Info_Class_GP) * premios.numPremios);
        for (int j = 0; j < premios.numPremios; ++j) {
            clasificacion.clas_GPs[j].clas = (Info_Class *) malloc(sizeof(Info_Class) * NUM_PILOTS);
        }

        //Inicialitzem Allegro
        LS_allegro_init(1000, 600, "Projecte 2");

        //Bucle infinit del joc
        while (!nSortir) {

            //Escoltem el teclat esperant la tecla ESC
            if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
                nSortir = 1;
            }

            al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 500 - 264, 200, 0, "%s",
                          "Bienvenidos a LS Racing!");
            al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 500 - 354, 240, 0, "%s",
                          "Acceda al terminal para ver las funcionalidades disponibles");

            //Pintem la pantalla de la finestra gràfica
            LS_allegro_clear_and_paint(BLACK);

            if (num_parametres == 5) {
                printf("Bienvenidos a LS Racing!\n");
                while (opcion != 0) {
                    printarMenu();
                    opcion = leer_opcion();
                    switch (opcion) {
                        case 1:
                            if (!controlador) {
                                leerPiloto(&piloto);
                                controlador = 1;
                            }
                            mostrarGaraje(&piloto, categoriaPiezas, confCoche);
                            pantallaMenu();
                            break;
                        case 2:
                            if (numOp2 < premios.numPremios && controlador == 1) {
                                LS_allegro_clear_and_paint(BLACK);
                                printf("Preparando carrera #%d: %s ...\n", numOp2 + 1, premios.premios[numOp2].nombre);
                                cargarCarrera(&premios, &pilotos, &tiempos, &piloto, numOp2);
                                guardarClasificacion(&tiempos, &premios, &clasificacion, numOp2);
                                mostrarFinalCarrera(&piloto, posicion);
                                numOp2++;
                            } else {
                                if (controlador != 1) printf("Aun no has configurado el coche.\n");
                                else printf("Ya has finalizado la temporada.\n");
                            }
                            break;
                        case 3:
                            if (numOp2 > 0) {
                                printarClasificacion(&clasificacion, numOp2 - 1);
                            } else printf("La temporada aun no ha empezado.\n");
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
            } else {
                printf("Error. El programa tiene que recibir 4 argumentos.\n");
                nSortir = 1;
            }
            //LS_allegro_clear_and_paint(BLACK);
        }

        free(confCoche);
        for (int j = 0; j < premios.numPremios; ++j) {
            free(clasificacion.clas_GPs[j].clas);
        }
        free(clasificacion.clas_GPs);
        //Tanquem la finestra gràfica
        LS_allegro_exit();
    }
    return 0;
}

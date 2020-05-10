#include <stdio.h>
#include "LS_allegro.h"
#include "menu.h"
#include "conf_Coche.h"
#include "tipos.h"
#include "pieza.h"
#include "listaGPs.h"
#include "corredores.h"
#include "carrera.h"
#include "base.h"
#include "clasificacion.h"
#include "guardar_Temporada.h"

int main(int num_parametres, char **parametres) {

    int nSortir = 0, opcion = 100, controlador = 0, i, err = 0, posicion = 1;
    Corredor piloto;
    ConjuntoCorredores pilotos;
    CategoriaPiezas categoriaPiezas;
    ListaGPs premios;
    Base base;
    Tiempos tiempos;
    Pieza *confCoche;
    Clasificacion clasificacion;

    premios = LISTAGPS_crea();

    clasificacion.numClasificaciones = 0;

    if (num_parametres != 5) err = 3;
    if (!err) err = leerPiezas(parametres[1], &categoriaPiezas);
    if (!err) err = leerPremios(parametres[2], &premios);
    if (!err) err = leerCorredores(parametres[3], &pilotos);
    if (!err) err = leerBase(parametres[4], &base);

    printFileErr(err);

    if (!err) {
        confCoche = (Pieza *) malloc(sizeof(Pieza) * categoriaPiezas.numeroCategorias);
        for (i = 0; i < categoriaPiezas.numeroCategorias; ++i) {
            confCoche[i] = categoriaPiezas.categorias[i].piezas[0];
        }
        clasificacion.clas_GPs = (Info_Class_GP *) malloc(sizeof(Info_Class_GP) * premios.numPremios);
        for (i = 0; i < premios.numPremios; ++i) {
            clasificacion.clas_GPs[i].clas = (Info_Class *) malloc(sizeof(Info_Class) * NUM_PILOTS);
        }


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
                    break;
                case 2:
                    if (clasificacion.numClasificaciones < premios.numPremios && controlador == 1) {
                        printf("Preparando carrera #%d: %s ...\n", clasificacion.numClasificaciones + 1,
                               LISTAGPS_consulta(premios).nombre);
                        cargarCarrera(LISTAGPS_consulta(premios), &pilotos, &tiempos, &piloto);
                        guardarClasificacion(&tiempos, LISTAGPS_consulta(premios), &clasificacion,
                                             clasificacion.numClasificaciones, &posicion);
                        mostrarFinalCarrera(&piloto, &posicion);
                        clasificacion.numClasificaciones++;
                        premios = LISTAGPS_avanza(premios);
                    } else {
                        if (controlador != 1) printf("Aun no has configurado el coche.\n");
                        else printf("Ya has finalizado la temporada.\n");
                    }
                    break;
                case 3:
                    if (clasificacion.numClasificaciones > 0) {
                        printf("Mostrando clasificacion...\n");
                        mostrarClasificacion(&clasificacion, clasificacion.numClasificaciones - 1,
                                             premios.numPremios);
                    } else printf("La temporada aun no ha empezado.\n");
                    break;
                case 4:
                    if (clasificacion.numClasificaciones > 0) {
                        exportTemporada(clasificacion);
                    } else printf("La temporada aun no ha empezado.\n");
                    break;
                case 0:
                    printf("\nHasta Pronto!\n");
                    nSortir = 1;
                    break;
            }
        }


        //LLiberem tota le memòria dinàmica utilitzada
        LISTAGPS_destruye(premios);
        free(confCoche);
        for (i = 0; i < clasificacion.numClasificaciones; ++i) {
            free(clasificacion.clas_GPs[i].clas);
        }
        free(clasificacion.clas_GPs);
    }
    return 0;
}

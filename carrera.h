//
// Created by edmon on 23/3/2020.
//

#ifndef GRUPO_4_CARRERA_H
#define GRUPO_4_CARRERA_H

#include <stdio.h>
#include <stdlib.h>
#include "LS_allegro.h"
#include "premio.h"
#include <time.h>
#include "corredor.h"
#include "tiempo.h"
#include <time.h>

#define NUM_PILOTS 8
#define VEL_text "VELOCITAT"
#define CON_text "CONSUM"
#define FIA_text "FIABILITAT"
#define ACC_text "ACELERACION"
#define PIL_text "PILOT"
#define ESC_text "ESCUDERIA"
#define DOR_text "DORSAL"
#define NOM_text "NOM"

/**
 * Estructura tiempos_corredor almacena características de la carrera como (pit_stops, duración, información personal del piloto)
 * por un piloto en concreto. Y luego se va a crear un array para que cada piloto disponga de esta estructura.
 */
typedef struct {
    int tiempo_carrera;
    int tiempo_stops;
    char nombre[MAX_STRING];
    int dorsal;
    int num_stops;
} Tiempos_Corredor;

/**
 * Estructura Tiempos almacena un array dinámico con tantas posicones como tantos pilotos haya en el juego. Y para cada posicion
 * que va a corresponder a un piloto en concreto, guardaremos la estrucutra tiempos_corredor en su interior. Estos tiempos son
 * utilizados a lo largo del modulo carrera para la interfaz gráfica y además para aquellos pilotos que hay que simular una vez el
 * nuestro ya ha ganado para más tarde concluir con una correcta clasifiación según los tiempos.
 */
typedef struct {
    Tiempos_Corredor *tiempos;
} Tiempos;

/**
 * Funcion que implementa una serie de salidas por pantalla que muestran una información especifica del gran premio
 * @param premios   Estructura donde hay guardad la información de todos los gran premios
 * @param num       Entero que indica en que gran premio nos encontramos dentro de la temporada
 */
void printarInfoCarrera(Premio premio);

/**
 * Función con finalidad gráfica de printar el semáforo incial antes de empezar la carrera
 * @param vermelles     Entero para controlar cuando hay que poner el semáforo en rojo o no
 */
void mostrarSemaforo(int vermelles);

/**
 * Función dedicada al movimiento de los coches sobre la interfaz gráfica según va avanzando el tiempo. Además de controlar
 * si hay llamada de radio para entrar al pit stop
 * @param piloto    Estructura que utilzara la función gráfica para imprimir la información del piloto
 * @param tiempos   Estrucutra que permite saber cuanto tiempo va a durar la carrera
 */
void mostrarCarrera(Corredor *piloto, Tiempos *tiempos);

/**
 * Función con finalidad matemática para averiguar cuando tarda cada uno de los pilotos en el gran premio actual en realizar
 * la carrera, según su configuración del coche y las propias habilidades del piloto
 * @param pilotos   Información individual de cada piloto y mecánica de su coche
 * @param premios   Información de las estadística del gran premio
 * @param tiempos   Estructura donde guardaremos los cálculos realizados en la función
 * @param piloto    Infromación solamento de nuestro piloto y su coche
 * @param num       Entero que indica en que gran premio nos encontramos dentro de la temporada
 */
void calcularTiempo(Corredores *pilotos, Premio premio, Tiempos *tiempos, Corredor *piloto);

/**
 * Función que implementa la salida por pantalla de la posición de nuestro piloto al final de la carrera
 * @param piloto    Información de nuestro piloto para printar su nombre
 * @param posicion  Posición de la carrera en la que ha quedado nuestro piloto
 */
void mostrarFinalCarrera(Corredor *piloto, int *posicion);

/**
 * Funcion dedicada a llamar otras funciones que van a llevar a cabo todas las modalidades para ejecutar la opcion carrera
 * correctamente.
 * @param premios   Información de cada uno de los gran premios de la temporada
 * @param pilotos   Infromación de cada piloto y su coche
 * @param tiempos   Estructura donde guardaremos los tiempos que tarda cada piloto en un gran premio
 * @param piloto    Información solamente de nuestro propio piloto y la configuración de su coche
 * @param num       Entero que indica en que gran premio nos encontramos dentro de la temporada
 */
void cargarCarrera(Premio premio, Corredores *pilotos, Tiempos *tiempos, Corredor *piloto);

/**
 * Función especifica para printar casi toda la parte gràfica de la pantalla específica de la carrera. Como la información
 * de nuestro piloto, el tiempo transcurrido, los pit-stops...
 * @param piloto        Estructura de nuestro piloto con su información personal y mecánica del coche
 * @param tiempos       Información de los tiempos de carrera, pero en este caso también para saber los pit stops de nuestro piloto
 * @param num_stops     Entero que indica cuantos pit stops lleva durante la carrera nuestro piloto
 */
void interfaz_graf_carrera(Corredor *piloto, Tiempos *tiempos, int num_stops);

#endif //GRUPO_4_CARRERA_H

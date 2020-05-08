#include "guardar_Temporada.h"

/**
 * Procediment que exporta l'informació de tot el que es porta de temporada en un ficher de text amb un format llegible
 * @param clasificacion Informació de totes les carreres que s'han fet en la temporada
 */
void exportTemporada(Clasificacion clasificacion) {
    char path[1000];
    int i, j;
    FILE *file;

    printf("Fichero/Ruta exportacion: ");
    fgets(path, 1000, stdin);
    if (path[strlen(path) - 1] == '\n') path[strlen(path) - 1] = '\0';

    file = fopen(path, "w");

    if (file == NULL)printf("\nError. No se ha podido acceder a la ruta '%s'", path);
    else {
        for (i = 0; i < clasificacion.numClasificaciones; ++i) {
            fprintf(file, "Clasificación del %s\n", clasificacion.clas_GPs[i].nombreGP);
            for (j = 0; j < NUM_PILOTS; ++j) {
                fprintf(file, "%d. %s amb %d segons. Punts: %d\n", clasificacion.clas_GPs[i].clas[j].posicion,
                        clasificacion.clas_GPs[i].clas[j].nombre, clasificacion.clas_GPs[i].clas[j].tiempo_carrera,
                        clasificacion.clas_GPs[i].clas[j].puntos);
            }
        }
        fclose(file);
    }
}

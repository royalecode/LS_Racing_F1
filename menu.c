//
// Created by edmon on 23/3/2020.
//

#include "menu.h"

void printarMenu(){
    printf("\n\t1. Configurar coche");
    printf("\n\t2. Carrera");
    printf("\n\t3. Ver clasificacion");
    printf("\n\t4. Guardar temporada\n\n");
    printf("Que opcion quieres ejecutar? ");
}

int leer_opcion(){
    char cad[MAX], cad2 = "exit";
    int opcion = 0, at_exit;
    fgets(cad, MAX, stdin);
    cad[strlen(cad-1)] = '\0';
    at_exit = atoi("exit");
    //printf("%d", at_exit);
    if(atoi(cad) == at_exit && strlen(cad) > 1) {
        return 0;
    }else {
        if(control_numero(atoi(cad), 1, 4)){
            return opcion = atoi(cad);
        }else {
            while (!control_numero(atoi(cad), 1, 4)) {
                printf("\nError. Opcion no valida.\n");
                printarMenu();
                fgets(cad, MAX, stdin);
                cad[strlen(cad-1)] = '\0';
                opcion = atoi(cad);
            }
            return opcion;
        }
    }
}
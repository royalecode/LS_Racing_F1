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
    char cad[MAX];
    int opcion = 0;
    scanf("%s", cad);
    if(strcmp(cad,"exit") == 0) {
         return opcion = -1;
    }else {
        if(control_numero(atoi(cad), 1, 4) == true){
            return opcion = atoi(cad);
        }else {
            while (control_numero(atoi(cad), 1, 4) == false) {
                printf("\nError. Opcion no valida.\n");
                printarMenu();
                scanf("%s", cad);
                opcion = atoi(cad);
            }
            return opcion;
        }
    }
}
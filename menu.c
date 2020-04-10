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

int leer_opcion() {
    char cad[MAX];
    int op, controlador = 0;

    fgets(cad, MAX, stdin);
    if((strcmp(cad,"exit\n"))==0){
        cad[strlen(cad-1)]='\0';
        op = 0;
    } else {
        cad[strlen(cad-1)]='\0';
        op = atoi(cad);
        while ((control_numero(op, 1, 4)) != 1  && controlador == 0) {
            printf("\nError. Opcion no valida.\n");
            printarMenu();
            fgets(cad, MAX, stdin);
            if((strcmp(cad,"exit\n"))==0) {
                cad[strlen(cad-1)]='\0';
                op = 0;
                controlador = 1;
            }else {
                cad[strlen(cad-1)]='\0';
                op = atoi(cad);
            }
        }
    }

    return op;
}


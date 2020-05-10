//
// Created by edmon on 23/3/2020.
//

#include "menu.h"

/**
 * Función utilitzada para printar el menu del programa cada vez que sea necesario
 */
void printarMenu(){
    printf("\n\t1. Configurar coche");
    printf("\n\t2. Carrera");
    printf("\n\t3. Ver clasificacion");
    printf("\n\t4. Guardar temporada\n\n");
    printf("Que opcion quieres ejecutar? ");
}

/**
 * Función que lee por teclado la opción que introduce el usuario, este entra una cadena de carácteres que se transforma
 * en un entero
 * @return      Devolvemos el entero que el usuario ha introducido como opción del menu
 */
int leer_opcion() {
    char cad[MAX_STRING];
    int op, controlador = 0;

    fgets(cad, MAX_STRING, stdin);
    if((strcmp(cad,"exit\n"))==0){
        cad[strlen(cad-1)]='\0';
        op = 0;
    } else {
        cad[strlen(cad-1)]='\0';
        op = atoi(cad);
        while ((op < 1 || op > 4) && controlador == 0) {
            printf("\nError. Opcion no valida.\n");
            printarMenu();
            fgets(cad, MAX_STRING, stdin);
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

/**
 * Printa un missatge d'error si la lectura dels fichers no ha funcionat correctament
 * @param err Codi error
 */
void printFileErr(int err){
    switch (err){
        case 1:
            printf("\nError. Ha ocurrido un error durante el procesamiento de los ficheros.\n");
            break;
        case 2:
            printf("\nError. Hay un fichero vacio.\n");
            break;
        case 3:
            printf("\nError. El programa tiene que recibir 4 argumentos.\n");
            break;
        default:
            break;
    }
}

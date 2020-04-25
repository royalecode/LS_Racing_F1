//
// Created by artur on 25/04/2020.
//

#include "tiempo.h"

void sleep(int ms){
    float time = (float)ms / 1000;
    float clock1, clock2;
    clock1 = (float)clock();
    clock2 = (float)clock();
    while(time > (clock2-clock1) / (float)CLOCKS_PER_SEC){
        clock2 = (float)clock();
    }
}

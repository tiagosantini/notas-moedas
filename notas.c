#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "headers/prototypes.h"

int * get_quantidade_notas(double n, int *quantidade) {
    float nota[] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00};

    int i = 0;
    while(n >= 0) {
        
        if (n != 0){

            quantidade[i] = n / nota[i];
            n = fmod(n, nota[i]);        
        }
        else
        {
            quantidade[i] = n / nota[i];
            i++;
            break;
        }
        i++;
    }
    return quantidade;
}

void show_quantidade_notas(int *notas) {
    float valores[] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00};
    int i;

    printf("NOTAS:\n");
    for (i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %.2f\n", notas[i], valores[i]);
    }
}
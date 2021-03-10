#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "headers/prototypes.h"

int * get_quantidade_moedas(double n, int *quantidade) {
    double x;

    x = modf(n, &n) * 100;

    quantidade[0] = (((((((int) x % 100) % 50) % 20) % 10) % 5) % 2) / 1.00;

    quantidade[1] = (int) x / 50;
    quantidade[2] = ((int) x % 50) / 25;
    quantidade[3] = (((int) x % 50) % 25) / 10;
    quantidade[4] = ((((int) x % 50) % 25) % 10) / 5;
    quantidade[5] = (((((int) x % 50) % 25) % 10) % 5) / 1.00;

    return quantidade;
}

void show_quantidade_moedas(int *moedas) {
    float valores[] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01};
    int i;

    printf("MOEDAS:\n");
    for (i = 0; i < 6; i++) {
        printf("%d moeda(s) de R$ %.2f\n", moedas[i], valores[i]);
    }
}
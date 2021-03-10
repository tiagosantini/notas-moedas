#include <stdio.h>
#include <stdlib.h>

#include "headers/prototypes.h"

int main() {

    double n;
    int *quant_nota = (int*) malloc(7 * sizeof(int));
    int *quant_moeda = (int*) malloc(7 * sizeof(int));

    system("clear");

    printf("Digite um valor: R$ ");
    scanf("%lf", &n);

    int *notas = get_quantidade_notas(n, quant_nota);
    show_quantidade_notas(notas);

    int *moedas = get_quantidade_moedas(n, quant_moeda);
    show_quantidade_moedas(moedas);


    free(quant_nota);

    return 0;
}
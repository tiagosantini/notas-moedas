#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * getQuantNotas(float n, int *quantidade) {
    float nota[] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00};

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

int * getQuantMoedas(float n, int *quantidade) {
    int moeda[] = {1, 50, 25, 10, 5, 1};

    int notas = n;
    int moedas = (n - notas) * 100;

    if ((moedas * 1000) % 10 == 9) {
        moedas++;
    }

    int i = 0;
    while(n >= 0) {

        if (moeda[0] == 1) {
            quantidade[i] = notas / 1;
            notas %= 1;
        } 

        if (n != 0) {

            quantidade[i] = moedas / moeda[i];
            n = fmod(moedas, moeda[i]);        
        }

        else
        {
            quantidade[i] = moedas / moeda[i];
            i++;
            break;
        }

    }

    return quantidade;
}

int main() {

    float n;

    int *quant_nota = (int*) malloc(7 * sizeof(int));
    int *quant_moeda = (int*) malloc(7 * sizeof(int));

    scanf("%f", &n);

    int * notas = getQuantNotas(n, quant_nota);
    int * moedas = getQuantMoedas(n, quant_moeda);

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", notas[0]);
    printf("%d nota(s) de R$ 50.00\n", notas[1]);
    printf("%d nota(s) de R$ 20.00\n", notas[2]);
    printf("%d nota(s) de R$ 10.00\n", notas[3]);
    printf("%d nota(s) de R$ 5.00\n", notas[4]);
    printf("%d nota(s) de R$ 2.00\n", notas[5]);
    
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", moedas[0]);
    printf("%d moeda(s) de R$ 0.50\n", moedas[1]);
    printf("%d moeda(s) de R$ 0.25\n", moedas[2]);
    printf("%d moeda(s) de R$ 0.10\n", moedas[3]);
    printf("%d moeda(s) de R$ 0.05\n", moedas[4]);
    printf("%d moeda(s) de R$ 0.01\n", moedas[5]);

    free(quant_nota);
    return 0;
}
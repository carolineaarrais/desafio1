#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ARMARIOS 8

void printbin(unsigned char num) {
    printf("Estado dos armarios: ");
    for (int i = 7; i >= 0; i--) {
        if (num & (1 << i)) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }
    printf("\n");
}

int main() {
    unsigned char armario = 0, controle;
    int opcao;

    srand(time(NULL));

    while (1) {
        printf("\nMenu:\n");
        printf("1. Ocupar armario\n");
        printf("2. Liberar armario\n");
        printf("3. Sair\n\n");
        printbin(armario);
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (armario == 255) {
                printf("\nTodos os armarios estao ocupados.\n");
            } else {
                do {
                    controle = rand() % NUM_ARMARIOS;
                } while (armario & (1 << controle));
                armario |= (1 << controle);
                printf("\nArmario %hhd ocupado.\n", controle + 1);
            }
        } else if (opcao == 2) {
            if (armario == 0) {
                printf("\nTodos os armarios estao livres.\n");
            } else {
                do {
                    printf("\nDigite o numero do armario para liberar (1 a 8): ");
                    scanf("%hhd", &controle);
                    controle--;
                    if (controle < 0 || controle > 7) {
                        printf("\nValor de armario invalido! Escolha entre 1 e 8 para liberar.\n");
                    } else if (!(armario & (1 << controle))) {
                    printf("\nArmario %hhd ja esta livre.\n", controle + 1);
                    } 
                }  while (controle < 0 || controle > 7 || !(armario & (1 << controle)));
                if (armario & (1 << controle)) {
                    armario &= ~(1 << controle);
                    printf("\nArmario %hhd liberado.\n", controle + 1);
                }
            }
        } else if (opcao == 3) {
            printf("\nSaindo do programa...\n\n");
            return 0;
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}

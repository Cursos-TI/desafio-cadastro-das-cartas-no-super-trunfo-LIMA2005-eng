#include <stdio.h>
#include <string.h>

// Estrutura representando um país
typedef struct {
    char nome[30];
    int populacao; // em milhões
    float area;    // em mil km²
    float pib;     // em trilhões USD
} Pais;

// Função para mostrar os dados do país
void mostrarPais(Pais p) {
    printf("País: %s\n", p.nome);
    printf("População: %d milhões\n", p.populacao);
    printf("Área: %.2f mil km²\n", p.area);
    printf("PIB: %.2f trilhões USD\n", p.pib);
}

// Função para comparar os países com base em um atributo
void comparar(Pais jogador, Pais computador, int atributo) {
    printf("\n--- Comparando Países ---\n");
    printf("\nVocê escolheu:\n");
    mostrarPais(jogador);

    printf("\nOponente (computador):\n");
    mostrarPais(computador);

    printf("\nResultado: ");

    switch(atributo) {
        case 1: // População
            if (jogador.populacao > computador.populacao)
                printf("Você venceu!\n");
            else if (jogador.populacao < computador.populacao)
                printf("Computador venceu!\n");
            else
                printf("Empate!\n");
            break;
        case 2: // Área
            if (jogador.area > computador.area)
                printf("Você venceu!\n");
            else if (jogador.area < computador.area)
                printf("Computador venceu!\n");
            else
                printf("Empate!\n");
            break;
        case 3: // PIB
            if (jogador.pib > computador.pib)
                printf("Você venceu!\n");
            else if (jogador.pib < computador.pib)
                printf("Computador venceu!\n");
            else
                printf("Empate!\n");
            break;
        default:
            printf("Atributo inválido!\n");
    }
}

int main() {
    Pais brasil = {"Brasil", 214, 8516.0, 2.0};
    Pais alemanha = {"Alemanha", 83, 357.0, 4.5};

    int escolhaPais, atributo;
    Pais jogador, computador;

    printf("=== Super Trunfo: Brasil x Alemanha ===\n");
    printf("Escolha seu país:\n");
    printf("1. Brasil\n");
    printf("2. Alemanha\n");
    printf("Digite 1 ou 2: ");
    scanf("%d", &escolhaPais);

    if (escolhaPais == 1) {
        jogador = brasil;
        computador = alemanha;
    } else if (escolhaPais == 2) {
        jogador = alemanha;
        computador = brasil;
    } else {
        printf("Escolha inválida.\n");
        return 1;
    }

    printf("\nEscolha um atributo para competir:\n");
    printf("1. População\n2. Área\n3. PIB\n");
    printf("Digite 1, 2 ou 3: ");
    scanf("%d", &atributo);

    comparar(jogador, computador, atributo);

    return 0;
}

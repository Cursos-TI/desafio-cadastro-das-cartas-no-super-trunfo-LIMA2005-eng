#include <stdio.h>
#include <string.h>

// Estrutura representando um país
typedef struct {
    char nome[30];
    int populacao;            // em milhões
    float area;               // em mil km²
    float pib;                // em trilhões USD
    int pontosTuristicos;     // número de pontos turísticos
    float densidade;          // habitantes por km²
} Pais;

// Função auxiliar para imprimir os nomes dos atributos
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Retorna o valor numérico de um atributo genérico
float obterValor(Pais p, int atributo) {
    switch(atributo) {
        case 1: return (float)p.populacao;
        case 2: return p.area;
        case 3: return p.pib;
        case 4: return (float)p.pontosTuristicos;
        case 5: return p.densidade;
        default: return 0;
    }
}

// Exibe dados do país
void mostrarPais(Pais p) {
    printf("País: %s\n", p.nome);
    printf("População: %d milhões\n", p.populacao);
    printf("Área: %.2f mil km²\n", p.area);
    printf("PIB: %.2f trilhões USD\n", p.pib);
    printf("Pontos turísticos: %d\n", p.pontosTuristicos);
    printf("Densidade demográfica: %.2f hab/km²\n", p.densidade);
}

// Compara dois atributos e exibe resultados
void compararAtributos(Pais p1, Pais p2, int a1, int a2) {
    float v1_p1 = obterValor(p1, a1);
    float v1_p2 = obterValor(p2, a1);
    float v2_p1 = obterValor(p1, a2);
    float v2_p2 = obterValor(p2, a2);

    int pontos_p1 = 0, pontos_p2 = 0;

    printf("\n--- COMPARAÇÃO DOS ATRIBUTOS ---\n");

    for (int i = 0; i < 2; i++) {
        int atributo = (i == 0) ? a1 : a2;
        float valor1 = (i == 0) ? v1_p1 : v2_p1;
        float valor2 = (i == 0) ? v1_p2 : v2_p2;

        printf("\nAtributo: %s\n", nomeAtributo(atributo));
        printf("%s: %.2f\n", p1.nome, valor1);
        printf("%s: %.2f\n", p2.nome, valor2);

        if (atributo == 5) { // Densidade: MENOR vence
            if (valor1 < valor2) pontos_p1++;
            else if (valor1 > valor2) pontos_p2++;
        } else {
            if (valor1 > valor2) pontos_p1++;
            else if (valor1 < valor2) pontos_p2++;
        }
    }

    float soma_p1 = v1_p1 + v2_p1;
    float soma_p2 = v1_p2 + v2_p2;

    printf("\n--- SOMA DOS ATRIBUTOS ---\n");
    printf("%s: %.2f\n", p1.nome, soma_p1);
    printf("%s: %.2f\n", p2.nome, soma_p2);

    printf("\n=== RESULTADO FINAL ===\n");
    if (soma_p1 > soma_p2)
        printf("Vencedor: %s\n", p1.nome);
    else if (soma_p1 < soma_p2)
        printf("Vencedor: %s\n", p2.nome);
    else
        printf("Empate!\n");
}

int main() {
    Pais brasil = {"Brasil", 214, 8516.0, 2.0, 65, 25.1};
    Pais alemanha = {"Alemanha", 83, 357.0, 4.5, 90, 232.5};

    int attr1 = 0, attr2 = 0;

    printf("=== SUPER TRUNFO: BRASIL x ALEMANHA ===\n\n");

    printf("Sua carta:\n");
    mostrarPais(brasil);
    printf("\nCarta do computador:\n");
    mostrarPais(alemanha);

    // Menu para escolha do primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &attr1);

    // Menu para escolha do segundo atributo (dinâmico)
    do {
        printf("\nEscolha o SEGUNDO atributo para comparar (diferente do primeiro):\n");
        for (int i = 1; i <= 5; i++) {
            if (i != attr1)
                printf("%d - %s\n", i, nomeAtributo(i));
        }
        printf("Digite sua escolha: ");
        scanf("%d", &attr2);
        if (attr2 == attr1)
            printf("Você já escolheu esse atributo. Tente outro.\n");
    } while (attr2 == attr1 || attr2 < 1 || attr2 > 5);

    compararAtributos(brasil, alemanha, attr1, attr2);

    return 0;
}

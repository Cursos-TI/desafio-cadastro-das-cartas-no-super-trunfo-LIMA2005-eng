 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição da estrutura para representar um país
typedef struct {
    char nome[50];
    int area;
    int populacao;
    float idh;
} Pais;

// Função para criar uma carta (objeto Pais)
Pais cria_carta(const char *nome, int area, int populacao, float idh) {
    Pais carta;
    strcpy(carta.nome, nome);
    carta.area = area;
    carta.populacao = populacao;
    carta.idh = idh;
    return carta;
}

// Função para embaralhar as cartas
void embaralha_cartas(Pais cartas[], int num_cartas) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com a hora atual
    for (int i = 0; i < num_cartas; i++) {
        int j = rand() % num_cartas;
        Pais temp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = temp;
    }
}

// Função principal (simulando um jogo)
int main() {
    // Criando algumas cartas (países)
    Pais cartas[2]; // Exemplo com 4 cartas
    cartas[0] = cria_carta("Brasil", 8515767, 210000000, 0.76);
    cartas[1] = cria_carta("Estados Unidos", 9833520, 330000000, 0.94);
    

    // Embaralhando as cartas
    embaralha_cartas(cartas, 2);

    // Exibindo as cartas embaralhadas (para verificar)
    printf("Cartas Embaralhadas:\n");
    for (int i = 0; i < 2; i++) {
        printf("%s - Area: %d - Populacao: %d - IDH: %.2f\n", cartas[i].nome, cartas[i].area, cartas[i].populacao, cartas[i].idh);
    }

    // Implementação da lógica do jogo (em um próximo passo)

    return 0;
}
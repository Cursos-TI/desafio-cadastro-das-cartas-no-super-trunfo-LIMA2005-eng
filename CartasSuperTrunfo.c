#include <stdio.h>
 
int main(){

    int estado[50];
    int codigo[2];
    int cidade[22];
    int populacao;
    int Pontosturisticos;
    float area;
    float pib;

    printf("Digite seu Estado: \n");
    scanf("%s" , &estado);

    printf("Codigo: \n");
    scanf("%s" , &codigo);

    printf("Nome da Cidade: \n");
    scanf("%s" , &cidade);

    printf("Total de Habitantes: \n");
    scanf("%d" , &populacao);
    
    printf("Area: \n");
    scanf("%f" , &area);

    printf("Pib: \n");
    scanf("%f", &pib);


    printf("Pontos turisticos: \n");
    scanf("%d" , &Pontosturisticos);

    printf("Carta 1! \n");
    printf("Estado: %s \n" , estado);
    printf("Codigo da carta: %s%s \n", estado, codigo);
    printf("Cidade: %s \n", cidade);
    printf("Habitantes: %d \n", populacao);
    printf("Area: %f \n", area);
    printf("Pib: %f \n", pib);
    printf("Pontos turisticos: %d \n", Pontosturisticos);
 
    return 0;
}
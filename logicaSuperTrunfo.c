#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 

typedef struct{
    char estado[50];
    char cidade[50];
    char codigo[50];
    float populacao; // Em milhões
    float area; // Em Km²
    float pib; // Em bilhões
    int pontos_turisticos; 
} Carta;




int main() {

      // Carta 1
      Carta carta1 = {
        .estado = "Bahia",
        .cidade = "Salvador",
        .codigo = "B01",
        .populacao = 2.418, // Em milhões
        .area = 693.442, // Em Km²
        .pib = 62.954, // Em bilhões
        .pontos_turisticos = 15
    };


    // Carta 2
    Carta carta2 = {
        .estado = "Ceara",
        .cidade = "Fortaleza",
        .codigo = "C02",
        .populacao = 2.574, // Em milhões
        .area = 312.353, // Em Km²
        .pib = 73.0, // Em bilhões
        .pontos_turisticos = 25
    };

    printf("Digite o código da cidade: \n");
    scanf("%s", carta1.codigo);

    printf("Digite o código da cidade: \n");
    scanf("%s", carta2.codigo);


    if (carta1.populacao > carta2.populacao){
        printf("Salvador tem maior população, portanto Carta 1 é a vencedora. \n");

    } else{
        printf("Fortaleza tem maior população, portanto Carta 2 é a vencedora. \n");
    }

    

    return 0;
}

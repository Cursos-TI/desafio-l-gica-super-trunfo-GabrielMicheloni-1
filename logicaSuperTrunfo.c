#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char estado[50];
    char cidade[50];
    char codigo[50];
    float populacao; // Em milhões
    float area; // Em Km²
    float pib; // Em bilhões
    int pontos_turisticos; 
} Carta;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void compararPopulacao(Carta c1, Carta c2) {
    if (c1.populacao > c2.populacao) {
        printf("%s tem maior população (%.3f milhões) que %s (%.3f milhões). Carta 1 vence!\n", 
               c1.cidade, c1.populacao, c2.cidade, c2.populacao);
    } else if (c1.populacao < c2.populacao) {
        printf("%s tem maior população (%.3f milhões) que %s (%.3f milhões). Carta 2 vence!\n", 
               c2.cidade, c2.populacao, c1.cidade, c1.populacao);
    } else {
        printf("População igual (%.3f milhões). Empate!\n", c1.populacao);
    }
}

void compararArea(Carta c1, Carta c2) {
    if (c1.area > c2.area) {
        printf("%s tem maior área (%.3f km²) que %s (%.3f km²). Carta 1 vence!\n", 
               c1.cidade, c1.area, c2.cidade, c2.area);
    } else if (c1.area < c2.area) {
        printf("%s tem maior área (%.3f km²) que %s (%.3f km²). Carta 2 vence!\n", 
               c2.cidade, c2.area, c1.cidade, c1.area);
    } else {
        printf("Área igual (%.3f km²). Empate!\n", c1.area);
    }
}

void compararPIB(Carta c1, Carta c2) {
    if (c1.pib > c2.pib) {
        printf("%s tem maior PIB (R$ %.3f bilhões) que %s (R$ %.3f bilhões). Carta 1 vence!\n", 
               c1.cidade, c1.pib, c2.cidade, c2.pib);
    } else if (c1.pib < c2.pib) {
        printf("%s tem maior PIB (R$ %.3f bilhões) que %s (R$ %.3f bilhões). Carta 2 vence!\n", 
               c2.cidade, c2.pib, c1.cidade, c1.pib);
    } else {
        printf("PIB igual (R$ %.3f bilhões). Empate!\n", c1.pib);
    }
}

void compararPontosTuristicos(Carta c1, Carta c2) {
    if (c1.pontos_turisticos > c2.pontos_turisticos) {
        printf("%s tem mais pontos turísticos (%d) que %s (%d). Carta 1 vence!\n", 
               c1.cidade, c1.pontos_turisticos, c2.cidade, c2.pontos_turisticos);
    } else if (c1.pontos_turisticos < c2.pontos_turisticos) {
        printf("%s tem mais pontos turísticos (%d) que %s (%d). Carta 2 vence!\n", 
               c2.cidade, c2.pontos_turisticos, c1.cidade, c1.pontos_turisticos);
    } else {
        printf("Número de pontos turísticos igual (%d). Empate!\n", c1.pontos_turisticos);
    }
}

void desempate(Carta c1, Carta c2) {
    printf("\n*** Desempate ***\n");
    printf("Comparando pela população das cidades:\n");
    compararPopulacao(c1, c2);
}

void exibirCarta(Carta c, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Cidade: %s\n", c.cidade);
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %.3f milhões\n", c.populacao);
    printf("Área: %.3f km²\n", c.area);
    printf("PIB: R$ %.3f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {
        .estado = "Bahia",
        .cidade = "Salvador",
        .codigo = "B01",
        .populacao = 2.418,
        .area = 693.442,
        .pib = 62.954,
        .pontos_turisticos = 15
    };

    Carta carta2 = {
        .estado = "Ceara",
        .cidade = "Fortaleza",
        .codigo = "C02",
        .populacao = 2.574,
        .area = 312.353,
        .pib = 73.0,
        .pontos_turisticos = 25
    };

    char opcao;
    int sair = 0;

    printf("Bem-vindo ao Super Trunfo de Cidades!\n");

    while (!sair) {
        printf("\nMenu Principal:\n");
        printf("1 - Exibir cartas\n");
        printf("2 - Comparar cartas\n");
        printf("3 - Alterar código das cartas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        limparBuffer();

        switch (toupper(opcao)) {
            case '1':
                exibirCarta(carta1, 1);
                exibirCarta(carta2, 2);
                break;

            case '2': {
                char atributo;
                printf("\nEscolha o atributo para comparar:\n");
                printf("A - População\n");
                printf("B - Área\n");
                printf("C - PIB\n");
                printf("D - Pontos Turísticos\n");
                printf("E - Voltar\n");
                printf("Opção: ");
                scanf(" %c", &atributo);
                limparBuffer();

                switch (toupper(atributo)) {
                    case 'A':
                        compararPopulacao(carta1, carta2);
                        break;
                    case 'B':
                        compararArea(carta1, carta2);
                        break;
                    case 'C':
                        compararPIB(carta1, carta2);
                        break;
                    case 'D':
                        compararPontosTuristicos(carta1, carta2);
                        break;
                    case 'E':
                        break;
                    default:
                        printf("Opção inválida!\n");
                }
                break;
            }

            case '3':
                printf("Digite o novo código para Carta 1 (atual: %s): ", carta1.codigo);
                scanf("%49s", carta1.codigo);
                limparBuffer();
                
                printf("Digite o novo código para Carta 2 (atual: %s): ", carta2.codigo);
                scanf("%49s", carta2.codigo);
                limparBuffer();
                
                printf("Códigos atualizados com sucesso!\n");
                break;

            case '4':
                sair = 1;
                printf("Obrigado por jogar!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
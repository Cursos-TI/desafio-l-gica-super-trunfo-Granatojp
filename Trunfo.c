#include <stdio.h>

// Estrutura para armazenar as informações de uma carta de cidade
typedef struct {
    char estado[50];
    int codigo;
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} CartaCidade;

// Função para cadastrar as informações de uma cidade
void cadastrarCarta(CartaCidade *carta) {
    printf("Digite o estado da cidade: ");
    scanf("%s", carta->estado);
    printf("Digite o código da carta: ");
    scanf("%d", &carta->codigo);
    printf("Digite o nome da cidade: ");
    scanf("%s", carta->cidade);
    printf("Digite a população da cidade: ");
    scanf("%d", &carta->populacao);
    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB da cidade (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir as informações de uma carta de cidade
void exibirCarta(CartaCidade carta) {
    printf("\nInformações da Cidade:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %d\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontosTuristicos);
}

// Função para comparar as cartas com base em um atributo
void compararCartas(CartaCidade carta1, CartaCidade carta2, int escolha) {
    if (escolha == 1) {
        // Comparar população
        printf("\nComparando a População:\n");
        if (carta1.populacao > carta2.populacao) {
            printf("A cidade %s venceu com maior população!\n", carta1.cidade);
        } else if (carta1.populacao < carta2.populacao) {
            printf("A cidade %s venceu com maior população!\n", carta2.cidade);
        } else {
            printf("As cidades têm a mesma população.\n");
        }
    } else if (escolha == 2) {
        // Comparar área
        printf("\nComparando a Área:\n");
        if (carta1.area > carta2.area) {
            printf("A cidade %s venceu com maior área!\n", carta1.cidade);
        } else if (carta1.area < carta2.area) {
            printf("A cidade %s venceu com maior área!\n", carta2.cidade);
        } else {
            printf("As cidades têm a mesma área.\n");
        }
    } else if (escolha == 3) {
        // Comparar PIB
        printf("\nComparando o PIB:\n");
        if (carta1.pib > carta2.pib) {
            printf("A cidade %s venceu com maior PIB!\n", carta1.cidade);
        } else if (carta1.pib < carta2.pib) {
            printf("A cidade %s venceu com maior PIB!\n", carta2.cidade);
        } else {
            printf("As cidades têm o mesmo PIB.\n");
        }
    } else if (escolha == 4) {
        // Comparar densidade populacional (população / área)
        float densidade1 = carta1.populacao / carta1.area;
        float densidade2 = carta2.populacao / carta2.area;

        printf("\nComparando a Densidade Populacional:\n");
        if (densidade1 < densidade2) {
            printf("A cidade %s venceu com menor densidade populacional!\n", carta1.cidade);
        } else if (densidade1 > densidade2) {
            printf("A cidade %s venceu com menor densidade populacional!\n", carta2.cidade);
        } else {
            printf("As cidades têm a mesma densidade populacional.\n");
        }
    }
}

int main() {
    CartaCidade carta1, carta2;

    printf("Cadastro da primeira carta de cidade:\n");
    cadastrarCarta(&carta1);
    printf("\nCadastro da segunda carta de cidade:\n");
    cadastrarCarta(&carta2);

    // Exibindo as cartas cadastradas
    printf("\n\nCartas cadastradas:\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    // Escolha do critério de comparação
    int escolha;
    printf("\nEscolha o critério de comparação (1: População, 2: Área, 3: PIB, 4: Densidade Populacional): ");
    scanf("%d", &escolha);

    // Comparando as cartas
    compararCartas(carta1, carta2, escolha);

    return 0;
}

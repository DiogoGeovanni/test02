#include <stdio.h>

#define MAX_SIZE 50

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int esquerda = 0, direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (vetor[meio] == valor)
            return meio;
        if (vetor[meio] < valor)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }
    return -1;
}

void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    if (*tamanho >= MAX_SIZE) {
        printf("O vetor está na capacidade máxima!\n");
        return;
    }
    int i;
    for (i = *tamanho - 1; i >= 0 && vetor[i] > valor; i--) {
        vetor[i + 1] = vetor[i];
    }
    vetor[i + 1] = valor;
    (*tamanho)++;
}

void removerElemento(int vetor[], int *tamanho, int valor) {
    int posicao = buscaBinaria(vetor, *tamanho, valor);
    if (posicao == -1) {
        printf("Elemento não encontrado!\n");
        return;
    }
    for (int i = posicao; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
}

int main() {
    int vetor[MAX_SIZE], tamanho;
    
    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > MAX_SIZE);
    
    printf("Digite %d valores inteiros ordenados:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        int valor;
        scanf("%d", &valor);
        inserirOrdenado(vetor, &i, valor);
    }
    
    int opcao, valor;
    do {
        printf("\nMenu:\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Consultar posição de um elemento\n");
        printf("3 - Remover um elemento\n");
        printf("4 - Inserir um elemento\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;
            case 2:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                printf("Posição: %d\n", buscaBinaria(vetor, tamanho, valor));
                break;
            case 3:
                printf("Digite o valor para remover: ");
                scanf("%d", &valor);
                removerElemento(vetor, &tamanho, valor);
                break;
            case 4:
                if (tamanho < MAX_SIZE) {
                    printf("Digite o valor para inserir: ");
                    scanf("%d", &valor);
                    inserirOrdenado(vetor, &tamanho, valor);
                } else {
                    printf("O vetor está cheio!\n");
                }
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *vetor, int tamanho, int *trocas)
{
    int atual, proximo, auxiliar;
    *trocas = 0;

    for (atual = 1; atual < tamanho; atual++)
    {
        for (proximo = 0; proximo < tamanho - 1; proximo++)
        {
            if (vetor[proximo] > vetor[proximo + 1])
            {
                auxiliar = vetor[proximo];
                vetor[proximo] = vetor[proximo + 1];
                vetor[proximo + 1] = auxiliar;
                (*trocas)++;
            }
        }
    }
}

void imprimirVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("[%d] ", vetor[i]);
    }
}

int main()
{
    int tamanhoVetor = 10;                         // Insira aqui o tamanho (1000, 5000, etc...)
    int vetor[] = {9, 5, 2, 7, 1, 8, 3, 6, 10, 4}; // Insira aqui os dados
    int trocas = 0;
    clock_t inicio, fim;
    double tempo;

    printf("Vetor antes da ordenacao\n");
    imprimirVetor(vetor, tamanhoVetor);

    inicio = clock();
    bubbleSort(vetor, tamanhoVetor, &trocas);
    fim = clock();

    printf("\n\nVetor ordenado\n");
    imprimirVetor(vetor, tamanhoVetor);

    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\n\nNumero de trocas realizadas: %d\n", trocas);
    printf("Tempo de ordenacao: %f segundos\n", tempo);

    return 0;
}

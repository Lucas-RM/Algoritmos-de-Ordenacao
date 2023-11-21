#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int low, int high, int *total_trocas)
{
    int pivo = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivo)
        {
            i++;
            troca(&arr[i], &arr[j]);
            *total_trocas += 1;
        }
    }

    troca(&arr[i + 1], &arr[high]);
    *total_trocas += 1;
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *total_trocas)
{
    if (low < high)
    {
        int pi = particionar(arr, low, high, total_trocas);

        quickSort(arr, low, pi - 1, total_trocas);
        quickSort(arr, pi + 1, high, total_trocas);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int size = 1000;  // Insira aqui o tamanho (1000, 5000, etc...)
    int vetor[] = {}; // Insira aqui os dados
    int trocas = 0;
    clock_t start_time, end_time;
    double total_time;

    printf("Vetor antes da ordenacao\n");
    printArray(vetor, size);

    start_time = clock();
    quickSort(vetor, 0, size - 1, &trocas);
    end_time = clock();

    printf("\n\nVetor ordenado\n");
    printArray(vetor, size);

    printf("inicio: %f", (double)start_time);
    printf("fim: %f", (double)end_time);

    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\n\nNumero de trocas realizadas: %d\n", trocas);
    printf("Tempo levado: %f segundos\n", total_time);

    return 0;
}
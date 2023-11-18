#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int low, int high, unsigned long long *total_trocas)
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

void quickSort(int arr[], int low, int high, unsigned long long *total_trocas)
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
    int size = 100000;        // Insira aqui o tamanho (1000, 5000, etc...)
    int lista_valores[] = {}; // Insira aqui os dados
    int dados[size];

    for (int i = 0; i < size && i < sizeof(lista_valores) / sizeof(lista_valores[0]); i++)
    {
        dados[i] = lista_valores[i];
    }

    unsigned long long total_trocas = 0;

    clock_t start_time, end_time;
    double total_time;

    start_time = clock();
    quickSort(dados, 0, size - 1, &total_trocas);
    end_time = clock();

    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Números Ordenados:\n\n ");
    printArray(dados, size);

    printf("\nQuantidade total de trocas: %llu\n", total_trocas);
    printf("Tempo levado: %f segundos\n", total_time);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r, unsigned long long *total_trocas)
{
    int VetorA, VetorB, VetorC;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (VetorA = 0; VetorA < n1; VetorA++)
        L[VetorA] = arr[l + VetorA];
    for (VetorB = 0; VetorB < n2; VetorB++)
        R[VetorB] = arr[m + 1 + VetorB];

    VetorA = 0;
    VetorB = 0;
    VetorC = l;
    while (VetorA < n1 && VetorB < n2)
    {
        if (L[VetorA] <= R[VetorB])
        {
            arr[VetorC] = L[VetorA];
            VetorA++;
        }
        else
        {
            arr[VetorC] = R[VetorB];
            VetorB++;
            *total_trocas += (m - l + 1 - VetorA);
        }
        VetorC++;
    }

    while (VetorA < n1)
    {
        arr[VetorC] = L[VetorA];
        VetorA++;
        VetorC++;
    }

    while (VetorB < n2)
    {
        arr[VetorC] = R[VetorB];
        VetorB++;
        VetorC++;
    }
}

void mergeSort(int arr[], int l, int r, unsigned long long *total_trocas)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, total_trocas);
        mergeSort(arr, m + 1, r, total_trocas);

        merge(arr, l, m, r, total_trocas);
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
    int size = 1000;          // Insira aqui o tamanho (1000, 5000, etc...)
    int lista_valores[] = {}; // Insira aqui os dados
    int dados[size];

    for (int i = 0; i < size; i++)
    {
        if (i < sizeof(lista_valores) / sizeof(lista_valores[0]))
        {
            dados[i] = lista_valores[i];
        }
        else
        {
            dados[i] = 0;
        }
    }

    unsigned long long total_trocas = 0;

    clock_t start_time, end_time;
    double total_time;

    start_time = clock();
    mergeSort(dados, 0, size - 1, &total_trocas);
    end_time = clock();

    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Números Ordenados:\n\n ");
    printArray(dados, size);

    printf("\nQuantidade total de trocas: %llu\n", total_trocas);
    printf("Tempo levado: %f segundos\n", total_time);

    return 0;
}

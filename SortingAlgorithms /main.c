#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

 // Selection Sort
void selectionSort(int arr[], int tamanho) {
    clock_t inicio = clock();
    int troca;

    for (int i = 0; i < tamanho - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < tamanho; j++)
        {
            if (arr[j] < arr[menor]) menor = j;
        }

        troca = arr[i];
        arr[i] = arr[menor];
        arr[menor] = troca;
    }

    printf("Tempo Selection: %lf segundos\n", (double)(clock() - inicio) / CLOCKS_PER_SEC);
}


// Insertion Sort
void insertionSort (int arr[], int tamanho) {
    clock_t inicio = clock();
    for(int i = 1; i < tamanho; i++){
        int chave = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > chave){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = chave;
    }
    printf("Tempo Insertion: %lf segundos\n", (double)(clock() - inicio) / CLOCKS_PER_SEC);
}

// Bubble Sort
void bubbleSort (int arr[], int tamanho){
    clock_t inicio = clock();
    bool troca;

    for (int i = 0; i < tamanho; i++)
    {
        troca = false;
        for(int j = 0; j < tamanho-i-1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                troca = true;
            }
        }

        if (!troca) break;
    }

    printf("Tempo Bubble: %lf segundos\n", (double)(clock() - inicio) / CLOCKS_PER_SEC);
}

int main()
{
    int arr1[10], arr2[1000], arr3[100000];

    srand(time(NULL));
    for( int i=0; i<10; i++) arr1[i]=rand();

    srand(time(NULL));
    for( int i=0; i<1000; i++) arr2[i]=rand();

    srand(time(NULL));
    for( int i=0; i<100000; i++) arr3[i]=rand();

    selectionSort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    selectionSort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    selectionSort(arr3, sizeof(arr3)/sizeof(arr3[0]));

    srand(time(NULL));
    for( int i=0; i<10; i++) arr1[i]=rand();

    srand(time(NULL));
    for( int i=0; i<1000; i++) arr2[i]=rand();

    srand(time(NULL));
    for( int i=0; i<100000; i++) arr3[i]=rand();

    printf("\n");
    insertionSort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    insertionSort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    insertionSort(arr3, sizeof(arr3)/sizeof(arr3[0]));

    srand(time(NULL));
    for( int i=0; i<10; i++) arr1[i]=rand();

    srand(time(NULL));
    for( int i=0; i<1000; i++) arr2[i]=rand();

    srand(time(NULL));
    for( int i=0; i<100000; i++) arr3[i]=rand();

    printf("\n");
    bubbleSort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    bubbleSort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    bubbleSort(arr3, sizeof(arr3)/sizeof(arr3[0]));

    return 0;
}

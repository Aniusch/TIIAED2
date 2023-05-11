#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void heapify(LogRecord* arr[], int n, int i, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){ 
    int largest = i; // inicializa o maior como raiz
    int l = 2 * i + 1; // elemento da esquerda
    int r = 2 * i + 2; // elemento da direita
    LogRecord* temp;
    if (ascending) {
        if (l < n) {
            (*numComparacoes)++;
            if (arr[l]->process_id > arr[largest]->process_id) {
                largest = l;
            }
        }
        if (r < n) {
            (*numComparacoes)++;
            if (arr[r]->process_id > arr[largest]->process_id) {
                largest = r;
            }
        }
    } else {
        if (l < n) {
            (*numComparacoes)++;
            if (arr[l]->process_id < arr[largest]->process_id) {
                largest = l;
            }
        }
        if (r < n) {
            (*numComparacoes)++;
            if (arr[r]->process_id < arr[largest]->process_id) {
                largest = r;
            }
        }
    }
    if (largest != i) {
        (*numTrocas)++;
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, numComparacoes, numTrocas, ascending);
    }
}
void heapSort(LogRecord* arr[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending) {
    LogRecord* temp;
    // Construindo o heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, numComparacoes, numTrocas, ascending);
    }
    // Extraindo elementos do heap
    for (int i = n - 1; i >= 0; i--) {
        (*numTrocas)++;
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, numComparacoes, numTrocas, ascending);
    }
}

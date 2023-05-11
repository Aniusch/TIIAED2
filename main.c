#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

int main(int argc, char *argv[]){
   if (argc < 4){
        return 1;
    }
    int escolha = atoi(argv[1]); // escolha um algoritmo
    int n = atoi(argv[2]); // numero de registros de log
    int ordem = atoi(argv[3]); // 0 para ordem decrescente e 1 para ordem crescente

    clock_t start, end; // medir tempo de execucao
    double cpu_time; // tempo de execucao

    long int numComparacoes = 0; // numero de comparacoes
    long int numTrocas = 0; // numero de trocas

    if(ordem == 2){
        ordem = rand() % 2; // gera um numero aleatorio entre 0 e 1
    }

    LogRecord* logArray[n];
    // gerando registros de log aleatorios
    int i;
    for(i = 0; i < n; i++){
        logArray[i] = generateLogRecord(); // gera um registro de log aleatorio
    }

    switch (escolha){
    case 1:
        printf("Bubble Sort\n");
        start = clock();
        bubbleSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 2:
        printf("Insertion Sort\n");
        start = clock();
        insertionSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 3:
        printf("Selection Sort\n");
        start = clock();
        selectionSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 4:
        printf("Shell Sort\n");
        start = clock();
        shellSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 5:
        printf("Merge Sort\n");
        start = clock();
        mergeSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 6:
        printf("Heap Sort\n");
        start = clock();
        heapSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 7:
        printf("Quick Sort\n");
        start = clock();
        quickSort(logArray, 0, n-1, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 8:
        printf("Comb Sort\n");
        start = clock();
        combSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 9:
        printf("Cocktail Shaker Sort\n");
        start = clock();
        cocktailShakerSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    case 10:
        printf("Bingo Sort\n");
        start = clock();
        bingoSort(logArray, n, &numComparacoes, &numTrocas, ordem);
        end = clock();
        break;
    default:
        printf("Algoritmo nao encontrado.\n");
        return 1;
        break;
    }
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // imprimindo registros de log ordenados ate 20
    printf("Registros de log ordenados:\n");
    for(i = 0; i < n; i++){
        printf("%d/%d/%d %d:%d:%d - Processo %d\n", logArray[i]->day, logArray[i]->month, logArray[i]->year, 
        logArray[i]->hour, logArray[i]->minute, logArray[i]->second, logArray[i]->process_id);
        if(i > 20){
           break;
        }
    }

    printf("Tempo de execucao: %lf segundos\n", cpu_time);
    printf("Numero de comparacoes: %lu\n", numComparacoes);
    printf("Numero de trocas: %lu\n", numTrocas);
    

    // liberando memoria alocada para os registros de log
    for(i = 0; i < n; i++){
        free(logArray[i]);
    }

    return 0;
}
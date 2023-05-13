#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

// Funcao para gerar um registro de log
LogRecord* generateLogRecord(){
    // Aloca um registros de log
    LogRecord *logRecordUnit = malloc(sizeof(LogRecord));
    if (logRecordUnit == NULL){
        perror("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }
    // Gera uma data aleatoria no intervalo de 2010 a 2022
    logRecordUnit->year = rand() % 13 + 2010;
    logRecordUnit->month = rand() % 12 + 1;
    logRecordUnit->day = rand() % 31 + 1;
    // Gera um horario aleatorio no intervalo de 00:00:00 a 23:59:59
    logRecordUnit->hour = rand() % 24;
    logRecordUnit->minute = rand() % 60;
    logRecordUnit->second = rand() % 60;
    // Gera um id de processo aleatorio
    logRecordUnit->process_id = rand() % 100;
    return logRecordUnit;
}
void printRegistros(LogRecord* logArray[], int n){
    int i;
    // imprimindo registros de log ordenados
    printf("Registros de log ordenados:\n");
    while(i < 100 && i < n){
        printf("%d/%d/%d %d:%d:%d - Processo %d\n", logArray[i]->day, logArray[i]->month, logArray[i]->year, 
        logArray[i]->hour, logArray[i]->minute, logArray[i]->second, logArray[i]->process_id);
        i++;
   }
}
void userinput(int *escolha, int *n, int *ordem){
    printf("Escolha um algoritmo de ordenacao:\n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insertion Sort\n");
    printf("3 - Selection Sort\n");
    printf("4 - Shell Sort\n");
    printf("5 - Merge Sort\n");
    printf("6 - Heap Sort\n");
    printf("7 - Quick Sort\n");
    printf("8 - Comb Sort\n");
    printf("9 - Cocktail Shaker Sort\n");
    printf("10 - Bingo Sort\n");
    scanf("%d", escolha);
    printf("Digite o numero de registros de log:\n");
    scanf("%d", n);
    printf("Digite a ordem dos registros:\n");
    printf("0 - Decrescente\n");
    printf("1 - Crescente\n");
    printf("2 - Aleatoria\n");
    scanf("%d", ordem);
}
int main(){
    int escolha; // escolha um algoritmo
    int n; // numero de registros de log
    int ordem; // 0 para ordem decrescente e 1 para ordem crescente
    clock_t start, end; // medir tempo de execucao
    double cpu_time; // tempo de execucao
    long int numComparacoes = 0; // numero de comparacoes
    long int numTrocas = 0; // numero de trocas

    userinput(&escolha, &n, &ordem);

    LogRecord* logArray[n];
    // gerando registros de log aleatorios
    for(int i = 0; i < n; i++){
        logArray[i] = generateLogRecord(); // gera um registro de log aleatorio
    }

    if(ordem < 2){
        quickSort(logArray, 0, n-1, &numComparacoes, &numTrocas, ordem); // organiza o registro
        numComparacoes = 0;
        numTrocas = 0;
    }
    ordem = 1; // crescente

    switch (escolha){
    case 1:
        printf("Bubble Sort\n");
        start = clock();
        bubbleSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 2:
        printf("Insertion Sort\n");
        start = clock();
        insertionSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 3:
        printf("Selection Sort\n");
        start = clock();
        selectionSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 4:
        printf("Shell Sort\n");
        start = clock();
        shellSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 5:
        printf("Merge Sort\n");
        start = clock();
        mergeSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 6:
        printf("Heap Sort\n");
        start = clock();
        heapSort(logArray, n, &numComparacoes, &numTrocas);
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
        combSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 9:
        printf("Cocktail Shaker Sort\n");
        start = clock();
        cocktailShakerSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    case 10:
        printf("Bingo Sort\n");
        start = clock();
        bingoSort(logArray, n, &numComparacoes, &numTrocas);
        end = clock();
        break;
    default:
        printf("Algoritmo nao encontrado.\n");
        return 1;
        break;
    }
    cpu_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    //printRegistros(logArray, n);
    printf("Tempo de execucao: %lf segundos\n", cpu_time);
    printf("Numero de comparacoes: %lu\n", numComparacoes);
    printf("Numero de trocas: %lu\n", numTrocas);

    // liberando memoria alocada para os registros de log
    for(int i = 0; i < n; i++){
        free(logArray[i]);
    }
    return 0;
}
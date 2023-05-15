#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

// Funcao para gerar um registro de log
LogRecord* generateLogRecord(){
    // Aloca um registros de log
    LogRecord *logRecordUnit = malloc(sizeof(LogRecord));
    if (logRecordUnit == NULL){
        printf("Erro ao alocar memoria");
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
void printRegistros(LogRecord* logArray[], long int n){
    int i;
    // imprimindo registros de log ordenados
    printf("Registros de log ordenados:\n");
    while(i < 100 && i < n){
        printf("%d/%d/%d %d:%d:%d - Processo %d\n", logArray[i]->day, logArray[i]->month, logArray[i]->year, 
        logArray[i]->hour, logArray[i]->minute, logArray[i]->second, logArray[i]->process_id);
        i++;
   }
}
void userinput(int *escolha, long int *n, int *ordem){
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
    if(*ordem < 0 || *ordem > 2){
        printf("Ordem invalida\n");
        exit(EXIT_FAILURE);
    }
}

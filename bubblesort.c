#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void bubbleSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas) {
    int i, j;
    LogRecord* aux;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            ++(*numComparacoes);
            if((logArray[j]->process_id > logArray[j+1]->process_id) ||
            ((logArray[j]->process_id == logArray[j+1]->process_id) &&
            ((logArray[j]->year > logArray[j+1]->year) ||
            ((logArray[j]->year == logArray[j+1]->year) &&
            ((logArray[j]->month > logArray[j+1]->month) ||
            ((logArray[j]->month == logArray[j+1]->month) &&
            ((logArray[j]->day > logArray[j+1]->day) ||
            ((logArray[j]->day == logArray[j+1]->day) &&
            ((logArray[j]->hour > logArray[j+1]->hour) ||
            ((logArray[j]->hour == logArray[j+1]->hour) &&
            (logArray[j]->minute > logArray[j+1]->minute))))))))))){
                aux = logArray[j]; // troca
                logArray[j] = logArray[j+1];
                logArray[j+1] = aux;
                ++(*numTrocas);
            }
        if(*numTrocas == 0) break; // vetor ordenado
        }
    }
}
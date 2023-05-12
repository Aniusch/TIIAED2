#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void selectionSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas){
    int i, j, min_idx;
    LogRecord* temp;
    for(i = 0; i < n-1; i++){
        min_idx = i;
        for(j = i+1; j < n; j++, ++(*numComparacoes)){
            if((logArray[j]->process_id < logArray[min_idx]->process_id) ||
               (logArray[j]->process_id == logArray[min_idx]->process_id &&
                logArray[j]->year < logArray[min_idx]->year) ||
               (logArray[j]->process_id == logArray[min_idx]->process_id &&
                logArray[j]->year == logArray[min_idx]->year &&
                logArray[j]->month < logArray[min_idx]->month) ||
               (logArray[j]->process_id == logArray[min_idx]->process_id &&
                logArray[j]->year == logArray[min_idx]->year &&
                logArray[j]->month == logArray[min_idx]->month &&
                logArray[j]->day < logArray[min_idx]->day) ||
               (logArray[j]->process_id == logArray[min_idx]->process_id &&
                logArray[j]->year == logArray[min_idx]->year &&
                logArray[j]->month == logArray[min_idx]->month &&
                logArray[j]->day == logArray[min_idx]->day &&
                logArray[j]->hour < logArray[min_idx]->hour) ||
               (logArray[j]->process_id == logArray[min_idx]->process_id &&
                logArray[j]->year == logArray[min_idx]->year &&
                logArray[j]->month == logArray[min_idx]->month &&
                logArray[j]->day == logArray[min_idx]->day &&
                logArray[j]->hour == logArray[min_idx]->hour &&
                logArray[j]->minute < logArray[min_idx]->minute) ||
               (logArray[j]->process_id == logArray[min_idx]->process_id &&
                logArray[j]->year == logArray[min_idx]->year &&
                logArray[j]->month == logArray[min_idx]->month &&
                logArray[j]->day == logArray[min_idx]->day &&
                logArray[j]->hour == logArray[min_idx]->hour &&
                logArray[j]->minute == logArray[min_idx]->minute &&
                logArray[j]->second < logArray[min_idx]->second)){
                min_idx = j; // atualiza o índice do menor elemento
            }
        }
        temp = logArray[i];
        logArray[i] = logArray[min_idx];
        logArray[min_idx] = temp;
        ++(*numTrocas);
    }
}

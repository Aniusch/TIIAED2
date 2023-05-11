#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void quickSort(LogRecord* logArray[], int left, int right, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending) {
    int i, j;
    LogRecord* pivot; // pivo
    i = left;
    j = right;
    pivot = logArray[(left + right) / 2];
    while (i <= j) {
        if (ascending) {
            while ((logArray[i]->process_id < pivot->process_id) ||
                    (logArray[i]->process_id == pivot->process_id) && 
                    ((logArray[i]->year < pivot->year) ||
                    (logArray[i]->year == pivot->year) && 
                    ((logArray[i]->month < pivot->month) ||
                    (logArray[i]->month == pivot->month) && 
                    ((logArray[i]->day < pivot->day) ||
                    (logArray[i]->day == pivot->day) && 
                    ((logArray[i]->hour < pivot->hour) ||
                    (logArray[i]->hour == pivot->hour) && 
                    ((logArray[i]->minute < pivot->minute) ||
                    (logArray[i]->minute == pivot->minute) && 
                    (logArray[i]->second < pivot->second))))))) {
                ++(*numComparacoes);
                i++;
            }
            while ((logArray[j]->process_id > pivot->process_id) ||
                    (logArray[j]->process_id == pivot->process_id) && 
                    ((logArray[j]->year > pivot->year) ||
                    (logArray[j]->year == pivot->year) && 
                    ((logArray[j]->month > pivot->month) ||
                    (logArray[j]->month == pivot->month) && 
                    ((logArray[j]->day > pivot->day) ||
                    (logArray[j]->day == pivot->day) && 
                    ((logArray[j]->hour > pivot->hour) ||
                    (logArray[j]->hour == pivot->hour) && 
                    ((logArray[j]->minute > pivot->minute) ||
                    (logArray[j]->minute == pivot->minute) && 
                    (logArray[j]->second > pivot->second))))))) {
                ++(*numComparacoes);
                j--;
            }
        } else { // descending
            while ((logArray[i]->process_id > pivot->process_id) ||
                    (logArray[i]->process_id == pivot->process_id) && 
                    ((logArray[i]->year > pivot->year) ||
                    (logArray[i]->year == pivot->year) && 
                    ((logArray[i]->month > pivot->month) ||
                    (logArray[i]->month == pivot->month) && 
                    ((logArray[i]->day > pivot->day) ||
                    (logArray[i]->day == pivot->day) && 
                    ((logArray[i]->hour > pivot->hour) ||
                    (logArray[i]->hour == pivot->hour) && 
                    ((logArray[i]->minute > pivot->minute) ||
                    (logArray[i]->minute == pivot->minute) && 
                    (logArray[i]->second > pivot->second))))))) {
                ++(*numComparacoes);
                i++;
            }
            while ((logArray[j]->process_id < pivot->process_id) ||
                    (logArray[j]->process_id == pivot->process_id) && 
                    ((logArray[j]->year < pivot->year) ||
                    (logArray[j]->year == pivot->year) && 
                    ((logArray[j]->month < pivot->month) ||
                    (logArray[j]->month == pivot->month) && 
                    ((logArray[j]->day < pivot->day) ||
                    (logArray[j]->day == pivot->day) && 
                    ((logArray[j]->hour < pivot->hour) ||
                    (logArray[j]->hour == pivot->hour) && 
                    ((logArray[j]->minute < pivot->minute) ||
                    (logArray[j]->minute == pivot->minute) &&
                    (logArray[j]->second < pivot->second))))))) {
                ++(*numComparacoes);
                j--;
            }
        }
        if (i <= j) { // troca
            LogRecord* temp = logArray[i];
            logArray[i] = logArray[j];
            logArray[j] = temp;
            ++(*numTrocas);
            i++;
            j--;
        }
    }
    if (left < j) { // recursao ate os elementos da esquerda estarem ordenados
        quickSort(logArray, left, j, numComparacoes, numTrocas, ascending);
    }
    if (i < right) { // recursao ate os elementos da direita estarem ordenados
        quickSort(logArray, i, right, numComparacoes, numTrocas, ascending);
    }
}

#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void insertionSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){
    int i, j;
    LogRecord* key; // chave do Insertion Sort
    for(i = 1; i < n; i++){
        key = logArray[i];
        j = i-1;
        if(ascending == 1) {
            while(++(*numComparacoes) && j >= 0 && ((logArray[j]->process_id > key->process_id) ||
                ((logArray[j]->process_id == key->process_id) &&
                ((logArray[j]->year > key->year) ||
                ((logArray[j]->year == key->year) &&
                ((logArray[j]->month > key->month) ||
                ((logArray[j]->month == key->month) &&
                ((logArray[j]->day > key->day) ||
                ((logArray[j]->day == key->day) &&
                ((logArray[j]->hour > key->hour) ||
                ((logArray[j]->hour == key->hour) &&
                (logArray[j]->minute > key->minute)))))))))))){
                    logArray[j+1] = logArray[j];
                    j = j-1;
            }
        }
        else if(ascending == 0) {
            
            while(++(*numComparacoes) && j >= 0 && ((logArray[j]->process_id < key->process_id) ||
                ((logArray[j]->process_id == key->process_id) &&
                ((logArray[j]->year < key->year) ||
                ((logArray[j]->year == key->year) &&
                ((logArray[j]->month < key->month) ||
                ((logArray[j]->month == key->month) &&
                ((logArray[j]->day < key->day) ||
                ((logArray[j]->day == key->day) &&
                ((logArray[j]->hour < key->hour) ||
                ((logArray[j]->hour == key->hour) &&
                (logArray[j]->minute < key->minute)))))))))))){
                    logArray[j+1] = logArray[j];
                    j = j-1;
            }
        }
        logArray[j+1] = key;
        ++(*numTrocas);
    }
}
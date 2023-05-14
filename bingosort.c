#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void bingoSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas){
    int sorted = 0; // variavel que indica se o array esta ordenado
    LogRecord* temp;
    while(!sorted){ 
        sorted = 1; 
        for(int i = 0; i < n-1; i++, ++(*numComparacoes)) {
            int should_swap = (logArray[i]->process_id > logArray[i+1]->process_id) || 
                (logArray[i]->process_id == logArray[i+1]->process_id &&
                logArray[i]->year > logArray[i+1]->year) ||
                (logArray[i]->process_id == logArray[i+1]->process_id &&
                logArray[i]->year == logArray[i+1]->year &&
                logArray[i]->month > logArray[i+1]->month) ||
                (logArray[i]->process_id == logArray[i+1]->process_id &&
                logArray[i]->year == logArray[i+1]->year &&
                logArray[i]->month == logArray[i+1]->month &&
                logArray[i]->day > logArray[i+1]->day) ||
                (logArray[i]->process_id == logArray[i+1]->process_id &&
                logArray[i]->year == logArray[i+1]->year &&
                logArray[i]->month == logArray[i+1]->month &&
                logArray[i]->day == logArray[i+1]->day &&
                logArray[i]->hour > logArray[i+1]->hour) ||
                (logArray[i]->process_id == logArray[i+1]->process_id &&
                logArray[i]->year == logArray[i+1]->year &&
                logArray[i]->month == logArray[i+1]->month &&
                logArray[i]->day == logArray[i+1]->day &&
                logArray[i]->hour == logArray[i+1]->hour &&
                logArray[i]->minute > logArray[i+1]->minute) ||
                (logArray[i]->process_id == logArray[i+1]->process_id &&
                logArray[i]->year == logArray[i+1]->year &&
                logArray[i]->month == logArray[i+1]->month &&
                logArray[i]->day == logArray[i+1]->day &&
                logArray[i]->hour == logArray[i+1]->hour &&
                logArray[i]->minute == logArray[i+1]->minute &&
                logArray[i]->second > logArray[i+1]->second);
            if(should_swap){  // se o array nao esta ordenado
                temp = logArray[i];
                logArray[i] = logArray[i+1];
                logArray[i+1] = temp;
                ++(*numTrocas);
                sorted = 0; 
            }
        }
    }
}
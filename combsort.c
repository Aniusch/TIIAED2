#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void combSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas){
    int gap = n;
    float shrink = 1.3;
    int sorted = 0;
    LogRecord* temp;
    while(!sorted){
        gap = gap / shrink;
        if(gap <= 1){
            gap = 1;
            sorted = 1;
        }
        int i = 0;
        while(i + gap < n){
            int should_swap = 0; 
            should_swap = (logArray[i]->process_id > logArray[i+gap]->process_id) ||
                (logArray[i]->process_id == logArray[i+gap]->process_id &&
                logArray[i]->year > logArray[i+gap]->year) ||
                (logArray[i]->process_id == logArray[i+gap]->process_id &&
                logArray[i]->year == logArray[i+gap]->year &&
                logArray[i]->month > logArray[i+gap]->month) ||
                (logArray[i]->process_id == logArray[i+gap]->process_id &&
                logArray[i]->year == logArray[i+gap]->year &&
                logArray[i]->month == logArray[i+gap]->month &&
                logArray[i]->day > logArray[i+gap]->day) ||
                (logArray[i]->process_id == logArray[i+gap]->process_id &&
                logArray[i]->year == logArray[i+gap]->year &&
                logArray[i]->month == logArray[i+gap]->month &&
                logArray[i]->day == logArray[i+gap]->day &&
                logArray[i]->hour > logArray[i+gap]->hour) ||
                (logArray[i]->process_id == logArray[i+gap]->process_id &&
                logArray[i]->year == logArray[i+gap]->year &&
                logArray[i]->month == logArray[i+gap]->month &&
                logArray[i]->day == logArray[i+gap]->day &&
                logArray[i]->hour == logArray[i+gap]->hour &&
                logArray[i]->minute > logArray[i+gap]->minute) ||
                (logArray[i]->process_id == logArray[i+gap]->process_id &&
                logArray[i]->year == logArray[i+gap]->year &&
                logArray[i]->month == logArray[i+gap]->month &&
                logArray[i]->day == logArray[i+gap]->day &&
                logArray[i]->hour == logArray[i+gap]->hour &&
                logArray[i]->minute == logArray[i+gap]->minute &&
                logArray[i]->second > logArray[i+gap]->second);
            ++(*numComparacoes);
            if(should_swap){ // se o elemento da esquerda for maior que o da direita, troca
                temp = logArray[i];
                logArray[i] = logArray[i+gap];
                logArray[i+gap] = temp;
                ++(*numTrocas);
                sorted = 0;
            }
            i++;
        }
    }
}

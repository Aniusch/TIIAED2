#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void shellSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas){
    int i, j, h;
    LogRecord* temp;
    // Definindo a sequência de lacunas
    for (h = n/2; h > 0; h /= 2){
        for(i = h; i < n; i++){
            temp = logArray[i];
            for(j = i; j >= h && (
                    ((  logArray[j-h]->process_id > temp->process_id || 
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year > temp->year) || 
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month > temp->month) ||
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day > temp->day) ||
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour > temp->hour) ||
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour == temp->hour && logArray[j-h]->minute > temp->minute) ||
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour == temp->hour && logArray[j-h]->minute == temp->minute && logArray[j-h]->second > temp->second))
                    )
                ); j -= h, ++(*numComparacoes)){
                logArray[j] = logArray[j-h];
            }
            logArray[j] = temp;
            ++(*numTrocas);
        }
    }
}
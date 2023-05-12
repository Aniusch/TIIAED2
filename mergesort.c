#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void mergeSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas){
    if (n > 1) {
        int mid = n / 2;
        LogRecord* left[mid];
        LogRecord* right[n - mid];
        int i, j, k; 
        for (i = 0; i < mid; i++) {
            left[i] = logArray[i];
        }
        for (j = 0; j < n - mid; j++) {
            right[j] = logArray[mid + j];
        }
        mergeSort(left, mid, numComparacoes, numTrocas); // ordena a primeira metade
        mergeSort(right, n - mid, numComparacoes, numTrocas); // ordena a segunda metade
        i = 0; 
        j = 0;
        k = 0;
        while (i < mid && j < n - mid) { 
            ++(*numComparacoes);
            if ((left[i]->process_id < right[j]->process_id ||
                (left[i]->process_id == right[j]->process_id && (
                    left[i]->year < right[j]->year ||
                    (left[i]->year == right[j]->year && (
                        left[i]->month < right[j]->month ||
                        (left[i]->month == right[j]->month && (
                            left[i]->day < right[j]->day ||
                            (left[i]->day == right[j]->day && (
                                left[i]->hour < right[j]->hour ||
                                (left[i]->hour == right[j]->hour && (
                                    left[i]->minute < right[j]->minute ||
                                    (left[i]->minute == right[j]->minute &&
                                        left[i]->second < right[j]->second
                                    )
                                ))
                            ))
                        ))
                    ))
                ))
            ))
            {
                logArray[k] = left[i]; 
                i++;
            } else {
                logArray[k] = right[j];
                j++;
            }
            k++;
            ++(*numTrocas);
        }
        while (i < mid) { // se sobrou elementos na primeira metade
            logArray[k] = left[i];
            i++;
            k++;
            ++(*numTrocas);
        }
        while (j < n - mid) { // se sobrou elementos na segunda metade
            logArray[k] = right[j];
            j++;
            k++;
            ++(*numTrocas);
        }
    }
}
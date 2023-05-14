#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void mergeSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas){
    if (n <= 1) {
        return;
    }

    LogRecord** aux = (LogRecord**)malloc(n * sizeof(LogRecord*));
    if (aux == NULL) {
        // se falhar em alocar memoria, quita o programa
        return;
    }

    int width;
    for (width = 1; width < n; width *= 2) {
        int i;
        for (i = 0; i < n; i += 2 * width) {
            int left = i;
            int mid = i + width;
            int right = i + 2 * width;

            if (mid > n) {
                mid = n;
            }
            if (right > n) {
                right = n;
            }

            merge(logArray, aux, left, mid, right, numComparacoes, numTrocas);
        }

        // copia o array auxiliar para o array original
        for (i = 0; i < n; i++) {
            logArray[i] = aux[i];
        }
    }

    free(aux);
}

void merge(LogRecord* logArray[], LogRecord* aux[], int left, int mid, int right, unsigned long *numComparacoes, unsigned long *numTrocas){
    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right) {
        ++(*numComparacoes);
        if ((logArray[i]->process_id < logArray[j]->process_id) ||
            (logArray[i]->process_id == logArray[j]->process_id && (
                logArray[i]->year < logArray[j]->year ||
                (logArray[i]->year == logArray[j]->year && (
                    logArray[i]->month < logArray[j]->month ||
                    (logArray[i]->month == logArray[j]->month && (
                        logArray[i]->day < logArray[j]->day ||
                        (logArray[i]->day == logArray[j]->day && (
                            logArray[i]->hour < logArray[j]->hour ||
                            (logArray[i]->hour == logArray[j]->hour && (
                                logArray[i]->minute < logArray[j]->minute ||
                                (logArray[i]->minute == logArray[j]->minute &&
                                    logArray[i]->second < logArray[j]->second
                                )
                            ))
                        ))
                    ))
                ))
            ))
        ) {
            aux[k] = logArray[i];
            i++;
        } else {
            aux[k] = logArray[j];
            j++;
        }
        k++;
        ++(*numTrocas);
    }

    // copia o resto dos elementos da primeira metade, se houver
    while (i < mid) {
        aux[k] = logArray[i];
        i++;
        k++;
        ++(*numTrocas);
    }

    // Copia os elementos da segunda metade, se houver
    while (j < right) {
        aux[k] = logArray[j];
        j++;
        k++;
        ++(*numTrocas);
    }
}


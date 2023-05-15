#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void cocktailShakerSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas) {
    int comeco = 0, fim = n - 1;
    int troca = 1;
    LogRecord* aux;

    while (troca){
        troca = 0;
        // percorre do inicio ao fim 
        for (int j = comeco; j < fim; j++, ++(*numComparacoes)) {
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
                (logArray[j]->minute > logArray[j+1]->minute))))))))))) {
                aux = logArray[j]; // troca
                logArray[j] = logArray[j+1];
                logArray[j+1] = aux;
                troca = 1;  // Define trocas como 1 se ocorrer uma troca
                ++(*numTrocas);  // Conta cada troca realizada
            }
        }

        if (!troca) {
            break; 
        }

        troca = 0;
        fim--;

        // percorre do fim ao inicio
        for (int i = fim - 1; i >= comeco; i--, ++(*numComparacoes)) {
            ++(*numComparacoes);
            if((logArray[i]->process_id > logArray[i+1]->process_id) ||
                ((logArray[i]->process_id == logArray[i+1]->process_id) &&
                ((logArray[i]->year > logArray[i+1]->year) ||
                ((logArray[i]->year == logArray[i+1]->year) &&
                ((logArray[i]->month > logArray[i+1]->month) ||
                ((logArray[i]->month == logArray[i+1]->month) &&
                ((logArray[i]->day > logArray[i+1]->day) ||
                ((logArray[i]->day == logArray[i+1]->day) &&
                ((logArray[i]->hour > logArray[i+1]->hour) ||
                ((logArray[i]->hour == logArray[i+1]->hour) &&
                (logArray[i]->minute > logArray[i+1]->minute))))))))))) {
                aux = logArray[i]; // troca
                logArray[i] = logArray[i+1];
                logArray[i+1] = aux;
                troca = 1;  // Define trocas como 1 se ocorrer uma troca
                ++(*numTrocas);  // Conta cada troca realizada
            }
        }
        comeco++;
    }
}
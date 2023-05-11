#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

void cocktailShakerSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){
    int comeco = 0, fim = n - 1;
    int troca = 1;
    LogRecord* temp;
    while(troca){
        troca = 0;
        // percorre do inicio ao fim
        for(int i = comeco; i < fim; i++, ++(*numComparacoes)){
            int cond = (logArray[i]->process_id > logArray[i+1]->process_id) ||
                (logArray[i]->process_id == logArray[i+1]->process_id) && 
                (logArray[i]->year > logArray[i+1]->year) ||
                (logArray[i]->year == logArray[i+1]->year) && 
                (logArray[i]->month > logArray[i+1]->month) ||
                (logArray[i]->month == logArray[i+1]->month) && 
                (logArray[i]->day > logArray[i+1]->day) ||
                (logArray[i]->day == logArray[i+1]->day) && 
                (logArray[i]->hour > logArray[i+1]->hour) ||
                (logArray[i]->hour == logArray[i+1]->hour) && 
                (logArray[i]->minute > logArray[i+1]->minute) ||
                (logArray[i]->minute == logArray[i+1]->minute) && 
                (logArray[i]->second > logArray[i+1]->second);
            if((ascending && cond) || (!ascending && !cond)){
                temp = logArray[i];
                logArray[i] = logArray[i+1];
                logArray[i+1] = temp;
                ++(*numTrocas);
                troca = 1;
            }
        }
        if(!troca){
            break; // se nao houve troca, o array esta ordenado
        } 
        troca = 0;
        fim--; // desloca o final do array um indice para a esquerda
        // percorre do fim ao inicio
        for(int i = fim-1; i >= comeco; i--, ++(*numComparacoes)){
            int cond = (logArray[i]->process_id > logArray[i+1]->process_id) ||
                (logArray[i]->process_id == logArray[i+1]->process_id) && 
                (logArray[i]->year > logArray[i+1]->year) ||
                (logArray[i]->year == logArray[i+1]->year) && 
                (logArray[i]->month > logArray[i+1]->month) ||
                (logArray[i]->month == logArray[i+1]->month) && 
                (logArray[i]->day > logArray[i+1]->day) ||
                (logArray[i]->day == logArray[i+1]->day) && 
                (logArray[i]->hour > logArray[i+1]->hour) ||
                (logArray[i]->hour == logArray[i+1]->hour) && 
                (logArray[i]->minute > logArray[i+1]->minute) ||
                (logArray[i]->minute == logArray[i+1]->minute) && 
                (logArray[i]->second > logArray[i+1]->second);
            if((ascending && cond) || (!ascending && !cond)){
                temp = logArray[i];
                logArray[i] = logArray[i+1];
                logArray[i+1] = temp;
                ++(*numTrocas);
                troca = 1;
            }
        }
        comeco++; // desloca o inicio do array um indice para
    }
}
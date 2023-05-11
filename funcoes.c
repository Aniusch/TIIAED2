#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>

// Funcao para gerar um registro de log
LogRecord* generateLogRecord(){
    // Aloca um registros de log
    LogRecord *logRecordUnit = malloc(sizeof(LogRecord));
    if (logRecordUnit == NULL){
        perror("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }
    // Gera uma data aleatoria no intervalo de 2010 a 2022
    logRecordUnit->year = rand() % 13 + 2010;
    logRecordUnit->month = rand() % 12 + 1;
    logRecordUnit->day = rand() % 31 + 1;
    // Gera um horario aleatorio no intervalo de 00:00:00 a 23:59:59
    logRecordUnit->hour = rand() % 24;
    logRecordUnit->minute = rand() % 60;
    logRecordUnit->second = rand() % 60;
    // Gera um id de processo aleatorio
    logRecordUnit->process_id = rand() % 100;
    return logRecordUnit;
}
void bubbleSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending) {
    int i, j;
    LogRecord* aux;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if (ascending == 1) { // 1 = crescente
                ++(*numComparacoes);
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
                (logArray[j]->minute > logArray[j+1]->minute))))))))))){
                    aux = logArray[j]; // troca
                    logArray[j] = logArray[j+1];
                    logArray[j+1] = aux;
                    ++(*numTrocas);
                }
            }
            else if (ascending == 0) { // 0 = decrescente
                ++(*numComparacoes);
                if((logArray[j]->process_id < logArray[j+1]->process_id) ||
                ((logArray[j]->process_id == logArray[j+1]->process_id) &&
                ((logArray[j]->year < logArray[j+1]->year) ||
                ((logArray[j]->year == logArray[j+1]->year) &&
                ((logArray[j]->month < logArray[j+1]->month) ||
                ((logArray[j]->month == logArray[j+1]->month) &&
                ((logArray[j]->day < logArray[j+1]->day) ||
                ((logArray[j]->day == logArray[j+1]->day) &&
                ((logArray[j]->hour < logArray[j+1]->hour) ||
                ((logArray[j]->hour == logArray[j+1]->hour) &&
                (logArray[j]->minute < logArray[j+1]->minute))))))))))){
                    aux = logArray[j];
                    logArray[j] = logArray[j+1];
                    logArray[j+1] = aux;
                    ++(*numTrocas);
                }
            }
        }
    }
}
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

void selectionSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){
    int i, j, min_idx;
    LogRecord* temp;
    for(i = 0; i < n-1; i++){
        min_idx = i;
        for(j = i+1; j < n; j++, ++(*numComparacoes)){
            if((ascending && logArray[j]->process_id < logArray[min_idx]->process_id) ||
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
                logArray[j]->second < logArray[min_idx]->second) ||
               (!ascending && logArray[j]->process_id > logArray[min_idx]->process_id)){
                min_idx = j; // atualiza o índice do menor elemento
            }
        }
        temp = logArray[i];
        logArray[i] = logArray[min_idx];
        logArray[min_idx] = temp;
        ++(*numTrocas);
    }
}

void shellSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){
    int i, j, h;
    LogRecord* temp;
    
    // Definindo a sequência de lacunas
    for (h = n/2; h > 0; h /= 2){
        for(i = h; i < n; i++){
            temp = logArray[i];
            
            for(j = i; j >= h && (
                    (ascending && (
                        logArray[j-h]->process_id > temp->process_id || 
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year > temp->year) || 
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month > temp->month) ||
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day > temp->day) ||
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour > temp->hour) ||
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour == temp->hour && logArray[j-h]->minute > temp->minute) ||
                        (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour == temp->hour && logArray[j-h]->minute == temp->minute && logArray[j-h]->second > temp->second))
                    ) || (ascending == 0 && (
    logArray[j-h]->process_id < temp->process_id || 
    (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year < temp->year) || 
    (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month < temp->month) ||
    (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day < temp->day) ||
    (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour < temp->hour) ||
    (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour == temp->hour && logArray[j-h]->minute < temp->minute) ||
    (logArray[j-h]->process_id == temp->process_id && logArray[j-h]->year == temp->year && logArray[j-h]->month == temp->month && logArray[j-h]->day == temp->day && logArray[j-h]->hour == temp->hour && logArray[j-h]->minute == temp->minute && logArray[j-h]->second < temp->second)))
                ); j -= h, ++(*numComparacoes)){
                logArray[j] = logArray[j-h];
            }
            logArray[j] = temp;
            ++(*numTrocas);
        }
    }
}

void mergeSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){
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
        mergeSort(left, mid, numComparacoes, numTrocas, ascending); // ordena a primeira metade
        mergeSort(right, n - mid, numComparacoes, numTrocas, ascending); // ordena a segunda metade
        i = 0; 
        j = 0;
        k = 0;
        while (i < mid && j < n - mid) { 
            ++(*numComparacoes);
            if ((ascending && (left[i]->process_id < right[j]->process_id ||
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
            )) || (!ascending && (left[i]->process_id > right[j]->process_id ||
                (left[i]->process_id == right[j]->process_id && (
                    left[i]->year > right[j]->year ||
                    (left[i]->year == right[j]->year && (
                        left[i]->month > right[j]->month ||
                        (left[i]->month == right[j]->month && (
                            left[i]->day > right[j]->day ||
                            (left[i]->day == right[j]->day && (
                                left[i]->hour > right[j]->hour ||
                                (left[i]->hour == right[j]->hour && (
                                    left[i]->minute > right[j]->minute ||
                                    (left[i]->minute == right[j]->minute &&
                                        left[i]->second > right[j]->second
                                    )
                                ))
                            ))
                        ))
                    ))
                ))
            ))) {
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
void heapify(LogRecord* arr[], int n, int i, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){ 
    int largest = i; // inicializa o maior como raiz
    int l = 2 * i + 1; // elemento da esquerda
    int r = 2 * i + 2; // elemento da direita
    LogRecord* temp;
    if (ascending) {
        if (l < n) {
            (*numComparacoes)++;
            if (arr[l]->process_id > arr[largest]->process_id) {
                largest = l;
            }
        }
        if (r < n) {
            (*numComparacoes)++;
            if (arr[r]->process_id > arr[largest]->process_id) {
                largest = r;
            }
        }
    } else {
        if (l < n) {
            (*numComparacoes)++;
            if (arr[l]->process_id < arr[largest]->process_id) {
                largest = l;
            }
        }
        if (r < n) {
            (*numComparacoes)++;
            if (arr[r]->process_id < arr[largest]->process_id) {
                largest = r;
            }
        }
    }
    if (largest != i) {
        (*numTrocas)++;
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, numComparacoes, numTrocas, ascending);
    }
}
void heapSort(LogRecord* arr[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending) {
    LogRecord* temp;
    // Construindo o heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, numComparacoes, numTrocas, ascending);
    }
    // Extraindo elementos do heap
    for (int i = n - 1; i >= 0; i--) {
        (*numTrocas)++;
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, numComparacoes, numTrocas, ascending);
    }
}
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
void combSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){
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
            if (ascending) {
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
            } else {
                should_swap = (logArray[i]->process_id < logArray[i+gap]->process_id) ||
                    (logArray[i]->process_id == logArray[i+gap]->process_id &&
                    logArray[i]->year < logArray[i+gap]->year) ||
                    (logArray[i]->process_id == logArray[i+gap]->process_id &&
                    logArray[i]->year == logArray[i+gap]->year &&
                    logArray[i]->month < logArray[i+gap]->month) ||
                    (logArray[i]->process_id == logArray[i+gap]->process_id &&
                    logArray[i]->year == logArray[i+gap]->year &&
                    logArray[i]->month == logArray[i+gap]->month &&
                    logArray[i]->day < logArray[i+gap]->day) ||
                    (logArray[i]->process_id == logArray[i+gap]->process_id &&
                    logArray[i]->year == logArray[i+gap]->year &&
                    logArray[i]->month == logArray[i+gap]->month &&
                    logArray[i]->day == logArray[i+gap]->day &&
                    logArray[i]->hour < logArray[i+gap]->hour) ||
                    (logArray[i]->process_id == logArray[i+gap]->process_id &&
                    logArray[i]->year == logArray[i+gap]->year &&
                    logArray[i]->month == logArray[i+gap]->month &&
                    logArray[i]->day == logArray[i+gap]->day &&
                    logArray[i]->hour == logArray[i+gap]->hour &&
                    logArray[i]->minute < logArray[i+gap]->minute) ||
                    (logArray[i]->process_id == logArray[i+gap]->process_id &&
                    logArray[i]->year == logArray[i+gap]->year &&
                    logArray[i]->month == logArray[i+gap]->month &&
                    logArray[i]->day == logArray[i+gap]->day &&
                    logArray[i]->hour == logArray[i+gap]->hour &&
                    logArray[i]->minute == logArray[i+gap]->minute &&
                    logArray[i]->second < logArray[i+gap]->second);
            }
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
void bingoSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending){
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
            if((ascending && should_swap) || (!ascending && !should_swap)){  // se o array nao esta ordenado
                temp = logArray[i];
                logArray[i] = logArray[i+1];
                logArray[i+1] = temp;
                ++(*numTrocas);
                sorted = 0; 
            }
        }
    }
}


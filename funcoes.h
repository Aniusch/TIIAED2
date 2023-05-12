// funcoes.h
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int process_id; // id do processo
}LogRecord;

LogRecord* generateLogRecord();
void bubbleSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void insertionSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void selectionSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void shellSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void mergeSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void heapify(LogRecord* arr[], int n, int i, unsigned long *numComparacoes, unsigned long *numTrocas);
void heapSort(LogRecord* arr[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void quickSort(LogRecord* logArray[], int left, int right, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void combSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void cocktailShakerSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void bingoSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas);

#endif /* FUNCOES_H */

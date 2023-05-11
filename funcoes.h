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
void bubbleSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void insertionSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void selectionSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void shellSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void mergeSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void heapify(LogRecord* arr[], int n, int i, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void heapSort(LogRecord* arr[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void quickSort(LogRecord* logArray[], int left, int right, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void combSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void cocktailShakerSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void bingoSort(LogRecord* logArray[], int n, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);

#endif /* FUNCOES_H */

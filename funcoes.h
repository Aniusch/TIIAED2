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
void printRegistros(LogRecord* logArray[], long int n);
void userinput(int *escolha, long int *n, int *ordem);
void bubbleSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void insertionSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void selectionSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void shellSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void mergeSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void merge(LogRecord* logArray[], LogRecord* aux[], int left, int mid, int right, unsigned long *numComparacoes, unsigned long *numTrocas);
void heapify(LogRecord* arr[], long int n, long int i, unsigned long *numComparacoes, unsigned long *numTrocas);
void heapSort(LogRecord* arr[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void quickSort(LogRecord* logArray[], long int left, long int right, unsigned long *numComparacoes, unsigned long *numTrocas, int ascending);
void combSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void cocktailShakerSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);
void bingoSort(LogRecord* logArray[], long int n, unsigned long *numComparacoes, unsigned long *numTrocas);

#endif /* FUNCOES_H */

# Trabalho II AED2

O objetivo deste trabalho é realizar uma análise de desempenho de diversos algoritmos de ordenação em diferentes cenários, comparando-os em três métricas: número de comparações, número de trocas realizadas e tempo total gasto para ordenação considerando apenas o tempo de processamento. A análise é fundamental para determinar a eficiência de cada algoritmo de ordenação e identificar qual deles é mais adequado para cada cenário específico.

O cenário em questão é a organização dos registros de log de um programa específico em uma empresa. Um sistema gera uma grande quantidade de logs que são armazenados de forma desordenada. A tarefa é criar um sistema para organizá-los. Cada registro de log é composto por uma data e um número de identificação (ID) do processo que o gerou. Os registros de logs devem ser ordenados primeiro pelo ID do processo e, em seguida, pela data de registro. Além disso, é necessário avaliar o comportamento dos algoritmos ao lidar com registros de log totalmente aleatórios e também quando os registros já estão ordenados, primeiro em ordem crescente e, em seguida, em ordem decrescente. O tempo de processamento será medido na linguagem C usando o comando clock( ).

## Algoritmos de Ordenação

- (1) Bubble Sort;
- (2) Insertion Sort;
- (3) Selection Sort;
- (4) Shell Sort;
- (5) Merge Sort;
- (6) Heap Sort;
- (7) Quick Sort;
- (8) Comb Sort;
- (9) Cocktail Shaker Sort;
- (10) Bingo Sort.

## Compilação

gcc -o ordenacao main.c bubblesort.c insertionsort.c selectionsort.c shellsort.c mergesort.c heapsort.c quicksort.c combsort.c cocktailshaker.c bingosort.c suporte.c

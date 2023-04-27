//
// Created by k17 on 12.09.2021.
//

typedef long long (*sortFunc)(int *, int *, long long *);

void swap(int *a, int *b);
int testSort(int *array, int size);
void copyArray(int *src, int *dst, int size);

long long selectionSort(int *begin, int *end, long long *cmpCount);
long long bubbleSort(int *begin, int *end, long long *cmpCount);
long long insertionSort(int *begin, int *end, long long *cmpCount);
///быстрая сортировка элементов между begin и end. cmpCount будет увеличен на число сравнений, выполненных сортировкой.
///Значение под cmpCount не обнуляется и должно быть обнулено вручную перед вызовом функции, если не требуется иного
long long quickSort(int *begin, int *end, long long *cmpCount);
long long stoogeSort(int *begin, int *end, long long *cmpCount);

long long merge(int *begin, int *end, int *mid, long long *cmpCount);

long long mergeSort(int *begin, int *end, long long *cmpCount);
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "include/arrayFunctions.h"

void performSortTest(int *array, int size, sortFunc sortFunction) {
    long long cmpCount = 0;
    long long swpCount = 0;
    clock_t begin, diff;

    begin = clock();
    swpCount = sortFunction(array, array+size, &cmpCount);
    diff = clock() - begin;


    double timeSpent = ((double)(diff * 1000)) / CLOCKS_PER_SEC;
    int testResult = testSort(array, size);
    if(testResult > 0)
    {
        printf("Ошибка сортировки на элементе %d\n", testResult);
    }
    else
    {
        printf("%20lf | %20lld | %20lld |\n", timeSpent, swpCount, cmpCount);
    }
#ifdef DEBUG
    printf("Изменённый массив:\n");
    OutputIntArray(array, size);
#endif
}
int main() {
    int size = InputInt("Enter array size", 1, 100000000);
    int *arr = (int *) malloc(size * sizeof(int));
    int *copy = (int *) malloc(size * sizeof(int));



    for(int i = 0; i < 3; ++i) {
        srand(100 * i);
        printf("Проход № %d\n", i+1);
        printf("%15s | %19s | %20s | %20s |\n","name", "time", "swaps", "compares");
        GenerateIntArray(arr, size, 0, 10);
#ifdef DEBUG
        printf("Массив до сортировки:\n");
        OutputIntArray(arr, size);
#endif
        // ------- selection sort -------
        printf("%15s |", "Selection sort:");
        copyArray(arr, copy, size);
        performSortTest(copy, size, selectionSort);

        // ------- bubble sort -------
        printf("%15s |", "Bubble sort:");
        copyArray(arr, copy, size);
        performSortTest(copy, size, bubbleSort);

        // ------- insertion sort -------
        printf("%15s |", "Insertion sort:");
        copyArray(arr, copy, size);
        performSortTest(copy, size, insertionSort);

        // ------- quick sort -------
        printf("%15s |", "Quick sort:");
        copyArray(arr, copy, size);
        performSortTest(copy, size, quickSort);
        // ------- stooge sort -------
        printf("%15s |", "Stooge sort:");
        copyArray(arr, copy, size);
        performSortTest(copy, size, stoogeSort);
        // ------- merge sort -------
        printf("%15s |", "Merge sort:");
        copyArray(arr, copy, size);
        performSortTest(copy, size, mergeSort);
    }
    free(arr);
    free(copy);
    return 0;
}



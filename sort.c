//
// Created by k17 on 12.12.2021.
//
#include <malloc.h>
#include "sort.h"

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

long long selectionSort(int *begin, int *end, long long *cmpCount) {
    long size = end - begin;
    long long swpCount = 0;
    *cmpCount = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            (*cmpCount)++;
            if (begin[j] < begin[i]) {
                swap(&begin[i], &begin[j]);
                swpCount++;
            }
        }
    }
    return swpCount;
}

long long bubbleSort(int *begin, int *end, long long *cmpCount) {
    long long swpCount = 0;
    long size = end - begin;
    *cmpCount = 0;
    for (int i = 0; i < size; ++i) {
        int c = 0; // счётчик перестановок за одну итерацию верхнего цикла. Если будет равен 0 - массив отсортирован
        for (int j = 0; j < size - i - 1; ++j) {
            (*cmpCount)++;
            if (begin[j + 1] < begin[j]) {
                swap(begin + j + 1, begin + j);
                c++;
            }
        }
        if (c == 0) {
            break;
        }
        swpCount += c;
    }
    return swpCount;
}

long long insertionSort(int *begin, int *end, long long *cmpCount) {
    long size = end - begin;
    long long swpCount = 0;
    for (int i = 1; i < size; i++) {
        int l = 0, r = i - 1;
        int m;
        while (l <= r) {
            m = (r + l) / 2;
            (*cmpCount)++;
            if (begin[i] >= begin[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int el = begin[i];
        for (int j = i; j > l; j--) {
            begin[j] = begin[j - 1];
            swpCount++;
        }
        swpCount++;
        begin[l] = el;
    }
    return swpCount;
}


///быстрая сортировка элементов между begin и end. cmpCount будет увеличен на число сравнений, выполненных сортировкой.
///Значение под cmpCount не обнуляется и должно быть обнулено вручную перед вызовом функции, если не требуется иного
long long quickSort(int *begin, int *end, long long *cmpCount) {
    if (end - begin <= 1)
        return 0;
    if (end - begin == 2 && (*begin) == (*(end - 1)))
        return 0;

    long long swpCount = 0;

    int *mid = begin + ((end - begin) / 2);
    if ((*mid) < (*begin)) {
        swap(mid, begin);
        swpCount++;
        (*cmpCount)++;
    }
    if ((*mid) > (*(end - 1))) {
        swap(mid, end - 1);
        swpCount++;
        (*cmpCount)++;
    }
    if ((*mid) < (*begin)) {
        swap(mid, begin);
        swpCount++;
        (*cmpCount)++;
    }

    int p = *mid;
    int *r2 = begin, *l2 = end - 1;
    while (r2 < l2) {
        while ((*r2) < p && r2 < end) {
            r2++;
            (*cmpCount)++;
        }
        while ((*l2) >= p && l2 > begin) {
            l2--;
            (*cmpCount)++;
        }
        if (r2 < l2) {
            swpCount++;
            swap(l2, r2);
        }
    }
    if (r2 < end && r2 - begin > 0)
        swpCount += quickSort(begin, r2, cmpCount);
    if (l2 >= begin && end - l2 > 0)
        swpCount += quickSort(l2 + 1, end, cmpCount);
    return swpCount;
}

long long stoogeSort(int *begin, int *end, long long *cmpCount) {
    long long swpCount = 0;
    (*cmpCount)++;
    if (*(end - 1) < *begin) {
        swap(begin, end - 1);
        swpCount++;
    }
    if (end - begin > 2) {
        long t = (end - begin) / 3;
        swpCount += stoogeSort(begin, end - t, cmpCount);
        swpCount += stoogeSort(begin + t, end, cmpCount);
        swpCount += stoogeSort(begin, end - t, cmpCount);
    }
    return swpCount;
}


int testSort(int *array, int size) {
    for (int i = 1; i < size; ++i) {
        if (array[i - 1] > array[i]) return i;
    }
    return 0;
}

///Копирование целочисленного массива src размера size в целочисленный массив dst
void copyArray(int *src, int *dst, int size) {
    for (int i = 0; i < size; ++i) {
        dst[i] = src[i];
    }
}

long long merge(int *begin, int *end, int *mid, long long int *cmpCount) {
    int size_merged = end - begin;
    long long swpCount = 0;
    int *merged = (int *) malloc(sizeof(int) * size_merged);
    int size_a = mid - begin;
    int size_b = end - mid;
    int ind_a = 0, ind_b = 0, ind_c = 0;
    for (ind_c = 0; ind_c < size_merged; ind_c++) {
        if (ind_b != size_b && ind_a != size_a)
            (*cmpCount)++;
        if ((ind_b == size_b) || (ind_a < size_a) && (begin[ind_a] <= mid[ind_b])) {
            merged[ind_c] = begin[ind_a++];
        } else {
            merged[ind_c] = mid[ind_b++];
            if (size_a > ind_a) {
                swpCount += (size_a - ind_a - 1);
            }
        }
    }
    for (int i = 0; i < size_merged; ++i) {
        begin[i] = merged[i];
    }
    free(merged);
    return swpCount;
}

long long mergeSort(int *begin, int *end, long long int *cmpCount) {
    if (end - begin < 2)
        return 0;
    int *mid = begin + ((end - begin) / 2);
    long long swpCount = mergeSort(begin, mid, cmpCount);
    swpCount += mergeSort(mid, end, cmpCount);
    swpCount += merge(begin, end, mid, cmpCount);
    return swpCount;
}

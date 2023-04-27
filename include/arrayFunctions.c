#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "arrayFunctions.h"



float InputFloat(char *prompt, float lowerBound, float upperBound)
{
    float r = lowerBound - 1;
    do {
        printf("%s (floating point value in range [%f;%f]): ", prompt, lowerBound, upperBound);
        scanf("%f", &r);
    } while(r < lowerBound || r > upperBound);
    return r;
}
int InputInt(char *prompt, int lowerBound, int upperBound)
{
    int r = lowerBound-1;
    do {
        printf("%s (integer value in range [%d;%d]): ", prompt, lowerBound, upperBound);
        scanf("%d", &r);
    } while(r < lowerBound || r > upperBound);
    return r;
}

void OutputIntArray(int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("[%d] = %d\n", i, array[i]);
    }
}
void OutputFloatArray(float array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("[%d] = %f\n", i, array[i]);
    }
}

void InputIntArray(char *prompt, int array[], int size)
{
    printf("%s[multiple integer values]:\n", prompt);
    for(int i = 0; i < size; ++i)
    {
        printf("[%d] = ", i);
        scanf("%d", &array[i]);
    }
}

void InputFloatArray(char *prompt, float array[], int size)
{
    printf("%s [multiple floating point values]:\n", prompt);
    for(int i = 0; i < size; ++i)
    {
        printf("[%d] = ", i);
        scanf("%f", &array[i]);
    }
}

void GenerateFloatArray(float array[], int size, float lowerBound, float upperBound)
{
    for(int i = 0; i < size; ++i)
    {
        array[i] = (upperBound - lowerBound) * ((double) rand()) / RAND_MAX + lowerBound;
    }
}

void GenerateIntArray(int array[], int size, int lowerBound, int upperBound)
{
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % (upperBound - lowerBound + 1) + lowerBound;
    }
}
// Индекс максимального элемента массива
int MaxElementIndexFromIntArray(int array[], int size)
{
    int max_index = 0;
    for(int i = 0; i < size; ++i)
    {
        if(array[i] > array[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

int MaxElementIndexFromFloatArray(float array[], int size)
{
    int max_index = 0;
    for(int i = 0; i < size; ++i)
    {
        if(array[i] > array[max_index])
        {
            max_index = i;
        }
    }
    return max_index;
}

int MinElementIndexFromIntArray(int array[], int size)
{
    int min_index = 0;
    for(int i = 0; i < size; ++i)
    {
        if(array[i] < array[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}

int MinElementIndexFromFloatArray(float array[], int size)
{
    int min_index = 0;
    for(int i = 0; i < size; ++i)
    {
        if(array[i] < array[min_index])
        {
            min_index = i;
        }
    }
    return min_index;
}

int FindElementIndexInIntArray(int array[], int size, int element)
{
    int index = -1;
    for(int i = 0; i < size; ++i)
    {
        if(array[i] == element)
        {
            index = i;
            return index;
        }
    }
    return index;
}
int FindElementIndexInFloatArray(float array[], int size, int element)
{
    int index = -1;
    for(int i = 0; i < size; ++i)
    {
        if(array[i] == element)
        {
            index = i;
            return index;
        }
    }
    return index;
}

void SortIntArray(int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[j] < array[i])
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

void SortFloatArray(float array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[j] < array[i])
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}



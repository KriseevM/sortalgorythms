//
// Created by k17 on 12.12.2021.
//

#ifndef SORTALGORITHMS_ARRAYFUNCTIONS_H
#define SORTALGORITHMS_ARRAYFUNCTIONS_H

float InputFloat(char *prompt, float lowerBound, float upperBound);
int InputInt(char *prompt, int lowerBound, int upperBound);
void OutputFloatArray(float array[], int size);
void OutputIntArray(int array[], int size);
void GenerateFloatArray(float array[], int size, float lowerBound, float upperBound);
void GenerateIntArray(int array[], int size, int lowerBound, int upperBound);

void InputFloatArray(char *prompt, float array[], int size);
void InputIntArray(char *prompt, int array[], int size);


int MaxElementIndexFromIntArray(int array[], int size);
int MinElementIndexFromIntArray(int array[], int size);

int MaxElementIndexFromFloatArray(float array[], int size);
int MinElementIndexFromFloatArray(float array[], int size);

int FindElementIndexInIntArray(int array[], int size, int element);
int FindElementIndexInFloatArray(float array[], int size, int element);

void SortIntArray(int array[], int size);
void SortFloatArray(float array[], int size);

#endif //SORTALGORITHMS_ARRAYFUNCTIONS_H

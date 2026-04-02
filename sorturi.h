#ifndef SORTURI_H
#define SORTURI_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void bubbleSort(int *arr, int n);
void insertionSort(int *arr, int n);
void selectionSort(int *arr, int n);
void mergeSort(int *arr, int l, int r);
void quickSort(int *arr, int low, int high);

void generateRandom(int *arr, int n);
void generateSorted(int *arr, int n);
void generateReverseSorted(int *arr, int n);
void generateAlmostSorted(int *arr, int n);

int isSorted(int *arr, int n);

#endif
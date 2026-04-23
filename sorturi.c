#include "sorturi.h"

void swap(int *a, int *b)
 {
    int temp= *a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int *arr, int n)
 {
    for (int i=0; i<n-1; i++)
        for (int j=0; j< n-i-1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void insertionSort(int *arr, int n) 
{
    int i, key, j;
    for (i=1;i<n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j-1;
        }
        arr[j + 1] = key;
    }
}

void merge(int *arr, int l, int m, int r)
 {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i<n1 && j<n2)
     {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L); free(R);
}

void mergeSort(int *arr, int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int *arr, int low, int high) 
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i+1);
}

void quickSort(int *arr, int low, int high)
 {
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/*
void generateRandom(int *arr, int n)
{
    for (int i = 0; i < n; i++) arr[i] = rand() % 100000;
}

void generateSorted(int *arr, int n) 
{
    for (int i = 0; i < n; i++) arr[i] = i;
}

void isSortedCheck(int *arr, int n) 
{
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) return;
}
*/
int isSorted(int *arr, int n) 
{
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) return 0;
    return 1;
}

#include "sorturi.h"

void run_test(const char* name, void (*sort_func)(int*, int), int *data, int n) 
{
    int *copy = (int*)malloc(n * sizeof(int));
    memcpy(copy, data, n * sizeof(int));

    clock_t start = clock();
    if (strcmp(name, "MergeSort") == 0) mergeSort(copy, 0, n - 1);
    else if (strcmp(name, "QuickSort") == 0) quickSort(copy, 0, n - 1);
    else sort_func(copy, n);
    clock_t end = clock();

    double time_spent = (double)(end - start)/ CLOCKS_PER_SEC;
    
    if (isSorted(copy, n)) {
        printf("%-15s  N=%-7d  Timp: %f sec\n", name, n, time_spent);
    } else {
        printf("%-15s  N=%-7d  EROARE SORTARE\n", name, n);
    }

    free(copy);
}

int main() 
{
    srand(time(NULL));
    int sizes[] = {100, 1000, 10000, 50000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) 
    {
        int n = sizes[i];
        int *data = (int*)malloc(n * sizeof(int));
        
        printf("\nTestare pentru N = % d \n", n);
        generateRandom(data, n);

        if (n <= 10000) 
        {
            run_test("BubbleSort", bubbleSort, data, n);
            run_test("InsertionSort", insertionSort, data, n);
        }
        run_test("MergeSort", NULL, data, n);
        run_test("QuickSort", NULL, data, n);

        free(data);
    }

    return 0;
}
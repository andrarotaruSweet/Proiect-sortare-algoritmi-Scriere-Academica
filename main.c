#include "sorturi.h"

void test_file(const char* filename) 
{
    FILE* f = fopen(filename, "r");
    if (!f) return;
    int n;
    if (fscanf(f, "%d", &n) != 1) 
    {
         fclose(f);
          return; 
    }
    int *original = malloc(n*sizeof(int));
    for (int i = 0; i<n; i++)
        fscanf(f, "%d", &original[i]);
    fclose(f);

    printf("\nFisier: %s (N=%d)\n", filename, n);
    const char* names[] = {"Bubble", "Insertion", "Selection", "MergeSort", "QuickSort"};
    
    for (int i=0; i<5; i++) 
    {
        if (n > 20000 && i< 3) 
            continue;
        int *copy = malloc(n*sizeof(int));
        memcpy(copy, original, n*sizeof(int));

        clock_t start = clock();
        if (i == 0) bubbleSort(copy, n);
        else if (i == 1) insertionSort(copy, n);
        else if (i == 2) selectionSort(copy, n);
        else if (i == 3) mergeSort(copy, 0, n - 1);
        else if (i == 4) quickSort(copy, 0, n - 1);
        clock_t end = clock();

        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Algoritm: %s, Timp: %f secunde, Status: %s\n", names[i], time_spent, isSorted(copy, n) ? "OK" : "FAIL");
        free(copy);
    }
    free(original);
}

int main() 
{
    test_file("rand_100.txt");
    test_file("sort_100.txt");
    test_file("inv_100.txt");
    test_file("quasi_100.txt");
    test_file("flat_100.txt");

    test_file("rand_1000.txt");
    test_file("sort_1000.txt");
    test_file("inv_1000.txt");
    test_file("quasi_1000.txt");
    test_file("flat_1000.txt");
   
    test_file("rand_10000.txt");
    test_file("sort_10000.txt");
    test_file("inv_10000.txt");
    test_file("quasi_10000.txt");
    test_file("flat_10000.txt");
   
    test_file("rand_100000.txt");
    //test_file("sort_100000.txt"); 
    //test_file("inv_100000.txt");    
    //test_file("quasi_100000.txt");   
    //test_file("flat_100000.txt");     
   
   //teste mari
    test_file("rand_1000000.txt");
   //test_file("sort_1000000.txt"); 
    //test_file("inv_1000000.txt");  
    //test_file("quasi_1000000.txt");
    test_file("flat_1000000.txt");

    return 0;
}

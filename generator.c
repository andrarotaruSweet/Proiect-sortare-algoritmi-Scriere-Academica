#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void save_to_file(const char* filename, int* arr, int n) 
{
    FILE* f= fopen(filename, "w");
    if (f == NULL) 
    {
        printf("Eroare la crearea fisierului %s\n", filename);
        return;
    }
    // scriu n pe prima linie
    fprintf(f, "%d\n", n); 
    for (int i=0; i<n; i++) 
        fprintf(f, "%d ", arr[i]);
    fclose(f);
}

void generare(int n) 
{
    int *arr = malloc(n*sizeof(int));
    char filename[100];

    // Aleatoare
    for (int i=0; i<n; i++) 
        arr[i] = rand() % 1000000;
    sprintf(filename, "rand_%d.txt", n);
    save_to_file(filename, arr, n);

    //  Sortate
    for (int i=0; i<n; i++) 
        arr[i]=i;
    sprintf(filename, "sort_%d.txt", n);
    save_to_file(filename, arr, n);

    // Invers sortate
    for (int i= 0; i<n; i++) 
        arr[i]=n-i;
    sprintf(filename, "inv_%d.txt", n);
    save_to_file(filename, arr, n);

    // Aproape sortate (5% swap-uri)
    for (int i=0; i<n; i++) 
        arr[i]= i;
    for (int i=0; i<n/20; i++) 
    {
        int idx1 = rand() % n;
        int idx2 = rand() % n;
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }
    sprintf(filename, "quasi_%d.txt", n);
    save_to_file(filename, arr, n);

    // Plate 
    for (int i=0; i<n; i++) 
        arr[i] = rand()% 10;
    sprintf(filename, "flat_%d.txt", n);
    save_to_file(filename, arr, n);

    free(arr);
}

int main() 
{
    srand(time(NULL));
    int sizes[] = {100, 1000, 10000, 100000, 1000000}; 
    for(int i=0; i<5; i++) 
        generare(sizes[i]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform selection sort on an array
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;  // Assume the current element is the minimum
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;  // Update min_idx if a smaller element is found
            }
        }
        // Swap the found minimum element with the current element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Function to generate random integers
void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000; // Generate random integers between 0 and 99999
}


int main()
{
    FILE *fp = fopen("selection_sort.dat", "w");
    if (!fp) {
        printf("Failed to open file for writing\n");
        return 1;
    }

    int min_n = 6000, max_n = 50000, step = 4000;
    for (int n = min_n; n <= max_n; n += step)
    {
        int *arr = (int *)malloc(n * sizeof(int));
        if (!arr) {
            printf("Memory allocation failed for n=%d\n", n);
            continue;
        }
        generateRandomArray(arr, n);

        clock_t start = clock();
        for (int i = 0; i < 10; i++) // Fewer iterations for larger n
            selectionSort(arr, n);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 10.0;
        printf("n=%d, time=%f\n", n, time_taken);
        fprintf(fp, "%d %f\n", n, time_taken);

        free(arr);
    }
    fclose(fp);
    return 0;
}


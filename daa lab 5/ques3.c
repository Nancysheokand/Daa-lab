#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    FILE *fp;
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    /* Store random numbers in file */
    fp = fopen("numbers.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        fprintf(fp, "%d ", a[i]);
    }

    fclose(fp);

    /* Read numbers from file */
    fp = fopen("numbers.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        fscanf(fp, "%d", &a[i]);

    fclose(fp);

    printf("\nElements before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    quickSort(a, 0, n - 1);

    printf("\n\nElements after Quick Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
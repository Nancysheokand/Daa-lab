#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    /* Build Max Heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements */
    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    FILE *fp;
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    srand(time(NULL));

    /* Generate and store random numbers */
    fp = fopen("heapnumbers.txt", "w");

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
    fp = fopen("heapnumbers.txt", "r");

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

    heapSort(a, n);

    printf("\n\nElements after Heap Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
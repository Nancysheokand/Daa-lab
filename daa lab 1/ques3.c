
#include <stdio.h>

void bubbleOptimized(int a[], int n)
{
    int i, j, temp;
    int swapped;
    int comp = 0;
    for (int i = 0; i < n; i++)
    {
        swapped = 0;
        for (int j = 0; j < n; j++)
        {
            comp++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
    printf("Optimized bubble sort=%d\n", comp);
}

void bubbleNormal(int a[], int n)
{
    int i, j, temp;
    int comp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            comp++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("Normal comp=%d\n", comp);
}

int main()
{
    int n, i;
    printf("Enter the number of elem:\n");
    scanf("%d", &n);

    int a[n], b[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    bubbleOptimized(a, n);
    bubbleNormal(b, n);

    return 0;
}

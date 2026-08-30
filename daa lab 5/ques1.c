#include <stdio.h>

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

int quickSelect(int a[], int low, int high, int k)
{
    int pos;

    if (low <= high)
    {
        pos = partition(a, low, high);

        if (pos == k)
            return a[pos];

        if (k < pos)
            return quickSelect(a, low, pos - 1, k);

        return quickSelect(a, pos + 1, high, k);
    }

    return -1;
}

int main()
{
    int a[100], n, i;
    int m1, m2;
    float median;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    if (n % 2 == 1)
    {
        m1 = quickSelect(a, 0, n - 1, n / 2);
        median = m1;
    }
    else
    {
        m1 = quickSelect(a, 0, n - 1, n / 2 - 1);
        m2 = quickSelect(a, 0, n - 1, n / 2);

        median = (m1 + m2) / 2.0;
    }

    printf("Median = %.2f\n", median);

    return 0;
}
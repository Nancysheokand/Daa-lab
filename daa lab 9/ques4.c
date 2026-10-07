#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] < a[smallest])
        smallest = l;

    if (r < n && a[r] < a[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&a[i], &a[smallest]);
        heapify(a, n, smallest);
    }
}

int extractMin(int a[], int *n) {
    int x = a[0];

    a[0] = a[*n - 1];
    (*n)--;

    heapify(a, *n, 0);

    return x;
}

void insert(int a[], int *n, int x) {
    int i = (*n)++;
    a[i] = x;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (a[p] <= a[i])
            break;

        swap(&a[p], &a[i]);
        i = p;
    }
}

int main() {
    int n;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    int size = n;
    int cost = 0;

    while (size > 1) {
        int x = extractMin(a, &size);
        int y = extractMin(a, &size);

        int sum = x + y;
        cost += sum;

        insert(a, &size, sum);
    }

    printf("Minimum total cost = %d\n", cost);

    return 0;
}
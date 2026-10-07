#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];
    int minVal = 1000000000;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] % 2 == 1)
            a[i] *= 2;

        if (a[i] < minVal)
            minVal = a[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    int answer = 1000000000;

    while (1) {
        int maxVal = a[0];

        if (maxVal - minVal < answer)
            answer = maxVal - minVal;

        if (maxVal % 2 == 1)
            break;

        a[0] = maxVal / 2;

        if (a[0] < minVal)
            minVal = a[0];

        heapify(a, n, 0);
    }

    printf("Minimum deviation = %d\n", answer);

    return 0;
}
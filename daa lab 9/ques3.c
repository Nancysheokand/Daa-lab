#include <stdio.h>

typedef struct {
    int distance;
    int fuel;
} Station;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void push(int heap[], int *size, int value) {
    int i = (*size)++;
    heap[i] = value;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (heap[p] >= heap[i])
            break;

        swap(&heap[p], &heap[i]);
        i = p;
    }
}

int pop(int heap[], int *size) {
    int result = heap[0];
    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < *size && heap[l] > heap[largest])
            largest = l;

        if (r < *size && heap[r] > heap[largest])
            largest = r;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }

    return result;
}

int main() {
    int n, D, F;

    printf("Enter number of stations: ");
    scanf("%d", &n);

    Station s[n];

    printf("Enter distance and fuel at each station:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &s[i].distance, &s[i].fuel);

    printf("Enter target distance and initial fuel: ");
    scanf("%d %d", &D, &F);

    int heap[n];
    int size = 0;
    int stops = 0;
    int prev = 0;

    for (int i = 0; i <= n; i++) {
        int pos = (i == n) ? D : s[i].distance;

        F -= pos - prev;

        while (F < 0 && size > 0) {
            F += pop(heap, &size);
            stops++;
        }

        if (F < 0) {
            printf("Target cannot be reached.\n");
            return 0;
        }

        if (i < n)
            push(heap, &size, s[i].fuel);

        prev = pos;
    }

    printf("Minimum refuelling stops = %d\n", stops);

   return 0;
}
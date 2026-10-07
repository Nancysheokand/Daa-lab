#include <stdio.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
    int available;
} Node;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void heapify(Node heap[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l].freq > heap[largest].freq)
        largest = l;

    if (r < n && heap[r].freq > heap[largest].freq)
        largest = r;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(heap, n, largest);
    }
}

Node extractMax(Node heap[], int *n) {
    Node x = heap[0];

    heap[0] = heap[*n - 1];
    (*n)--;

    heapify(heap, *n, 0);

    return x;
}

void insert(Node heap[], int *n, Node x) {
    int i = (*n)++;
    heap[i] = x;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (heap[p].freq >= heap[i].freq)
            break;

        swap(&heap[p], &heap[i]);
        i = p;
    }
}

int main() {
    char s[1000];
    int K;

    printf("Enter string: ");
    scanf("%s", s);

    printf("Enter K: ");
    scanf("%d", &K);

    if (K <= 1) {
        printf("Reorganized string = %s\n", s);
        return 0;
    }

    int freq[256] = {0};

    for (int i = 0; s[i]; i++)
        freq[(unsigned char)s[i]]++;

    Node heap[256];
    int size = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            heap[size].ch = (char)i;
            heap[size].freq = freq[i];
            heap[size].available = 0;
            size++;
        }
    }

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);

    char result[1000];
    int len = 0;

    Node waiting[256];
    int front = 0, rear = 0;

    for (int pos = 0; pos < (int)strlen(s); pos++) {

        if (front < rear && waiting[front].available <= pos) {
            insert(heap, &size, waiting[front]);
            front++;
        }

        if (size == 0) {
            printf("Impossible\n");
            return 0;
        }

        Node x = extractMax(heap, &size);

        result[len++] = x.ch;
        x.freq--;

        if (x.freq > 0) {
            x.available = pos + K;
            waiting[rear++] = x;
        }
    }

    result[len] = '\0';

    printf("Reorganized string = %s\n", result);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node* createNode(char ch, int freq) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

void swap(Node **a, Node **b) {
    Node *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(Node *heap[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && heap[l]->freq < heap[smallest]->freq)
        smallest = l;

    if (r < n && heap[r]->freq < heap[smallest]->freq)
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

Node* extractMin(Node *heap[], int *n) {
    Node *min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    minHeapify(heap, *n, 0);
    return min;
}

void insertHeap(Node *heap[], int *n, Node *node) {
    int i = (*n)++;
    heap[i] = node;

    while (i > 0) {
        int p = (i - 1) / 2;

        if (heap[p]->freq <= heap[i]->freq)
            break;

        swap(&heap[p], &heap[i]);
        i = p;
    }
}

void printCodes(Node *root, char code[], int depth) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        code[depth] = '\0';
        printf("%c : %s\n", root->ch, code);
        return;
    }

    code[depth] = '0';
    printCodes(root->left, code, depth + 1);

    code[depth] = '1';
    printCodes(root->right, code, depth + 1);
}

int main() {
    int n;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    Node *heap[100];

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;

        scanf(" %c %d", &ch, &freq);
        heap[i] = createNode(ch, freq);
    }

    int size = n;

    for (int i = size / 2 - 1; i >= 0; i--)
        minHeapify(heap, size, i);

    while (size > 1) {
        Node *x = extractMin(heap, &size);
        Node *y = extractMin(heap, &size);

        Node *z = createNode('$', x->freq + y->freq);
        z->left = x;
        z->right = y;

        insertHeap(heap, &size, z);
    }

    char code[100];

    printf("\nHuffman Codes:\n");
    printCodes(heap[0], code, 0);

    return 0;
}
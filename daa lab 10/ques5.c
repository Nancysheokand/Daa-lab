
#include <stdio.h>
#include <stdlib.h>

int *parent, *sz;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (sz[a] < sz[b]) {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    sz[a] += sz[b];
}

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    int *A = malloc(n * sizeof(int));
    parent = malloc(n * sizeof(int));
    sz = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        unite(u, v);
    }

    int *visited = calloc(n, sizeof(int));
    int *positions = malloc(n * sizeof(int));
    int *values = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int root = find(i);

        if (visited[root])
            continue;

        visited[root] = 1;

        int count = 0;

        for (int j = 0; j < n; j++) {
            if (find(j) == root) {
                positions[count] = j;
                values[count] = A[j];
                count++;
            }
        }

        qsort(positions, count, sizeof(int), compare);
        qsort(values, count, sizeof(int), compare);

        for (int j = 0; j < count; j++)
            A[positions[j]] = values[j];
    }

    printf("Lexicographically smallest permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");

    free(A);
    free(parent);
    free(sz);
    free(visited);
    free(positions);
    free(values);

    return 0;
}

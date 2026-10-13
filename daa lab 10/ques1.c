
#include <stdio.h>
#include <stdlib.h>

int *parent, *sz, *parity;

int find(int x) {
    if (parent[x] == x)
        return x;

    int p = parent[x];
    parent[x] = find(p);
    parity[x] ^= parity[p];
    return parent[x];
}

int addEdge(int u, int v) {
    int ru = find(u);
    int pu = parity[u];
    int rv = find(v);
    int pv = parity[v];

    if (ru == rv)
        return (pu ^ pv) == 1;

    if (sz[ru] < sz[rv]) {
        parent[ru] = rv;
        parity[ru] = pu ^ pv ^ 1;
        sz[rv] += sz[ru];
    } else {
        parent[rv] = ru;
        parity[rv] = pu ^ pv ^ 1;
        sz[ru] += sz[rv];
    }

    return 1;
}

int main(void) {
    int V, E;
    scanf("%d%d", &V, &E);

    parent = malloc(V * sizeof(int));
    sz = malloc(V * sizeof(int));
    parity = calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        if (addEdge(u, v))
            printf("Edge (%d, %d) accepted\n", u, v);
        else
            printf("Edge (%d, %d) rejected\n", u, v);
    }

    free(parent);
    free(sz);
    free(parity);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

int *parent, *sz;
ll *sum;

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
    sum[a] += sum[b];
}

ll maximumWeight(int n, int K) {
    ll best = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        if (find(i) == i && sz[i] <= K) {
            if (sum[i] > best)
                best = sum[i];
        }
    }

    return best;
}

int main(void) {
    int n, m, K;
    scanf("%d%d%d", &n, &m, &K);

    parent = malloc(n * sizeof(int));
    sz = malloc(n * sizeof(int));
    sum = malloc(n * sizeof(ll));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &sum[i]);
        parent[i] = i;
        sz[i] = 1;
    }

    printf("Initial maximum: %lld\n",
           maximumWeight(n, K));

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        unite(u, v);

        printf("After edge %d: %lld\n",
               i + 1, maximumWeight(n, K));
    }

    free(parent);
    free(sz);
    free(sum);
    return 0;
}

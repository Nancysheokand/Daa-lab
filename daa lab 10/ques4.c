
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

int *parent, *sz, *active;
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

ll maximumSum(int n) {
    ll best = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        if (active[i] && find(i) == i &&
            sum[i] > best) {
            best = sum[i];
        }
    }

    return best == LLONG_MIN ? 0 : best;
}

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);

    parent = malloc(n * sizeof(int));
    sz = malloc(n * sizeof(int));
    active = calloc(n, sizeof(int));
    sum = malloc(n * sizeof(ll));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &sum[i]);
        parent[i] = i;
        sz[i] = 1;
    }

    int *U = malloc(m * sizeof(int));
    int *V = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++)
        scanf("%d%d", &U[i], &V[i]);

    int *P = malloc(n * sizeof(int));
    ll *ans = malloc(n * sizeof(ll));

    for (int i = 0; i < n; i++)
        scanf("%d", &P[i]);

    /* Process deletions in reverse */
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = maximumSum(n);

        int x = P[i];
        active[x] = 1;

        for (int j = 0; j < m; j++) {
            int u = U[j], v = V[j];

            if (u == x && active[v])
                unite(u, v);
            else if (v == x && active[u])
                unite(u, v);
        }
    }

    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i]);

    printf("\n");

    free(parent);
    free(sz);
    free(active);
    free(sum);
    free(U);
    free(V);
    free(P);
    free(ans);

    return 0;
}

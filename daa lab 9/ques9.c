#include <stdio.h>
#include <limits.h>

typedef struct {
    int weight;
    int left;
    int right;
} Block;

int main() {
    int n;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    Block b[n];

    printf("Enter weights:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i].weight);
        b[i].left = i;
        b[i].right = i;
    }

    int totalCost = 0;

    /*
       Greedy simulation:
       repeatedly choose the cheapest legal adjacent merge.
    */

    int active = n;

    while (active > 1) {
        int best = -1;
        int bestCost = INT_MAX;

        for (int i = 0; i < active - 1; i++) {
            int cost = b[i].weight + b[i + 1].weight;

            if (cost < bestCost) {
                bestCost = cost;
                best = i;
            }
        }

        printf("Merge %d and %d -> %d\n",
               b[best].weight,
               b[best + 1].weight,
               bestCost);

        b[best].weight += b[best + 1].weight;

        for (int j = best + 1; j < active - 1; j++)
            b[j] = b[j + 1];

        active--;

        totalCost += bestCost;
    }

    printf("\nTotal merge cost = %d\n", totalCost);

    return 0;
}
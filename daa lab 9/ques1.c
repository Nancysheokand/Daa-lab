#include <stdio.h>

typedef struct {
    double v, w, lambda;
    double fraction;
} Item;

int main() {
    int n;
    double W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item a[n];

    printf("Enter value, weight and decay rate:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &a[i].v, &a[i].w, &a[i].lambda);
        a[i].fraction = 0;
    }

    printf("Enter knapsack capacity: ");
    scanf("%lf", &W);

    double time = 0;
    double totalValue = 0;

    for (int count = 0; count < n && W > 0; count++) {
        int best = -1;
        double bestDensity = -1e18;

        for (int i = 0; i < n; i++) {
            if (a[i].fraction < 1.0) {
                double d = a[i].v / a[i].w - a[i].lambda * time;

                if (d > bestDensity) {
                    bestDensity = d;
                    best = i;
                }
            }
        }

        if (best == -1 || bestDensity <= 0)
            break;

        double amount = a[best].w * (1.0 - a[best].fraction);

        if (amount > W)
            amount = W;

        double f = amount / a[best].w;

        a[best].fraction += f;
        totalValue += amount * bestDensity;
        W -= amount;

        time++;
    }

    printf("\nMaximum effective value = %.2lf\n", totalValue);

    printf("Fractions selected:\n");
    for (int i = 0; i < n; i++)
        printf("Item %d : %.2lf\n", i + 1, a[i].fraction);

    return 0;
}
#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int E, F;
    int dp[20][101];

    printf("Enter number of eggs: ");
    scanf("%d", &E);

    printf("Enter number of floors: ");
    scanf("%d", &F);

    // 0 floors need 0 attempts
    for (int e = 1; e <= E; e++) {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    // With 1 egg, we have to check floors one by one
    for (int f = 1; f <= F; f++) {
        dp[1][f] = f;
    }

    // Dynamic Programming
    for (int e = 2; e <= E; e++) {
        for (int f = 2; f <= F; f++) {

            dp[e][f] = INT_MAX;

            for (int x = 1; x <= f; x++) {

                int eggBreaks = dp[e - 1][x - 1];
                int eggSurvives = dp[e][f - x];

                int attempts = 1 + max(eggBreaks, eggSurvives);

                if (attempts < dp[e][f])
                    dp[e][f] = attempts;
            }
        }
    }

    printf("\nMinimum number of droppings = %d\n",
           dp[E][F]);

    return 0;
}
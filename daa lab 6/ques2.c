#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n, W;
    int i, w;

    int weight[100], profit[100];
    int dp[101][101];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter profits:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    /* Initialize first row and first column */
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum Profit = %d", dp[n][W]);

    return 0;
}
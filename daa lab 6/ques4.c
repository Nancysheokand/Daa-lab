#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    int N;
    int arr[100];
    int dp[100][100];

    int i, j, k;
    int length;
    int cost;

    printf("Enter N: ");
    scanf("%d", &N);

    printf("Enter array elements:\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Cost of multiplying one matrix is 0 */
    for (i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    /* length is the chain length */
    for (length = 2; length < N; length++)
    {
        for (i = 1; i < N - length + 1; i++)
        {
            j = i + length - 1;

            dp[i][j] = INT_MAX;

            /* Try every possible split */
            for (k = i; k < j; k++)
            {
                cost = dp[i][k]
                     + dp[k + 1][j]
                     + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications = %d",
           dp[1][N - 1]);

    return 0;
}
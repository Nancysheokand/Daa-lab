#include <stdio.h>
#include <limits.h>

long long power2(int n) {
    long long result = 1;

    for (int i = 0; i < n; i++)
        result *= 2;

    return result;
}

long long hanoi3(int n) {
    return power2(n) - 1;
}

long long min4Hanoi(int n) {
    long long dp[100];

    dp[0] = 0;

    if (n >= 1)
        dp[1] = 1;

    for (int i = 2; i <= n; i++) {

        dp[i] = LLONG_MAX;

        for (int k = 1; k < i; k++) {

            long long moves =
                2 * dp[k] +
                hanoi3(i - k);

            if (moves < dp[i])
                dp[i] = moves;
        }
    }

    return dp[n];
}

int main() {

    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\nMinimum moves = %lld\n",
           min4Hanoi(n));

    return 0;
}
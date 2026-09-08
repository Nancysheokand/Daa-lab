#include <stdio.h>

long long minimumMoves(int n) {
    long long power = 1;

    for (int i = 0; i < n + 1; i++)
        power *= 2;

    return power / 3;
}

void printSwitches(int switches[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d", switches[i]);

    printf("\n");
}

int main() {

    int n;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    long long moves = minimumMoves(n);

    printf("\nMinimum number of moves = %lld\n", moves);

    return 0;
}

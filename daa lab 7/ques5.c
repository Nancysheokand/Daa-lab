#include <stdio.h>

int main() {

    int n;

    printf("Enter number of hiding spots: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Invalid number of spots.\n");
        return 0;
    }

    printf("\nShooting sequence:\n");

    if (n % 2 == 0) {

        // Forward
        for (int i = 2; i <= n - 1; i++)
            printf("%d ", i);

        // Backward
        for (int i = n - 1; i >= 2; i--)
            printf("%d ", i);

    } else {

        // For odd n, sweep twice
        for (int k = 0; k < 2; k++) {
            for (int i = 2; i <= n - 1; i++)
                printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
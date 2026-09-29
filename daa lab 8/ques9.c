#include <stdio.h>
#include <stdlib.h>

unsigned long long collatzNext(unsigned long long n) {
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}

void printTrajectory(unsigned long long n) {

    printf("Trajectory: ");

    while (n != 1) {

        printf("%llu -> ", n);

        n = collatzNext(n);
    }

    printf("1\n");
}

unsigned long long trajectoryLength(unsigned long long n) {

    unsigned long long count = 0;

    while (n != 1) {

        n = collatzNext(n);
        count++;
    }

    return count;
}

void analyzeRange(unsigned long long a,
                  unsigned long long b) {

    unsigned long long maxLength = 0;
    unsigned long long maxNumber = a;

    for (unsigned long long i = a; i <= b; i++) {

        unsigned long long length =
            trajectoryLength(i);

        printf("n = %llu, steps = %llu\n",
               i, length);

        if (length > maxLength) {
            maxLength = length;
            maxNumber = i;
        }

        if (i == b)
            break;
    }

    printf("\nLongest trajectory:\n");
    printf("Starting number = %llu\n", maxNumber);
    printf("Number of steps = %llu\n", maxLength);
}

int main() {

    int choice;

    printf("COLLATZ CONJECTURE ANALYSIS\n");
    printf("---------------------------\n");

    printf("1. Analyze one number\n");
    printf("2. Analyze an interval\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {

        unsigned long long n;

        printf("Enter positive integer n: ");
        scanf("%llu", &n);

        if (n == 0) {
            printf("Enter a positive integer.\n");
            return 0;
        }

        printTrajectory(n);

        printf("Number of steps = %llu\n",
               trajectoryLength(n));
    }

    else if (choice == 2) {

        unsigned long long a, b;

        printf("Enter interval [a, b]: ");
        scanf("%llu %llu", &a, &b);

        if (a == 0 || a > b) {
            printf("Invalid interval.\n");
            return 0;
        }

        analyzeRange(a, b);
    }

    else {
        printf("Invalid choice.\n");
    }

    return 0;
}
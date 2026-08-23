#include <stdio.h>
#include <stdbool.h>

// Helper function: Simple Bubble Sort (can be replaced with qsort for O(n log n))
void sortArray(int S[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (S[j] > S[j + 1]) {
                int temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}

// Recursive helper to handle k-Sum using (k-2) nested selections + 2-pointer scan
bool kSumHelper(int S[], int n, int target, int k, int start, int result[]) {
    // Base Case: When k == 2, use Two-Pointer scan in O(n)
    if (k == 2) {
        int left = start;
        int right = n - 1;

        while (left < right) {
            int current_sum = S[left] + S[right];
            if (current_sum == target) {
                result[0] = S[left];
                result[1] = S[right];
                return true;
            } else if (current_sum < target) {
                left++;  // Move right to get a larger sum
            } else {
                right--; // Move left to get a smaller sum
            }
        }
        return false;
    }

    // Recursive Case: Fix one element and solve (k - 1)-Sum
    for (int i = start; i <= n - k; i++) {
        if (kSumHelper(S, n, target - S[i], k - 1, i + 1, result)) {
            result[k - 1] = S[i]; // Record chosen element
            return true;
        }
    }

    return false;
}

// Main function to check if k elements sum to T
bool hasKSum(int S[], int n, int T, int k, int result[]) {
    if (n < k) return false;

    // Step 1: Sort array in ascending order
    sortArray(S, n);

    // Step 2: Solve using kSumHelper
    return kSumHelper(S, n, T, k, 0, result);
}

int main() {
    int S[] = {4, 3, 37, 8, 19, 16, 1, 5};
    int n = sizeof(S) / sizeof(S[0]);
    int T = 25;
    int k = 3; // Find 3 numbers that add up to 33

    int result[10]; // Stores matching subset

    printf("Input Array: ");
    for (int i = 0; i < n; i++) printf("%d ", S[i]);
    printf("\nTarget T = %d, k = %d\n\n", T, k);

    if (hasKSum(S, n, T, k, result)) {
        printf("Found %d elements that sum to %d: [ ", k, T);
        for (int i = 0; i < k; i++) {
            printf("%d ", result[i]);
        }
        printf("]\n");
    } else {
        printf("No %d elements sum to %d\n", k, T);
    }

    return 0;
}
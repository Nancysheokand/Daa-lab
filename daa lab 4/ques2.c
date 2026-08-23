#include <stdio.h>
#include <stdbool.h>

// Helper function to sort an array in ascending order using Bubble Sort
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int S1[5] = {12, 3, 7, 1, 19};
    int S2[5] = {5, 20, 11, 2, 9};
    int n = 5;
    int x = 16; // Target sum

    // Step 1: Sort both arrays
    sortArray(S1, n); // S1 becomes: [1, 3, 7, 12, 19]
    sortArray(S2, n); // S2 becomes: [2, 5, 9, 11, 20]

    // Step 2: Use two pointers to find if a pair equals x
    int i = 0;     // Starts at smallest element of S1
    int j = n - 1; // Starts at largest element of S2
    bool found = false;

    while (i < n && j >= 0) {
        int sum = S1[i] + S2[j];

        if (sum == x) {
            printf("Pair Found: %d (from S1) + %d (from S2) = %d\n", S1[i], S2[j], x);
            found = true;
            break;
        } 
        else if (sum < x) {
            i++; // Move to a larger number in S1
        } 
        else {
            j--; // Move to a smaller number in S2
        }
    }

    if (!found) {
        printf("No pair exists that sums to %d\n", x);
    }

    return 0;
}
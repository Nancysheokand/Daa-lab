#include <stdio.h>

// Structure to represent an interval
struct Interval {
    int start;
    int end;
};

// Helper function to sort intervals by start time using Bubble Sort
// (Can be replaced with qsort for optimal standard implementation)
void sortIntervals(struct Interval arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                struct Interval temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to merge overlapping intervals
int mergeIntervals(struct Interval input[], int n, struct Interval output[]) {
    if (n <= 0) return 0;

    // Step 1: Sort intervals by start time
    sortIntervals(input, n);

    // Step 2: Initialize output with the first interval
    output[0] = input[0];
    int out_count = 1; // Number of merged intervals stored

    // Step 3: Iterate through remaining intervals
    for (int i = 1; i < n; i++) {
        struct Interval last = output[out_count - 1];
        struct Interval current = input[i];

        // Check if current overlaps with the last merged interval
        if (current.start <= last.end) {
            // Overlap exists: Merge by expanding the end time if needed
            if (current.end > output[out_count - 1].end) {
                output[out_count - 1].end = current.end;
            }
        } else {
            // No overlap: Add current interval as a new entry
            output[out_count] = current;
            out_count++;
        }
    }

    return out_count; // Return total merged count
}

int main() {
    // Input intervals: {(1,3), (2,6), (8,10), (7,18)}
    struct Interval input[4] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {7, 18}
    };
    int n = 4;
    struct Interval output[4];

    printf("Input Intervals:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", input[i].start, input[i].end);
    }
    printf("\n\n");

    int merged_size = mergeIntervals(input, n, output);

    printf("Merged Intervals:\n");
    for (int i = 0; i < merged_size; i++) {
        printf("(%d, %d) ", output[i].start, output[i].end);
    }
    printf("\n");

    return 0;
}
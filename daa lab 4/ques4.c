#include <stdio.h>

// Helper function to sort an array using simple Bubble Sort
void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Arrival and departure times for 5 people
    int entry[] = {1, 3, 5, 2, 8};
    int exit[]  = {4, 7, 9, 6, 10};
    int n = 5;

    // Step 1: Sort entry times and exit times separately
    sortArray(entry, n); // Becomes: [1, 2, 3, 5, 8]
    sortArray(exit, n);  // Becomes: [4, 6, 7, 9, 10]

    // Step 2: Use two pointers to track arrivals and departures
    int i = 0; // Pointer for entry times
    int j = 0; // Pointer for exit times

    int current_people = 0;
    int max_people = 0;
    int peak_time = -1;

    // Step 3: Compare entry and exit times in order
    while (i < n && j < n) {
        // If next event is an entry (someone arrives before anyone leaves)
        if (entry[i] < exit[j]) {
            current_people++; // Someone enters

            if (current_people > max_people) {
                max_people = current_people;
                peak_time = entry[i]; // Track the time peak was reached
            }
            i++; // Move to next entry
        } 
        else {
            current_people--; // Someone leaves
            j++; // Move to next exit
        }
    }

    // Print results
    printf("Max people present simultaneously: %d\n", max_people);
    printf("Time when peak was first reached: %d\n", peak_time);

    return 0;
}
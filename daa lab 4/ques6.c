#include <stdio.h>

// Structure representing an interval endpoint event
struct Event {
    int point;
    int type; // +1 for start, -1 for end
};

// Helper function to sort events by coordinate point
// If coordinates are equal, start (+1) comes before end (-1)
void sortEvents(struct Event events[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            // Compare coordinate points
            if (events[j].point > events[j + 1].point || 
               (events[j].point == events[j + 1].point && events[j].type < events[j + 1].type)) {
                struct Event temp = events[j];
                events[j] = events[j + 1];
                events[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Input intervals: {(10,40), (20,60), (50,90), (15,70)}
    int left[]  = {10, 20, 50, 15};
    int right[] = {40, 60, 90, 70};
    int n = 4;

    struct Event events[2 * 4];

    // Step 1: Create 2n events from n intervals
    for (int i = 0; i < n; i++) {
        events[2 * i].point = left[i];
        events[2 * i].type = 1;  // Interval start

        events[2 * i + 1].point = right[i];
        events[2 * i + 1].type = -1; // Interval end
    }

    // Step 2: Sort events in ascending order by coordinate point
    sortEvents(events, 2 * n);

    // Step 3: Sweep line to find the point of maximum overlap
    int current_count = 0;
    int max_count = 0;
    int best_point = -1;

    for (int i = 0; i < 2 * n; i++) {
        current_count += events[i].type;

        if (current_count > max_count) {
            max_count = current_count;
            best_point = events[i].point;
        }
    }

    // Output results
    printf("Input Intervals:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", left[i], right[i]);
    }
    printf("\n\n");

    printf("Point in maximum number of intervals: p = %d\n", best_point);
    printf("Maximum number of overlapping intervals: %d\n", max_count);

   return 0;
}
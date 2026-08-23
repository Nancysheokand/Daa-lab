#include <stdio.h>
struct Item {
    int number;
    int color; // 0 for Red, 1 for Blue, 2 for Yellow
};

int main() {
    // Input array of items, already sorted by number
    struct Item input[6] = {
        {10, 1}, // (10, Blue)
        {15, 0}, // (15, Red)
        {20, 2}, // (20, Yellow)
        {25, 0}, // (25, Red)
        {30, 1}, // (30, Blue)
        {35, 2}  // (35, Yellow)
    };
    int n = 6;
    struct Item output[6]; // Array to hold sorted results

    int count[3] = {0, 0, 0}; 
    int index[3] = {0, 0, 0}; 

    for (int i = 0; i < n; i++) {
        count[input[i].color]++;
    }
    index[0] = 0;                  // Reds start at index 0
    index[1] = count[0];           // Blues start right after Reds
    index[2] = count[0] + count[1];// Yellows start right after Blues

    for (int i = 0; i < n; i++) {
        int c = input[i].color;
        output[index[c]] = input[i];
        index[c]++;
    }

    printf("Sorted by Color (Red -> Blue -> Yellow):\n");
    for (int i = 0; i < n; i++) {
        if (output[i].color == 0)
            printf("(%d, Red)\n", output[i].number);
        else if (output[i].color == 1)
            printf("(%d, Blue)\n", output[i].number);
        else
            printf("(%d, Yellow)\n", output[i].number);
    }

    return 0;
}
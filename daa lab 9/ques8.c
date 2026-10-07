#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int start[n], end[n];

    printf("Enter start and end times:\n");

    for (int i = 0; i < n; i++)
        scanf("%d %d", &start[i], &end[i]);

    sort(start, n);
    sort(end, n);

    int i = 0, j = 0;
    int rooms = 0;
    int maxRooms = 0;

    while (i < n) {
        if (start[i] < end[j]) {
            rooms++;
            i++;

            if (rooms > maxRooms)
                maxRooms = rooms;
        } else {
            rooms--;
            j++;
        }
    }

    printf("Minimum number of rooms = %d\n", maxRooms);

    return 0;
}
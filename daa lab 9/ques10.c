#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAXLEN 1000

// Find maximum overlap between suffix of s1 and prefix of s2
int findOverlap(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int maxOverlap = 0;

    int maxLen = (len1 < len2) ? len1 : len2;

    for (int k = 1; k <= maxLen; k++) {
        int match = 1;

        for (int i = 0; i < k; i++) {
            if (s1[len1 - k + i] != s2[i]) {
                match = 0;
                break;
            }
        }

        if (match)
            maxOverlap = k;
    }

    return maxOverlap;
}

// Merge two strings using their maximum overlap
void mergeStrings(char *s1, char *s2, char *result) {
    int overlap = findOverlap(s1, s2);

    strcpy(result, s1);
    strcat(result, s2 + overlap);
}

int main() {
    int n;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    char s[MAX][MAXLEN];

    printf("Enter the strings:\n");

    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    while (n > 1) {
        int bestI = 0;
        int bestJ = 1;
        int bestOverlap = -1;

        // Find pair having maximum overlap
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                int overlap = findOverlap(s[i], s[j]);

                if (overlap > bestOverlap) {
                    bestOverlap = overlap;
                    bestI = i;
                    bestJ = j;
                }
            }
        }

        char merged[MAXLEN];

        mergeStrings(s[bestI], s[bestJ], merged);

        printf("\nMerging: %s + %s", s[bestI], s[bestJ]);
        printf("  (Overlap = %d)", bestOverlap);
        printf("\nResult: %s\n", merged);

        // Store merged string at bestI
        strcpy(s[bestI], merged);

        // Remove bestJ
        for (int i = bestJ; i < n - 1; i++)
            strcpy(s[i], s[i + 1]);

        n--;
    }

    printf("\nGreedy Superstring = %s\n", s[0]);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    int type;   // 0 = death, 1 = birth
} Event;

int compare(const void *a, const void *b) {

    Event *x = (Event *)a;
    Event *y = (Event *)b;

    if (x->year != y->year)
        return x->year - y->year;

    // Death before birth when same year
    return x->type - y->type;
}

int main() {

    int n;

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    Event events[2 * n];

    for (int i = 0; i < n; i++) {

        int birth, death;

        printf("Enter birth and death year of scientist %d: ",
               i + 1);

        scanf("%d %d", &birth, &death);

        events[2 * i].year = birth;
        events[2 * i].type = 1;   // birth

        events[2 * i + 1].year = death;
        events[2 * i + 1].type = 0;   // death
    }

    qsort(events, 2 * n, sizeof(Event), compare);

    int alive = 0;
    int maximum = 0;
    int bestYear = 0;

    for (int i = 0; i < 2 * n; i++) {

        if (events[i].type == 0) {
            alive--;
        }
        else {
            alive++;

            if (alive > maximum) {
                maximum = alive;
                bestYear = events[i].year;
            }
        }
    }

    printf("\nYear with maximum scientists alive = %d\n",
           bestYear);

    printf("Maximum number of scientists alive = %d\n",
           maximum);

    return 0;
}
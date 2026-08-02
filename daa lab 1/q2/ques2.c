#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, tosses = 10000;
    int fairHead = 0, biasedHead = 0;

    srand(time(NULL));

    for(i = 0; i < tosses; i++)
    {
        if(rand() % 2 == 0)
            fairHead++;
    }

    for(i = 0; i < tosses; i++)
    {
        if(rand() % 10 < 7)
            biasedHead++;
    }

    printf("Fair Coin Head Probability = %.3f\n",
           (float)fairHead/tosses);

    printf("Biased Coin Head Probability = %.3f\n",
           (float)biasedHead/tosses);

    return 0;
}

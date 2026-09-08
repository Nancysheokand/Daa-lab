#include<stdio.h>
   int main()
   {
    int n,total,moves;
    printf("enter no of rows:");
    scanf("%d",&n);
    total=n*(n+1)/2;
    moves=total/3;
    printf("total no of coins=%d\n",total);
    printf("minimum no of moves=%d\n",moves);
    return 0;

   }
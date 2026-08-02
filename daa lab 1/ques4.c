#include <stdio.h>

void TOH(int n, char A, char B, char C)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",A,C);
        return;
    }

    TOH(n-1,A,C,B);

    printf("Move disk %d from %c to %c\n",n,A,C);

    TOH(n-1,B,A,C);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d",&n);

    TOH(n,'A','B','C');

    return 0;
}

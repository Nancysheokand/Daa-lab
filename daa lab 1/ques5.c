#include <stdio.h>

int main()
{
    int n,i;
    printf("Enter size: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter elements (0 and 1):\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            printf("Partition index = %d\n",i);
            break;
        }
    }

    return 0;
}

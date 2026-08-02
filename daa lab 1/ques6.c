#include <stdio.h>

int main()
{
    int n,i,j;

    printf("Enter size: ");
    scanf("%d",&n);

    int a[n];

    printf("Enter elements:\n");

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                printf("Duplicate Found\n");
                return 0;
            }
        }
    }

    printf("All elements are unique");

    return 0;
}

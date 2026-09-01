#include<stdio.h>
int main(){
int n;
printf("enter the value of n:");
scanf("%d",&n);
int dp[100];
dp[0]=0;
dp[1]=1;
//taling input of array
for(int i=2;i<n;i++)
{
   dp[i]=dp[i-1]+dp[i-2];
}
//printing of array
for(int i=0;i<n;i++)
{
    printf("%d ",dp[i]);
}
return 0;
}
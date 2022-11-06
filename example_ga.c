#include<stdio.h>
int main()
{
    int i ,n;
    float sum = 0;
    printf("how many terms U want :");
    scanf("%d",&n);
    for(i = 1 ; i<=n;i++)
    {
        sum=sum+(float)i/(i+1);
        
    }

    printf("sum of series = %.2f",sum);

}
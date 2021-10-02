#include<stdio.h>
#define n 5

void main()
{
    int i,j,k,temp,arry[n],swap;
    printf("Enter Elements: ");
    for (i=0;i<n;i++)
        scanf("%d",&arry[i]);
    
    for (i=0;i<n-1;i++)
    {
        swap=0;
        for (j=0;j<=n-1-i;j++)
        {
            if (arry[j]>arry[j+1])
            {
                temp=arry[j];
                arry[j]=arry[j+1];
                arry[j+1]=temp;
                swap++;
            }
        }
        if (swap==0)
            break;
    }
    printf("Sorted Array: ");
    for (i=0;i<n;i++)
        printf("%d  ",arry[i]);
}
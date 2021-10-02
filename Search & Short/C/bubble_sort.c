/*
   Bubble Sort is the simplest sorting algorithm that works by repeatedly
   swapping the adjacent elements if they are in wrong order.

   Example: 1 3 7 6 2
   WHILE COMPARING THE ELEMENTS, THE ALGORITHM WILL COMPARE TO ELEMENTS A AND B AND WILL SWAP THEM 
   ONLY WHEN A>B.
   FIRST PASS:
    
   1 3 6 7 2  (7>6)
   1 3 6 2 7  (7>3)

   SECOND PASS:
   1 3 2 6 7  (6>2)

   THIRD PASS:
   1 2 3 6 7  (3>2)


*/  

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
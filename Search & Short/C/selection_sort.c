/*
    The selection sort algorithm sorts an array by repeatedly finding the minimum element 
    (considering ascending order) from unsorted part and putting it at the beginning.

    Example: 64 25 12 22 11
    Will find the minimum element of the arry in range 0 to 4 and place it at the the beginning of the chosen array range.

    11 25 12 22 64

    then will find min element of thw array in range 1 to 4.

    11 12 25 22 64

    then in range 2 to 4.

    11 12 22 25 64 

*/


#include <stdio.h>
void main()
{
    int i,j,k,l,temp,min;
    int n=5;
    int arry[5];
    printf("Enter Elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arry[i]);
    for(j=0;j<n-1;j++)
    {
        min=j;
        for (k=j+1;k<n;k++)
        {
            if (arry[k]<arry[min])
            min=k;
        }
        if (min!=j)
        {
            temp=arry[j];
            arry[j]=arry[min];
            arry[min]=temp;
        }
    }
    printf("Sorted array: ");
    for(l=0;l<n;l++)
        printf("%d\t",arry[l]);
}
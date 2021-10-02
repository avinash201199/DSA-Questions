/*
    QuickSort is a Divide and Conquer algorithm. 
    It picks an element as key/pivot and partitions the given array around the picked key/pivot.

*/


#include <stdio.h>
#define n 5

void printArray(int arry[])
//prints the array
{   
    printf("The array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arry[i]);
}

void swap(int i, int j,int arry[])
// swaps the numbers
{   int temp;
    temp = arry[i];
    arry[i] = arry[j];
    arry[j] = temp;
}
void quicksort(int arry[],int lb,int ub)
//Creates Parition as well Sorts them in ascending order
{
    if (lb<ub)
    {
        int key,i,j,flag=1;
        key=arry[lb];
        i=lb,j=ub+1;

        while(flag)
        {   i++;
            while(arry[i]<key)
                i++; 
            j--;
            while(arry[j]>key)
                j--;
            if (i<j)
                swap(i,j,arry);
            else
                flag=0;
        }
        swap(lb,j,arry);

        quicksort(arry,lb,j-1);
        quicksort(arry,j+1,ub);
    }
}


void main()
{
    int arry[n],i;
    int lb=0,ub=n-1;
    printf("Enter Elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arry[i]);
    quicksort(arry,lb,ub);
    printArray(arry);
}






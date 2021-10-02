#include <stdio.h>
#define n 5

void printArray(int arry[])
{   printf("The array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arry[i]);
}
void swap(int i, int j,int arry[])
{   int temp;
    temp = arry[i];
    arry[i] = arry[j];
    arry[j] = temp;
}
void quicksort(int arry[],int lb,int ub)
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







// int i,j,flag=1;
//     int key=arry[lb];
//     i=lb,j=ub+1;

//     swap(lb,j,arry);
//     // printArray(arry);

//     quicksort(arry,lb,j-1);
//     quicksort(arry,j+1,ub);










// #include<stdio.h>
// #define n 5

// void swap(int i,int j, int arry[])
// {
//     int temp;
//     temp=arry[i];
//     arry[i]=arry[j];
//     arry[j]=temp;
// }


// void q_sort(int arry[],int lb,int ub)
// {
//     int i,j,key,flag=1;
//     i=lb;j=ub+1;

//     key=arry[lb];

//     while(flag)
//     {
//         i++;
//         while(arry[i]<key)
//             i++;
//         j--;
//         while(arry[j]>key)
//             j--;
        
//         if (i<j)
//             swap(i,j,arry);
//         else    
//             flag=0;
//     }
//     swap(lb,j,arry);

//     q_sort(arry,lb,j-1);
//     q_sort(arry,j+1,ub);

// }

// void main()
// {
//     int i,arry[n],lb=0,ub=n-1;
//     for (i=0;i<n;i++)
//         scanf("%d",&arry[i]);
    
//     q_sort(arry,lb,ub);
//     printf("Sorted: ");
//     for (i=0;i<n;i++)
//         printf("%d",arry[i]);
// }
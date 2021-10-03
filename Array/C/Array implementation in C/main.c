// Tested on "https://www.programiz.com/c-programming/online-compiler/"

// Traversing 2d array
#include<stdio.h>
#include<stdlib.h>

void traverse(int arr[], int size){
    for(int i=0; i<size; i++)
        printf("%d ",arr[i]);
}

int main(){
    int arr[100]={1, 4, 6, 9, 15};
    int size=5;
    traverse(arr, size);
    return 0;
}

// linear search in linear array -------------------------------------------

int linearSearch(int arr[], int size, int element){
    int flag=0,index=0;
    for(int i=0; i<size; i++){
        
        if(arr[i] == element){
            flag=1;
            index=i+1;
        }
    }
        if (flag==1)
            return index;
        else
            return -1;
}

int main(){
    int arr[100]={1,4,8,12,45,78,23};
    int element=45, size=7;
    printf("Linear search...\n");
    int rslt = linearSearch(arr, size, element);
    printf("%d found at %d position.", element, rslt);
    return 0;
}

// binary search ---------------------------------------------------
#include <stdio.h>
int binarySearch(int arr[], int element, int size){
    int low=0, high=size-1;
    while(arr[low]<=arr[high]){
        int mid=(low+high)/2;
        if (arr[mid]==element)
            return mid;
        if (arr[mid]<element)
            low=mid+1;
        else
            high=mid-1;
    }
}
int main() {
    int arr[100]={1,5,9,24,44,67,78};
    int size=7, element=44;
    int rslt1 = binarySearch(arr, element, size);
    printf("Number %d found at %d position", element, rslt1-1);
    return 0;
}

// insertion and deletion of linear array ------------------------------------------
#include <stdio.h>
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertion(int arr[], int element, int size, int capacity, int index){
    if(size>capacity){
        return -1;
    }
    for(int i=size; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}

int deletion(int arr[], int size, int index){
    for(int i=index; i<=size;i++){
        arr[i]=arr[i+1];
    }
    return 1;
}

int main() {
    int arr[100]={1,5,9,24,44,67,78};
    int size=7, element=11, index=3;
    printf("Insertion here ...");
    insertion(arr, element, size, 100, index);
    size+=1;
    display(arr, size);
    
    printf("Deletion here ... ");
    deletion(arr, size, index);
    size-=1;
    display(arr, size);
    return 0;
}

// ------------------------------------------------------

// Binary Search using C

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int element, int size){
    int low=0, high=size-1;
    int mid=(low+high)/2;
    while(low<=high){
        if (arr[mid]==element)
            return mid;
        if (arr[mid]<element)
            arr[low]=arr[mid];
        else
            arr[high]=arr[mid];
    }
}

int main() {
    int arr[100]={1,5,9,24,44,67,78};
    int size=7, element=44;
    int rslt1 = binarySearch(arr, element, size);
    printf("Number %d found at %d.", element, rslt1);
    return 0;
}

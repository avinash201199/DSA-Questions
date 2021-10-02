// Traversing an array
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

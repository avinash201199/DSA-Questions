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

int main() {
    int arr[100]={1,5,9,24,44,67,78};
    int size=7, element=11, index=3;
    printf("Insertion here ...");
    insertion(arr, element, size, 100, index);
    size+=1;
    display(arr, size);
    return 0;
}

// ------------------------------------------------------

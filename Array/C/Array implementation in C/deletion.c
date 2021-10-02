#include <stdio.h>
void display(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    
    printf("Deletion here ... ");
    deletion(arr, size, index);
    size-=1;
    display(arr, size);
    return 0;
}

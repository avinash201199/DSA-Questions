#include <iostream>
using namespace std;

void swap_ints(int a, int b, int *arr){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main(){
    int arr[] = {2, 2, 1, 0, 1, 1, 0, 2, 0, 1};
    int n = sizeof(arr)/sizeof(int);
    int low = 0, mid = 0, high = n-1;
    while (mid <= high){
        switch (arr[mid])
        {
        case 0:
            swap_ints(mid, low, arr);
            mid++; low++;
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap_ints(high, mid, arr);
            high--;
            break;
        }
    }

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}
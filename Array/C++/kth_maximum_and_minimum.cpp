// sorting the array using O(N(logN)) sorting algorithm like Merge Sort, Heap Sort, etc, and return element at index k-1 in the sorted array.
// Time complexity of this solution is O(N logN)
// it is executed by using in built sort functions.

#include <algorithm>
#include<iostream>
using namespace std;

//structure to return value of both max and min together
struct minmax
{
    int min;
    int max;
};

//function to compute the kth max and min element
struct minmax kthsmallest(int arr[], int n, int k)
{
    struct minmax pair;
    //sort the given array
    sort(arr, arr + n);

    //Return kth element in the sorted array
    pair.min = arr[k-1];
    pair.max = arr[n-k];
    return pair;
}
//driver code
int main()
{
    int n;
    cout<< "Enter the number of elements of the array"<<endl;
    cin>>n;
    int arr[n];
    int k;
    cout<<"Enter the value of K"<<endl;
    cin>>k;
    cout<<"Enter the elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    struct minmax res = kthsmallest(arr,n,k);
    cout<<"The kth smallest element is "<< res.min<<endl;
    cout<<"The kth greatest element is "<< res.max<<endl;
    return 0;
}


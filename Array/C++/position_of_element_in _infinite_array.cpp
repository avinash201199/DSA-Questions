
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
	if (r>=l)
	{
		int mid = l + (r - l)/2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid-1, x);
		return binarySearch(arr, mid+1, r, x);
	}
	return -1;
}

int findPos(int arr[], int key)
{
	int l = 0, h = 1;
	int val = arr[0];

	// Find h to do binary search
	while (val < key)
	{
		l = h;	 // store previous high
		h = 2*h;	 // double high index
		val = arr[h]; // update new val
	}

	return binarySearch(arr, l, h, key);
}

int main()
{
	int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array : ";
    for(int i=0; i < n; i++)
    {
        cin>>arr[i];
    }
    int element;
    cout<<"enter the element to find: ";
    cin>>element;
	int ans = findPos(arr, element);
	if (ans==-1)
		cout << "Element not found";
	else
		cout << "Element found at index " << ans;
	return 0;
}

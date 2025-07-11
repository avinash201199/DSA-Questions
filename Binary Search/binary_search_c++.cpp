//Iterative Binary Search
#include <iostream>
using namespace std;

// Iterative Binary Search function
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Found, return index

        if (arr[mid] < target)
            left = mid + 1; // Move to right half
        else
            right = mid - 1; // Move to left half
    }
    return -1; // Not found
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (in ascending order): ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at position " << (result + 1) << endl;
    else
        cout << "Element not found in array." << endl;

    return 0;
}

// Recursive Binary Search 
#include <iostream>
using namespace std;

// Recursive Binary Search function
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1; // Not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid; // Found
    if (arr[mid] > target)
        return binarySearchRecursive(arr, left, mid - 1, target); // Left half
    else
        return binarySearchRecursive(arr, mid + 1, right, target); // Right half
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (in ascending order): ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1)
        cout << "Element found at position " << (result + 1) << endl;
    else
        cout << "Element not found in array." << endl;

    return 0;
}

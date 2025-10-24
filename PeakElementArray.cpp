#include <iostream>
#include <vector>
using namespace std;

int peakElement(vector<int> &arr) {
    int n = arr.size();
  
    for(int i = 0; i < n; i++) {
    	bool left = true;
        bool right = true;
      
        // Check for element to the left
        if(i > 0 && arr[i] <= arr[i - 1]) 
            left = false;
      
        // Check for element to the right
        if(i < n - 1 && arr[i] <= arr[i + 1])
            right = false;
      
        // If arr[i] is greater than its left as well as
        // its right element, return its index
        if(left && right) {
        	return i;
        }
    }
    return 0;
}

int main() {
    vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
    cout << peakElement(arr);
    return 0;
}

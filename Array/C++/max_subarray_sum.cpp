#include<bits/stdc++.h>
#include <climits>
using namespace std;

// Program to find the maximum subarray sum of an array of positive integers
// Uses Kadane's algorithm

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long max_so_far = INT_MIN;
        long long max_rn = 0;
        for (int i = 0; i < n; i++){
            max_rn = max_rn + arr[i];
            max_so_far = max(max_so_far, max_rn);
            if (max_rn < 0) max_rn = 0;
        }
        return max_so_far;
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
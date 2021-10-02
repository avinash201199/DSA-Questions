#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
	int minDifference(int arr[], int n)  {
	    int s=0;
	    for(int i=0;i<n;i++){
	        s+=arr[i];
	    }

	    bool t[n+1][s+1];

  for(int i=0;i<n+1;i++){
    for(int j=0;j<s+1;j++){
        if(i==0){
            t[i][j]=false;
        }
        if(j==0){
            t[i][j]=true;
        }
    }
  }

   for(int i=1;i<n+1;i++){
    for(int j=1;j<s+1;j++){
        if(arr[i-1]<=j){
            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        }else {
            t[i][j] = t[i-1][j];
        }
    }
  }
  int mn;
  for(int i=s/2;i>=0;i--){
      if(t[n][i]==true){
          mn= s - 2*i;
          break;
      }
  }

	return mn;
	}
};

int main()
{
   	int t;
    cin >> t;                           //Take no. of testcases
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	{
        	    cin >> a[i];            //Take elements of array
        	}
	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";

    }
    return 0;
}

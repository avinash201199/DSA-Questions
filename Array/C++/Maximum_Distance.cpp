#include<bits/stdc++.h>
using namespace std;
  int maxDistance(int arr[], int n)
    {
        unordered_map<int, int> mp;
        
        int res = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(mp.find(arr[i]) != mp.end())
            {
                res = max(res, i - mp[arr[i]]);
            }
            else
            {
                mp[arr[i]] = i;
            }
        }
        
        return res;
    }  

    int main()

    {
	    int arr[]={1,1,2,2,2,1};
	    int n = sizeof(arr)/sizeof(int);
	    int ans=maxDistance(arr,n);
	    cout<<ans;
	    return 0;
    }

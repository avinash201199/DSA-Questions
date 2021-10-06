// You are given N identical eggs and you have access to a K-floored building from 1 to K.

// There exists a floor f where 0 <= f <= K such that any egg dropped at a floor higher than f will break,
// and any egg dropped at or below floor f will not break. There are few rules given below. 

//  ->  An egg that survives a fall can be used again.
//  ->  A broken egg must be discarded.
//  ->  The effect of a fall is the same for all eggs.
//  ->  If the egg doesn't break at a certain floor, it will not break at any floor below.
//  ->  If the eggs breaks at a certain floor, it will break at any floor above.

// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// For more information, refer https://en.wikipedia.org/wiki/Dynamic_programming#Egg_dropping_puzzle

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n+1][k+1], res;
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int i=0; i<=k; i++){
            dp[1][i] = i;
        }
        
        for(int i=2; i<=n; i++){
            for(int j=2; j<=k; j++){
                dp[i][j] = INT_MAX;
                for(int x=1; x<j; x++){
                    res = 1+max(dp[i-1][x-1], dp[i][j-x]);
                    dp[i][j] = min(dp[i][j], res);
                }
            }
        }
        return dp[n][k];
    }
};

int main()
{
    int n, k;
    cin>>n>>k;
    Solution ob;
    cout<<ob.eggDrop(n, k)<<endl;
    return 0;
}
